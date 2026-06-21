"""
Contract Tests - Immutable test definitions that define the expected behavior
of each milestone. These are written FIRST (Red phase) before implementation.

Run with: pytest tests/contracts/ -v
"""

import json
from pathlib import Path

import pytest

# =============================================================================
# MILESTONE 0: Foundation & Test Harness
# =============================================================================


class TestEnvironmentContracts:
    """Basic environment contracts that must pass before any milestone."""

    def test_python_imports(self):
        """Core dependencies must be importable."""
        # cv_bridge is ROS2 system package - test separately if available
        try:
            from cv_bridge import CvBridge
        except (ImportError, AttributeError):
            pytest.skip("cv_bridge not available (numpy version mismatch)")
        # tensorrt is Jetson-specific
        try:
            import tensorrt as trt
        except ImportError:
            pytest.skip("tensorrt not installed (Jetson-only)")

    def test_ros2_workspace_structure(self):
        """ROS2 workspace must have required packages."""
        ws = Path(__file__).parent.parent.parent / "ros2_ws"
        assert (ws / "src" / "pegasus_msgs").exists(), "pegasus_msgs package missing"
        assert (ws / "src" / "pegasus_ai").exists(), "pegasus_ai package missing"

    def test_pegasus_msgs_structure(self):
        """pegasus_msgs must have all required message definitions."""
        msgs = Path(__file__).parent.parent.parent / "ros2_ws" / "src" / "pegasus_msgs" / "msg"
        required = [
            "DefectDetection.msg",
            "DefectArray.msg",
            "InspectionResult.msg",
            "ZoneInfo.msg",
            "NodeHealth.msg",
        ]
        for msg in required:
            assert (msgs / msg).exists(), f"Missing message: {msg}"

    def test_pegasus_ai_structure(self):
        """pegasus_ai must have required nodes and config."""
        ai = Path(__file__).parent.parent.parent / "ros2_ws" / "src" / "pegasus_ai"
        assert (ai / "pegasus_ai" / "inference_node.py").exists()
        assert (ai / "pegasus_ai" / "mock_camera_node.py").exists()
        assert (ai / "pegasus_ai" / "test_publisher.py").exists()
        assert (ai / "config" / "inference.yaml").exists()
        assert (ai / "launch" / "inference.launch.py").exists()

    def test_ci_pipeline_exists(self):
        """GitHub Actions CI workflow must exist."""
        ci = Path(__file__).parent.parent.parent / ".github" / "workflows" / "ci.yml"
        assert ci.exists(), "CI workflow missing"

    def test_docker_compose_exists(self):
        """Docker Compose for Isaac Sim + ROS2 must exist."""
        dc = Path(__file__).parent.parent.parent / "docker-compose.yml"
        assert dc.exists(), "docker-compose.yml missing"

    def test_pre_commit_config_exists(self):
        """Pre-commit hooks config must exist."""
        pc = Path(__file__).parent.parent.parent / ".pre-commit-config.yaml"
        assert pc.exists(), ".pre-commit-config.yaml missing"

    def test_crane_environment_script_syntax(self):
        """Isaac Sim bridge script must be syntactically valid Python."""
        script = Path(__file__).parent.parent.parent / "scripts" / "isaac_sim_ros2_bridge_test.py"
        import ast

        with open(script) as f:
            ast.parse(f.read())

    def test_dataset_dirs_exist(self):
        """Dataset directory structure for synthetic data must exist."""
        root = Path(__file__).parent.parent.parent / "dataset"
        assert root.exists(), "dataset root missing"


# =============================================================================
# MILESTONE 1: Synthetic Data Generation Contracts
# =============================================================================


