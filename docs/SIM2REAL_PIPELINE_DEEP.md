# Sim-to-Real Pipeline — Pegasus AI Crane Inspection Drone
## Deep Research & Implementation Plan

> Based on NVIDIA's official SDKs: Isaac Sim, Replicator, Cosmos 3 WFMs, Isaac Lab, OSMO

---

## 1. Overview: The Complete Sim-to-Real Stack

```
┌─────────────────────────────────────────────────────────────────────┐
│                    PEGASUS SIM-TO-REAL PIPELINE                      │
├─────────────────────────────────────────────────────────────────────┤
│                                                                     │
│  STAGE 1: Environment & Asset Creation                              │
│  ┌──────────────────────────────────────────────────────────────┐   │
│  │ • Crane USD model (Isaac Sim SimReady / custom)              │   │
│  │ • Defect materials: crack, corrosion, paint_damage           │   │
│  │ • Lighting / camera rig setup                                │   │
│  │ • Domain randomization config                                │   │
│  └──────────────────────────────────────────────────────────────┘   │
│         ↓                                                           │
│  STAGE 2: Synthetic Data Generation                                │
│  ┌──────────────────────────────────────────────────────────────┐   │
│  │ • Omniverse Replicator SDG pipeline                          │   │
│  │ → 10,000+ images with YOLO labels                             │   │
│  │ → RGB, depth, segmentation masks                              │   │
│  │ → Domain randomization: lighting, weather, camera, defects    │   │
│  └──────────────────────────────────────────────────────────────┘   │
│         ↓                                                           │
│  STAGE 3: Data Augmentation with Cosmos Transfer 2.5               │
│  ┌──────────────────────────────────────────────────────────────┐   │
│  │ • Cosmos Transfer 2.5: sim → photorealistic video             │   │
│  │ → Input: RGB + depth + seg masks from Replicator              │   │
│  │ → Output: photorealistic augmented video sequences             │   │
│  │ → Bridges the sim-to-real gap visually                        │   │
│  └──────────────────────────────────────────────────────────────┘   │
│         ↓                                                           │
│  STAGE 4: Model Training                                           │
│  ┌──────────────────────────────────────────────────────────────┐   │
│  │ • YOLOv8/11 training on synthetic + augmented data            │   │
│  │ → Synthetic-only baseline                                     │   │
│  │ → Synthetic + Cosmos-augmented                                │   │
│  │ → Hybrid (synthetic + real) for final model                   │   │
│  │ • Export to ONNX → TensorRT FP16                              │   │
│  └──────────────────────────────────────────────────────────────┘   │
│         ↓                                                           │
│  STAGE 5: Real-World Deployment                                    │
│  ┌──────────────────────────────────────────────────────────────┐   │
│  │ • ROS2 inference node (pegasus_ai)                           │   │
│  │ → Subscribes to drone camera                                 │   │
│  │ → Runs TensorRT YOLO inference                               │   │
│  │ → Publishes defect JSON to dashboard                         │   │
│  └──────────────────────────────────────────────────────────────┘   │
│         ↓                                                           │
│  STAGE 6: Domain Adaptation & Continuous Improvement               │
│  ┌──────────────────────────────────────────────────────────────┐   │
│  │ • Collect real-world edge cases                              │   │
│  │ • Cosmos Predict 2.5 for long-tail scenario generation        │   │
│  │ • Cosmos Reason 2 for failure analysis                       │   │
│  │ • Iterative retraining with expanded dataset                  │   │
│  └──────────────────────────────────────────────────────────────┘   │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘
```

---

## 2. NVIDIA Cosmos 3 — What It Is & How We Use It

Cosmos 3 is an **open world foundation model platform** with three model families:

### Cosmos Transfer 2.5 — Data Augmentation (OUR PRIMARY USE)

**What it does:** Transforms synthetic (simulated) video into photorealistic video while preserving structure. ControlNet-based architecture.

**Inputs we can feed it:**
- RGB frames from Isaac Sim Replicator
- Depth maps
- Segmentation masks (semantic labels)
- Edge maps
- 3D bounding boxes
- Text prompts ("crack on metal beam under overcast lighting")

**Outputs:**
- Photorealistic video sequences matching input structure
- Varied lighting, weather, textures — without re-running simulation

