"""
Pegasus AI — Mission Executor Node
===================================
ROS2 node that executes crane inspection waypoint missions.

Flow:
  1. Take off to cruise altitude
  2. Navigate through waypoints (crane inspection positions)
  3. At each waypoint: pause, trigger AI inspection, wait for results
  4. Land when mission complete or on abort

Uses the offboard_control_node for flight commands.

Usage:
  ros2 run pegasus_ai mission_executor --ros-args -p mission_file:=/path/to/mission.yaml
"""

import json
import math
import time
from dataclasses import dataclass, field
from enum import Enum
from pathlib import Path
from typing import Optional

import rclpy
import yaml
from geometry_msgs.msg import PoseStamped
from mavros_msgs.msg import State
from mavros_msgs.srv import CommandBool, SetMode
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy
from std_msgs.msg import String


@dataclass
class Waypoint:
    """A single inspection waypoint."""
    x: float
    y: float
    z: float
    yaw: float = 0.0
    label: str = ""
    dwell_time: float = 3.0  # seconds to hover for inspection


@dataclass
class Mission:
    """Full inspection mission."""
    name: str = "default_mission"
    takeoff_height: float = 5.0
    cruise_speed: float = 2.0
    waypoint_tolerance: float = 0.5  # meters
    waypoints: list[Waypoint] = field(default_factory=list)


class MissionPhase(Enum):
    IDLE = "idle"
    ARMING = "arming"
    TAKEOFF = "takeoff"
    TRANSIT = "transit"
    INSPECT = "inspect"
    RETURN = "return"
    LAND = "land"
    COMPLETE = "complete"
    ABORTED = "aborted"