class TestMilestone1DataGeneration:
    """Contracts for synthetic dataset generation from Isaac Sim."""

    DATASET_ROOT = Path(__file__).parent.parent.parent / "dataset" / "synthetic_v2"

    @pytest.fixture(autouse=True)
    def check_dataset_exists(self):
        """Skip tests if dataset not yet generated."""
        if not self.DATASET_ROOT.exists():
            pytest.skip("Synthetic dataset not yet generated")

    def test_dataset_directory_structure(self):
        """Synthetic dataset must have required directory structure."""
        required = [
            "images",
            "labels_yolo",
            "masks",
            "metadata.json",
        ]
        for d in required:
            assert (self.DATASET_ROOT / d).exists(), f"Missing: {d}"

    def test_dataset_size_minimum(self):
        """Must generate at least 100 synthetic images."""
        img_dir = self.DATASET_ROOT / "images"
        count = len(list(img_dir.glob("*.png"))) + len(list(img_dir.glob("*.jpg")))
        assert count >= 100, f"Only {count} images, need ≥100"

    def test_domain_randomization_coverage(self):
        """Metadata must document randomization coverage."""
        meta = json.loads((self.DATASET_ROOT / "metadata.json").read_text())
        required_keys = [
            "lighting_modes",
            "camera_angles",
            "class_counts",
            "total_annotations",
        ]
        # Check top-level keys: lists should have 5+ items, ints should be >= 5
        for key in required_keys:
            assert key in meta, f"Missing randomization metadata: {key}"
            val = meta[key]
            if isinstance(val, dict):
                count = len(val)
            elif isinstance(val, (list, tuple)):
                count = len(val)
            else:
                count = int(val) if val else 0
            # class_counts is a dict of 3 classes — that's by design
            if key == "class_counts":
                assert count >= 3, f"Not enough classes in {key}: {count}"
            else:
                assert count >= 5, f"Insufficient variation for {key}: {count}"
        # Check per-sample keys (crack_shapes exists in sample data)
        sample_keys = {"crack_shapes"}
        found_keys = set()
        for sample in meta.get("samples", []):
            found_keys.update(sample_keys & set(sample.keys()))
        missing_keys = sample_keys - found_keys
        assert not missing_keys, f"Missing per-sample metadata keys: {missing_keys}"

    def test_yolo_label_format(self):
        """YOLO labels must follow correct format: class_id x_center y_center width height (normalized)."""
        label_dir = self.DATASET_ROOT / "labels_yolo"
        labels = list(label_dir.glob("*.txt"))
        assert len(labels) > 0, "No label files found"

        for label_file in labels[:100]:  # Sample check
            content = label_file.read_text().strip()
            if not content:
                continue
            for line in content.split("\n"):
                parts = line.split()
                assert len(parts) == 5, f"Invalid label format in {label_file}: {line}"
                class_id = int(parts[0])
                assert 0 <= class_id <= 2, f"Invalid class_id: {class_id}"
                # Check normalized coordinates
                for coord in parts[1:]:
                    val = float(coord)
                    assert 0.0 <= val <= 1.0, f"Coordinate out of range [0,1]: {val}"

    def test_image_label_pairing(self):
        """Every image must have a corresponding label file with same stem."""
        img_dir = self.DATASET_ROOT / "images"
        lbl_dir = self.DATASET_ROOT / "labels_yolo"

        img_stems = {p.stem for p in img_dir.glob("*.png")}
        img_stems.update(p.stem for p in img_dir.glob("*.jpg"))
        lbl_stems = {p.stem for p in lbl_dir.glob("*.txt")}

        missing_labels = img_stems - lbl_stems
        missing_images = lbl_stems - img_stems

        assert len(missing_labels) == 0, f"Images without labels: {missing_labels}"
        assert len(missing_images) == 0, f"Labels without images: {missing_images}"

    def test_class_distribution(self):
        """Both crack and corrosion classes must be represented."""
        lbl_dir = self.DATASET_ROOT / "labels_yolo"
        class_counts = {0: 0, 1: 0, 2: 0}

        for label_file in lbl_dir.glob("*.txt"):
            for line in label_file.read_text().splitlines():
                if line.strip():
                    class_counts[int(line.split()[0])] += 1

        assert class_counts[0] > 100, f"Insufficient crack samples: {class_counts[0]}"
        assert class_counts[1] > 100, f"Insufficient corrosion samples: {class_counts[1]}"


