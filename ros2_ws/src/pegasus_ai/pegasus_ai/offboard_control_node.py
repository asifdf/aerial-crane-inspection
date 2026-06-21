"""
Pegasus AI — PX4 Offboard Control Node
=======================================
ROS2 node for commanding a PX4-controlled drone in OFFBOARD mode.

Architecture:
  PX4 SITL ← MAVLink → MAVROS ← ROS2 → offboard_control_node

Publishes:  /mavros/setpoint_position/local (geometry_msgs/PoseStamped) at 20 Hz
Subscribes: /mavros/state (mavros_msgs/State)
            /mavros/local_position/pose (geometry_msgs/PoseStamped)
Services:   /mavros/cmd/arming (mavros_msgs/CommandBool)
            /mavros/set_mode (mavros_msgs/SetMode)
            /mavros/cmd/takeoff (mavros_msgs/CommandTOL)

Usage:
  ros2 run pegasus_ai offboard_control
"""

import math
import time
from enum import Enum

import rclpy
from geometry_msgs.msg import PoseStamped
from mavros_msgs.msg import State
from mavros_msgs.srv import CommandBool, CommandTOL, SetMode
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy


class FlightPhase(Enum):
    IDLE = "idle"
    TAKEOFF = "takeoff"
    OFFBOARD = "offboard"
    LAND = "land"
    EMERGENCY = "emergency"


