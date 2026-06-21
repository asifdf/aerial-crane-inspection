# TDD Milestone Plan — AI with Isaac Sim (Sim-to-Real Drone Inspection)

> **Focus**: AI defect detection pipeline using Isaac Sim synthetic data → real deployment on Jetson Orin Nano
> **Scope**: Crane inspection drone — crack/corrosion detection, ROS2 integration, dashboard reporting
> **Philosophy**: Test-Driven Development — every milestone has executable tests that must pass before proceeding

---

## 1. TDD Principles Applied to Sim-to-Real AI Pipeline

| Traditional TDD | Sim-to-Real AI TDD |
|-----------------|---------------------|
| Red: Write failing unit test | **Red**: Write failing *integration test* (dataset → model → ROS2 → JSON) |
| Green: Make test pass | **Green**: Train model / build pipeline until test metrics met |
| Refactor: Clean code | **Refactor**: Domain randomization, quantization, latency optimization |

**Test Pyramid for This Project**:
```
         █ E2E: Real drone flight + AI inference + dashboard (Week 7-8)
       ███ Integration: Isaac Sim → ROS2 → AI node → JSON result (Week 3-4)
     █████ Unit: Data generation, model training, ONNX export, TensorRT (Week 1-2)
```

---

## 2. Milestone 0 — Foundation & Test Harness (Week 0-1)

### Goal
Establish reproducible environment, CI pipeline, and *test contracts* that all later milestones must satisfy.

### Test Contracts (Define First — These Never Change)

```python
# tests/contracts/test_data_contract.py
def test_synthetic_dataset_schema():
    """Every synthetic dataset must have these fields."""
    required = ["images/", "labels_yolo/", "masks/", "metadata.json"]
    for r in required:
        assert (DATASET_ROOT / "synthetic" / r).exists()

def test_yolo_label_format():
    """YOLO labels: class_id x_center y_center width height (normalized 0-1)"""
    for lbl in PATH.glob("labels_yolo/*.txt"):
        for line in lbl.read_text().splitlines():
            parts = line.split()
            assert len(parts) == 5
            assert all(0 <= float(p) <= 1 for p in parts[1:])

def test_metadata_completeness():
    """metadata.json must contain domain randomization params for reproducibility."""
    meta = json.loads(PATH.read_text())
    required_keys = ["crack_variations", "lighting_conditions", "camera_poses", "isaac_sim_version"]
    for k in required_keys:
        assert k in meta
```

### Deliverables

| Artifact | Location | Verification |
|----------|----------|--------------|
| `pyproject.toml` + `uv.lock` | `/` | `uv sync` succeeds |
| `docker-compose.yml` (Isaac Sim + ROS2 Humble) | `/` | `docker compose up -d` healthy |
| GitHub Actions CI: lint, type-check, contract tests | `.github/workflows/ci.yml` | `act` passes locally |
| Pre-commit hooks: ruff, mypy, black | `.pre-commit-config.yaml` | `pre-commit run -a` passes |

### TDD Task List

- [ ] `test_environment.py`: Isaac Sim Python API importable, ROS2 bridge loads
- [ ] `test_replicator_basic.py`: Can generate 10 images with bounding boxes
- [ ] `test_ros2_bridge.py`: `/camera/image_raw` publishes on ROS2 topic
- [ ] `test_dataset_writer.py`: Replicator writer outputs YOLO + COCO + masks

**Exit Criteria**: All contract tests pass in CI. No milestone proceeds without this.

---

## 3. Milestone 1 — Synthetic Data Generation (Week 1-2)

### Goal
Generate **5,000–10,000** domain-randomized synthetic images with ground truth for crack/corrosion detection.

### Test Contracts

```python
# tests/contracts/test_milestone1.py
def test_dataset_size():
    assert count_images(DATASET_ROOT / "synthetic/images") >= 5000

def test_domain_randomization_coverage():
    meta = json.loads((DATASET_ROOT / "synthetic/metadata.json").read_text())
    # Must have at least these variation counts
    assert meta["lighting_conditions"] >= 20
    assert meta["camera_distances"] >= 10
    assert meta["crack_shapes"] >= 10
    assert meta["corrosion_patterns"] >= 10
    assert meta["material_textures"] >= 5

def test_label_quality():
    """No empty labels, all boxes valid, class distribution reasonable."""
    labels = list((DATASET_ROOT / "synthetic/labels_yolo").glob("*.txt"))
    assert len(labels) == count_images(DATASET_ROOT / "synthetic/images")
    class_counts = Counter()
    for lbl in labels:
        for line in lbl.read_text().splitlines():
            class_counts[int(line.split()[0])] += 1
    # crack and corrosion both present
    assert class_counts[0] > 100  # crack
    assert class_counts[1] > 100  # corrosion

def test_image_label_pairing():
    """Every image has a label file with same stem."""
    imgs = {p.stem for p in (DATASET_ROOT / "synthetic/images").glob("*.png")}
    lbls = {p.stem for p in (DATASET_ROOT / "synthetic/labels_yolo").glob("*.txt")}
    assert imgs == lbls
```