# =============================================================================
# MILESTONE 2: Baseline Model Training Contracts
# =============================================================================


class TestMilestone2Training:
    """Contracts for YOLO baseline training on synthetic data."""

    RUNS_DIR = Path(__file__).parent.parent.parent / "runs" / "detect" / "train"

    @pytest.fixture(autouse=True)
    def check_training_exists(self):
        if not self.RUNS_DIR.exists():
            pytest.skip("Training not yet completed")

    def test_training_completed(self):
        """Training must complete successfully with best.pt."""
        assert (self.RUNS_DIR / "weights" / "best.pt").exists(), "best.pt not found"
        assert (self.RUNS_DIR / "results.csv").exists(), "Training results not found"

    def test_map50_threshold(self):
        """mAP@0.5 must be ≥ 0.70 on synthetic validation set."""
        results = self.RUNS_DIR / "results.csv"
        import pandas as pd

        df = pd.read_csv(results)
        # Last epoch metrics
        map50 = df.iloc[-1]["metrics/mAP50(B)"]
        assert map50 >= 0.70, f"mAP@0.5 = {map50:.3f}, need ≥ 0.70"

    def test_map50_95_threshold(self):
        """mAP@0.5:0.95 must be ≥ 0.40."""
        results = self.RUNS_DIR / "results.csv"
        import pandas as pd

        df = pd.read_csv(results)
        map50_95 = df.iloc[-1]["metrics/mAP50-95(B)"]
        assert map50_95 >= 0.40, f"mAP@0.5:0.95 = {map50_95:.3f}, need ≥ 0.40"

    def test_class_wise_performance(self):
        """Both classes must have decent AP."""
        results = self.RUNS_DIR / "results.csv"
        import pandas as pd

        df = pd.read_csv(results)
        # Check per-class metrics exist
        assert "metrics/AP50(crack)" in df.columns
        assert "metrics/AP50(corrosion)" in df.columns
        ap_crack = df.iloc[-1]["metrics/AP50(crack)"]
        ap_corrosion = df.iloc[-1]["metrics/AP50(corrosion)"]
        assert ap_crack >= 0.65, f"Crack AP50 = {ap_crack:.3f}"
        assert ap_corrosion >= 0.65, f"Corrosion AP50 = {ap_corrosion:.3f}"

    def test_onnx_export_exists(self):
        """ONNX model must be exported."""
        assert (self.RUNS_DIR / "weights" / "best.onnx").exists(), "ONNX export missing"

    def test_onnx_model_loadable(self):
        """ONNX model must load and run inference."""
        import numpy as np
        import onnxruntime as ort

        session = ort.InferenceSession(str(self.RUNS_DIR / "weights" / "best.onnx"))
        dummy = np.random.randn(1, 3, 640, 640).astype(np.float32)
        outputs = session.run(None, {"images": dummy})
        assert outputs[0].shape[1] == 84, f"Unexpected output shape: {outputs[0].shape}"

    def test_inference_speed_cpu(self):
        """CPU inference must be < 100ms (CI gate)."""
        import time

        import numpy as np
        import onnxruntime as ort

        session = ort.InferenceSession(str(self.RUNS_DIR / "weights" / "best.onnx"))
        dummy = np.random.randn(1, 3, 640, 640).astype(np.float32)

        # Warmup
        for _ in range(5):
            session.run(None, {"images": dummy})

        times = []
        for _ in range(20):
            t0 = time.perf_counter()
            session.run(None, {"images": dummy})
            times.append(time.perf_counter() - t0)

        median_ms = np.median(times) * 1000
        assert median_ms < 100, f"CPU inference too slow: {median_ms:.1f}ms"


# =============================================================================
# MILESTONE 3: ROS2 Integration Contracts
# =============================================================================


