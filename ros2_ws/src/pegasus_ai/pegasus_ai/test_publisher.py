#!/usr/bin/env python3
"""
Test Publisher for AI Pipeline Integration Testing
Publishes test images and verifies the inference pipeline end-to-end.
"""

import json
import time
from threading import Event

import cv2
import numpy as np
import rclpy
from cv_bridge import CvBridge
from pegasus_msgs.msg import DefectArray
from rclpy.node import Node
from rclpy.qos import QoSHistoryPolicy, QoSProfile, QoSReliabilityPolicy
from sensor_msgs.msg import Image
from std_msgs.msg import String


class TestPublisher(Node):
    """Integration test publisher for AI inference pipeline."""

    def __init__(self):
        super().__init__("test_publisher")

        self.declare_parameter("test_duration_sec", 10.0)
        self.declare_parameter("input_topic", "/camera/image_raw")
        self.declare_parameter("expected_detections_topic", "/ai/defect_detections")
        self.declare_parameter("expected_json_topic", "/ai/defect_json")
        self.declare_parameter("image_width", 640)
        self.declare_parameter("image_height", 480)
        self.declare_parameter("fps", 10.0)

        self.test_duration = self.get_parameter("test_duration_sec").value
        self.input_topic = self.get_parameter("input_topic").value
        self.expected_detections_topic = self.get_parameter("expected_detections_topic").value
        self.expected_json_topic = self.get_parameter("expected_json_topic").value
        self.width = self.get_parameter("image_width").value
        self.height = self.get_parameter("image_height").value
        self.fps = self.get_parameter("fps").value

        sensor_qos = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=10,
        )

        # Publisher for test images
        self.image_pub = self.create_publisher(Image, self.input_topic, sensor_qos)

        # Subscribers for results
        self.detections_received = []
        self.json_received = []
        self.detections_sub = self.create_subscription(
            DefectArray, self.expected_detections_topic, self.detections_callback, 10
        )
        self.json_sub = self.create_subscription(
            String, self.expected_json_topic, self.json_callback, 10
        )

        self.bridge = CvBridge()
        self.start_time = time.time()
        self.test_complete = Event()
        self.frame_count = 0

        # Timer for publishing test images
        self.publish_timer = self.create_timer(1.0 / self.fps, self.publish_test_image)

        # Timer for test timeout
        self.timeout_timer = self.create_timer(self.test_duration, self.on_timeout)

        self.get_logger().info(f"TestPublisher started - will run for {self.test_duration}s")
        self.get_logger().info(f"  Publishing to: {self.input_topic}")
        self.get_logger().info(f"  Expecting detections on: {self.expected_detections_topic}")
        self.get_logger().info(f"  Expecting JSON on: {self.expected_json_topic}")

    def publish_test_image(self):
        """Publish a synthetic test image with known patterns."""
        if self.test_complete.is_set():
            return

        # Create test image with synthetic defects
        image = self._create_test_image()

        msg = self.bridge.cv2_to_imgmsg(image, encoding="bgr8")
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "test_camera"
        self.image_pub.publish(msg)

        self.frame_count += 1

    def _create_test_image(self) -> np.ndarray:
        """Create a test image with known defect patterns."""
        # Base texture
        image = np.ones((self.height, self.width, 3), dtype=np.uint8) * 100
        noise = np.random.randint(-15, 15, (self.height, self.width, 3), dtype=np.int16)
        image = np.clip(image.astype(np.int16) + noise, 0, 255).astype(np.uint8)

        # Known crack pattern (horizontal line in upper third)
        y_crack = self.height // 3
        cv2.line(image, (50, y_crack), (self.width - 50, y_crack), (30, 30, 30), 3)

        # Known corrosion pattern (cluster in lower right)
        cx, cy = 3 * self.width // 4, 3 * self.height // 4
        cv2.circle(image, (cx, cy), 30, (40, 60, 120), -1)
        cv2.circle(image, (cx + 20, cy - 10), 15, (50, 80, 140), -1)

        # Frame counter
        cv2.putText(
            image,
            f"TEST Frame: {self.frame_count}",
            (10, 30),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.7,
            (255, 255, 255),
            2,
        )

        return image

    def detections_callback(self, msg: DefectArray):
        """Receive defect detections."""
        self.detections_received.append(
            {
                "stamp": msg.header.stamp,
                "frame_id": msg.header.frame_id,
                "drone_id": msg.drone_id,
                "zone_id": msg.zone_id,
                "count": msg.total_count,
                "detections": [
                    {
                        "type": d.type,
                        "confidence": d.confidence,
                        "bbox": [d.bbox_x, d.bbox_y, d.bbox_width, d.bbox_height],
                        "risk": d.risk_level,
                    }
                    for d in msg.detections
                ],
                "latency": msg.inference_latency,
            }
        )

    def json_callback(self, msg: String):
        """Receive JSON results."""
        try:
            data = json.loads(msg.data)
            self.json_received.append(
                {
                    "stamp": time.time(),
                    "data": data,
                }
            )
        except json.JSONDecodeError:
            self.get_logger().warn("Received invalid JSON")

    def on_timeout(self):
        """Test timeout - evaluate results."""
        self.timeout_timer.cancel()
        self.publish_timer.cancel()
        self.test_complete.set()

        self.get_logger().info("=== TEST RESULTS ===")
        self.get_logger().info(f"Frames published: {self.frame_count}")
        self.get_logger().info(f"Detections received: {len(self.detections_received)}")
        self.get_logger().info(f"JSON messages received: {len(self.json_received)}")

        # Verify detections
        if len(self.detections_received) == 0:
            self.get_logger().error("FAIL: No detections received!")
        else:
            self.get_logger().info("PASS: Detections received")
            for i, det in enumerate(self.detections_received[-3:]):  # Show last 3
                self.get_logger().info(
                    f"  Frame {i}: {det['count']} detections, "
                    f"latency={det['latency']*1000:.1f}ms"
                )
                for d in det["detections"]:
                    self.get_logger().info(
                        f"    {d['type']}: conf={d['confidence']:.2f}, "
                        f"bbox={d['bbox']}, risk={d['risk']}"
                    )

        # Verify JSON
        if len(self.json_received) == 0:
            self.get_logger().error("FAIL: No JSON received!")
        else:
            self.get_logger().info("PASS: JSON received")
            last_json = self.json_received[-1]["data"]
            self.get_logger().info(f"  Drone: {last_json.get('drone_id')}")
            self.get_logger().info(f"  Defects: {len(last_json.get('defects', []))}")

        # Check latency
        if self.detections_received:
            avg_latency = np.mean([d["latency"] for d in self.detections_received])
            self.get_logger().info(f"Average inference latency: {avg_latency*1000:.1f}ms")
            if avg_latency > 0.5:  # 500ms threshold
                self.get_logger().warn(f"WARNING: High latency ({avg_latency*1000:.1f}ms)")

        # Exit
        self.get_logger().info("Test complete. Shutting down...")
        rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)

    try:
        node = TestPublisher()
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        rclpy.shutdown()


if __name__ == "__main__":
    main()
