# NVIDIA Tools Integration for Sim-to-Real Drone Inspection

> Reference document for leveraging NVIDIA Cosmos, Isaac Sim Replicator, and related tools in the Pegasus AI pipeline.

---

## 1. NVIDIA Cosmos (World Foundation Models)

### Overview
NVIDIA Cosmos is a platform of **World Foundation Models (WFMs)** for physical AI — models that understand physics, geometry, and dynamics of the world. Key capabilities relevant to sim-to-real:

| Tool | Purpose | Relevance to Pegasus |
|------|---------|---------------------|
| **Cosmos Predict** | Video prediction from initial frames + action | Simulate future drone camera views for planning |
| **Cosmos Reason** | Physical reasoning over video | Verify defect detections make physical sense |
| **Cosmos Transfer** | Style/condition transfer between domains | Convert synthetic → realistic style without paired data |
| **Cosmos Tokenizer** | Compress video to tokens for efficient training | Reduce dataset storage/bandwidth for Jetson deployment |

### Integration Points

```python
# Example: Using Cosmos Transfer for synthetic-to-real style transfer
from cosmos import CosmosTransfer

# Train on synthetic, apply style transfer to look more real
cosmos_transfer = CosmosTransfer.from_pretrained("nvidia/cosmos-transfer-7b")
realistic_synthetic = cosmos_transfer(
    synthetic_images,
    condition="real_world_drone_footage",
    strength=0.7
)

# Use for training data augmentation
augmented_dataset = synthetic_dataset + realistic_synthetic
```

### When to Use
- **Phase 3-4 (Domain Hardening)**: Apply Cosmos Transfer to synthetic images to reduce sim-to-real gap before real data collection
- **Phase 7 (Drone Integration)**: Use Cosmos Predict to generate failure case simulations for safety testing

---

## 2. Isaac Sim Replicator (Synthetic Data Generation)

### Current Best Practice (Isaac Sim 4.x / 2024.x)

```python
# scripts/generate_synthetic_replicator.py
import omni.replicator.core as rep
from omni.replicator.core.scripts.writers import YoloWriter, SegmentationMaskWriter
import carb.settings

# Enable ROS2 bridge
carb.settings.get_settings().set_bool("/exts/omni.isaac.ros2_bridge/enabled", True)

def create_crane_scene():
    """Create crane inspection environment with drone camera rig."""
    # Load crane USD asset
    crane_prim = rep.create.from_usd("assets/crane_inspection.usd")

    # Create drone camera rig (stereo pair for VSLAM)
    left_cam = rep.create.camera(
        position=(0, -0.05, 0),
        rotation=(0, -90, 0),
        focal_length=24,
        focus_distance=10,
        f_stop=2.8,
    )
    right_cam = rep.create.camera(
        position=(0, 0.05, 0),
        rotation=(0, -90, 0),
        focal_length=24,
    )

    return crane_prim, left_cam, right_cam


def randomize_defects():
    """Domain randomization for crack/corrosion defects."""
    with rep.randomizer.defects():
        # Crack randomization
        rep.randomizer.crack(
            length=rep.distribution.uniform(0.02, 0.5),
            width=rep.distribution.uniform(0.001, 0.01),
            orientation=rep.distribution.uniform(0, 360),
            position=rep.distribution.uniform((-2, -1, 0.5), (2, 1, 3)),
            material="metal_crack",
        )

        # Corrosion randomization
        rep.randomizer.corrosion(
            density=rep.distribution.uniform(0.1, 0.8),
            color_palette="rust",
            patch_size=rep.distribution.uniform(0.1, 0.5),
        )

        # Paint damage
        rep.randomizer.paint_damage(
            scratch_length=rep.distribution.uniform(0.05, 0.3),
            scratch_width=rep.distribution.uniform(0.002, 0.01),
            chip_density=rep.distribution.uniform(0.01, 0.1),
        )


def randomize_environment():
    """Environment randomization for robustness."""
    with rep.randomizer.environment():
        # Lighting
        rep.randomizer.light(
            intensity=rep.distribution.uniform(100, 5000),
            color_temp=rep.distribution.uniform(2000, 8000),
            position=rep.distribution.sphere(10),
        )

        # Sky/background
        rep.randomizer.sky(
            type=rep.distribution.choice(["clear", "cloudy", "overcast", "sunset"]),
            sun_angle=rep.distribution.uniform(15, 75),
        )

        # Weather effects (Isaac Sim 4.2+)
        rep.randomizer.weather(
            rain=rep.distribution.choice([0, 0.3, 0.6]),
            fog=rep.distribution.uniform(0, 0.5),
            dust=rep.distribution.uniform(0, 0.2),
        )


def randomize_camera():
    """Camera sensor simulation."""
    with rep.randomizer.camera():
        rep.randomizer.camera_pose(
            position=rep.distribution.uniform((-3, -2, 1), (3, 2, 5)),
            look_at=rep.distribution.uniform((-1, -1, 0), (1, 1, 2)),
        )
        rep.randomizer.lens_effects(
            motion_blur=rep.distribution.uniform(0, 0.3),
            chromatic_aberration=rep.distribution.uniform(0, 0.02),
            vignette=rep.distribution.uniform(0, 0.3),
            distortion=rep.distribution.uniform(-0.1, 0.1),
        )
        rep.randomizer.sensor_noise(
            gaussian=rep.distribution.uniform(0, 0.02),
            shot_noise=rep.distribution.uniform(0, 0.01),
            quantization=rep.distribution.choice([8, 10, 12]),  # bit depth
        )


def build_replicator_graph():
    """Build the complete Replicator graph for dataset generation."""
    # Create scene
    crane, left_cam, right_cam = create_crane_scene()

    # Register randomizers
    rep.randomizer.register(randomize_defects)
    rep.randomizer.register(randomize_environment)
    rep.randomizer.register(randomize_camera)

    # Create writer for YOLO format
    writer = YoloWriter(
        output_dir="dataset/synthetic",
        annotation_type="2d_bounding_box",
        class_mapping={
            "crack": 0,
            "corrosion": 1,
            "paint_damage": 2,
        },
        write_masks=True,  # Also generate segmentation masks
        write_kitti=False,
        write_coco=True,
    )

    # Attach writer to cameras
    rep.orchestrator.step(writer, [left_cam, right_cam])

    return writer


def generate_dataset(num_frames=10000):
    """Generate synthetic dataset."""
    writer = build_replicator_graph()

    with rep.new_layer():
        # Trigger generation
        for i in range(num_frames):
            rep.orchestrator.step()
            if i % 100 == 0:
                print(f"Generated {i}/{num_frames} frames")

    writer.close()
    print("Dataset generation complete!")
    print(f"Output: dataset/synthetic/")


if __name__ == "__main__":
    generate_dataset(10000)
```