### TDD Tasks (Red → Green → Refactor)

| Phase | Task | Test Command |
|-------|------|--------------|
| **Red** | Write `tests/milestone1/test_generation.py` with all contracts above | `pytest tests/milestone1 -v` (all fail) |
| **Green** | Implement `scripts/generate_synthetic.py` using Replicator | `pytest tests/milestone1::test_dataset_size -v` |
| **Green** | Add domain randomization: lighting, camera, cracks, materials | `pytest tests/milestone1::test_domain_randomization_coverage -v` |
| **Green** | Implement YOLO + segmentation mask writers | `pytest tests/milestone1::test_label_quality -v` |
| **Refactor** | Optimize generation speed (target: 100 img/min) | `pytest tests/milestone1 -v && bench_generate --count 100` |
| **Refactor** | Add metadata.json with full randomization params | `pytest tests/milestone1::test_metadata_completeness -v` |

### Key Implementation Details

```python
# scripts/generate_synthetic.py (core structure)
from isaacsim.replicator import Replicator
from isaacsim.replicator.scripts.writers import YoloWriter, SegmentationMaskWriter

def build_scene():
    # Crane environment + drone camera rig
    crane = create_crane_asset()
    camera = create_camera_rig(fov=90, resolution=(1280, 720))
    return scene

def randomize_domain():
    with Replicator.randomize():
        # Lighting
        Replicator.modify.light.intensity(range=(100, 5000))
        Replicator.modify.light.color_temperature(range=(2000, 8000))
        Replicator.modify.light.position(sphere_radius=10)
        # Camera
        Replicator.modify.camera.pose(position=sampler.uniform_sphere(2, 8))
        # Defects
        Replicator.modify.crack.length(range=(0.01, 0.5))
        Replicator.modify.crack.orientation(range=(0, 360))
        Replicator.modify.corrosion.density(range=(0.1, 0.8))
        Replicator.modify.corrosion.color(palette="rust")
        # Materials
        Replicator.modify.material.texture(choices=METAL_TEXTURES)
        Replicator.modify.material.roughness(range=(0.2, 0.9))
```

### Deliverables

| Artifact | Path | Verification |
|----------|------|--------------|
| Synthetic dataset | `dataset/synthetic/` | Contract tests pass |
| Generation script | `scripts/generate_synthetic.py` | `python scripts/generate_synthetic.py --count 5000` |
| Domain randomization config | `configs/domain_randomization.yaml` | Version controlled |
| Metadata | `dataset/synthetic/metadata.json` | Complete, parseable |

---

## 4. Milestone 2 — Baseline Model Training (Week 2-3)

### Goal
Train **YOLOv8n/YOLOv11n** on synthetic data only. Achieve mAP@0.5 ≥ 0.7 on synthetic validation set.

### Test Contracts

```python
# tests/contracts/test_milestone2.py
def test_model_training_completes():
    result = subprocess.run(["python", "scripts/train_yolo.py", "--data", "dataset/synthetic/data.yaml"],
                          capture_output=True, timeout=3600)
    assert result.returncode == 0

def test_map_threshold():
    metrics = json.loads(Path("runs/detect/train/results.json").read_text())
    assert metrics["metrics/mAP50(B)"] >= 0.70
    assert metrics["metrics/mAP50-95(B)"] >= 0.40

def test_class_balance():
    metrics = json.loads(Path("runs/detect/train/results.json").read_text())
    # Both classes should have reasonable AP
    assert metrics["metrics/AP50(crack)"] >= 0.65
    assert metrics["metrics/AP50(corrosion)"] >= 0.65

def test_model_export_onnx():
    assert Path("runs/detect/train/weights/best.onnx").exists()
    # Verify ONNX model loads and runs inference
    import onnxruntime as ort
    session = ort.InferenceSession("runs/detect/train/weights/best.onnx")
    dummy = np.random.randn(1, 3, 640, 640).astype(np.float32)
    outputs = session.run(None, {"images": dummy})
    assert outputs[0].shape[1] == 84  # YOLOv8: 4 bbox + 80 classes (we have 2)

def test_inference_speed_cpu():
    """Baseline CPU inference < 100ms/image (for CI gate)."""
    import time
    session = ort.InferenceSession("runs/detect/train/weights/best.onnx")
    dummy = np.random.randn(1, 3, 640, 640).astype(np.float32)
    times = []
    for _ in range(10):
        t0 = time.perf_counter()
        session.run(None, {"images": dummy})
        times.append(time.perf_counter() - t0)
    assert np.median(times) < 0.1  # 100ms
```

### TDD Tasks

