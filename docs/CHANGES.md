# Changes from Upstream (aerial-autonomy-stack)

This project is based on [JacopoPan/aerial-autonomy-stack](https://github.com/JacopoPan/aerial-autonomy-stack) (AAS),
adapted for single-drone crane inspection with **Isaac Sim + Pegasus** instead of Gazebo.

## Summary

| # | Component | Upstream (AAS) | Ours | Rationale |
|---|-----------|---------------|------|-----------|
| 1 | **MAVROS port** | `fcu_url:=udp://:14540@...` | `fcu_url:=udp://:4560@...` | Pegasus Mavlink backend uses port 4560 |
| 2 | **Camera input** | GStreamer UDP pipeline (CSI/RTSP) | ROS2 `sensor_msgs/Image` topic | Isaac Sim publishes camera via ROS2 bridge |
| 3 | **LiDAR odometry** | `kiss_icp` node active | Not launched | No LiDAR in crane inspection scene |
| 4 | **Swarm tracking** | `state_sharing` + `SwarmObs` multi-drone | Not launched (single drone) | Crane inspection is single-drone; `ground_tracks_sub_` fires but unused |
| 5 | **Mission conops** | `yalla.yaml` (multi-drone swarm demo) | `crane_inspection_demo.yaml` (orbit + inspect) | Different use case |

## Detail

### 1. MAVROS port (`fcu_url`)

```
Upstream:  udp://:14540@localhost:14550   (standard PX4 SITL)
Ours:      udp://:4560@localhost:14550    (Pegasus Mavlink backend default)
```

The Pegasus Simulator's `PX4MavlinkBackend` auto-launches PX4 SITL on UDP port 4560.
Set via launch argument `fcu_url` in `drone_stack.launch.py`.

### 2. Camera input

```
Upstream:  yolo_py node reads from GStreamer pipeline (nvarguscamerasrc / udpsrc)
Ours:      pegasus_ai inference_node subscribes to ROS2 Image topic
```

Isaac Sim's Pegasus `ROS2Backend` publishes camera frames to
`/drone/inspection_camera/color/image_raw`. Our `inference_node` subscribes to this
topic directly. The upstream `yolo_py` package is not used because it expects
GStreamer input (designed for Jetson CSI cameras or Gazebo UDP streams).

### 3. LiDAR disabled

The upstream launches `kiss_icp` for LiDAR-based odometry. Our crane inspection
scene uses a monocular down-facing camera only. `kiss_icp` is excluded from the
launch file.

### 4. Single drone (no swarm)

Upstream `offboard_control` and `mission` subscribe to `SwarmObs` on `/tracks`
(published by `ground_system`). This subscription is still present in the code
(for upstream compatibility) but no `ground_system` node is launched, so it
receives no data. All swarm-related nodes (`state_sharing`, Zenoh bridge) are
excluded.

### 5. Mission YAML

```
Upstream:  yalla.yaml           (multi-drone coordinated flight)
Ours:      crane_inspection_demo.yaml  (single-drone orbit + inspection)
```

Our mission performs a takeoff, orbit around a target (crane), then land.
No inter-drone coordination needed.

## Node Mapping

| Function | Upstream Node | Our Node | Status |
|----------|--------------|----------|--------|
| Flight control | `autopilot_interface/px4_interface` | same | ✓ Used |
| Setpoint compute | `offboard_control/px4_offboard` | same | ✓ Used |
| Mission execute | `mission/mission` | same | ✓ Used |
| AI inference | `yolo_py` (GStreamer) | `pegasus_ai/inference_node` (ROS2) | Swapped |
| LiDAR odometry | `kiss_icp` | — | Dropped |
| Swarm state | `state_sharing` | — | Dropped |
| IMU publish | `imu_publisher` | — | Dropped (PX4 provides via MAVROS) |