class MissionExecutor(Node):
    """Executes crane inspection missions via MAVROS offboard control."""

    def __init__(self):
        super().__init__("mission_executor")

        # ── Parameters ─────────────────────────────────────────────
        self.declare_parameter("mission_file", "")
        self.declare_parameter("default_takeoff_height", 5.0)
        self.declare_parameter("default_dwell_time", 3.0)
        self.declare_parameter("waypoint_tolerance", 0.5)
        self.declare_parameter("setpoint_rate", 20.0)
        self.declare_parameter("auto_start", False)

        mission_file = self.get_parameter("mission_file").value
        self.default_takeoff_height = self.get_parameter("default_takeoff_height").value
        self.default_dwell_time = self.get_parameter("default_dwell_time").value
        self.waypoint_tolerance = self.get_parameter("waypoint_tolerance").value
        self.setpoint_rate = self.get_parameter("setpoint_rate").value
        auto_start = self.get_parameter("auto_start").value

        # ── State ──────────────────────────────────────────────────
        self.mission: Optional[Mission] = None
        self.current_state = State()
        self.current_pose = PoseStamped()
        self.phase = MissionPhase.IDLE
        self._wp_index: int = 0
        self._inspection_start: float = 0.0
        self._inspection_done: bool = False
        self._state_received: bool = False
        self._pose_received: bool = False

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

        # ── Publisher: setpoint stream ──────────────────────────────
        self.setpoint_pub = self.create_publisher(
            PoseStamped, "/mavros/setpoint_position/local", 10
        )

        # ── Inspection trigger (to inference_node) ──────────────────
        self.inspect_trigger_pub = self.create_publisher(
            String, "/mission/inspect_trigger", 10
        )

        # ── Inspection result subscriber ────────────────────────────
        self.inspect_result_sub = self.create_subscription(
            String, "/pegasus/ai/defect_json", self._inspect_result_callback, 10
        )

        # ── Service clients ─────────────────────────────────────────
        self.arming_client = self.create_client(
            CommandBool, "/mavros/cmd/arming", callback_group=self._service_cb
        )
        self.set_mode_client = self.create_client(
            SetMode, "/mavros/set_mode", callback_group=self._service_cb
        )

        # ── Timers ──────────────────────────────────────────────────
        self._setpoint_timer = self.create_timer(
            1.0 / self.setpoint_rate, self._publish_setpoint
        )
        self._mission_timer = self.create_timer(0.5, self._mission_tick)

        # ── Load mission ────────────────────────────────────────────
        if mission_file:
            self.load_mission(mission_file)

        if auto_start and self.mission:
            self.start_mission()

        self.get_logger().info("MissionExecutor node ready")
        self.get_logger().info(f"  Mission file: {mission_file or 'none'}")
        self.get_logger().info(f"  Auto start: {auto_start}")

    # ── Callbacks ──────────────────────────────────────────────────────

    def _state_callback(self, msg: State):
        self.current_state = msg
        self._state_received = True

    def _pose_callback(self, msg: PoseStamped):
        self.current_pose = msg
        self._pose_received = True

    def _inspect_result_callback(self, msg: String):
        """Called when defect JSON is published."""
        self._inspection_done = True
        # Parse and log defect summary
        try:
            data = json.loads(msg.data)
            defects = data.get("defects", [])
            wp = self.current_waypoint
            self.get_logger().info(
                f"Inspection at '{wp.label}' complete: {len(defects)} defects found"
            )
        except (json.JSONDecodeError, KeyError):
            self.get_logger().info("Inspection result received")

    def _publish_setpoint(self):
        """Stream setpoints. PX4 requires ≥2 Hz for OFFBOARD."""
        if self.mission is None:
            return

        sp = PoseStamped()
        sp.header.stamp = self.get_clock().now().to_msg()
        sp.header.frame_id = "map"

        wp = self.current_waypoint
        if wp:
            sp.pose.position.x = wp.x
            sp.pose.position.y = wp.y
            sp.pose.position.z = wp.z
        else:
            # Hover at takeoff position
            sp.pose.position.x = 0.0
            sp.pose.position.y = 0.0
            sp.pose.position.z = self.mission.takeoff_height

        sp.pose.orientation.w = 1.0
        self.setpoint_pub.publish(sp)

    # ── Mission management ─────────────────────────────────────────────

    @property
    def current_waypoint(self) -> Optional[Waypoint]:
        if self.mission and 0 <= self._wp_index < len(self.mission.waypoints):
            return self.mission.waypoints[self._wp_index]
        return None

    def load_mission(self, path: str):
        """Load mission from YAML file."""
        mission_path = Path(path)
        if not mission_path.exists():
            self.get_logger().error(f"Mission file not found: {path}")
            return

        with open(mission_path) as f:
            data = yaml.safe_load(f)

        waypoints = []
        for wp_data in data.get("waypoints", []):
            waypoints.append(
                Waypoint(
                    x=wp_data["x"],
                    y=wp_data["y"],
                    z=wp_data["z"],
                    yaw=wp_data.get("yaw", 0.0),
                    label=wp_data.get("label", f"WP{len(waypoints)}"),
                    dwell_time=wp_data.get("dwell_time", self.default_dwell_time),
                )
            )

        self.mission = Mission(
            name=data.get("name", "default_mission"),
            takeoff_height=data.get("takeoff_height", self.default_takeoff_height),
            cruise_speed=data.get("cruise_speed", 2.0),
            waypoint_tolerance=data.get("waypoint_tolerance", self.waypoint_tolerance),
            waypoints=waypoints,
        )
        self.get_logger().info(
            f"Loaded mission '{self.mission.name}' with {len(waypoints)} waypoints"
        )

    def load_mission_dict(self, data: dict):
        """Load mission from a dictionary (for programmatic use)."""
        waypoints = [
            Waypoint(
                x=w["x"], y=w["y"], z=w["z"],
                yaw=w.get("yaw", 0.0),
                label=w.get("label", f"WP{i}"),
                dwell_time=w.get("dwell_time", self.default_dwell_time),
            )
            for i, w in enumerate(data.get("waypoints", []))
        ]
        self.mission = Mission(
            name=data.get("name", "programmatic_mission"),
            takeoff_height=data.get("takeoff_height", self.default_takeoff_height),
            cruise_speed=data.get("cruise_speed", 2.0),
            waypoint_tolerance=data.get("waypoint_tolerance", self.waypoint_tolerance),
            waypoints=waypoints,
        )
        self.get_logger().info(
            f"Loaded mission '{self.mission.name}' with {len(waypoints)} waypoints"
        )

    def start_mission(self):
        """Begin mission execution."""
        if self.mission is None:
            self.get_logger().error("No mission loaded")
            return
        self.phase = MissionPhase.ARMING
        self.get_logger().info(f"Starting mission: {self.mission.name}")

    def abort_mission(self):
        """Abort: land immediately."""
        self.phase = MissionPhase.ABORTED
        self.get_logger().warn("Mission ABORTED — landing")
        self._set_mode("AUTO.LAND")

    # ── Services ───────────────────────────────────────────────────────

    def _set_mode(self, mode: str) -> bool:
        if not self.set_mode_client.wait_for_service(timeout_sec=2.0):
            return False
        req = SetMode.Request()
        req.custom_mode = mode
        future = self.set_mode_client.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        result = future.result()
        return result is not None and result.mode_sent

    def _arm(self, arm: bool = True) -> bool:
        if not self.arming_client.wait_for_service(timeout_sec=2.0):
            return False
        req = CommandBool.Request()
        req.value = arm
        future = self.arming_client.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        result = future.result()
        return result is not None and result.success

    # ── Mission state machine ──────────────────────────────────────────

    def _mission_tick(self):
        """State machine executed at 2 Hz."""
        if self.mission is None:
            return
        if self.phase in (MissionPhase.IDLE, MissionPhase.COMPLETE, MissionPhase.ABORTED):
            return

        if not self._state_received:
            self.get_logger().warn("Waiting for /mavros/state...", throttle_duration_sec=5.0)
            return

        getattr(self, f"_tick_{self.phase.value}", lambda: None)()

    def _tick_arming(self):
        """Phase: arm and switch to OFFBOARD."""
        if not self.current_state.connected:
            return

        if not self.current_state.armed:
            self.get_logger().info("Switching to OFFBOARD + arming...")
            if self._set_mode("OFFBOARD"):
                if self._arm(True):
                    self.get_logger().info("Armed. Taking off...")
                    self.phase = MissionPhase.TAKEOFF

    def _tick_takeoff(self):
        """Phase: climb to takeoff height."""
        if not self.current_state.armed:
            self.get_logger().warn("Disarmed during takeoff — aborting")
            self.phase = MissionPhase.ABORTED
            return

        z = self.current_pose.pose.position.z
        target = self.mission.takeoff_height
        if z >= target - 0.3:
            self.get_logger().info(f"Takeoff complete ({z:.1f}m). Starting waypoints.")
            self._wp_index = 0
            self.phase = MissionPhase.TRANSIT

    def _tick_transit(self):
        """Phase: moving to next waypoint."""
        if not self.current_state.armed:
            self.phase = MissionPhase.ABORTED
            return

        wp = self.current_waypoint
        if wp is None:
            self.get_logger().info("All waypoints visited. Returning home.")
            self.phase = MissionPhase.RETURN
            return

        # Check if we've arrived
        dist = self._distance_to(wp)
        if dist < self.mission.waypoint_tolerance:
            self.get_logger().info(f"Arrived at '{wp.label}'. Starting inspection.")
            self._inspection_start = time.time()
            self._inspection_done = False
            self.phase = MissionPhase.INSPECT
            # Trigger inspection
            trigger = String()
            trigger.data = json.dumps({"waypoint": self._wp_index, "label": wp.label})
            self.inspect_trigger_pub.publish(trigger)

    def _tick_inspect(self):
        """Phase: hovering at waypoint, waiting for AI inspection."""
        wp = self.current_waypoint
        if wp is None:
            self.phase = MissionPhase.RETURN
            return

        elapsed = time.time() - self._inspection_start
        if elapsed >= wp.dwell_time or self._inspection_done:
            self.get_logger().info(f"Inspection complete at '{wp.label}' ({elapsed:.1f}s)")
            self._wp_index += 1
            self.phase = MissionPhase.TRANSIT if self._wp_index < len(self.mission.waypoints) else MissionPhase.RETURN

    def _tick_return(self):
        """Phase: return to home position."""
        if not self.current_state.armed:
            self.phase = MissionPhase.ABORTED
            return

        # Go to home (0,0,takeoff_height)
        dist = math.sqrt(
            self.current_pose.pose.position.x**2
            + self.current_pose.pose.position.y**2
        )
        if dist < 0.5:
            self.get_logger().info("Home position reached. Landing.")
            self.phase = MissionPhase.LAND
            self._set_mode("AUTO.LAND")

    def _tick_land(self):
        """Phase: landing."""
        z = self.current_pose.pose.position.z
        if z < 0.2:
            self._arm(False)
            self.phase = MissionPhase.COMPLETE
            self.get_logger().info("Mission COMPLETE. Drone disarmed.")

    # ── Helpers ────────────────────────────────────────────────────────

    def _distance_to(self, wp: Waypoint) -> float:
        p = self.current_pose.pose.position
        return math.sqrt((p.x - wp.x) ** 2 + (p.y - wp.y) ** 2 + (p.z - wp.z) ** 2)


def main():
    rclpy.init()
    node = MissionExecutor()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
