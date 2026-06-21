import json
import time

import launch
import launch_ros.actions
import launch_testing
import launch_testing.actions
import numpy as np
import pytest
import rclpy
from pegasus_msgs.msg import DefectArray, NodeHealth
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import String


@pytest.mark.launch_test
def generate_test_description():
    mock_camera = launch_ros.actions.Node(
        package="pegasus_ai",
        executable="mock_camera_node",
        name="mock_camera",
        parameters=[
            {
                "image_width": 320,
                "image_height": 240,
                "fps": 2.0,
                "test_mode": "synthetic_defects",
                "topic_name": "/camera/image_raw",
            }
        ],
        output="screen",
    )

    inference = launch_ros.actions.Node(
        package="pegasus_ai",
        executable="inference_node",
        name="defect_inference",
        parameters=[
            {
                "model_type": "mock",
                "input_image_topic": "/camera/image_raw",
                "output_defect_array_topic": "/ai/defect_array",
                "output_json_topic": "/ai/defect_json",
                "output_health_topic": "/ai/node_health",
                "max_publish_rate": 0.0,
            }
        ],
        output="screen",
    )

    return (
        launch.LaunchDescription(
            [
                mock_camera,
                inference,
                launch_testing.actions.ReadyToTest(),
            ]
        ),
        {"mock_camera": mock_camera, "inference": inference},
    )


class TopicProbe(Node):
    def __init__(self):
        super().__init__("pegasus_ai_launch_probe")
        self.defect_json = None
        self.defect_array = None
        self.health = None
        self.image_pub = self.create_publisher(Image, "/camera/image_raw", 10)
        self.create_subscription(String, "/ai/defect_json", self._on_json, 10)
        self.create_subscription(DefectArray, "/ai/defect_array", self._on_array, 10)
        self.create_subscription(NodeHealth, "/ai/node_health", self._on_health, 10)

    def _on_json(self, msg):
        self.defect_json = msg

    def _on_array(self, msg):
        self.defect_array = msg

    def _on_health(self, msg):
        self.health = msg

    def publish_test_image(self):
        image = np.zeros((240, 320, 3), dtype=np.uint8)
        image[45:120, 60:160, 2] = 255
        image[130:205, 175:270, 0] = 255

        msg = Image()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "test_camera"
        msg.height = image.shape[0]
        msg.width = image.shape[1]
        msg.encoding = "bgr8"
        msg.is_bigendian = False
        msg.step = image.shape[1] * image.shape[2]
        msg.data = np.ascontiguousarray(image).tobytes()
        self.image_pub.publish(msg)


def test_mock_launch_publishes_detections_and_health():
    if not rclpy.ok():
        rclpy.init()
    probe = TopicProbe()
    deadline = time.time() + 10.0

    try:
        while time.time() < deadline:
            probe.publish_test_image()
            rclpy.spin_once(probe, timeout_sec=0.1)
            if probe.defect_json and probe.defect_array and probe.health:
                break

        assert probe.defect_json is not None, "No /ai/defect_json message received"
        assert probe.defect_array is not None, "No /ai/defect_array message received"
        assert probe.defect_array.total_count >= 1
        assert len(probe.defect_array.detections) >= 1

        payload = json.loads(probe.defect_json.data)
        assert len(payload["defects"]) >= 1

        assert probe.health is not None, "No /ai/node_health message received"
        assert hasattr(probe.health, "fps")
        assert hasattr(probe.health, "uptime_sec")
        assert probe.health.fps >= 0.0
        assert probe.health.uptime_sec >= 0.0
    finally:
        probe.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