| Phase | Task | Test Command |
|-------|------|--------------|
| **Red** | Write `tests/milestone2/test_training.py` with contracts | `pytest tests/milestone2 -v` |
| **Green** | `scripts/train_yolo.py` — Ultralytics YOLO training loop | `pytest tests/milestone2::test_model_training_completes -v` |
| **Green** | Hyperparameter sweep (lr, batch, epochs, augment) | `pytest tests/milestone2::test_map_threshold -v` |
| **Green** | Class-weighted loss if imbalance detected | `pytest tests/milestone2::test_class_balance -v` |
| **Green** | ONNX export + validation | `pytest tests/milestone2::test_model_export_onnx -v` |
| **Refactor** | Mixed precision, gradient accumulation for larger batch | `pytest tests/milestone2 -v` |
| **Refactor** | WandB/MLflow logging for experiment tracking | Visual check in dashboard |

### Data Config (YOLO format)

```yaml
# dataset/synthetic/data.yaml
path: /workspace/dataset/synthetic
train: images/train
val: images/val
test: images/test

names:
  0: crack
  1: corrosion
```

### Deliverables

| Artifact | Path | Verification |
|----------|------|--------------|
| Trained weights (PyTorch) | `runs/detect/train/weights/best.pt` | mAP50 ≥ 0.70 |
| ONNX model | `runs/detect/train/weights/best.onnx` | Loads in ONNX Runtime |
| Training config | `configs/train_yolo.yaml` | Reproducible |
| Training logs | `runs/detect/train/results.csv` | Complete metrics |

---

## 5. Milestone 3 — ROS2 Integration & Inference Node (Week 3-4)

### Goal
Deploy trained model as a **ROS2 node** that subscribes to `/camera/image_raw`, runs inference, publishes `/ai/defect_detections` (custom msg) and `/ai/defect_json` (std_msgs/String JSON).

### Test Contracts

```python
# tests/contracts/test_milestone3.py
import rclpy
from sensor_msgs.msg import Image
from pegasus_msgs.msg import DefectDetection, DefectArray

def test_ros2_node_starts():
    """Node launches without errors, registers publishers/subscribers."""
    proc = subprocess.Popen(["ros2", "run", "pegasus_ai", "inference_node"])
    time.sleep(3)
    topics = subprocess.run(["ros2", "topic", "list"], capture_output=True, text=True)
    assert "/ai/defect_detections" in topics.stdout
    assert "/ai/defect_json" in topics.stdout
    proc.terminate()

def test_inference_pipeline():
    """End-to-end: publish image → receive detection JSON."""
    rclpy.init()
    node = rclpy.create_node("test_client")
    pub = node.create_publisher(Image, "/camera/image_raw", 10)
    received = []
    sub = node.create_subscription(String, "/ai/defect_json",
                                   lambda msg: received.append(msg.data), 10)

    # Publish test image
    test_img = np.random.randint(0, 255, (720, 1280, 3), dtype=np.uint8)
    img_msg = cv2_to_imgmsg(test_img, encoding="bgr8")
    for _ in range(5):
        pub.publish(img_msg)
        rclpy.spin_once(node, timeout_sec=0.5)

    assert len(received) >= 1
    result = json.loads(received[0])
    assert "defects" in result
    assert "timestamp" in result
    assert "zone_id" in result
    for det in result["defects"]:
        assert det["type"] in ["crack", "corrosion"]
        assert 0 <= det["confidence"] <= 1
        assert len(det["bbox"]) == 4

def test_inference_latency():
    """ROS2 node latency < 200ms (image in → JSON out)."""
    # Measured via message timestamps
    latencies = measure_ros2_latency("/camera/image_raw", "/ai/defect_json", n=50)
    assert np.percentile(latencies, 95) < 0.2  # 200ms p95

def test_tensorrt_inference():
    """Verify TensorRT engine is used (not PyTorch)."""
    # Check logs for "TensorRT engine loaded" or profile GPU memory
    logs = get_node_logs("inference_node")
    assert "TensorRT" in logs or "TRT" in logs
```

### TDD Tasks

| Phase | Task | Test Command |
|-------|------|--------------|
| **Red** | Write `tests/milestone3/test_ros2_integration.py` | `pytest tests/milestone3 -v` |
| **Green** | `ros2_ws/src/pegasus_ai/pegasus_ai/inference_node.py` — basic structure | `pytest tests/milestone3::test_ros2_node_starts -v` |
| **Green** | ONNX Runtime inference + ROS2 msg conversion | `pytest tests/milestone3::test_inference_pipeline -v` |
| **Green** | Custom msg types: `DefectDetection`, `DefectArray` | `colcon build && pytest tests/milestone3::test_inference_pipeline -v` |
| **Green** | TensorRT conversion + integration | `pytest tests/milestone3::test_tensorrt_inference -v` |
| **Refactor** | Latency optimization (batch=1, FP16, CUDA graphs) | `pytest tests/milestone3::test_inference_latency -v` |
| **Refactor** | Health monitoring: publish `/ai/node_health` (fps, gpu_mem, errors) | Visual check |