**Why it matters for us:**
- One simulation pass → 100s of photorealistic variants
- Covers conditions Isaac Sim can't easily render (real rust textures, real crack patterns)
- Policy trained on synthetic + Cosmos-augmented data outperforms synthetic-only by significant margins (NVIDIA's closed-loop eval)

### Cosmos Predict 2.5 — Long-Tail Scenario Generation

**What it does:** Generates up to 30-second predicted video sequences from text, start/end frames, or partial video.

**For us:** Generate rare defect scenarios (e.g., catastrophic crack propagation) that are too rare in real data.

### Cosmos Reason 2 — Physical AI Reasoning

**What it does:** Vision-language model with 2D/3D spatial understanding, 256K context, temporal reasoning.

**For us:** Analyze failure cases, generate explanations for missed detections, suggest data augmentation strategies.

---

## 3. Implementation Roadmap

### Phase 1: Synthetic Data Generation with Replicator (Week 1-2)

**Goal:** Generate 10,000+ synthetic crane defect images with YOLO labels.

**Steps:**
1. [ ] **Crane environment in Isaac Sim**
   - Load or create crane USD asset
   - Add Replicator-compatible materials for metal, paint, rust
   - Set up 8+ camera positions around crane

2. [ ] **Defect material library**
   - Crack textures (hairline, branched, spiderweb, edge) — implemented in replicator script
   - Corrosion patterns (rust pitting, surface flaking, discoloration)
   - Paint damage (scratches, chips, fading, peeling)
   - Apply via OmniPBR material randomization

3. [ ] **Domain randomization config**
   - Lighting: 5 modes (bright, overcast, dusk, dawn, shadowed)
   - Weather: rain, fog, dust particles (via Replicator)
   - Camera noise: Gaussian, motion blur, defocus
   - Defect placement: random positions, scales, rotations on crane surfaces

4. [ ] **Replicator SDG pipeline**
   - Use `rep.randomizer`, `rep.trigger`, `rep.writer` APIs
   - Writers: YOLO (bounding boxes), COCO, segmentation masks
   - Register custom randomizers for defect placement
   - Output: `dataset/synthetic_v2/` with proper structure

5. [ ] **Validation**
   - Run contract tests: 5000+ images, correct YOLO format
   - Visual inspection: sample 100 images for quality
   - Class distribution: balanced across 3 defect types

### Phase 2: Cosmos Transfer Augmentation (Week 2-3)

**Goal:** Generate 50,000+ photorealistic variants from 10,000 synthetic images.

**Steps:**
1. [ ] **Set up Cosmos Transfer 2.5**
   - Clone: `git clone https://github.com/nvidia-cosmos/cosmos-transfer2.5`
   - Install dependencies (PyTorch, diffusers, etc.)
   - Download model from Hugging Face: `huggingface.co/nvidia/Cosmos-Transfer2.5`

2. [ ] **Prepare inputs from Replicator output**
   - Convert Replicator output to Cosmos-expected format (video frames)
   - Extract RGB, depth, segmentation from each synthesis run
   - Package as structured dataset directory

3. [ ] **Run augmentation pipeline**
   - Text prompts for defect-specific augmentation
   - Vary: lighting, texture, background, camera angle
   - Output: photorealistic video frames aligned with source

4. [ ] **Augmented dataset creation**
   - Merge synthetic + Cosmos-augmented data
   - Generate combined `data.yaml` for YOLO training
   - Split: 70% train, 20% val, 10% test

### Phase 3: Model Training (Week 2-3)

**Goal:** Train YOLOv8/11 model with mAP@0.5 ≥ 0.70.

**Steps:**
1. [ ] **Baseline: synthetic-only training**
   - `python scripts/train_yolo.py --data dataset/synthetic_v2/data.yaml --epochs 100`
   - Record mAP@0.5, mAP@0.5:0.95, class-wise AP

2. [ ] **Augmented training**
   - `python scripts/train_yolo.py --data dataset/augmented/data.yaml --epochs 150`
   - Compare vs baseline

3. [ ] **Model export**
   - ONNX: `model.export(format='onnx')`
   - TensorRT FP16: `trtexec --onnx=best.onnx --saveEngine=best_fp16.trt --fp16`
   - INT8 quantization (optional): `trtexec --onnx=best.onnx --saveEngine=best_int8.trt --int8`

### Phase 4: ROS2 Inference Deployment (Current — Mostly Done)

**Goal:** Run inference on drone camera feed in real-time.

**Status:** Core ROS2 nodes built, need end-to-end validation with Isaac Sim camera feed.

**Remaining:**
1. [ ] Connect Isaac Sim camera → ROS2 inference node → defect JSON
2. [ ] Test with Pegasus drone's inspection_camera topic
3. [ ] Validate latency (target: <100ms per frame)
4. [ ] Deploy as ROS2 launch file

### Phase 5: Real-World Data Collection & Domain Adaptation (Ongoing)

**Goal:** Continuously improve model with real-world data.

**Steps:**
1. [ ] Collect real crane inspection images (or use public datasets)
2. [ ] Label with YOLO format (at least 500 images)
3. [ ] Hybrid training: synthetic (70%) + real (30%)
4. [ ] Use Cosmos Reason 2 for failure analysis
5. [ ] Iterative retraining with expanded real dataset

---

## 4. Data Aggregation Strategy

```
                    ┌─────────────────────┐
                    │  Isaac Sim           │
                    │  Replicator SDG      │
                    │  10,000 images       │
                    └─────────┬───────────┘
                              │ RGB + depth + seg
                              ▼
                    ┌─────────────────────┐
                    │  Cosmos Transfer 2.5 │
                    │  ×50 augmentation    │
                    │  500,000 variants    │
                    └─────────┬───────────┘
                              │
            ┌─────────────────┼─────────────────┐
            ▼                 ▼                  ▼
    ┌──────────────┐  ┌──────────────┐  ┌──────────────┐
    │ Synthetic    │  │ Real-world   │  │ Edge-case     │
    │ (10,000 img) │  │ (500+ img)   │  │ (Cosmos Pred) │
    └──────┬───────┘  └──────┬───────┘  └──────┬───────┘
           │                 │                  │
           └─────────────────┼──────────────────┘
                             │
                             ▼
                    ┌─────────────────────┐
                    │  Hybrid Dataset      │
                    │  ~510,000 images     │
                    │  70% synth / 30% real│
                    └─────────┬───────────┘
                              │
                              ▼
                    ┌─────────────────────┐
                    │  YOLO Training       │
                    │  → ONNX → TensorRT   │
                    └─────────────────────┘
```

### Dataset Storage Layout

```
dataset/
├── synthetic/          # Phase 1 — basic synthetic (already exists)
│   ├── images/
│   ├── labels_yolo/
│   ├── masks/
│   └── metadata.json
├── synthetic_v2/       # Phase 1 — advanced replicator (next)
│   ├── images/
│   ├── labels_yolo/
│   ├── masks/
│   ├── depth/
│   └── metadata.json
├── augmented/          # Phase 2 — Cosmos Transfer output
│   ├── synthetic_v2_aug/
│   │   ├── images/
│   │   └── labels_yolo/
│   └── data.yaml
├── real/               # Phase 5 — real-world images
│   ├── images/
│   ├── labels_yolo/
│   └── data.yaml
└── mixed_train/        # Final training dataset
    ├── images/
    ├── labels_yolo/
    └── data.yaml
```

---

## 5. Technology Stack

| Component | Technology | Status |
|-----------|-----------|--------|
| Simulation | Isaac Sim 5.1 | ✅ Running |
| Drone Sim | Pegasus Simulator (Iris + PX4) | ✅ Loaded |
| ROS2 Bridge | isaacsim.ros2.bridge (internal humble) | ✅ Loaded |
| SDG Pipeline | Omniverse Replicator | ⬜ Not started |
| Data Augmentation | Cosmos Transfer 2.5 | ⬜ Not started |
| Model Training | YOLOv8/11 (ultralytics) | ✅ Script ready |
| Model Export | ONNX → TensorRT | ✅ Script ready |
| Inference Node | ROS2 (pegasus_ai) | ✅ Built |
| Data Orchestration | N/A (local for now, OSMO later) | ⬜ |
| Visualization | Foxglove Studio (ws://localhost:8765) | ✅ Running |

---

## 6. Key NVIDIA Resources

### Official Repos
- https://github.com/nvidia-cosmos/cosmos-transfer2.5
- https://github.com/nvidia-cosmos/cosmos-predict2.5
- https://github.com/nvidia-cosmos/cosmos-reason2
- https://github.com/NVIDIA-AI-IOT/synthetic_data_generation_training_workflow
- https://github.com/NVIDIA-Omniverse/synthetic-data-examples

### Official Docs
- Isaac Sim Replicator: https://docs.isaacsim.omniverse.nvidia.com/latest/replicator_tutorials/
- Isaac Sim ROS2: https://docs.isaacsim.omniverse.nvidia.com/latest/ros2_tutorials/
- Cosmos Cookbook: https://nvidia-cosmos.github.io/cosmos-cookbook/
- Isaac Lab: https://isaac-sim.github.io/IsaacLab/

### Models (Hugging Face)
- Cosmos Transfer 2.5: https://huggingface.co/nvidia/Cosmos-Transfer2.5
- Cosmos Predict 2.5: https://huggingface.co/nvidia/Cosmos-Predict2.5
- Cosmos Reason 2: https://huggingface.co/nvidia/Cosmos-Reason2
