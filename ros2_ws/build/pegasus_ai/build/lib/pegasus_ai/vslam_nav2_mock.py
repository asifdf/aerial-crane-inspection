#!/usr/bin/env python3
"""
Pegasus AI — VSLAM + Nav2 Mock Node for Crane Inspection
========================================================
Simulates Visual SLAM (ORB-SLAM3 style) and Nav2 path planning for
autonomous drone navigation to defect locations.

Publishes:
  /pegasus/vslam/pose        — estimated camera pose (PoseStamped)
  /pegasus/vslam/map_points  — tracked map points (PointCloud2)
  /pegasus/nav2/path         — planned inspection path (Path)
  /pegasus/nav2/goal         — current navigation goal (PoseStamped)

Subscribes:
  /pegasus0/inspection_camera/color/image_raw — drone camera (optional)
  /pegasus/ai/defect_json                     — defect detection results

Run:
  ros2 run pegasus_ai vslam_nav2_mock_node
"""

import json
import math
import random
import time

import numpy as np
import rclpy
from geometry_msgs.msg import Point, Pose, PoseStamped, Quaternion, TransformStamped
from nav_msgs.msg import Path
from rclpy.node import Node
from sensor_msgs.msg import Image, PointCloud2, PointField
from std_msgs.msg import Header, String
import struct