### Key Replicator Features for Pegasus

| Feature | Usage | Benefit |
|---------|-------|---------|
| **Semantic Segmentation** | `rep.AnnotatorRegistry.get_annotator("semantic_segmentation")` | Pixel-perfect masks for corrosion area calculation |
| **Instance Segmentation** | `instance_id_segmentation` | Separate individual crack instances |
| **3D Bounding Boxes** | `bounding_box_3d` | 3D defect position for zone mapping |
| **Depth/Point Cloud** | `distance_to_camera`, `point_cloud` | Validate VSLAM, collision checking |
| **Custom Randomizers** | Python functions with `rep.distribution` | Full control over variation space |
| **Offline Generation** | Headless mode, no GUI | CI/CD compatible, scalable |

---

## 3. Isaac ROS (NVIDIA-ROS) — Selective Use

### Philosophy: Use Minimal Isaac ROS
The user requested **ROS2 Humble native** without full Isaac ROS stack. However, these specific packages are valuable:

| Package | Use Case | Alternative |
|---------|----------|-------------|
| `isaac_ros_image_proc` | GPU-accelerated image rectify, resize, crop | CPU `image_proc` (slower) |
| `isaac_ros_tensorrt` | TensorRT inference integration | Custom TRT wrapper (what we built) |
| `isaac_ros_visual_slam` | Stereo VSLAM for drone localization | `rtabmap_ros`, `orb_slam3` |
| `isaac_ros_depth` | Disparity/depth from stereo | `stereo_image_proc` |

### Recommended: Lightweight Integration
```bash
# Install only what you need
sudo apt install ros-humble-isaac-ros-image-proc
sudo apt install ros-humble-isaac-ros-tensorrt
# Skip: isaac_ros_visual_slam (heavy, use rtabmap instead)
```

### VSLAM Alternative (Lighter)
```bash
# RTAB-Map for visual SLAM - well maintained, ROS2 native
sudo apt install ros-humble-rtabmap-ros

# Or ORB-SLAM3 (mono/stereo, loop closing)
# Build from source: https://github.com/UZ-SLAMLab/ORB_SLAM3
```

---

## 4. TAO Toolkit (Model Training Optimization)

### When to Use
- **Phase 2-5**: Automated hyperparameter tuning, quantization-aware training
- **Phase 6**: INT8 calibration for Jetson deployment

```bash
# TAO Toolkit via Docker (recommended)
docker run -it --gpus all -v $PWD:/workspace nvidia/tao/tao-toolkit:5.0.0

# Inside container: train YOLO with QAT
tao yolo_v4 train -e /workspace/specs/yolo_v4_qat.txt \
    -r /workspace/results -k $KEY
```

### Benefits for Pegasus
- **Quantization-Aware Training (QAT)**: Better INT8 accuracy than post-training quantization
- **AutoML**: Neural architecture search for optimal speed/accuracy
- **TensorRT Export**: Built-in ONNX → TRT with optimization profiles

---

