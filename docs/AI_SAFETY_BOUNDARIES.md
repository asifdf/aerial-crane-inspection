# AI Safety Boundaries — Pegasus Drone Inspection System

> **MANDATORY CONSTRAINT**: The Pegasus AI subsystem is a **read-only reporting layer**.
> It observes, classifies, and reports defects. It never issues motor commands, never
> controls flight paths, and never overrides the human pilot or flight controller.

---

## Table of Contents

1. [Fundamental AI Safety Principle](#1-fundamental-ai-safety-principle)
2. [Detection Confidence Threshold](#2-detection-confidence-threshold)
3. [Minimum Detection Area](#3-minimum-detection-area)
4. [Maximum Detection Area (Frame Coverage)](#4-maximum-detection-area-frame-coverage)
5. [Temporal Consistency Requirement](#5-temporal-consistency-requirement)
6. [Human-in-the-Loop for Critical Detections](#6-human-in-the-loop-for-critical-detections)
7. [Audit Trail Requirements](#7-audit-trail-requirements)
8. [Data Retention Policy](#8-data-retention-policy)
9. [Safety Module Architecture](#9-safety-module-architecture)

---

## 1. Fundamental AI Safety Principle

### 1.1 AI Reports Only — Never Motor Control

The AI inference node (`defect_inference`) has **zero authority** over:

- Motor speed, direction, or arming state
- Flight mode changes (STABILIZE, LOITER, RTL, LAND, etc.)
- Waypoint modification or mission abort
- RC link or telemetry commands
- Any MAVLink command (MAV_CMD_*)

**Implementation enforcement**: The `SafetyFilter`, `SafetyAuditLogger`, and `SafetyEnforcer`
classes in `scripts/safety_boundaries.py` contain no motor control methods. This is
verified by automated tests (`tests/safety/test_safety_boundaries.py`).

**Permitted AI outputs**:
- ROS2 topic publications: `/ai/defect_detections`, `/ai/defect_array`, `/ai/defect_json`
- Health reporting: `/ai/node_health`
- JSONL audit log entries
- Operator dashboard notifications (read-only display)

### 1.2 AI Cannot Interfere With Flight Controller

The Jetson companion computer communicates with the PX4 flight controller over MAVROS.
The AI inference node subscribes to camera topics **only** and does not write to any
MAVROS command or service topics.

```
Allowed: /camera/image_raw  →  [AI Inference]  →  /ai/defect_detections
Forbidden: [AI Inference]  ✗→  /mavros/cmd/command
Forbidden: [AI Inference]  ✗→  /mavros/setpoint_velocity/cmd_vel
```

---

## 2. Detection Confidence Threshold

### 2.1 Minimum Confidence: 0.50

All detections with a model confidence score below **0.50 (50%)** are silently discarded
before any downstream processing, logging, or operator notification.

| Confidence | Action |
|-----------|--------|
| < 0.50 | **Discard** — not logged, not published |
| 0.50 – 0.69 | **Low confidence** — logged, published with `confidence_flag: "low"` |
| 0.70 – 0.89 | **Normal** — standard processing |
| ≥ 0.90 | **High confidence** — expedited operator notification |

### 2.2 Rationale

Crane surface imagery contains lighting gradients, reflections, and debris that
cause YOLO false positives at confidence levels below 0.5. Field testing showed
< 3% precision at confidence 0.3 and > 85% precision at confidence ≥ 0.5.

### 2.3 Runtime Configuration

The threshold is configurable via ROS2 parameter but has an enforced floor:

```yaml
# inference.yaml
conf_threshold: 0.50  # Default. Do not set below 0.50 without engineering review.
```

```python
# Safety enforcement — cannot be overridden by config
if detection.confidence < SafetyConfig.confidence_threshold:
    return  # Discard regardless of parameter value
```

---

## 3. Minimum Detection Area

### 3.1 Minimum Bounding Box: 10 × 10 Pixels (100 px²)

Any detection whose bounding box area is less than **100 square pixels** (equivalent
to a 10 × 10 pixel square) is discarded as noise.

| Bounding Box Area | Action |
|------------------|--------|
| < 100 px² | **Discard** — subpixel noise or JPEG artifact |
| 100 – 999 px² | **Small defect** — flag for follow-up inspection pass |
| ≥ 1000 px² | **Standard defect** — normal processing |

### 3.2 Rationale

At typical standoff distance (2–5 m from crane surface), a real surface crack occupies
a minimum of 10–15 pixels in width on a 640×480 sensor. Detections smaller than 10×10
are reliably noise, lens flares, or JPEG compression artifacts and should not generate
operator alerts.

### 3.3 Calculation

```python
x1, y1, x2, y2 = detection.bbox
area = (x2 - x1) * (y2 - y1)
if area < 100:
    discard()
```

---

## 4. Maximum Detection Area (Frame Coverage)

### 4.1 Maximum Frame Coverage: 50%

A defect detection that covers more than **50% of the camera frame** is automatically
flagged as `oversized`. Oversized detections are NOT discarded, but receive special
treatment:

| Coverage | Action |
|---------|--------|
| ≤ 50% | Normal detection |
| > 50% | `oversized=True` flag added; operator must manually review |

### 4.2 Rationale

A bounding box covering more than half the frame almost always indicates one of:
1. The drone is too close to the surface (safety hazard).
2. The model has produced a false-positive super-detection.
3. The camera feed contains image corruption.

These scenarios all require human review before any action is taken.

### 4.3 Calculation

```python
frame_area = frame_width * frame_height
det_area   = (x2 - x1) * (y2 - y1)
if det_area / frame_area > 0.50:
    detection.oversized = True
    notify_operator(detection)
```

---

## 5. Temporal Consistency Requirement

### 5.1 Minimum Consecutive Frames: 3

A detection is only considered **confirmed** after it has appeared in **3 or more
consecutive camera frames** at approximately the same location.

| Consecutive Frames | Status |
|-------------------|--------|
| 1 | **Candidate** — not reported to operator |
| 2 | **Candidate** — not reported to operator |
| ≥ 3 | **Confirmed** — reported to operator, logged to audit trail |

### 5.2 Rationale

Single-frame detections are frequently caused by:
- Motion blur during drone movement
- Brief RF interference in camera link
- Random model activations on texture

Three consecutive frames at approximately 10 FPS represent 300 ms of persistent
evidence — sufficient to distinguish a real defect from transient noise.

### 5.3 Implementation

```python
# SafetyFilter maintains per-detection temporal buffers
def check_temporal_consistency(self, detection_id: str, frame_id: int) -> bool:
    buf = self._temporal_buffers[detection_id]
    buf.append(frame_id)
    if len(buf) < self.config.temporal_window:
        return False
    return all(buf[i] == buf[i-1] + 1 for i in range(1, len(buf)))
```

### 5.4 Frame Gap Reset

If a detection is absent for any single frame, the consecutive-frame counter resets.
This prevents the accumulation of non-consecutive observations as confirmation.

---

## 6. Human-in-the-Loop for Critical Detections

### 6.1 CRITICAL Risk Always Requires Confirmation

Any detection classified as **CRITICAL** risk requires explicit human confirmation
before any escalation action (such as requesting a follow-up inspection pass or
halting further mission progress).

```
Risk Level  │  Auto-Report  │  Requires Human OK
───────────────────────────────────────────────
LOW         │  Yes          │  No
MEDIUM      │  Yes          │  No
HIGH        │  Yes          │  No
CRITICAL    │  Yes          │  YES — must be confirmed
```

### 6.2 Confirmation UI Flow

```
[AI detects CRITICAL risk defect]
         │
         ▼
[Publish to /ai/defect_detections with risk_level="CRITICAL"]
         │
         ▼
[Operator dashboard shows confirmation dialog]
         │
     ┌───┴───┐
   Confirm  Reject (false positive)
     │         │
[Log + alert] [Log dismissal]
```

### 6.3 Risk Classification

| Risk Level | Criteria |
|-----------|---------|
| LOW | paint_damage at any confidence; crack/corrosion at confidence < 0.5 |
| MEDIUM | corrosion at confidence ≥ 0.7; crack at 0.5 – 0.8 |
| HIGH | crack at confidence > 0.8 |
| CRITICAL | crack at confidence > 0.95; structural compromise assessment by operator |

---

## 7. Audit Trail Requirements

### 7.1 Every Detection Must Be Logged

Every detection that passes the safety filter (confidence ≥ 0.5, area ≥ 100 px²)
must produce a JSONL audit log entry **before** it is published to any ROS2 topic.

### 7.2 Required Audit Entry Fields

| Field | Type | Description |
|-------|------|-------------|
| `timestamp` | ISO 8601 string | UTC timestamp when detection was processed |
| `image_hash` | SHA-256 hex string | Hash of the raw camera frame bytes |
| `model_version` | string | TRT engine filename or model card version |
| `detection` | object | Full detection dict (class, confidence, bbox, risk) |

### 7.3 Audit Log Format (JSONL)

Each line is a complete JSON object:

```json
{
  "timestamp": "2026-06-15T07:30:00.123456+00:00",
  "image_hash": "a1b2c3d4e5f6...64_hex_chars",
  "model_version": "hybrid_fp16_v1.0.trt",
  "detection": {
    "class_name": "crack",
    "confidence": 0.87,
    "bbox": [120, 80, 240, 160],
    "risk_level": "HIGH",
    "oversized": false
  }
}
```

### 7.4 Audit Log Location

```
/var/log/pegasus/safety_audit.jsonl        # Production (Jetson)
/tmp/pegasus_safety_audit.jsonl            # Development / CI default
```

### 7.5 Audit Log Integrity

- Logs are **append-only** — no deletion or modification permitted in-field.
- Log file SHA-256 checksums are computed at mission end and stored alongside.
- Tampering with audit logs invalidates the inspection certificate.

---

## 8. Data Retention Policy

| Data Type | Retention Period | Location | Purge Method |
|-----------|-----------------|----------|-------------|
| Raw camera images | **30 days** | `/data/images/` | Automated cron job |
| Annotated images | **30 days** | `/data/annotated/` | Automated cron job |
| Detection JSONL logs | **1 year** | `/var/log/pegasus/` | Automated cron job |
| Inspection reports (PDF) | **5 years** | Cloud archive | Manual / policy |
| Audit trail checksums | **5 years** | Cloud archive | Manual / policy |

### 8.1 Purge Schedule

```bash
# /etc/cron.d/pegasus-data-retention
# Run nightly at 02:00
0 2 * * * pegasus find /data/images -mtime +30 -delete
0 2 * * * pegasus find /data/annotated -mtime +30 -delete
0 3 * * * pegasus find /var/log/pegasus -name "*.jsonl" -mtime +365 -delete
```

---

## 9. Safety Module Architecture

```
scripts/safety_boundaries.py
├── SafetyConfig          # Dataclass: all configurable thresholds
├── SafetyFilter          # Validates detections: confidence, area, temporal
│   ├── filter_detections()
│   ├── check_temporal_consistency()
│   └── requires_human_confirmation()
├── SafetyAuditLogger     # Writes JSONL audit entries
│   ├── log_detection()
│   └── hash_image()
├── SafetyEnforcer        # Orchestrates filter + audit
│   ├── process()
│   └── requires_human_confirmation()
├── create_cv_bridge()    # Graceful cv_bridge / numpy compatibility wrapper
└── select_inference_mode()  # Returns 'tensorrt' or 'mock' based on GPU availability
```

### 9.1 Automated Test Coverage

All safety boundaries are verified by `tests/safety/test_safety_boundaries.py`:

| Test | Boundary Verified |
|------|------------------|
| `test_confidence_threshold_enforced` | Detections below 0.5 are filtered |
| `test_min_detection_area_enforced` | Detections < 10×10 px are discarded |
| `test_max_detection_area_capped` | Detections > 50% frame are flagged |
| `test_temporal_consistency_required` | 3+ consecutive frames required |
| `test_never_motor_control` | No motor methods on any safety class |
| `test_critical_detection_requires_confirmation` | CRITICAL needs human OK |
| `test_audit_log_format` | JSONL has timestamp, image_hash, model_version |
| `test_cv_bridge_fallback_graceful` | numpy 1.x/2.x handled gracefully |
| `test_inference_node_starts_in_mock_mode_when_no_gpu` | GPU fallback to mock |

---

## Revision History

| Version | Date | Author | Changes |
|---------|------|--------|---------|
| 1.0 | 2026-06-15 | Pegasus Team | Initial release |