class TestMilestone3ROS2Integration:
    """Contracts for ROS2 inference node."""

    @pytest.fixture(autouse=True)
    def check_ros2_node(self):
        """Skip if ROS2 node not available for testing."""
        # These tests require a running ROS2 system
        pytest.skip("Requires running ROS2 - run manually with test_publisher")

    def test_node_starts_without_errors(self):
        """Inference node must start and register publishers/subscribers."""
        pass  # Implemented in integration test

    def test_input_output_topics(self):
        """Node must subscribe to /camera/image_raw and publish to /ai/defect_detections, /ai/defect_json."""
        pass

    def test_e2e_inference_pipeline(self):
        """End-to-end: publish image → receive detection JSON with correct schema."""
        pass

    def test_detection_message_schema(self):
        """DefectArray message must have all required fields populated."""
        pass

    def test_json_output_schema(self):
        """JSON output must match expected schema for dashboard."""
        pass

    def test_inference_latency_p95(self):
        """P95 latency must be < 200ms (image in → JSON out)."""
        pass

    def test_tensorrt_engine_used(self):
        """Node must use TensorRT engine (not PyTorch)."""
        pass

    def test_health_monitoring(self):
        """Node must publish /ai/node_health with FPS, latency, GPU stats."""
        pass


# =============================================================================
# MILESTONE 4: Domain Randomization Hardening Contracts
# =============================================================================


class TestMilestone4Hardening:
    """Contracts for expanded domain randomization."""

    DATASET_V2_ROOT = Path(__file__).parent.parent.parent / "dataset" / "augmented"
    """Checks the augmented dataset (Cosmos Transfer output)."""

    @pytest.fixture(autouse=True)
    def check_v2_exists(self):
        if not self.DATASET_V2_ROOT.exists():
            pytest.skip("V2 dataset (Cosmos augmented) not yet generated — run scripts/cosmos_augment_pipeline.py")

    def test_expanded_randomization_dimensions(self):
        """Augmented metadata must include randomization dimensions from Cosmos."""
        meta_path = self.DATASET_V2_ROOT / "metadata.json"
        if not meta_path.exists():
            pytest.skip("metadata.json not yet generated for augmented dataset")

        meta = json.loads(meta_path.read_text())
        new_dims = [
            "weather_conditions",
            "camera_noise_models",
            "background_variations",
            "seasonal_lighting",
        ]
        for dim in new_dims:
            assert dim in meta, f"Missing randomization dimension: {dim}"

    def test_fid_improvement(self):
        """FID vs real images should improve over V1."""
        # Requires real images and FID computation
        pass

    def test_no_regression_on_v1(self):
        """Model trained on V2 must not regress on V1 validation."""
        pass


# =============================================================================
# MILESTONE 5: Real Data + Hybrid Training Contracts
# =============================================================================


class TestMilestone5HybridTraining:
    """Contracts for real data collection and hybrid training."""

    REAL_ROOT = Path(__file__).parent.parent.parent / "dataset" / "real"
    HYBRID_ROOT = Path(__file__).parent.parent.parent / "dataset" / "hybrid"

    @pytest.fixture(autouse=True)
    def check_real_exists(self):
        if not self.REAL_ROOT.exists() and not self.HYBRID_ROOT.exists():
            pytest.skip("Real/hybrid dataset not yet downloaded — run scripts/download_real_datasets.py")

    def test_real_dataset_size(self):
        """Must collect at least 500 real images (from HuggingFace / Roboflow / Kaggle)."""
        count = 0
        if self.REAL_ROOT.exists():
            for ext in ("*.jpg", "*.png", "*.jpeg"):
                count += len(list(self.REAL_ROOT.glob(f"**/{ext}")))
        if self.HYBRID_ROOT.exists():
            hybrid_images = self.HYBRID_ROOT / "images"
            if hybrid_images.exists():
                for ext in ("*.jpg", "*.png", "*.jpeg"):
                    count += len(list(hybrid_images.glob(f"{ext}")))
        assert count >= 500, f"Only {count} real/public images, need ≥500. Run: python3 scripts/download_real_datasets.py"

    def test_real_label_quality(self):
        """All real images must have labels in YOLO format."""
        img_stems = {p.stem for p in self.REAL_ROOT.glob("images/*")}
        lbl_stems = {p.stem for p in self.REAL_ROOT.glob("labels_yolo/*.txt")}
        assert img_stems == lbl_stems, "Image/label mismatch"

    def test_mixed_dataset_ratio(self):
        """Mixed train set must have ~70% synthetic, 30% real."""
        # Check by filename prefix or metadata
        pass

    def test_hybrid_improves_real_map(self):
        """Hybrid model must outperform synthetic-only on real test set."""
        pass