## 5. Jetson Orin Nano Super Specific Optimizations

### Hardware Specs (Super vs Regular)
| Spec | Orin Nano 8GB | **Orin Nano Super 8GB** |
|------|---------------|-------------------------|
| GPU | 1024 CUDA + 32 Tensor | **1024 CUDA + 32 Tensor** |
| CPU | 6-core Arm Cortex-A78AE | **6-core Arm Cortex-A78AE** |
| **Memory** | 8GB LPDDR5 68 GB/s | **8GB LPDDR5 102 GB/s** |
| **Max Power** | 15W | **25W (Super mode)** |
| **AI TOPS (INT8)** | 40 | **67** |

### Optimization Strategy for Super
```bash
# Enable SUPER mode (25W)
sudo nvpmodel -m 0  # MAXN
sudo jetson_clocks

# Verify
cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq  # Should be max
tegrastats  # Watch GPU/CPU utilization
```

### TensorRT Build for Super
```bash
# FP16 (recommended for Super - 67 TOPS INT8, but FP16 is 33 TFLOPS)
trtexec --onnx=model.onnx \
        --saveEngine=model_fp16.trt \
        --fp16 \
        --workspace=4096 \
        --minShapes=images:1x3x640x640 \
        --optShapes=images:1x3x640x640 \
        --maxShapes=images:4x3x640x640 \
        --buildOnly

# INT8 (if need max FPS, use QAT from TAO)
trtexec --onnx=model.onnx \
        --saveEngine=model_int8.trt \
        --int8 \
        --calib=calibration.cache \
        --workspace=4096
```

---

## 6. Integration Roadmap

### Phase 1-2 (Weeks 1-3): Foundation
- [ ] Isaac Sim Replicator → synthetic dataset (YoloWriter + masks)
- [ ] Basic ROS2 bridge test (scripts/isaac_sim_ros2_bridge_test.py)
- [ ] YOLO training on synthetic (PyTorch → ONNX)

### Phase 3-4 (Weeks 3-5): Hardening
- [ ] Expanded Replicator randomization (weather, sensor noise, materials)
- [ ] Cosmos Transfer experiment for style transfer (optional, if gap large)
- [ ] TensorRT FP16 deployment on Jetson Super

### Phase 5 (Week 5): Real Data
- [ ] Collect 500+ real images (drone static + manual flight recording)
- [ ] Label with CVAT/LabelImg → YOLO format
- [ ] Hybrid training (70/30 synthetic/real)

### Phase 6 (Week 6): Jetson Optimization
- [ ] TensorRT FP16 → 30+ FPS benchmark
- [ ] INT8 calibration if needed (TAO QAT preferred)
- [ ] Thermal stress test 10 min

### Phase 7 (Week 7): Drone Integration
- [ ] Camera → Jetson → ROS2 → PX4/MAVROS
- [ ] Safety injection order enforcement
- [ ] Dashboard JSON integration

### Phase 8 (Week 8): Final Demo
- [ ] Isaac Sim autonomous mission
- [ ] Real drone manual flight + AI
- [ ] Code/model parity verification

---

## 7. Useful Commands Quick Reference

```bash
# Isaac Sim headless dataset generation
./isaac-sim-headless.sh -p scripts/generate_synthetic_replicator.py

# ROS2 bridge test in Isaac Sim
# 1. Enable ROS2 Bridge extension
# 2. Run script in Script Editor

# Jetson benchmark
trtexec --loadEngine=models/hybrid_fp16.trt \
        --warmUp=50 --iterations=500 \
        --avgRuns=10

# TAO training (in container)
tao detectnet_v2 train -e specs/detectnet_v2_qat.txt -r results -k $KEY

# Cosmos Transfer (when available via API)
python -c "
from cosmos import CosmosTransfer
model = CosmosTransfer.from_pretrained('nvidia/cosmos-transfer-7b')
output = model(synthetic_batch, condition='drone_inspection_real')
"

# RTAB-Map VSLAM launch
ros2 launch rtabmap_launch rtabmap.launch.py \
    stereo:=true \
    rtabmap_args:="--delete_db_on_start" \
    rgb_topic:=/camera/left/image_raw \
    depth_topic:=/camera/depth
```

---

## 8. Key References

- **Isaac Sim Replicator Docs**: https://docs.omniverse.nvidia.com/isaacsim/latest/replicator_tutorials/
- **Isaac ROS Repos**: https://github.com/NVIDIA-ISAAC-ROS
- **TAO Toolkit**: https://developer.nvidia.com/tao-toolkit
- **Jetson Orin Nano Super**: https://developer.nvidia.com/embedded/jetson-orin-nano-super
- **Cosmos Platform**: https://www.nvidia.com/en-us/ai-world-foundation-models/
- **RTAB-Map ROS2**: https://github.com/introlab/rtabmap_ros

---

*Last updated: 2026-06-15 | For Pegasus AI Drone Inspection Project*
