# Architecture — Aerial Crane Inspection

Based on [JacopoPan/aerial-autonomy-stack](https://github.com/JacopoPan/aerial-autonomy-stack) (AAS),
adapted for Isaac Sim + Pegasus single-drone crane inspection.

```
┌─ ISAAC SIM ──────────────────────────────────────────────────────────┐
│  Pegasus Simulator                                                    │
│  ├── USD Scene: container harbor + port cranes                        │
│  ├── Multirotor: Iris quadrotor                                       │
│  ├── MonocularCamera: 640×640, 20Hz, down-facing                      │
│  ├── PX4MavlinkBackend: auto-launches PX4 SITL, MAVLink UDP :4560    │
│  └── ROS2Backend: publishes camera frames to ROS2                     │
│                                                                       │
│  Launch: spawn_drone_px4.py                                           │
└───────────────────────┬───────────────────────────────────────────────┘
                        │
          MAVLink :4560 │  ROS2 topic
          ┌─────────────┼──────────────┐
          ▼             │              ▼
┌─PX4 SITL────────────┐ │  /drone/inspection_camera/color/image_raw
│  Auto-launched by   │ │
│  Pegasus backend    │ │
└──────────┬──────────┘ │
           │             │
┌──────────▼─────────────▼──────────────────────────────────────────────┐
│  ROS2 NODES (drone_stack.launch.py)                                    │
│                                                                        │
│  ┌─ MAVROS ──────────────────────────────────────────────────────┐    │
│  │  fcu_url: udp://:4560@localhost:14550  ← CHANGE from :14540  │    │
│  │  Topics: /mavros/state, /mavros/local_position/pose, etc.     │    │
│  └──────────────────────────┬────────────────────────────────────┘    │
│                             │                                          │
│  ┌─ AAS: autopilot_interface ────────────────────────────────────┐    │
│  │  px4_interface (C++)                                           │    │
│  │  Namespace: /Drone1                                            │    │
│  │  ROS2 Actions:                                                 │    │
│  │    /Drone1/takeoff_action   (Takeoff)                          │    │
│  │    /Drone1/land_action      (Land)                             │    │
│  │    /Drone1/orbit_action     (Orbit)                            │    │
│  │    /Drone1/offboard_action  (Offboard)                         │    │
│  │  Services: /Drone1/set_reposition, /Drone1/set_speed           │    │
│  └──────────────────────────┬────────────────────────────────────┘    │
│                             │                                          │
│  ┌─ AAS: offboard_control ───────────────────────────────────────┐    │
│  │  px4_offboard (C++)                                            │    │
│  │  Subscribes:                                                   │    │
│  │    /detections      ← YOLO bounding boxes                      │    │
│  │    /mavros/local_position/pose                                 │    │
│  │  Publishes: /reference → PX4 trajectory setpoints              │    │
│  └──────────────────────────┬────────────────────────────────────┘    │
│                             │                                          │
│  ┌─ AAS: mission ────────────────────────────────────────────────┐    │
│  │  mission (Python)                                              │    │
│  │  Conops: crane_inspection_demo.yaml                            │    │
│  │  Calls: autopilot_interface actions (Takeoff → Orbit → Land)   │    │
│  └────────────────────────────────────────────────────────────────┘    │
│                                                                        │
│  ┌─ pegasus_ai: inference_node ───────────────────────────────────┐    │
│  │  TensorRT YOLO defect detection                                  │    │
│  │  Subscribes: /drone/inspection_camera/color/image_raw           │    │
│  │  Publishes:  /detections (vision_msgs/Detection2DArray)         │    │
│  └────────────────────────────────────────────────────────────────┘    │
│                                                                        │
│  NOT launched (vs upstream):                                           │
│    ✗ kiss_icp        — no LiDAR                                       │
│    ✗ state_sharing   — single drone, no swarm                         │
│    ✗ imu_publisher   — PX4 provides IMU via MAVROS                    │
│    ✗ yolo_py         — uses GStreamer, we use ROS2 camera topic       │
└────────────────────────────────────────────────────────────────────────┘
```

## Data Flow

```
Isaac Sim Camera
    │  640×640, 20Hz, down-facing
    │  ROS2 topic: /drone/inspection_camera/color/image_raw
    ▼
inference_node (TensorRT YOLO)
    │  ROS2 topic: /detections
    ▼
offboard_control (setpoint computation)
    │  ROS2 topic: /reference
    ▼
autopilot_interface (action server)
    │  MAVROS
    ▼
PX4 SITL
    │  MAVLink
    ▼
Isaac Sim (physics)
```

## Comparison: Upstream vs Ours

| Layer | Upstream (AAS) | Ours |
|-------|---------------|------|
| Simulation | Gazebo Harmonic | Isaac Sim 5.1 + Pegasus |
| World | .sdf (swiss_town, waterworld) | USD (container harbor + cranes) |
| Autopilot | PX4 + ArduPilot SITL | PX4 SITL only |
| Camera input | GStreamer UDP | ROS2 Image topic |
| AI | yolo_py (ONNX GPU) | inference_node (TensorRT) |
| LiDAR | kiss_icp | Not used |
| Swarm | state_sharing + Zenoh | Not used |
| Deploy | Docker (aircraft-image) | Direct ROS2 |
| Network | Dual LAN (SIM + AIR subnets) | localhost |
| Multi-drone | N drones, HITL | Single drone |
| Mission | yalla.yaml (swarm) | crane_inspection_demo.yaml |
