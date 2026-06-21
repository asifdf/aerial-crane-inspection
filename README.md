# Aerial AI — Crane Inspection Drone

> **Sim-to-Real AI Pipeline for Defect Detection**
> Aerial Autonomy Stack + Isaac Sim + PX4 SITL → Jetson Orin

## Architecture

```
┌──────────────────────────────────────────────────────┐
│  Isaac Sim + Pegasus (physics/rendering)              │
│  ├── Container Harbor + Cranes (USD scene)            │
│  ├── Iris Quadrotor (multirotor dynamics)             │
│  └── Inspection Camera (640×640, 20Hz, down-facing)   │
├──────────────────────────────────────────────────────┤
│  PX4 SITL (flight controller)                         │
│  ←→ MAVLink UDP (port 14540)                         │
├──────────────────────────────────────────────────────┤
│  MAVROS (MAVLink ↔ ROS2 bridge)                       │
│  Topics: /mavros/state, /mavros/local_position/pose   │
├──────────────────────────────────────────────────────┤
│  Aerial Autonomy Stack (ROS2 nodes)                   │
│  ├── autopilot_interface (C++)  — ROS2 actions        │
│  │   Actions: Takeoff, Land, Orbit, Offboard           │
│  │   Services: SetReposition, SetSpeed                │
│  ├── mission (Python)           — YAML conops executor│
│  ├── yolo_py (Python)           — ONNX GPU inference  │
│  └── state_sharing (C++)        — Swarm state via Zenoh│
├──────────────────────────────────────────────────────┤
│  pegasus_ai (our nodes)                               │
│  └── inference_node (TensorRT YOLO defect detection)  │
├──────────────────────────────────────────────────────┤
│  Jetson Orin Nano Super (deployment)                  │
│  TensorRT FP16, ≥30 FPS, ROS2 Humble                  │
└──────────────────────────────────────────────────────┘
```

## Quick Start

### Prerequisites
- Ubuntu 22.04 (ROS2 Humble)
- PX4-Autopilot v1.14.3 (SITL)
- Isaac Sim 5.1.0 (with Pegasus Simulator)
- MAVROS (ROS2)

### 1. Clone
```bash
git clone <this-repo> /workspace/aerial_ws
cd /workspace/aerial_ws
```

### 2. Build ROS2 Workspace
```bash
cd ros2_ws
source /opt/ros/humble/setup.bash
colcon build
source install/setup.bash
```

### 3. Start PX4 SITL (Terminal 1)
```bash
cd /workspace/PX4-Autopilot
make px4_sitl none
```

### 4. Launch Drone Stack (Terminal 2)
```bash
source /opt/ros/humble/setup.bash
source /workspace/aerial_ws/ros2_ws/install/setup.bash

# MAVROS
ros2 run mavros mavros_node --ros-args \
  -p fcu_url:=udp://:14540@localhost:14550

# Takeoff action server
ros2 run autopilot_interface px4_interface_node

# Mission executor
DRONE_ID=1 ros2 run mission mission --conops /workspace/aerial_ws/missions/crane_inspection.yaml
```

### 5. With Isaac Sim (Terminal 3)
```bash
export OMNI_KIT_ALLOW_ROOT=1 DISPLAY=:1
export ROS_DOMAIN_ID=42
/workspace/isaacsim/isaac-sim.sh --allow-root \
  --ext-path /workspace/pegasus/PegasusSimulator/extensions/pegasus.simulator \
  --enable pegasus.simulator \
  --exec /workspace/aerial_ws/scripts/spawn_drone_px4.py
```

### 6. Run Tests
```bash
python3 -m pytest tests/ -v
```

## TDD Milestones

| # | Milestone | Focus |
|---|-----------|-------|
| 0 | Foundation | CI, ROS2 ws, imports |
| 1 | Synthetic Data | Isaac Sim Replicator, 5k+ images |
| 2 | Baseline Training | YOLO on synthetic, mAP@0.5 ≥ 0.70 |
| 3 | ROS2 Integration | Autopilot actions, topics, latency <200ms |
| 4 | Domain Hardening | Weather, noise, materials |
| 5 | Hybrid Training | 500+ real images, 70/30 split |
| 6 | Jetson Deploy | TensorRT FP16, ≥30 FPS |
| 7 | Drone Stack | Aerial Autonomy Stack + PX4 SITL + MAVROS |
| 8 | Final Demo | Sim autonomous + real flight |

## Project Structure

```
aerial_ws/
├── ros2_ws/src/
│   ├── autopilot_interface/      # ROS2 action servers (Takeoff, Land, Orbit)
│   ├── autopilot_interface_msgs/ # Action/Srv/Msg definitions
│   ├── offboard_control/         # PX4/ArduPilot offboard setpoint streaming
│   ├── mission/                  # YAML conops mission executor
│   ├── yolo_py/                  # YOLO ONNX GPU inference
│   ├── state_sharing/            # Inter-drone state (Zenoh)
│   └── imu_publisher/            # IMU data forwarding
├── scripts/                      # Isaac Sim integration scripts
├── tests/                        # Contract tests (TDD milestones)
├── missions/                     # Conops YAML files
├── docs/                         # TDD plan, safety, operations
├── dataset/
│   ├── synthetic/                # Isaac Sim generated
│   ├── real/                     # Collected real images
│   └── mixed_train/              # Hybrid training set
├── models/                       # Trained weights (ONNX, TensorRT)
└── pyproject.toml
```

## Safety

**AI NEVER CONTROLS MOTORS DIRECTLY** — only detects and reports.
Follow `docs/SAFETY_INJECTION_ORDER.md` for real drone deployment.

## License

Apache-2.0 — Aerial Autonomy Stack components retain their original BSD-3-Clause.
