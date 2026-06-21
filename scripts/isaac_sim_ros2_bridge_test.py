#!/usr/bin/env python3
"""
Isaac Sim ROS2 Bridge Test Harness
Runs INSIDE Isaac Sim (Script Editor or standalone) to publish sensor data to ROS2.
Tests the ROS2 bridge connection and message formats.

Usage in Isaac Sim:
1. Open Script Editor (Window > Script Editor)
2. Paste this code or run as extension
3. Execute to start publishing to ROS2 topics

Requires: ROS2 bridge extension enabled in Isaac Sim
"""

import cv2
import numpy as np
import omni.kit.app
import omni.usd
import rclpy
from cv_bridge import CvBridge
from geometry_msgs.msg import Quaternion, TransformStamped, Vector3
from nav_msgs.msg import Odometry
from omni.isaac.sensor import Camera
from rclpy.node import Node
from sensor_msgs.msg import CameraInfo, Image, Imu
from tf2_msgs.msg import TFMessage


class IsaacSimROS2BridgeTest(Node):
    """Test node running inside Isaac Sim to publish sensor data to ROS2."""

    def __init__(self):
        super().__init__("isaac_sim_bridge_test")

        # ROS2 Publishers
        self.image_pub = self.create_publisher(Image, "/camera/image_raw", 10)
        self.camera_info_pub = self.create_publisher(CameraInfo, "/camera/camera_info", 10)
        self.depth_pub = self.create_publisher(Image, "/camera/depth", 10)
        self.imu_pub = self.create_publisher(Imu, "/imu", 10)
        self.odom_pub = self.create_publisher(Odometry, "/drone/odom", 10)
        self.tf_pub = self.create_publisher(TFMessage, "/tf", 10)

        self.bridge = CvBridge()
        self.frame_id = "camera_link"
        self.drone_frame = "base_link"
        self.world_frame = "world"

        # Isaac Sim camera
        self.camera = None
        self.camera_prim_path = "/World/Camera"

        # Timer for publishing
        self.timer = self.create_timer(1.0 / 30.0, self.publish_sensor_data)

        self.get_logger().info("IsaacSimROS2BridgeTest initialized")
        self.get_logger().info(
            "Publishing to: /camera/image_raw, /camera/camera_info, /camera/depth"
        )
        self.get_logger().info("              /imu, /drone/odom, /tf")

    def setup_camera(self, width=1280, height=720):
        """Create or get camera in Isaac Sim."""
        stage = omni.usd.get_context().get_stage()

        # Check if camera exists
        camera_prim = stage.GetPrimAtPath(self.camera_prim_path)
        if not camera_prim.IsValid():
            # Create new camera
            self.camera = Camera(
                prim_path=self.camera_prim_path,
                position=np.array([0, 0, 1.5]),
                orientation=np.array([1, 0, 0, 0]),  # w, x, y, z
            )
            self.camera.initialize()
            self.camera.set_resolution(width, height)
            self.camera.set_focal_length(24.0)
            self.get_logger().info(f"Created camera at {self.camera_prim_path}")
        else:
            self.camera = Camera(prim_path=self.camera_prim_path)
            self.camera.initialize()
            self.get_logger().info(f"Using existing camera at {self.camera_prim_path}")

        return self.camera

    def publish_sensor_data(self):
        """Publish all sensor data to ROS2."""
        stamp = self.get_clock().now().to_msg()

        # 1. RGB Camera Image
        if self.camera:
            try:
                rgb = self.camera.get_rgb()  # Returns RGBA
                if rgb is not None:
                    # Convert RGBA to BGR for ROS
                    bgr = cv2.cvtColor(rgb[:, :, :3], cv2.COLOR_RGB2BGR)

                    img_msg = self.bridge.cv2_to_imgmsg(bgr, encoding="bgr8")
                    img_msg.header.stamp = stamp
                    img_msg.header.frame_id = self.frame_id
                    self.image_pub.publish(img_msg)

                    # Camera Info
                    cam_info = self._create_camera_info(bgr.shape[1], bgr.shape[0], stamp)
                    self.camera_info_pub.publish(cam_info)

                    # Depth (if available)
                    depth = self.camera.get_depth()
                    if depth is not None:
                        depth_msg = self.bridge.cv2_to_imgmsg(
                            depth.astype(np.float32), encoding="32FC1"
                        )
                        depth_msg.header.stamp = stamp
                        depth_msg.header.frame_id = self.frame_id
                        self.depth_pub.publish(depth_msg)
            except Exception as e:
                self.get_logger().warn(f"Camera publish error: {e}")

        # 2. IMU Data (simulated)
        imu_msg = Imu()
        imu_msg.header.stamp = stamp
        imu_msg.header.frame_id = "imu_link"
        imu_msg.orientation = Quaternion(x=0.0, y=0.0, z=0.0, w=1.0)
        imu_msg.orientation_covariance = [0.01, 0, 0, 0, 0.01, 0, 0, 0, 0.01]
        imu_msg.angular_velocity = Vector3(x=0.0, y=0.0, z=0.0)
        imu_msg.angular_velocity_covariance = [0.01, 0, 0, 0, 0.01, 0, 0, 0, 0.01]
        imu_msg.linear_acceleration = Vector3(x=0.0, y=0.0, z=9.81)
        imu_msg.linear_acceleration_covariance = [0.01, 0, 0, 0, 0.01, 0, 0, 0, 0.01]
        self.imu_pub.publish(imu_msg)

        # 3. Odometry (simulated drone position)
        odom_msg = Odometry()
        odom_msg.header.stamp = stamp
        odom_msg.header.frame_id = self.world_frame
        odom_msg.child_frame_id = self.drone_frame
        odom_msg.pose.pose.position.x = 0.0
        odom_msg.pose.pose.position.y = 0.0
        odom_msg.pose.pose.position.z = 2.0
        odom_msg.pose.pose.orientation = Quaternion(x=0.0, y=0.0, z=0.0, w=1.0)
        odom_msg.twist.twist.linear.x = 0.0
        odom_msg.twist.twist.linear.y = 0.0
        odom_msg.twist.twist.linear.z = 0.0
        self.odom_pub.publish(odom_msg)

        # 4. TF Transforms
        tf_msg = TFMessage()
        # world -> base_link
        t1 = TransformStamped()
        t1.header.stamp = stamp
        t1.header.frame_id = self.world_frame
        t1.child_frame_id = self.drone_frame
        t1.transform.translation.x = 0.0
        t1.transform.translation.y = 0.0
        t1.transform.translation.z = 2.0
        t1.transform.rotation = Quaternion(x=0.0, y=0.0, z=0.0, w=1.0)
        tf_msg.transforms.append(t1)

        # base_link -> camera_link
        t2 = TransformStamped()
        t2.header.stamp = stamp
        t2.header.frame_id = self.drone_frame
        t2.child_frame_id = self.frame_id
        t2.transform.translation.x = 0.1
        t2.transform.translation.y = 0.0
        t2.transform.translation.z = -0.05
        t2.transform.rotation = Quaternion(x=0.0, y=0.0, z=0.0, w=1.0)
        tf_msg.transforms.append(t2)

        self.tf_pub.publish(tf_msg)

    def _create_camera_info(self, width, height, stamp):
        """Create CameraInfo message."""
        fx = width / (2 * np.tan(np.radians(90) / 2))
        fy = fx
        cx = width / 2
        cy = height / 2

        cam_info = CameraInfo()
        cam_info.header.stamp = stamp
        cam_info.header.frame_id = self.frame_id
        cam_info.width = width
        cam_info.height = height
        cam_info.distortion_model = "plumb_bob"
        cam_info.d = [0.0, 0.0, 0.0, 0.0, 0.0]
        cam_info.k = [float(fx), 0.0, float(cx), 0.0, float(fy), float(cy), 0.0, 0.0, 1.0]
        cam_info.r = [1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0]
        cam_info.p = [
            float(fx),
            0.0,
            float(cx),
            0.0,
            0.0,
            float(fy),
            float(cy),
            0.0,
            0.0,
            0.0,
            1.0,
            0.0,
        ]
        return cam_info


def main():
    """Main entry point for Isaac Sim script."""
    # Initialize ROS2
    rclpy.init()

    try:
        node = IsaacSimROS2BridgeTest()
        node.setup_camera()

        # Spin in background - Isaac Sim handles the main loop
        # In Isaac Sim, we need to integrate with the simulation loop
        import asyncio

        async def spin_ros2():
            while rclpy.ok():
                rclpy.spin_once(node, timeout_sec=0.0)
                await asyncio.sleep(0.0)

        # Schedule ROS2 spin
        asyncio.ensure_future(spin_ros2())

        node.get_logger().info("Bridge test running. Check ROS2 topics with: ros2 topic list")

    except Exception as e:
        print(f"Error: {e}")
    finally:
        # Note: In Isaac Sim, don't call rclpy.shutdown() as it may crash the simulator
        pass


if __name__ == "__main__":
    main()