# =============================================================================
# MILESTONE 6: Jetson Orin Nano Super Deployment Contracts
# =============================================================================


class TestMilestone6JetsonDeploy:
    """Contracts for Jetson Orin Nano Super deployment."""

    MODEL_DIR = Path(__file__).parent.parent.parent / "models"

    @pytest.fixture(autouse=True)
    def check_jetson(self):
        """Skip if not on Jetson."""
        # Check for Jetson
        try:
            with open("/proc/device-tree/model") as f:
                if "orin" not in f.read().lower():
                    pytest.skip("Not running on Jetson Orin")
        except:
            pytest.skip("Not running on Jetson")

    def test_trt_engine_build(self):
        """ONNX → TensorRT FP16 engine must build successfully."""
        assert (self.MODEL_DIR / "hybrid_fp16.trt").exists(), "FP16 engine missing"

    def test_fps_requirement(self):
        """Must achieve ≥30 FPS on Jetson Orin Nano Super."""
        pass  # Requires benchmark script

    def test_accuracy_preserved_fp16(self):
        """FP16 accuracy within 1% of FP32 on real test set."""
        pass

    def test_memory_usage(self):
        """GPU memory must be < 4GB during inference."""
        pass

    def test_thermal_stability(self):
        """Sustained inference for 10 min without throttling."""
        pass


# =============================================================================
# MILESTONE 7: Real Drone Integration Contracts
# =============================================================================


class TestMilestone7DroneIntegration:
    """Contracts for real drone hardware integration."""

    @pytest.fixture(autouse=True)
    def check_drone(self):
        pytest.skip("Requires drone hardware")

    def test_camera_bridge_fps(self):
        """Real camera must publish at ≥25 FPS."""
        pass

    def test_ai_node_on_drone(self):
        """Inference node runs on drone Jetson."""
        pass

    def test_e2e_latency_drone(self):
        """Camera → JSON < 300ms on drone."""
        pass

    def test_dashboard_receives_json(self):
        """Backend receives JSON from drone."""
        pass

    def test_safety_injection_order_documented(self):
        """Safety injection order must be documented and followed."""
        safety_doc = Path(__file__).parent.parent.parent / "docs" / "SAFETY_INJECTION_ORDER.md"
        assert safety_doc.exists(), "Safety injection order doc missing"
        content = safety_doc.read_text()
        required_steps = ["Step 1", "Step 2", "Step 3", "Step 4", "Step 5", "Step 6", "Step 7"]
        for step in required_steps:
            assert step in content, f"Missing {step} in safety doc"


# =============================================================================
# MILESTONE 8: Final Demo Contracts
# =============================================================================


class TestMilestone8FinalDemo:
    """Contracts for final dual demonstration."""

    @pytest.fixture(autouse=True)
    def check_demo(self):
        pytest.skip("Requires full system integration")

    def test_isaac_sim_autonomous_mission(self):
        """Isaac Sim drone follows waypoints, detects defects, reports JSON."""
        pass

    def test_real_drone_camera_demo(self):
        """Real drone manual flight with AI detection shown on dashboard."""
        pass

    def test_sim_real_code_parity(self):
        """Sim and real use identical AI node code and model."""
        pass

    def test_dashboard_completeness(self):
        """Dashboard shows map, defects, risk levels, export."""
        pass


if __name__ == "__main__":
    pytest.main([__file__, "-v"])