class VSLAMNav2MockNode(Node):
    """Mock VSLAM + Nav2 for crane inspection drone."""

    def __init__(self):
        super().__init__("vslam_nav2_mock")

        # ── Crane inspection waypoints (pre-defined for warehouse) ──────────
        self.inspection_waypoints = [
            # [x, y, z, yaw] — drone position and heading
            [5.0, -2.0, 8.0, 0.0],    # Starting position (drone spawn)
            [3.0, 1.0, 7.0, 45.0],    # Approach crane boom
            [0.0, 3.0, 6.0, 90.0],    # Side view of crane midsection
            [-2.0, 5.0, 7.0, 135.0],  # Rear view of crane
            [2.0, 6.0, 8.0, 180.0],   # Top-down view
            [5.0, 4.0, 6.0, -90.0],   # Opposite side
            [7.0, 0.0, 5.0, -45.0],   # Close-up of base
            [5.0, -2.0, 8.0, 0.0],    # Return to start
        ]
        self.current_waypoint_idx = 0
        self.current_pos = list(self.inspection_waypoints[0])
        self.map_points = []

        # ── Publishers ────────────────────────────────────────────────────
        self.pose_pub = self.create_publisher(PoseStamped, "/pegasus/vslam/pose", 10)
        self.map_pub = self.create_publisher(PointCloud2, "/pegasus/vslam/map_points", 10)
        self.path_pub = self.create_publisher(Path, "/pegasus/nav2/path", 10)
        self.goal_pub = self.create_publisher(PoseStamped, "/pegasus/nav2/goal", 10)

        # ── Subscribers ────────────────────────────────────────────────────
        self.camera_sub = self.create_subscription(
            Image, "/pegasus0/inspection_camera/color/image_raw",
            self._on_camera, 10
        )
        self.defect_sub = self.create_subscription(
            String, "/pegasus/ai/defect_json",
            self._on_defect, 10
        )

        # ── State ──────────────────────────────────────────────────────────
        self.camera_frame_count = 0
        self.tracked_features = []
        self.defect_locations = []
        self.navigation_mode = "patrol"  # patrol → approach_defect → return

        # ── Timers ─────────────────────────────────────────────────────────
        self.vslam_timer = self.create_timer(0.033, self._publish_vslam)   # ~30 Hz
        self.nav2_timer = self.create_timer(0.1, self._publish_nav2)       # ~10 Hz
        self.map_timer = self.create_timer(0.5, self._publish_map_points)  # ~2 Hz

        self.get_logger().info("VSLAM + Nav2 Mock Node started")
        self.get_logger().info("  Patrolling 8 inspection waypoints")
        self.get_logger().info(f"  Current: waypoint {self.current_waypoint_idx + 1}/8")

    # ── Callbacks ───────────────────────────────────────────────────────

    def _on_camera(self, msg: Image):
        """Simulate feature tracking from camera frames."""
        self.camera_frame_count += 1
        # Simulate 50-200 tracked features per frame
        n_features = random.randint(50, 200)
        self.tracked_features = [
            [random.uniform(0, 640), random.uniform(0, 640), random.uniform(1, 20)]
            for _ in range(n_features)
        ]

    def _on_defect(self, msg: String):
        """React to defect detections — navigate to them."""
        try:
            data = json.loads(msg.data)
            if data.get("detections") and len(data["detections"]) > 0:
                # Simulate a defect location near current position
                defect_pos = [
                    self.current_pos[0] + random.uniform(-0.5, 0.5),
                    self.current_pos[1] + random.uniform(-0.5, 0.5),
                    self.current_pos[2],
                ]
                self.defect_locations.append({
                    "position": defect_pos,
                    "class": data["detections"][0]["class_name"],
                    "confidence": data["detections"][0]["confidence"],
                    "timestamp": data["timestamp"],
                })

                # If not already approaching, switch to defect approach
                if self.navigation_mode == "patrol" and len(self.defect_locations) <= 3:
                    self.navigation_mode = "approach_defect"
                    self.get_logger().info(
                        f"⚠ Defect detected! Navigating to {defect_pos}"
                    )
        except (json.JSONDecodeError, KeyError):
            pass

    # ── Publishers ──────────────────────────────────────────────────────

    def _publish_vslam(self):
        """Publish estimated pose (interpolating between waypoints)."""
        # Interpolate toward next waypoint
        target = self.inspection_waypoints[self.current_waypoint_idx]
        step = 0.02
        self.current_pos = [
            self.current_pos[i] + (target[i] - self.current_pos[i]) * step
            for i in range(4)
        ]

        # Check if reached waypoint
        dist = math.sqrt(
            (self.current_pos[0] - target[0]) ** 2 +
            (self.current_pos[1] - target[1]) ** 2
        )
        if dist < 0.1:
            self.current_waypoint_idx = (self.current_waypoint_idx + 1) % len(
                self.inspection_waypoints
            )
            self.get_logger().info(
                f"  → Waypoint {self.current_waypoint_idx + 1}/8"
            )

        # Convert yaw to quaternion
        yaw_rad = math.radians(self.current_pos[3])
        q = self._euler_to_quaternion(0, 0, yaw_rad)

        pose_msg = PoseStamped()
        pose_msg.header = Header(stamp=self.get_clock().now().to_msg(), frame_id="map")
        pose_msg.pose.position = Point(
            x=self.current_pos[0],
            y=self.current_pos[1],
            z=self.current_pos[2],
        )
        pose_msg.pose.orientation = Quaternion(x=q[0], y=q[1], z=q[2], w=q[3])
        self.pose_pub.publish(pose_msg)

        # Feature count health
        if self.camera_frame_count % 100 == 0:
            self.get_logger().info(
                f"[VSLAM] {len(self.tracked_features)} features tracked | "
                f"Pos: ({self.current_pos[0]:.1f}, {self.current_pos[1]:.1f}, {self.current_pos[2]:.1f})"
            )

    def _publish_nav2(self):
        """Publish planned path and current goal."""
        # Build path from current position through remaining waypoints
        path_msg = Path()
        path_msg.header = Header(stamp=self.get_clock().now().to_msg(), frame_id="map")

        remaining = (
            self.inspection_waypoints[self.current_waypoint_idx:] +
            self.inspection_waypoints[:self.current_waypoint_idx]
        )
        for wp in remaining[:5]:  # Show next 5 waypoints
            pose = PoseStamped()
            pose.header = Header(stamp=self.get_clock().now().to_msg(), frame_id="map")
            pose.pose.position = Point(x=wp[0], y=wp[1], z=wp[2])
            yaw_r = math.radians(wp[3])
            q = self._euler_to_quaternion(0, 0, yaw_r)
            pose.pose.orientation = Quaternion(x=q[0], y=q[1], z=q[2], w=q[3])
            path_msg.poses.append(pose)
        self.path_pub.publish(path_msg)

        # Publish current navigation goal
        goal = self.inspection_waypoints[self.current_waypoint_idx]
        goal_msg = PoseStamped()
        goal_msg.header = Header(stamp=self.get_clock().now().to_msg(), frame_id="map")
        goal_msg.pose.position = Point(x=goal[0], y=goal[1], z=goal[2])
        yaw_r = math.radians(goal[3])
        q = self._euler_to_quaternion(0, 0, yaw_r)
        goal_msg.pose.orientation = Quaternion(x=q[0], y=q[1], z=q[2], w=q[3])
        self.goal_pub.publish(goal_msg)

    def _publish_map_points(self):
        """Publish simulated sparse map (ORB-SLAM3 style point cloud)."""
        if len(self.tracked_features) < 10:
            return

        # Generate structured map points around crane area
        points = []
        for _ in range(200):
            x = self.current_pos[0] + random.gauss(0, 2.0)
            y = self.current_pos[1] + random.gauss(0, 2.0)
            z = self.current_pos[2] + random.gauss(0, 1.0)
            points.extend([x, y, z])

        # Build PointCloud2 message (simplified)
        cloud_msg = PointCloud2()
        cloud_msg.header = Header(stamp=self.get_clock().now().to_msg(), frame_id="map")
        cloud_msg.height = 1
        cloud_msg.width = len(points) // 3
        cloud_msg.fields = [
            PointField(name="x", offset=0, datatype=PointField.FLOAT32, count=1),
            PointField(name="y", offset=4, datatype=PointField.FLOAT32, count=1),
            PointField(name="z", offset=8, datatype=PointField.FLOAT32, count=1),
        ]
        cloud_msg.point_step = 12
        cloud_msg.row_step = cloud_msg.point_step * cloud_msg.width
        cloud_msg.data = struct.pack(f"{len(points)}f", *points)
        cloud_msg.is_dense = True
        self.map_pub.publish(cloud_msg)

    @staticmethod
    def _euler_to_quaternion(roll, pitch, yaw):
        """Convert Euler angles to quaternion [x, y, z, w]."""
        cr, cp, cy = math.cos(roll / 2), math.cos(pitch / 2), math.cos(yaw / 2)
        sr, sp, sy = math.sin(roll / 2), math.sin(pitch / 2), math.sin(yaw / 2)
        return [
            sr * cp * cy - cr * sp * sy,
            cr * sp * cy + sr * cp * sy,
            cr * cp * sy - sr * sp * cy,
            cr * cp * cy + sr * sp * sy,
        ]


def main(args=None):
    rclpy.init(args=args)
    node = VSLAMNav2MockNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