### ROS2 Node Architecture

```python
# ros2_ws/src/pegasus_ai/pegasus_ai/inference_node.py
class DefectInferenceNode(Node):
    def __init__(self):
        super().__init__("defect_inference")

        # TensorRT engine
        self.engine = TRTEngine("models/best_fp16.trt")
        self.preprocess = YOLOPreprocessor(input_size=(640, 640))
        self.postprocess = YOLOPostprocessor(conf_thresh=0.25, iou_thresh=0.45)

        # ROS2 interfaces
        self.sub = self.create_subscription(Image, "/camera/image_raw",
                                            self.image_callback, 10)
        self.pub_detections = self.create_publisher(DefectArray, "/ai/defect_detections", 10)
        self.pub_json = self.create_publisher(String, "/ai/defect_json", 10)
        self.pub_health = self.create_publisher(NodeHealth, "/ai/node_health", 1)

        # Metrics
        self.latencies = deque(maxlen=100)

    def image_callback(self, msg: Image):
        t0 = time.perf_counter()

        # Preprocess
        img = imgmsg_to_cv2(msg, "bgr8")
        tensor = self.preprocess(img)

        # Inference
        outputs = self.engine.infer(tensor)

        # Postprocess
        detections = self.postprocess(outputs, img.shape[:2])

        # Publish
        self.publish_detections(detections, msg.header)
        self.publish_json(detections, msg.header)

        # Health
        latency = time.perf_counter() - t0
        self.latencies.append(latency)
        self.publish_health(latency)
```

### Deliverables

| Artifact | Path | Verification |
|----------|------|--------------|
| ROS2 package | `ros2_ws/src/pegasus_ai/` | `colcon build --packages-select pegasus_ai` |
| Custom messages | `ros2_ws/src/pegasus_msgs/msg/` | `ros2 interface show pegasus_msgs/msg/DefectArray` |
| Inference node | `ros2_ws/src/pegasus_ai/pegasus_ai/inference_node.py` | All contract tests pass |
| TensorRT engine | `models/best_fp16.trt` | `trtexec --loadEngine=models/best_fp16.trt` |
| Launch file | `ros2_ws/src/pegasus_ai/launch/inference.launch.py` | `ros2 launch pegasus_ai inference.launch.py` |

---

## 6. Milestone 4 — Domain Randomization Hardening (Week 4)

### Goal
Increase synthetic dataset diversity to close sim-to-real gap. Target: **10,000–20,000 images** with expanded randomization.

### Test Contracts

```python
# tests/contracts/test_milestone4.py
def test_expanded_randomization_space():
    meta = json.loads((DATASET_ROOT / "synthetic_v2/metadata.json").read_text())
    # New randomization dimensions
    assert "weather_conditions" in meta  # rain, fog, dust
    assert "camera_noise_models" in meta  # motion blur, sensor noise, compression
    assert "background_variations" in meta  # sky, clouds, structures
    assert "seasonal_lighting" in meta  # sun angle by season

def test_similarity_metric():
    """Measure sim-to-real feature distribution distance (FID / KID)."""
    fid = compute_fid(real_features, synthetic_features)
    assert fid < 50  # Lower than baseline (target improvement)

def test_model_robustness():
    """Model trained on v2 dataset maintains mAP on v1 val set."""
    metrics = evaluate_model("models/v2_best.pt", "dataset/synthetic_v1/val")
    assert metrics["mAP50"] >= 0.68  # No regression

def test_stress_conditions():
    """Generate & test extreme conditions."""
    extremes = generate_extreme_conditions(n=500)
    results = evaluate_on_set("models/v2_best.pt", extremes)
    # Should not catastrophically fail
    assert results["detection_rate"] > 0.5
```

### TDD Tasks

| Phase | Task | Test Command |
|-------|------|--------------|
| **Red** | Write expanded contracts | `pytest tests/milestone4 -v` |
| **Green** | Add weather, sensor noise, background randomization | `pytest tests/milestone4::test_expanded_randomization_space -v` |
| **Green** | Generate v2 dataset (10k-20k images) | `python scripts/generate_synthetic.py --config v2 --count 15000` |
| **Green** | Retrain YOLO on v2 dataset | `pytest tests/milestone4::test_model_robustness -v` |
| **Green** | Compute FID/KID vs real images (if available) | `pytest tests/milestone4::test_similarity_metric -v` |
| **Refactor** | Active learning: identify weak zones, oversample | Visual analysis + targeted generation |

### New Randomization Dimensions

```yaml
# configs/domain_randomization_v2.yaml
weather:
  - clear
  - overcast
  - light_rain
  - fog
  - dust_haze

sensor_effects:
  motion_blur: {kernel: [3, 15], angle: [0, 360]}
  gaussian_noise: {std: [0, 25]}
  jpeg_compression: {quality: [50, 95]}
  rolling_shutter: {factor: [0, 0.3]}

background:
  sky_types: [clear_blue, cloudy, overcast, sunset]
  distant_structures: [none, buildings, towers, vegetation]

seasonal:
  sun_elevation: [15, 75]
  sun_azimuth: [0, 360]
```

