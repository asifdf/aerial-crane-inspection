# Operations Checklist — Pegasus Drone Inspection System

> **PURPOSE**: Step-by-step operational runbook for all mission phases.
> Use this document alongside `docs/SAFETY_PROCEDURES.md` for every flight.
> Print and bring to field. Do not substitute from memory.

---

## Table of Contents

1. [Pre-Mission Checklist (10 Steps)](#1-pre-mission-checklist)
2. [Mission Monitoring](#2-mission-monitoring)
3. [Post-Mission Procedure](#3-post-mission-procedure)
4. [Emergency Landing (7 Steps)](#4-emergency-landing)
5. [Communications Failure Recovery (3-Tier)](#5-communications-failure-recovery)

---

## 1. Pre-Mission Checklist

Complete all 10 steps in order. No step may be skipped. Record initials against each.

| # | Step | Criteria | Init |
|---|------|---------|------|
| 1 | **Site survey** | Walk inspection zone. Mark obstacles, personnel exclusion area (radius ≥ 15 m from LZ), wind direction. Confirm no overhead wires within 50 m of flight path. | ___ |
| 2 | **Airspace & NOTAMs** | Verify no TFRs or active NOTAMs. Confirm FAA LAANC (or local authority) clearance is active. Operational ceiling ≤ 120 m AGL. | ___ |
| 3 | **Weather check** | Wind ≤ 7 m/s sustained, gusts ≤ 10 m/s. Visibility ≥ 3 km. No precipitation. Temp between −10 °C and 50 °C. Check forecast for mission duration + 30 min buffer. | ___ |
| 4 | **Hardware inspection** | Inspect airframe, propellers (no chips/cracks), motor mounts, landing gear. Confirm all fasteners are tight. Record drone ID and serial. | ___ |
| 5 | **Battery & power** | Measure battery voltage per cell (≥ 3.8 V/cell, delta ≤ 0.1 V). Confirm battery secured and connector locked. Spare battery charged and on-site. | ___ |
| 6 | **Sensor calibration** | GPS lock ≥ 12 sats, HDOP ≤ 1.0. Compass heading ±5° of reference. Baro altitude ±2 m of ground truth. | ___ |
| 7 | **Flight controller** | Power on FC. Load mission waypoints. Confirm geofence polygon is loaded (polygon + max altitude 120 m). Verify failsafe action = RTL. | ___ |
| 8 | **AI system boot** | SSH to Jetson. Run `ros2 node list` — confirm `defect_inference` and `mock_camera_node` (or `camera_node`) are present. Verify `/ai/node_health` publishing at ≥ 1 Hz. | ___ |
| 9 | **Comms check** | RC RSSI ≥ -80 dBm. Telemetry heartbeat ≥ 1 Hz. Companion computer link active. Crew radios tested on correct channel. All crew confirm call signs. | ___ |
| 10 | **Crew briefing & sign-off** | Brief all crew: mission objective, flight path, emergency procedures, emergency call ("DOWN" for emergency landing, "AWAY" for all-clear). Pilot and Operator both sign the Pre-Flight sign-off in `SAFETY_PROCEDURES.md §1`. | ___ |

**Go/No-Go Decision**: All 10 items must be checked before arm. Any open item = NO-GO.

---

## 2. Mission Monitoring

### 2.1 Continuous Monitoring (Throughout Flight)

The Mission Operator (non-pilot) monitors the following at all times:

| Parameter | Nominal | Warning | Action |
|-----------|---------|---------|--------|
| Battery % | > 40% | 25% | Begin RTL plan |
| Battery V/cell | > 3.7 V | < 3.7 V | RTL immediately |
| RSSI | > -80 dBm | -85 dBm | Reduce range, return |
| GPS sats | ≥ 12 | < 8 | Switch to manual, plan RTL |
| HDOP | ≤ 1.0 | > 1.5 | Switch to manual |
| AI health topic | Healthy | Degraded | Continue; no AI guidance |
| Inference latency | < 100 ms | > 200 ms | Log; investigate post-flight |
| Temperature (Jetson) | < 65 °C | > 80 °C | Reduce workload or land |

### 2.2 Inspection Phase Monitoring

During active inspection waypoints:

1. **Confirm AI is publishing**: `ros2 topic hz /ai/defect_detections` — expect 5–30 Hz.
2. **Monitor detection feed**: Open dashboard or run:
   ```bash
   ros2 topic echo /ai/defect_json | python3 -m json.tool
   ```
3. **Log image-defect pairs**: Confirm `/ai/annotated_image` is recording (if enabled).
4. **Zone coverage**: Tick off each inspection zone as the drone completes it.
   Use QGroundControl or mission log for zone status.
5. **CRITICAL detection alerts**: If dashboard shows CRITICAL risk:
   - Confirm detection in 3+ frames (temporal consistency).
   - Operator provides confirmation or rejects via dashboard.
   - Log decision with timestamp and rationale.

### 2.3 Routine Check Cadence

Every 2 minutes, operator verbally confirms to pilot:
> "Battery ___ %, GPS ___ sats, AI ___ [healthy/degraded/offline]."

Pilot acknowledges or calls for abort.

---

## 3. Post-Mission Procedure

Complete all steps before leaving the field.

### 3.1 Landing and Safe-Down

1. **Confirm drone on ground**: All propellers stopped. Wait 15 seconds after last
   motor spin before approaching.
2. **Disarm**: Verify motors are disarmed (FC status LED confirmed). RC transmitter
   in disarm position.
3. **Battery disconnect**: Disconnect main battery connector. Place battery on
   fireproof mat for cool-down (minimum 15 minutes before stowing).
4. **Power down Jetson**: Graceful shutdown:
   ```bash
   ros2 lifecycle set /defect_inference shutdown || true
   sudo shutdown -h now
   ```
5. **Retrieve all equipment**: Collect drone, remote, chargers, cones, landing pad.

### 3.2 Data Harvest

6. **Copy flight logs**: Pull FC logs (`.BIN` files) via USB or SD card:
   ```bash
   mavftp -m udp:localhost:14550 "ls @SYS/logs"
   ```
7. **Export AI audit log**: Copy from Jetson:
   ```bash
   scp jetson@192.168.1.100:/var/log/pegasus/safety_audit.jsonl ./logs/
   ```
8. **Export ROS2 bag** (if recorded):
   ```bash
   scp -r jetson@192.168.1.100:~/ros2_bags/mission_$(date +%Y%m%d)/ ./bags/
   ```
9. **Checksum verification**: Verify audit log integrity:
   ```bash
   sha256sum ./logs/safety_audit.jsonl > ./logs/safety_audit.jsonl.sha256
   ```

### 3.3 Post-Mission Reporting

10. **Inspection report**: Generate defect summary from audit JSONL:
    ```bash
    python3 scripts/generate_inspection_report.py \
      --audit-log ./logs/safety_audit.jsonl \
      --output ./reports/$(date +%Y%m%d)_inspection.pdf
    ```
11. **Hardware inspection**: Check propellers and airframe for flight damage.
    Log any wear or damage in the maintenance record.
12. **Incident check**: If any emergency procedure was activated, file an incident
    report within 24 hours (template in `docs/SAFETY_PROCEDURES.md §7`).

---

## 4. Emergency Landing

Activate when: motor failure, battery critical, loss of control, pilot command, or any
crew member calls "DOWN."

### Step-by-Step (7 Steps)

| Step | Action |
|------|--------|
| **1. Announce** | Pilot calls **"EMERGENCY LANDING"**. All crew clear landing zone and move ≥ 15 m upwind. |
| **2. Mode switch** | Pilot switches to LAND mode (RC switch) or sends LAND command: `ros2 service call /mavros/cmd/command mavros_msgs/srv/CommandLong "{command: 21, ...}"` |
| **3. Clear LZ** | Operator confirms landing zone is clear of people and obstacles. Calls **"LZ CLEAR"**. |
| **4. Monitor descent** | Watch for lateral drift. If drifting toward hazard: abort LAND, switch to STABILIZE, reposition manually, re-attempt LAND. |
| **5. Touch down** | Wait for full touchdown — all arms/legs on ground, drone stationary. |
| **6. Disarm** | Pilot disarms motors immediately after touchdown (RC kill switch or `ros2 service call /mavros/cmd/arming` with `value: false`). |
| **7. Approach** | Wait 10 seconds after motor stop. Operator approaches drone, disconnects battery, places on mat. Pilot stays at RC. |

### Key Rules

- **Never approach while motors are spinning.**
- If the drone is on fire → do not approach. Call emergency services. Use Class D extinguisher from distance.
- If the drone lands in an inaccessible area (roof, tree) → cordon area, do not leave unattended, retrieve safely.

---

## 5. Communications Failure Recovery

Three-tier protocol for comms failure. Work through tiers in order.

### Tier 1 — RC Link Lost, Telemetry Up (0 – 30 seconds)

**Situation**: RC transmitter RSSI drops to zero; telemetry (MAVLink) still active.

| Action | Command |
|--------|---------|
| 1. Operator alerts crew: **"RC LOST"** | — |
| 2. Wait 10 seconds for auto-reconnect | — |
| 3. If no recovery: send RTL via MAVROS | `ros2 service call /mavros/cmd/command mavros_msgs/srv/CommandLong "{command: 176, param1: 1.0, param2: 4.0}"` |
| 4. Monitor drone on GCS map; confirm climb to RTL altitude (15 m) | QGroundControl |
| 5. Re-bind RC transmitter; regain manual control when in range | RC transmitter re-bind |

**Expected outcome**: Drone RTLs autonomously and lands at home point.

---

### Tier 2 — RC and Telemetry Both Lost (30 – 120 seconds)

**Situation**: No RC signal. No MAVLink heartbeat. Drone position unknown.

| Action | Notes |
|--------|-------|
| 1. Operator alerts crew: **"FULL COMMS LOSS"** | Everyone heads up |
| 2. Verify FC failsafe activated | FC should start RTL after 10 s of no RC |
| 3. Move to last-known drone position | Note heading, speed, altitude at comms loss |
| 4. Listen for drone motors | Quadcoptors are audible at ≤ 200 m |
| 5. Attempt visual reacquisition | Binoculars if available; check cloud ceiling |
| 6. Do NOT activate companion watchdog RTL manually | Watchdog triggers automatically at 10 s |
| 7. Prepare for uncontrolled descent | Clear estimated landing area (radius = altitude × 1.5) |

**Expected outcome**: FC failsafe brings drone to home point or nearest safe spot.

---

### Tier 3 — Full Comms Loss, No Auto-Recovery (> 120 seconds)

**Situation**: No comms, no return, no visual, drone position unknown.

| Action | Notes |
|--------|-------|
| 1. Evacuate estimated impact area | Based on last known position + heading |
| 2. Alert local authority (ATC if near airport, police if urban) | Provide last known coords |
| 3. Wait for battery exhaustion | Estimated ~8 min hover at 50% throttle |
| 4. Send search team after battery estimated dead | Use GPS logger last waypoint if available |
| 5. Preserve all flight data | Do not power cycle GCS or companion computer until data is saved |
| 6. File incident report within 24 hours | Template in `docs/SAFETY_PROCEDURES.md §7` |
| 7. Do not fly again until root cause determined | Ground entire fleet until investigation complete |

**Expected outcome**: Drone lands via battery exhaustion. Team retrieves drone. Investigation launched.

---

## Quick Reference Card

```
PRE-MISSION (10 steps):  Site → Airspace → Weather → HW → Battery →
                         Sensors → FC → AI → Comms → Crew

MONITORING: Battery % / V, RSSI, GPS, AI health every 2 min.
            CRITICAL detections require human confirmation.

POST-MISSION: Land → Disarm → Battery out → Power down Jetson →
              Copy logs → Checksum → Report

EMERGENCY LANDING (7 steps):
  Announce → Mode LAND → Clear LZ → Monitor → Touch → Disarm → Approach

COMMS FAILURE:
  Tier 1 (RC lost, telem up):   RTL via MAVROS
  Tier 2 (all comms lost):      FC failsafe + visual search
  Tier 3 (no recovery):         Evacuate, alert authority, wait for batt dead
```

---

## Revision History

| Version | Date | Author | Changes |
|---------|------|--------|---------|
| 1.0 | 2026-06-15 | Pegasus Team | Initial release |
