"""
Automated safety boundary tests for Pegasus AI drone inspection system.

Verifies that all AI safety constraints are correctly enforced by
scripts/safety_boundaries.py.  These tests must pass in CI (no GPU, no ROS2).
"""

import hashlib
import json
import sys
from pathlib import Path
from unittest.mock import patch

import pytest

sys.path.insert(0, str(Path(__file__).parent.parent.parent / "scripts"))

from safety_boundaries import (
    SafetyAuditLogger,
    SafetyConfig,
    SafetyEnforcer,
    SafetyFilter,
    create_cv_bridge,
    select_inference_mode,
)


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------


def _det(
    confidence: float = 0.8,
    x1: float = 50,
    y1: float = 50,
    x2: float = 100,
    y2: float = 100,
    risk_level: str = "low",
    class_name: str = "crack",
) -> dict:
    return {
        "class_name": class_name,
        "confidence": confidence,
        "bbox": [x1, y1, x2, y2],
        "risk_level": risk_level,
    }


# ---------------------------------------------------------------------------
# 1. Confidence threshold
# ---------------------------------------------------------------------------


class TestConfidenceThreshold:
    def test_confidence_threshold_enforced(self):
        sf = SafetyFilter(SafetyConfig(confidence_threshold=0.5))
        detections = [
            _det(confidence=0.3),   # below — discard
            _det(confidence=0.49),  # just below — discard
            _det(confidence=0.5),   # exactly at threshold — keep
            _det(confidence=0.8),   # above — keep
        ]
        results = sf.filter_detections(detections)

        assert len(results) == 2, f"Expected 2 detections above threshold, got {len(results)}"
        assert all(d["confidence"] >= 0.5 for d in results)


# ---------------------------------------------------------------------------
# 2. Minimum detection area
# ---------------------------------------------------------------------------


class TestMinDetectionArea:
    def test_min_detection_area_enforced(self):
        sf = SafetyFilter(SafetyConfig(min_area=100))

        small = _det(x1=0, y1=0, x2=9, y2=9)    # 9×9 = 81 px² — discard
        exact = _det(x1=0, y1=0, x2=10, y2=10)   # 10×10 = 100 px² — keep
        large = _det(x1=0, y1=0, x2=20, y2=20)   # 20×20 = 400 px² — keep

        results = sf.filter_detections([small, exact, large])
        areas = [(d["bbox"][2] - d["bbox"][0]) * (d["bbox"][3] - d["bbox"][1]) for d in results]

        assert len(results) == 2, f"Expected 2 detections with area >= 100, got {len(results)}"
        assert all(a >= 100 for a in areas)


# ---------------------------------------------------------------------------
# 3. Maximum detection area (frame coverage)
# ---------------------------------------------------------------------------


class TestMaxDetectionArea:
    def test_max_detection_area_capped(self):
        sf = SafetyFilter(SafetyConfig(max_area_ratio=0.5))
        frame_w, frame_h = 640, 480  # frame area = 307,200 px²

        # 640×200 / 307200 ≈ 41.7% — normal, not flagged
        normal = _det(x1=0, y1=0, x2=640, y2=200)
        # 640×300 / 307200 ≈ 62.5% — oversized, must be flagged
        oversized = _det(x1=0, y1=0, x2=640, y2=300)

        results = sf.filter_detections([normal, oversized], frame_width=frame_w, frame_height=frame_h)

        assert len(results) == 2, "Both detections should survive (oversized is flagged, not dropped)"
        assert results[0]["oversized"] is False, "Normal detection must not be flagged"
        assert results[1]["oversized"] is True, "Oversized detection must be flagged"


# ---------------------------------------------------------------------------
# 4. Temporal consistency
# ---------------------------------------------------------------------------


class TestTemporalConsistency:
    def test_temporal_consistency_required(self):
        sf = SafetyFilter(SafetyConfig(temporal_window=3))
        det_id = "crack_zone_A"

        # Frames 1 and 2: not yet enough consecutive frames
        assert sf.check_temporal_consistency(det_id, 1) is False
        assert sf.check_temporal_consistency(det_id, 2) is False
        # Frame 3: three consecutive frames → confirmed
        assert sf.check_temporal_consistency(det_id, 3) is True

    def test_temporal_consistency_breaks_on_gap(self):
        sf = SafetyFilter(SafetyConfig(temporal_window=3))
        det_id = "crack_zone_B"

        sf.check_temporal_consistency(det_id, 1)
        sf.check_temporal_consistency(det_id, 2)
        # Gap: frame 5 (not 3) → streak broken
        result = sf.check_temporal_consistency(det_id, 5)
        assert result is False