---

## 7. Milestone 5 — Real Data Collection & Hybrid Training (Week 5)

### Goal
Collect **500–1,000 real images**, label them, train **hybrid model** (70% synthetic + 30% real).

### Test Contracts

```python
# tests/contracts/test_milestone5.py
def test_real_dataset_size():
    assert count_images(DATASET_ROOT / "real/images") >= 500

def test_real_label_quality():
    """All real images labeled, consistent format."""
    imgs = {p.stem for p in (DATASET_ROOT / "real/images").glob("*.jpg")}
    lbls = {p.stem for p in (DATASET_ROOT / "real/labels_yolo").glob("*.txt")}
    assert imgs == lbls
    # Spot-check: no degenerate boxes
    for lbl in (DATASET_ROOT / "real/labels_yolo").glob("*.txt"):
        for line in lbl.read_text().splitlines():
            _, x, y, w, h = map(float, line.split())
            assert w > 0.01 and h > 0.01  # Not tiny

def test_hybrid_training_improves_real_map():
    """Hybrid model must outperform synthetic-only on real test set."""
    synthetic_only_map = evaluate("models/synthetic_only.pt", "dataset/real/test")
    hybrid_map = evaluate("models/hybrid.pt", "dataset/real/test")
    assert hybrid_map["mAP50"] > synthetic_only_map["mAP50"] + 0.05

def test_mixed_dataset_split():
    """Mixed train set has correct ratio."""
    mixed = DATASET_ROOT / "mixed_train"
    synthetic_count = len(list((mixed / "images").glob("*_syn_*")))
    real_count = len(list((mixed / "images").glob("*_real_*")))
    ratio = real_count / (synthetic_count + real_count)
    assert 0.25 <= ratio <= 0.35  # 30% ± 5%
```

### TDD Tasks

| Phase | Task | Test Command |
|-------|------|--------------|
| **Red** | Write contracts | `pytest tests/milestone5 -v` |
| **Green** | Real data collection script (phone, USB cam, drone static) | `python scripts/collect_real.py --out dataset/real --target 500` |
| **Green** | Labeling workflow (CVAT / LabelImg / YOLO format) | Manual + `pytest tests/milestone5::test_real_label_quality -v` |
| **Green** | Create mixed dataset with 70/30 split | `python scripts/create_mixed_dataset.py --ratio 0.7` |
| **Green** | Train hybrid model | `pytest tests/milestone5::test_hybrid_training_improves_real_map -v` |
| **Refactor** | Hard negative mining from synthetic false positives | `python scripts/hard_mining.py --model models/hybrid.pt` |

### Data Collection Checklist

- [ ] **Static collection**: Drone on tripod, camera facing textured surfaces (concrete, metal, painted)
- [ ] **Weather variation**: Sunny, cloudy, morning/evening light
- [ ] **Distance variation**: 1m, 2m, 3m, 5m from surface
- [ ] **Angle variation**: Perpendicular, 30°, 45°, 60°
- [ ] **Defect proxies**: Rusty metal, cracked concrete, peeling paint, scratches
- [ ] **Labeling**: Minimum 2 annotators, IoU agreement > 0.8

---

## 8. Milestone 6 — Jetson Deployment & TensorRT Optimization (Week 6)

### Goal
Deploy hybrid model on **Jetson Orin Nano** with **TensorRT FP16/INT8**, achieve **≥30 FPS** at 640×640.

### Test Contracts

```python
# tests/contracts/test_milestone6.py
def test_jetson_tensorrt_build():
    """ONNX → TensorRT engine builds successfully on Jetson."""
    result = subprocess.run([
        "trtexec", "--onnx=models/hybrid.onnx",
        "--saveEngine=models/hybrid_fp16.trt",
        "--fp16", "--workspace=2048"
    ], capture_output=True, timeout=300)
    assert result.returncode == 0
    assert Path("models/hybrid_fp16.trt").exists()

def test_jetson_fps():
    """Benchmark: ≥30 FPS on Jetson Orin Nano."""
    fps = benchmark_trt_engine("models/hybrid_fp16.trt",
                               input_shape=(1, 3, 640, 640),
                               warmup=50, iterations=500)
    assert fps >= 30

def test_jetson_accuracy_preserved():
    """TensorRT FP16 accuracy within 1% of PyTorch FP32 on real test set."""
    pt_map = evaluate_pytorch("models/hybrid.pt", "dataset/real/test")
    trt_map = evaluate_tensorrt("models/hybrid_fp16.trt", "dataset/real/test")
    assert trt_map["mAP50"] >= pt_map["mAP50"] - 0.01

def test_jetson_memory():
    """GPU memory < 4GB during inference (Orin Nano has 8GB shared)."""
    mem = measure_gpu_memory("models/hybrid_fp16.trt", iterations=100)
    assert mem["peak_mb"] < 4000

def test_jetson_thermal():
    """Sustained inference for 10 min without throttling."""
    stats = sustained_benchmark("models/hybrid_fp16.trt", duration_sec=600)
    assert stats["throttled"] == False
    assert stats["fps_stability"] > 0.95  # FPS doesn't drop >5%
```

