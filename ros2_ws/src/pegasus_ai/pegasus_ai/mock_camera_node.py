#!/usr/bin/env python3
"""
Mock Camera Node for Isaac Sim Testing
Publishes synthetic camera images to /camera/image_raw for testing the AI pipeline.
"""

import cv2
import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSHistoryPolicy, QoSProfile, QoSReliabilityPolicy
from sensor_msgs.msg import CameraInfo, Image


class MockCameraNode(Node):
    """Publishes simulated camera images for testing."""

    def __init__(self):
        super().__init__("mock_camera")

        # Parameters
        self.declare_parameter("image_width", 1280)
        self.declare_parameter("image_height", 720)
        self.declare_parameter("fps", 30.0)
        self.declare_parameter("frame_id", "camera_link")
        self.declare_parameter("topic_name", "/camera/image_raw")
        self.declare_parameter("camera_info_topic", "/camera/camera_info")
        self.declare_parameter("test_mode", "static")  # 'static', 'noise', 'synthetic_defects'

        self.width = self.get_parameter("image_width").value
        self.height = self.get_parameter("image_height").value
        self.fps = self.get_parameter("fps").value
        self.frame_id = self.get_parameter("frame_id").value
        self.topic_name = self.get_parameter("topic_name").value
        self.camera_info_topic = self.get_parameter("camera_info_topic").value
        self.test_mode = self.get_parameter("test_mode").value

        # QoS for sensor data
        sensor_qos = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=1,
        )

        # Publishers
        self.image_pub = self.create_publisher(Image, self.topic_name, sensor_qos)
        self.camera_info_pub = self.create_publisher(CameraInfo, self.camera_info_topic, sensor_qos)

        self.frame_count = 0

        # Camera intrinsics (typical 90deg FOV)
        self.fx = self.width / (2 * np.tan(np.radians(90) / 2))
        self.fy = self.fx
        self.cx = self.width / 2
        self.cy = self.height / 2

        # Timer
        self.timer = self.create_timer(1.0 / self.fps, self.timer_callback)

        self.get_logger().info(
            f"MockCameraNode started: {self.width}x{self.height} @ {self.fps}fps"
        )
        self.get_logger().info(f"  Publishing to: {self.topic_name}")
        self.get_logger().info(f"  Test mode: {self.test_mode}")

    def timer_callback(self):
        """Generate and publish test image."""
        stamp = self.get_clock().now().to_msg()

        # Generate test image based on mode
        if self.test_mode == "static":
            image = self._generate_static_image()
        elif self.test_mode == "noise":
            image = self._generate_noise_image()
        elif self.test_mode == "synthetic_defects":
            image = self._generate_synthetic_defects()
        else:
            image = self._generate_static_image()

        # Publish image
        img_msg = self._numpy_to_image_msg(image, stamp)
        self.image_pub.publish(img_msg)

        # Publish camera info
        cam_info = CameraInfo()
        cam_info.header.stamp = stamp
        cam_info.header.frame_id = self.frame_id
        cam_info.width = self.width
        cam_info.height = self.height
        cam_info.distortion_model = "plumb_bob"
        cam_info.d = [0.0, 0.0, 0.0, 0.0, 0.0]
        cam_info.k = [
            float(self.fx),
            0.0,
            float(self.cx),
            0.0,
            float(self.fy),
            float(self.cy),
            0.0,
            0.0,
            1.0,
        ]
        cam_info.r = [1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0]
        cam_info.p = [
            float(self.fx),
            0.0,
            float(self.cx),
            0.0,
            0.0,
            float(self.fy),
            float(self.cy),
            0.0,
            0.0,
            0.0,
            1.0,
            0.0,
        ]
        self.camera_info_pub.publish(cam_info)

        self.frame_count += 1

    def _numpy_to_image_msg(self, image: np.ndarray, stamp) -> Image:
        """Convert a BGR numpy image to a ROS Image without cv_bridge."""
        msg = Image()
        msg.header.stamp = stamp
        msg.header.frame_id = self.frame_id
        msg.height = int(image.shape[0])
        msg.width = int(image.shape[1])
        msg.encoding = "bgr8"
        msg.is_bigendian = False
        msg.step = int(image.shape[1] * image.shape[2])
        msg.data = np.ascontiguousarray(image).tobytes()
        return msg

    def _generate_static_image(self) -> np.ndarray:
        """Generate a static test pattern."""
        # Gradient background
        x = np.linspace(0, 1, self.width)
        y = np.linspace(0, 1, self.height)
        xx, yy = np.meshgrid(x, y)
        image = np.zeros((self.height, self.width, 3), dtype=np.uint8)
        image[:, :, 0] = (xx * 255).astype(np.uint8)  # Blue gradient
        image[:, :, 1] = (yy * 255).astype(np.uint8)  # Green gradient
        image[:, :, 2] = 128  # Constant red

        # Add frame counter text
        cv2.putText(
            image,
            f"Frame: {self.frame_count}",
            (20, 40),
            cv2.FONT_HERSHEY_SIMPLEX,
            1,
            (255, 255, 255),
            2,
        )
        cv2.putText(
            image,
            f"Mode: {self.test_mode}",
            (20, 80),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.7,
            (255, 255, 255),
            2,
        )

        return image

    def _generate_noise_image(self) -> np.ndarray:
        """Generate random noise image."""
        image = np.random.randint(0, 256, (self.height, self.width, 3), dtype=np.uint8)
        cv2.putText(
            image,
            f"NOISE Frame: {self.frame_count}",
            (20, 40),
            cv2.FONT_HERSHEY_SIMPLEX,
            1,
            (255, 255, 255),
            2,
        )
        return image

    def _generate_synthetic_defects(self) -> np.ndarray:
        """Generate synthetic defects for testing detection."""
        # Base: concrete/metal texture
        base = np.ones((self.height, self.width, 3), dtype=np.uint8) * 120
        noise = np.random.randint(-20, 20, (self.height, self.width, 3), dtype=np.int16)
        image = np.clip(base.astype(np.int16) + noise, 0, 255).astype(np.uint8)

        # Add some "crack-like" lines
        for i in range(3):
            x1 = np.random.randint(0, self.width)
            y1 = np.random.randint(0, self.height)
            x2 = x1 + np.random.randint(-100, 100)
            y2 = y1 + np.random.randint(-100, 100)
            x2 = np.clip(x2, 0, self.width - 1)
            y2 = np.clip(y2, 0, self.height - 1)
            cv2.line(image, (x1, y1), (x2, y2), (50, 50, 50), np.random.randint(2, 5))

        # Add some "corrosion-like" spots
        for i in range(5):
            cx = np.random.randint(0, self.width)
            cy = np.random.randint(0, self.height)
            r = np.random.randint(10, 40)
            color = (
                np.random.randint(30, 80),
                np.random.randint(40, 100),
                np.random.randint(80, 150),
            )
            cv2.circle(image, (cx, cy), r, color, -1)

        cv2.putText(
            image,
            f"SYNTHETIC Frame: {self.frame_count}",
            (20, 40),
            cv2.FONT_HERSHEY_SIMPLEX,
            1,
            (255, 255, 255),
            2,
        )

        return image


def main(args=None):
    rclpy.init(args=args)

    try:
        node = MockCameraNode()
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        rclpy.shutdown()


if __name__ == "__main__":
    main()