# ---------------------------------------------------------------------------
# 5. No motor control methods
# ---------------------------------------------------------------------------


class TestNoMotorControl:
    def test_never_motor_control(self):
        motor_methods = {
            "set_motor", "arm", "disarm", "thrust",
            "throttle", "spin", "motor_command",
        }
        for cls in (SafetyFilter, SafetyAuditLogger, SafetyEnforcer):
            public_methods = {name for name in dir(cls) if not name.startswith("_")}
            forbidden = public_methods & motor_methods
            assert not forbidden, (
                f"{cls.__name__} must not expose motor control methods; found: {forbidden}"
            )


# ---------------------------------------------------------------------------
# 6. Critical detection requires human confirmation
# ---------------------------------------------------------------------------


class TestCriticalDetectionConfirmation:
    def test_critical_detection_requires_confirmation(self):
        sf = SafetyFilter()

        assert sf.requires_human_confirmation(_det(risk_level="CRITICAL")) is True
        assert sf.requires_human_confirmation(_det(risk_level="critical")) is True  # case-insensitive
        assert sf.requires_human_confirmation(_det(risk_level="high")) is False
        assert sf.requires_human_confirmation(_det(risk_level="medium")) is False
        assert sf.requires_human_confirmation(_det(risk_level="low")) is False


# ---------------------------------------------------------------------------
# 7. Audit log format
# ---------------------------------------------------------------------------


class TestAuditLogFormat:
    def test_audit_log_format(self, tmp_path):
        log_file = tmp_path / "audit.jsonl"
        logger = SafetyAuditLogger(log_path=log_file)

        det = _det(confidence=0.9, risk_level="HIGH")
        image_hash = hashlib.sha256(b"synthetic_frame_bytes").hexdigest()
        model_version = "hybrid_fp16_v1.0.trt"

        entry = logger.log_detection(det, image_hash, model_version)

        # Returned dict has required fields
        assert "timestamp" in entry, "Audit entry must contain 'timestamp'"
        assert "image_hash" in entry, "Audit entry must contain 'image_hash'"
        assert "model_version" in entry, "Audit entry must contain 'model_version'"
        assert entry["image_hash"] == image_hash
        assert entry["model_version"] == model_version

        # Written to disk as valid JSONL
        assert log_file.exists()
        lines = log_file.read_text().strip().split("\n")
        assert len(lines) == 1
        written = json.loads(lines[0])
        assert "timestamp" in written
        assert "image_hash" in written
        assert "model_version" in written
        assert written["image_hash"] == image_hash
        assert written["model_version"] == model_version


# ---------------------------------------------------------------------------
# 8. cv_bridge numpy 1.x/2.x fallback
# ---------------------------------------------------------------------------


class TestCvBridgeFallback:
    def test_cv_bridge_fallback_graceful(self):
        """create_cv_bridge returns None gracefully when cv_bridge is unavailable."""
        with patch.dict("sys.modules", {"cv_bridge": None}):
            result = create_cv_bridge()
        # Must not raise; must return None when bridge is unavailable
        assert result is None

    def test_cv_bridge_fallback_graceful_exception(self):
        """create_cv_bridge does not propagate any exception."""
        with patch.dict("sys.modules", {"cv_bridge": None}):
            try:
                result = create_cv_bridge()
                assert result is None
            except Exception as exc:
                pytest.fail(f"create_cv_bridge raised unexpectedly: {exc}")


# ---------------------------------------------------------------------------
# 9. Inference node falls back to mock mode without GPU
# ---------------------------------------------------------------------------


class TestInferenceMockFallback:
    def test_inference_node_starts_in_mock_mode_when_no_gpu(self):
        """select_inference_mode returns 'mock' when TensorRT/pycuda are unavailable."""
        with patch.dict("sys.modules", {"pycuda": None, "pycuda.autoinit": None, "tensorrt": None}):
            mode = select_inference_mode()
        assert mode == "mock", f"Expected 'mock' without GPU, got '{mode}'"