### TDD Tasks

| Phase | Task | Test Command |
|-------|------|--------------|
| **Red** | Write Jetson contracts (run on Jetson via SSH) | `pytest tests/milestone6 -v --host jetson` |
| **Green** | ONNX → TensorRT FP16 conversion script | `pytest tests/milestone6::test_jetson_tensorrt_build -v` |
| **Green** | FP16 accuracy validation | `pytest tests/milestone6::test_jetson_accuracy_preserved -v` |
| **Green** | FPS benchmark + optimization (DLA, CUDA graphs) | `pytest tests/milestone6::test_jetson_fps -v` |
| **Green** | Memory profiling + optimization | `pytest tests/milestone6::test_jetson_memory -v` |
| **Green** | Thermal stress test | `pytest tests/milestone6::test_jetson_thermal -v` |
| **Refactor** | INT8 calibration (if FP16 not fast enough) | `trtexec --int8 --calib=calib_data --onnx=...` |

### Jetson Optimization Checklist

```bash
# Jetson-specific optimizations
sudo nvpmodel -m 0        # MAXN mode
sudo jetson_clocks        # Max clocks

# TensorRT build flags
trtexec --onnx=model.onnx \
        --saveEngine=model_fp16.trt \
        --fp16 \
        --workspace=2048 \
        --minShapes=images:1x3x640x640 \
        --optShapes=images:1x3x640x640 \
        --maxShapes=images:4x3x640x640 \
        --buildOnly
```

### Deliverables

| Artifact | Path | Verification |
|----------|------|--------------|
| TensorRT FP16 engine | `models/hybrid_fp16.trt` | `pytest tests/milestone6 -v` on Jetson |
| Benchmark report | `reports/jetson_benchmark.json` | FPS ≥ 30, mem < 4GB |
| INT8 engine (optional) | `models/hybrid_int8.trt` | Accuracy within 2% |
| Deployment script | `scripts/deploy_jetson.sh` | One-command setup |

---

## 9. Milestone 7 — Real Drone Integration (Week 7)

### Goal
Integrate AI node with **real drone hardware**: camera → Jetson → ROS2 → PX4/MAVROS → dashboard.

### Test Contracts

```python
# tests/contracts/test_milestone7.py
def test_camera_ros2_bridge():
    """Real camera publishes /camera/image_raw at 30 FPS."""
    hz = measure_topic_hz("/camera/image_raw", duration=10)
    assert hz >= 25

def test_ai_node_on_drone():
    """Inference node runs on drone Jetson, publishes detections."""
    # SSH to drone, start node, verify topics
    topics = ssh_run("drone", "ros2 topic list")
    assert "/ai/defect_detections" in topics
    assert "/ai/defect_json" in topics

def test_end_to_end_latency_drone():
    """Camera capture → JSON publish < 300ms on drone."""
    latencies = measure_e2e_latency_drone("/camera/image_raw", "/ai/defect_json", n=50)
    assert np.percentile(latencies, 95) < 0.3

def test_dashboard_receives_json():
    """Backend receives and parses JSON from drone."""
    # Simulate or use actual backend
    received = collect_dashboard_messages(duration=30)
    assert len(received) > 0
    for msg in received[:5]:
        data = json.loads(msg)
        assert data["drone_id"] == "drone_01"
        assert "defects" in data
        assert "position" in data

def test_safety_injection_order():
    """Verify safety steps documented and followed."""
    # This is a documentation test
    safety_doc = Path("docs/SAFETY_INJECTION_ORDER.md").read_text()
    assert "Step 1: Desk inference" in safety_doc
    assert "Step 2: Props removed" in safety_doc
    assert "Step 3: Manual flight + record" in safety_doc
    assert "Step 4: Manual flight + AI" in safety_doc
    assert "Step 5: Position hold" in safety_doc
    assert "Step 6: Waypoint + AI" in safety_doc
```

### TDD Tasks

| Phase | Task | Test Command |
|-------|------|--------------|
| **Red** | Write integration contracts | `pytest tests/milestone7 -v` |
| **Green** | Camera driver + ROS2 bridge on drone | `pytest tests/milestone7::test_camera_ros2_bridge -v` |
| **Green** | Deploy inference node to drone (Docker/over-the-air) | `pytest tests/milestone7::test_ai_node_on_drone -v` |
| **Green** | MQTT/REST bridge to backend | `pytest tests/milestone7::test_dashboard_receives_json -v` |
| **Green** | Safety injection procedure doc + checklist | `pytest tests/milestone7::test_safety_injection_order -v` |
| **Refactor** | Bandwidth optimization (compress images, throttle rate) | Monitor network usage |

