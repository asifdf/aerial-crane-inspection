# pegasus_ai

ROS2 Humble AI inference package for Pegasus crane inspection. The package
provides a defect inference node, a synthetic mock camera, and test publishers
for validating the camera-to-detection pipeline.

## Nodes

- `inference_node`: subscribes to `sensor_msgs/Image` on `/camera/image_raw`,
  runs TensorRT YOLO inference or deterministic mock inference, and publishes:
  - `/ai/defect_array` (`pegasus_msgs/DefectArray`)
  - `/ai/defect_json` (`std_msgs/String`)
  - `/ai/node_health` (`pegasus_msgs/NodeHealth`)
- `mock_camera_node`: publishes synthetic BGR images and camera info for local
  testing without Isaac Sim or a physical camera.

## Mock mode

Mock mode avoids importing `cv_bridge` and converts `sensor_msgs/Image` payloads
directly with NumPy. This is useful on ROS2 Humble systems where `cv_bridge` was
built against NumPy 1.x but the Python environment has NumPy 2.x.

Run the inference node in mock mode:

```bash
source /opt/ros/humble/setup.bash
cd ros2_ws
colcon build --packages-select pegasus_msgs pegasus_ai
source install/setup.bash
ros2 run pegasus_ai inference_node --ros-args -p model_type:=mock
```

In another shell, publish synthetic camera frames:

```bash
source /opt/ros/humble/setup.bash
cd ros2_ws
source install/setup.bash
ros2 run pegasus_ai mock_camera_node --ros-args -p test_mode:=synthetic_defects
```

Inspect output:

```bash
ros2 topic echo /ai/defect_array
ros2 topic echo /ai/defect_json
ros2 topic echo /ai/node_health
```

## TensorRT mode

TensorRT is the default backend and expects a serialized engine at
`/opt/models/hybrid_fp16.trt` unless `model_path` is overridden.

```bash
ros2 launch pegasus_ai inference.launch.py model_path:=/path/to/model.trt
```

If the engine file is missing, TensorRT/PyCUDA cannot be imported, CUDA is not
available, or warmup inference fails, the node logs a warning and automatically
switches to mock mode instead of exiting.

## Configuration

Default parameters live in `config/inference.yaml`. Common overrides:

```bash
ros2 run pegasus_ai inference_node --ros-args \
  -p model_type:=mock \
  -p input_image_topic:=/camera/image_raw \
  -p output_defect_array_topic:=/ai/defect_array \
  -p output_json_topic:=/ai/defect_json \
  -p max_publish_rate:=30.0
```

## Launch testing

The launch test starts `mock_camera_node` and `inference_node` in mock mode,
publishes a test image, and verifies detection and health topics.

```bash
source /opt/ros/humble/setup.bash
cd ros2_ws
colcon build --packages-select pegasus_msgs pegasus_ai
source install/setup.bash
cd ..
python3 -m pytest tests/milestone3/test_launch.py -v
```

