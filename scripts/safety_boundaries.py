"""
Safety boundaries for Pegasus AI drone inspection system.

Enforces operational constraints on AI detections.
Reports only — no motor control. Never issues flight commands.
"""

from __future__ import annotations

import hashlib
import json
import logging
from collections import deque
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Optional


@dataclass
class SafetyConfig:
    """Configurable thresholds for safety boundary enforcement."""

    confidence_threshold: float = 0.5
    min_area: int = 100          # minimum 10x10 pixels
    max_area_ratio: float = 0.5  # maximum 50% of frame
    temporal_window: int = 3     # consecutive frames required for confirmation


class SafetyFilter:
    """
    Validates AI detections against safety configuration.

    Filters low-confidence and undersized detections.
    Flags oversized detections that exceed max_area_ratio.
    Tracks temporal consistency per detection ID.
    """

    def __init__(self, config: Optional[SafetyConfig] = None) -> None:
        self.config = config or SafetyConfig()
        self._temporal_buffers: dict[str, deque] = {}

    def filter_detections(
        self,
        detections: list[dict],
        frame_width: int = 640,
        frame_height: int = 480,
    ) -> list[dict]:
        """Apply confidence and area filters. Returns detections that pass, with oversized flag."""
        result = []
        for det in detections:
            if not self._passes_confidence(det):
                continue
            if not self._passes_min_area(det):
                continue
            validated = dict(det)
            validated["oversized"] = self._exceeds_max_area(det, frame_width, frame_height)
            result.append(validated)
        return result

    def _passes_confidence(self, det: dict) -> bool:
        return float(det.get("confidence", 0.0)) >= self.config.confidence_threshold

    def _passes_min_area(self, det: dict) -> bool:
        x1, y1, x2, y2 = det["bbox"]
        return (x2 - x1) * (y2 - y1) >= self.config.min_area

    def _exceeds_max_area(self, det: dict, frame_width: int, frame_height: int) -> bool:
        frame_area = frame_width * frame_height
        if frame_area == 0:
            return False
        x1, y1, x2, y2 = det["bbox"]
        det_area = (x2 - x1) * (y2 - y1)
        return (det_area / frame_area) > self.config.max_area_ratio

    def check_temporal_consistency(self, detection_id: str, frame_id: int) -> bool:
        """Return True once detection_id has been seen for temporal_window consecutive frames."""
        if detection_id not in self._temporal_buffers:
            self._temporal_buffers[detection_id] = deque(maxlen=self.config.temporal_window)

        buf = self._temporal_buffers[detection_id]
        buf.append(frame_id)

        if len(buf) < self.config.temporal_window:
            return False

        frames = list(buf)
        return all(frames[i] == frames[i - 1] + 1 for i in range(1, len(frames)))

    def requires_human_confirmation(self, detection: dict) -> bool:
        """CRITICAL risk detections always require explicit human confirmation."""
        return str(detection.get("risk_level", "")).upper() == "CRITICAL"


class SafetyAuditLogger:
    """
    Writes JSONL audit entries for every safety-validated detection.

    Retention policy:
      - Raw images:      30 days
      - Detection logs:  365 days (1 year)
    """

    IMAGE_RETENTION_DAYS = 30
    DETECTION_RETENTION_DAYS = 365

    def __init__(self, log_path: Optional[Path] = None) -> None:
        self.log_path = log_path or Path("/tmp/pegasus_safety_audit.jsonl")
        self._log = logging.getLogger("safety_audit")

    def log_detection(
        self,
        detection: dict,
        image_hash: str,
        model_version: str,
        timestamp: Optional[str] = None,
    ) -> dict:
        """Write a JSONL audit entry. Returns the entry written."""
        entry = {
            "timestamp": timestamp or datetime.now(tz=timezone.utc).isoformat(),
            "image_hash": image_hash,
            "model_version": model_version,
            "detection": detection,
        }
        with open(self.log_path, "a") as f:
            f.write(json.dumps(entry) + "\n")
        return entry

    @staticmethod
    def hash_image(image_bytes: bytes) -> str:
        """SHA-256 hash of raw image bytes for audit trail integrity."""
        return hashlib.sha256(image_bytes).hexdigest()


class SafetyEnforcer:
    """
    Orchestrates SafetyFilter and SafetyAuditLogger.

    Entry point for all detection safety decisions. Guarantees that every
    detection that reaches downstream consumers has passed safety filtering
    and has an immutable audit record.
    """

    def __init__(
        self,
        config: Optional[SafetyConfig] = None,
        log_path: Optional[Path] = None,
    ) -> None:
        self.config = config or SafetyConfig()
        self.filter = SafetyFilter(self.config)
        self.audit = SafetyAuditLogger(log_path)

    def process(
        self,
        detections: list[dict],
        image_hash: str,
        model_version: str,
        frame_width: int = 640,
        frame_height: int = 480,
    ) -> list[dict]:
        """Filter detections, log each validated one, and return the validated list."""
        validated = self.filter.filter_detections(detections, frame_width, frame_height)
        for det in validated:
            self.audit.log_detection(det, image_hash, model_version)
        return validated

    def requires_human_confirmation(self, detection: dict) -> bool:
        return self.filter.requires_human_confirmation(detection)


def create_cv_bridge():
    """
    Create a CvBridge instance with graceful numpy 1.x / 2.x fallback.

    numpy 2.x removed deprecated aliases (np.bool, np.int, etc.) that older
    cv_bridge Python bindings may reference. Returns None if cv_bridge is
    unavailable or incompatible rather than raising.
    """
    try:
        import numpy as np

        # Restore removed numpy 1.x aliases for cv_bridge compatibility
        for _alias, _target in [
            ("bool", np.bool_),
            ("int", np.int_),
            ("float", np.float64),
            ("complex", np.complex128),
            ("object", np.object_),
            ("str", np.str_),
        ]:
            if not hasattr(np, _alias):
                setattr(np, _alias, _target)

        from cv_bridge import CvBridge

        return CvBridge()
    except Exception:
        return None


def select_inference_mode() -> str:
    """
    Detect available compute and select inference backend.

    Returns 'tensorrt' if CUDA + TensorRT are available, 'mock' otherwise.
    Used by the inference node to start gracefully in CI or non-GPU environments.
    """
    try:
        import pycuda.autoinit  # noqa: F401
        import tensorrt  # noqa: F401

        return "tensorrt"
    except Exception:
        return "mock"