### Safety Injection Order (Enforced by Documentation Test)

```
Step 1: Jetson camera inference on desk (no drone)
Step 2: Drone powered, PROPELLERS REMOVED — test AI + ROS2
Step 3: Manual flight + record camera only (no AI)
Step 4: Manual flight + AI inference only (AI does not control)
Step 5: Position hold + waypoint test WITHOUT AI decision
Step 6: Waypoint inspection + AI detection (AI reports only)
Step 7: Dashboard integration
```

---

## 10. Milestone 8 — Final Demo & Hardening (Week 8)

### Goal
Complete **dual demonstration**: Isaac Sim autonomous inspection + Real drone camera inference → Dashboard.

### Test Contracts

```python
# tests/contracts/test_milestone8.py
def test_isaac_sim_full_mission():
    """Sim drone follows waypoints, detects defects, reports JSON."""
    # Run in Isaac Sim headless
    result = run_sim_mission("configs/mission_crane_inspection.yaml")
    assert result["waypoints_completed"] >= 0.9
    assert result["defects_detected"] > 0
    assert result["json_reports_generated"] == result["waypoints_completed"]

def test_real_drone_camera_demo():
    """Real drone: manual flight, AI detects, dashboard shows."""
    # Manual flight test
    log = collect_demo_log(duration=120)  # 2 min flight
    assert log["frames_processed"] > 100
    assert log["detections_published"] > 0
    assert log["dashboard_updates"] > 0

def test_dashboard_completeness():
    """Dashboard shows: map, defect list, risk levels, images."""
    # Check dashboard API / frontend
    resp = requests.get("http://dashboard/api/inspections/latest")
    data = resp.json()
    assert "drone_id" in data
    assert "defects" in data
    assert "zone_id" in data
    assert "position" in data
    for d in data["defects"]:
        assert d["risk"] in ["low", "medium", "high", "critical"]

def test_sim_real_consistency():
    """Sim and real use IDENTICAL AI node code + model."""
    sim_node_hash = hash_file("ros2_ws/src/pegasus_ai/pegasus_ai/inference_node.py")
    real_node_hash = ssh_hash("drone", "/opt/ros/humble/share/pegasus_ai/inference_node.py")
    assert sim_node_hash == real_node_hash

    sim_model_hash = hash_file("models/hybrid_fp16.trt")
    real_model_hash = ssh_hash("drone", "/opt/models/hybrid_fp16.trt")
    assert sim_model_hash == real_model_hash
```

### Deliverables Checklist

| Demo Component | Verification |
|----------------|--------------|
| Isaac Sim: autonomous waypoint inspection | Video + JSON logs |
| Real drone: manual flight + AI inference | Video + ROS2 bag + dashboard screenshots |
| Dashboard: defect map, risk heatmap, export report | Screenshots + API response |
| Code parity: sim ↔ real | Git commit hash match |
| Model parity: sim ↔ real | File hash match |
| Safety checklist completed | Signed document |

---

## 11. CI/CD Pipeline (Runs Every PR)

```yaml
# .github/workflows/ci.yml
name: TDD Pipeline

on: [push, pull_request]

jobs:
  contract-tests:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
      - name: Setup Python + UV
        uses: astral-sh/setup-uv@v3
      - name: Install deps
        run: uv sync --all-extras
      - name: Run contract tests (Milestones 0-4)
        run: pytest tests/contracts/ tests/milestone{1,2,3,4} -v
      - name: Type check
        run: uv run mypy src/
      - name: Lint
        run: uv run ruff check .

  jetson-tests:
    runs-on: [self-hosted, jetson, orin-nano]
    needs: contract-tests
    if: github.event_name == 'push' && github.ref == 'refs/heads/main'
    steps:
      - uses: actions/checkout@v4
      - name: Run Milestone 6 tests on Jetson
        run: pytest tests/milestone6 -v --host jetson
      - name: Run Milestone 7 tests on Drone
        run: pytest tests/milestone7 -v --host drone

  integration-test:
    runs-on: ubuntu-latest
    needs: contract-tests
    steps:
      - name: Isaac Sim headless test (Milestone 8)
        run: pytest tests/milestone8::test_isaac_sim_full_mission -v
```

---

## 12. Progress Tracking Dashboard

| Milestone | Status | Contract Tests | Key Metric | Target | Actual |
|-----------|--------|----------------|------------|--------|--------|
| 0: Foundation | ⬜ Planned | 4/4 | CI pass rate | 100% | — |
| 1: Synthetic Data | ⬜ Planned | 4/4 | Images generated | 5,000+ | — |
| 2: Baseline Training | ⬜ Planned | 5/5 | mAP@0.5 (syn) | ≥0.70 | — |
| 3: ROS2 Integration | ⬜ Planned | 4/4 | Latency p95 | <200ms | — |
| 4: Domain Hardening | ⬜ Planned | 4/4 | FID vs real | <50 | — |
| 5: Hybrid Training | ⬜ Planned | 4/4 | Real mAP gain | +5% | — |
| 6: Jetson Deploy | ⬜ Planned | 5/5 | FPS (Orin Nano) | ≥30 | — |
| 7: Drone Integration | ⬜ Planned | 5/5 | E2E latency | <300ms | — |
| 8: Final Demo | ⬜ Planned | 4/4 | Dual demo | ✓ | — |