class OffboardControl(Node):
    """PX4 offboard control node via MAVROS."""

    def __init__(self):
        super().__init__("offboard_control")

        # ── Parameters ─────────────────────────────────────────────
        self.declare_parameter("takeoff_height", 5.0)
        self.declare_parameter("setpoint_rate", 20.0)
        self.declare_parameter("hover_position", [0.0, 0.0, 5.0])
        self.declare_parameter("auto_arm", False)

        self.takeoff_height = self.get_parameter("takeoff_height").value
        self.setpoint_rate = self.get_parameter("setpoint_rate").value
        self.hover_position = self.get_parameter("hover_position").value
        self.auto_arm = self.get_parameter("auto_arm").value

        # ── State ──────────────────────────────────────────────────
        self.current_state = State()
        self.current_pose = PoseStamped()
        self.phase = FlightPhase.IDLE
        self.target_position = self.hover_position.copy()
        self._state_received = False
        self._pose_received = False

        # ── Callback groups ─────────────────────────────────────────
        self._service_cb = MutuallyExclusiveCallbackGroup()

        # ── Subscribers ─────────────────────────────────────────────
        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        self.state_sub = self.create_subscription(
            State, "/mavros/state", self._state_callback, qos
        )
        self.pose_sub = self.create_subscription(
            PoseStamped, "/mavros/local_position/pose", self._pose_callback, qos
        )

        # ── Publisher: setpoint stream (must be ≥2 Hz for OFFBOARD) ─
        self.setpoint_pub = self.create_publisher(
            PoseStamped, "/mavros/setpoint_position/local", 10
        )

        # ── Service clients ─────────────────────────────────────────
        self.arming_client = self.create_client(
            CommandBool, "/mavros/cmd/arming", callback_group=self._service_cb
        )
        self.set_mode_client = self.create_client(
            SetMode, "/mavros/set_mode", callback_group=self._service_cb
        )
        self.takeoff_client = self.create_client(
            CommandTOL, "/mavros/cmd/takeoff", callback_group=self._service_cb
        )

        # ── Timers ──────────────────────────────────────────────────
        self._setpoint_timer = self.create_timer(
            1.0 / self.setpoint_rate, self._publish_setpoint
        )
        self._state_timer = self.create_timer(0.5, self._check_state)

        self.get_logger().info("OffboardControl node ready")
        self.get_logger().info(f"  Takeoff height: {self.takeoff_height}m")
        self.get_logger().info(f"  Auto arm: {self.auto_arm}")

    # ── Callbacks ──────────────────────────────────────────────────────

    def _state_callback(self, msg: State):
        self.current_state = msg
        self._state_received = True

    def _pose_callback(self, msg: PoseStamped):
        self.current_pose = msg
        self._pose_received = True

    def _publish_setpoint(self):
        """Stream setpoints at setpoint_rate. PX4 requires ≥2 Hz for OFFBOARD."""
        sp = PoseStamped()
        sp.header.stamp = self.get_clock().now().to_msg()
        sp.header.frame_id = "map"
        sp.pose.position.x = self.target_position[0]
        sp.pose.position.y = self.target_position[1]
        sp.pose.position.z = self.target_position[2]
        sp.pose.orientation.w = 1.0  # level flight
        self.setpoint_pub.publish(sp)

    def _check_state(self):
        """Periodic state machine check."""
        if not self._state_received:
            self.get_logger().warn("Waiting for /mavros/state...", throttle_duration_sec=5.0)
            return

        if self.auto_arm and self.phase == FlightPhase.IDLE:
            if self.current_state.connected and not self.current_state.armed:
                self.arm_and_takeoff()

    # ── Commands ────────────────────────────────────────────────────────

    def set_mode(self, mode: str, timeout: float = 5.0) -> bool:
        """Switch PX4 flight mode."""
        if not self.set_mode_client.wait_for_service(timeout_sec=2.0):
            self.get_logger().error("set_mode service unavailable")
            return False

        req = SetMode.Request()
        req.custom_mode = mode
        future = self.set_mode_client.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=timeout)
        result = future.result()
        if result and result.mode_sent:
            self.get_logger().info(f"Mode set to '{mode}'")
            return True
        self.get_logger().error(f"Failed to set mode '{mode}'")
        return False

    def arm(self, arm: bool = True) -> bool:
        """Arm or disarm the drone."""
        if not self.arming_client.wait_for_service(timeout_sec=2.0):
            self.get_logger().error("arming service unavailable")
            return False

        req = CommandBool.Request()
        req.value = arm
        future = self.arming_client.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        result = future.result()
        if result and result.success:
            self.get_logger().info(f"{'Armed' if arm else 'Disarmed'}")
            return True
        self.get_logger().error(f"Failed to {'arm' if arm else 'disarm'}")
        return False

    def takeoff(self, altitude: float | None = None) -> bool:
        """Takeoff to specified altitude."""
        alt: float = altitude if altitude is not None else self.takeoff_height

        if not self.takeoff_client.wait_for_service(timeout_sec=2.0):
            self.get_logger().error("takeoff service unavailable")
            return False

        req = CommandTOL.Request()
        req.altitude = float(altitude)
        req.latitude = 0.0
        req.longitude = 0.0
        req.min_pitch = 0.0
        req.yaw = 0.0

        future = self.takeoff_client.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=10.0)
        result = future.result()
        if result and result.success:
            self.get_logger().info(f"Takeoff to {altitude}m")
            return True
        self.get_logger().error("Takeoff failed")
        return False

    def arm_and_takeoff(self):
        """Full sequence: set OFFBOARD → arm → takeoff."""
        self.get_logger().info("Starting arm & takeoff sequence...")

        # Step 1: Stream setpoints already running via timer
        # Step 2: Switch to OFFBOARD
        if not self.set_mode("OFFBOARD"):
            return

        # Step 3: Arm
        if not self.arm(True):
            return

        # Step 4: Takeoff
        self.target_position = self.hover_position.copy()
        if self.takeoff(self.takeoff_height):
            self.phase = FlightPhase.TAKEOFF
            self.get_logger().info("Takeoff in progress...")

    def go_to(self, x: float, y: float, z: float, yaw: float = 0.0):
        """Set target position setpoint."""
        self.target_position = [x, y, z]
        self.phase = FlightPhase.OFFBOARD

    def land(self):
        """Switch to LAND mode."""
        self.phase = FlightPhase.LAND
        self.set_mode("AUTO.LAND")

    def emergency(self):
        """Emergency: disarm immediately (dangerous in flight, use LAND first)."""
        self.phase = FlightPhase.EMERGENCY
        self.arm(False)

    @property
    def is_armed(self) -> bool:
        return self.current_state.armed

    @property
    def is_offboard(self) -> bool:
        return self.current_state.mode == "OFFBOARD"

    @property
    def current_z(self) -> float:
        return self.current_pose.pose.position.z


def main():
    rclpy.init()
    node = OffboardControl()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
