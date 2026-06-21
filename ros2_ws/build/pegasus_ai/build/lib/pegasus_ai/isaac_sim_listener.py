#!/usr/bin/env python3
"""
Isaac Sim Camera Listener — subscribes to Pegasus drone camera and AI inference output.
Run: ros2 run pegasus_ai isaac_sim_listener
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import String
import time


class IsaacSimCameraListener(Node):
    """Listens to Isaac Sim Pegasus drone camera feed and AI inference output."""

    def __init__(self):
        super().__init__("isaac_sim_listener")
        self.rgb_sub = self.create_subscription(
            Image, "/pegasus/inspection_camera/color/image_raw", self._on_rgb, 10
        )
        self.defect_sub = self.create_subscription(
            String, "/pegasus/ai/defect_json", self._on_defect, 10
        )
        self.rgb_count = 0
        self.defect_count = 0
        self._last_time = time.time()
        self.get_logger().info("IsaacSimListener started")
        self.get_logger().info("  Subscribed to:")
        self.get_logger().info("    /pegasus/inspection_camera/color/image_raw")
        self.get_logger().info("    /pegasus/ai/defect_json")

    def _on_rgb(self, msg):
        self.rgb_count += 1
        now = time.time()
        elapsed = now - self._last_time
        if self.rgb_count % 30 == 0:
            fps = 30.0 / elapsed if elapsed > 0 else 0
            self.get_logger().info(
                f"[RGB] #{self.rgb_count} — {msg.width}x{msg.height} "
                f"encoding={msg.encoding} FPS={fps:.1f}"
            )
            self._last_time = now

    def _on_defect(self, msg):
        self.defect_count += 1
        if self.defect_count <= 3:
            self.get_logger().info(f"[DEFECT] #{self.defect_count}: {msg.data[:200]}")


def main(args=None):
    rclpy.init(args=args)
    node = IsaacSimCameraListener()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