---

## 13. Risk Mitigation (TDD-Style)

| Risk | Detection (Test) | Mitigation |
|------|------------------|------------|
| Sim-to-real gap too large | `test_similarity_metric` (FID) | Increase randomization, add real data earlier |
| Jetson FPS < 30 | `test_jetson_fps` | Model pruning, INT8, DLA, reduce input resolution |
| ROS2 latency > 300ms | `test_end_to_end_latency_drone` | Zero-copy, node composition, reduce message size |
| Real labeling bottleneck | `test_real_label_quality` | Active learning, semi-auto labeling (SAM), outsource |
| Drone safety incident | `test_safety_injection_order` | Hardware interlocks, props-off testing, checklist enforcement |
| Model drift over time | `test_model_robustness` (regression) | Continuous eval on held-out real set, retrain trigger |

---

## 14. File Structure Summary

```
/workspaces/pegasus_ws/
├── configs/
│   ├── domain_randomization.yaml
│   ├── domain_randomization_v2.yaml
│   ├── train_yolo.yaml
│   └── mission_crane_inspection.yaml
├── dataset/
│   ├── synthetic/          # Milestone 1
│   ├── synthetic_v2/       # Milestone 4
│   ├── real/               # Milestone 5
│   ├── mixed_train/        # Milestone 5
│   └── val/, test_real/
├── docs/
│   ├── TDD_MILESTONE_AI_ISAAC_SIM.md  # THIS FILE
│   ├── SAFETY_INJECTION_ORDER.md
│   └── ARCHITECTURE.md
├── models/
│   ├── best.pt             # PyTorch weights
│   ├── best.onnx           # ONNX export
│   ├── hybrid_fp16.trt     # TensorRT FP16 (Jetson)
│   └── hybrid_int8.trt     # TensorRT INT8 (optional)
├── ros2_ws/
│   └── src/
│       ├── pegasus_ai/     # Inference node
│       └── pegasus_msgs/   # Custom messages
├── scripts/
│   ├── generate_synthetic.py
│   ├── train_yolo.py
│   ├── collect_real.py
│   ├── create_mixed_dataset.py
│   ├── deploy_jetson.sh
│   └── hard_mining.py
├── tests/
│   ├── contracts/          # Immutable test contracts
│   │   ├── test_data_contract.py
│   │   ├── test_milestone1.py
│   │   ...
│   ├── milestone1/
│   ├── milestone2/
│   ...
├── .github/workflows/ci.yml
├── docker-compose.yml
├── pyproject.toml
└── uv.lock
```

---

## 15. Quick Reference Commands

```bash
# Milestone 0: Foundation
uv sync && pre-commit install && act -j contract-tests

# Milestone 1: Generate synthetic data
python scripts/generate_synthetic.py --count 5000 --config configs/domain_randomization.yaml
pytest tests/milestone1 -v

# Milestone 2: Train baseline
python scripts/train_yolo.py --data dataset/synthetic/data.yaml --epochs 100
pytest tests/milestone2 -v

# Milestone 3: ROS2 integration
cd ros2_ws && colcon build --packages-select pegasus_ai pegasus_msgs
source install/setup.bash
ros2 launch pegasus_ai inference.launch.py
pytest tests/milestone3 -v

# Milestone 4: Harden randomization
python scripts/generate_synthetic.py --count 15000 --config configs/domain_randomization_v2.yaml
pytest tests/milestone4 -v

# Milestone 5: Hybrid training
python scripts/collect_real.py --target 500
python scripts/create_mixed_dataset.py --ratio 0.7
python scripts/train_yolo.py --data dataset/mixed_train/data.yaml
pytest tests/milestone5 -v

# Milestone 6: Jetson deploy (run ON Jetson)
trtexec --onnx=models/hybrid.onnx --saveEngine=models/hybrid_fp16.trt --fp16
pytest tests/milestone6 -v

# Milestone 7: Drone integration (run ON drone)
ssh drone "docker run --gpus all -v /opt/models:/models pegasus-ai:latest"
pytest tests/milestone7 -v --host drone

# Milestone 8: Final demo
# Isaac Sim: python scripts/run_sim_mission.py
# Real drone: manual flight + record
# Dashboard: open http://dashboard
pytest tests/milestone8 -v
```

---

**Last Updated**: 2026-06-15
**Version**: 1.0
**Author**: TDD Pipeline for Pegasus AI Drone Inspection
