#!/usr/bin/env python3
"""
Pegasus AI — Standalone Drone Stack (PX4 SITL + Isaac Sim)
============================================================
Spawns an Iris quadrotor with dual backend:
  - PX4MavlinkBackend  →  MAVLink flight control via PX4 SITL
  - ROS2Backend        →  camera/LiDAR sensor data to ROS2 topics

Architecture:
  Isaac Sim (physics) ←→ MAVLink (UDP port 14540) ←→ PX4 SITL (flight controller)
  Isaac Sim sensors   →  ROS2 topics (camera, depth, camera_info)

The Pegasus inference_node subscribes to these ROS2 topics for AI defect detection.

Based on the aerostack2/project_pegasus_isaac_sim dual-backend pattern.

Usage:
  export OMNI_KIT_ALLOW_ROOT=1 DISPLAY=:1
  export ROS_DISTRO=humble RMW_IMPLEMENTATION=rmw_fastrtps_cpp
  export LD_LIBRARY_PATH=/workspace/isaacsim/exts/isaacsim.ros2.bridge/humble/lib
  export ROS_DOMAIN_ID=42

  # Headless mode (standalone SimulationApp):
  /workspace/isaacsim/isaac-sim.sh --allow-root -p \\
    /workspaces/pegasus_ws/scripts/spawn_drone_px4.py \\
    --px4_dir /workspace/PX4-Autopilot

  # Exec mode (already-running Isaac Sim GUI):
  /workspace/isaacsim/isaac-sim.sh --allow-root \\
    --ext-path /workspace/pegasus/PegasusSimulator/extensions/pegasus.simulator \\
    --enable pegasus.simulator \\
    --/isaac/startup/ros_bridge_extension=isaacsim.ros2.bridge \\
    --exec /workspaces/pegasus_ws/scripts/spawn_drone_px4.py
"""

import argparse
import numpy as np

import carb
from isaacsim import SimulationApp

# ── Parse CLI args BEFORE SimulationApp (required for PX4 path) ──────────
parser = argparse.ArgumentParser(description="Pegasus AI — PX4 Drone Stack")
parser.add_argument(
    "--px4_dir",
    type=str,
    default="/workspace/PX4-Autopilot",
    help="Path to PX4-Autopilot directory",
)
parser.add_argument(
    "--headless",
    action="store_true",
    default=False,
    help="Run headless (no GUI)",
)
parser.add_argument(
    "--environment",
    type=str,
    default="container_harbor",
    help="Environment to load: container_harbor, curved_gridroom, warehouse",
)
cli_args, _ = parser.parse_known_args()

# ── Start SimulationApp ─────────────────────────────────────────────────
simulation_app = SimulationApp({"headless": cli_args.headless})

# Enable Pegasus extension (needed before importing pegasus modules)
from isaacsim.core.utils.extensions import enable_extension
enable_extension("pegasus.simulator")
import omni.kit.app
omni.kit.app.get_app().update()

import omni.timeline
from omni.isaac.core.world import World

from pegasus.simulator.logic.backends.px4_mavlink_backend import (
    PX4MavlinkBackend,
    PX4MavlinkBackendConfig,
)
from pegasus.simulator.logic.backends.ros2_backend import ROS2Backend
from pegasus.simulator.logic.graphical_sensors.monocular_camera import MonocularCamera
from pegasus.simulator.logic.interface.pegasus_interface import PegasusInterface
from pegasus.simulator.logic.vehicles.multirotor import Multirotor, MultirotorConfig
from pegasus.simulator.params import ROBOTS, SIMULATION_ENVIRONMENTS
from scipy.spatial.transform import Rotation


# ── Environment mapping ─────────────────────────────────────────────────
ENV_MAP = {
    "container_harbor": None,  # loaded from our USD scene
    "curved_gridroom": "Curved Gridroom",
    "warehouse": "Warehouse with Shelves",
    "simple_warehouse": "Simple Warehouse",
}


class PegasusDroneStack:
    """Standalone drone simulation with PX4 SITL flight controller."""

    def __init__(self, px4_dir: str, environment: str = "container_harbor"):
        self.timeline = omni.timeline.get_timeline_interface()
        self.pg = PegasusInterface()

        # Initialize world
        self.pg._world = World(**self.pg._world_settings)
        self.world = self.pg.world

        # Load environment
        env_key = ENV_MAP.get(environment)
        if env_key and env_key in SIMULATION_ENVIRONMENTS:
            self.pg.load_environment(SIMULATION_ENVIRONMENTS[env_key])
            carb.log_info(f"Pegasus: loaded environment '{env_key}'")
        elif environment == "container_harbor":
            self._load_container_harbor()
        else:
            carb.log_warn(f"Unknown environment '{environment}', using empty stage")

        # Reset after environment load
        self.world.reset()

        # ── Build drone configuration ───────────────────────────────────
        config_mr = MultirotorConfig()

        # Backend 1: PX4 Mavlink (flight control)
        # NOTE: px4_autolaunch=False — we use an external PX4 SITL running on UDP 14540.
        # The connection_baseport/connection_type must match the external PX4's MAVLink port.
        # If your external PX4 uses TCP lockstep on 4560, set:
        #   "connection_type": "tcpin", "connection_baseport": 4560
        mavlink_config = PX4MavlinkBackendConfig(
            {
                "vehicle_id": 0,
                "px4_autolaunch": False,
                "px4_dir": px4_dir,
                "px4_vehicle_model": "gazebo-classic_iris",
                "connection_type": "udpin",
                "connection_baseport": 14540,
            }
        )
        px4_backend = PX4MavlinkBackend(mavlink_config)

        # Backend 2: ROS2 (sensor data publishing)
        ros2_backend = ROS2Backend(
            vehicle_id=1,
            config={
                "namespace": "drone",
                "pub_sensors": False,
                "pub_graphical_sensors": True,
                "pub_state": False,
                "pub_tf": True,
                "sub_control": False,
            },
        )

        config_mr.backends = [px4_backend, ros2_backend]

        # ── Sensors ─────────────────────────────────────────────────────
        config_mr.graphical_sensors = [
            MonocularCamera(
                "inspection_camera",
                config={
                    "depth": True,
                    "position": np.array([0.10, 0.0, -0.15]),
                    "orientation": np.array([0.0, 90.0, 0.0]),  # pitch 90° = down
                    "resolution": (640, 640),
                    "frequency": 20,
                },
            )
        ]

        # ── Spawn Iris ──────────────────────────────────────────────────
        Multirotor(
            "/World/quadrotor",
            ROBOTS["Iris"],
            0,
            [0.0, 0.0, 0.07],
            Rotation.from_euler("XYZ", [0.0, 0.0, 0.0], degrees=True).as_quat(),
            config=config_mr,
        )

        # ── Final reset ─────────────────────────────────────────────────
        self.world.reset()
        self.stop_sim = False

        carb.log_info("=" * 60)
        carb.log_info("Pegasus AI — Standalone Drone Stack")
        carb.log_info(f"  Isaac Sim  : 5.1.0")
        carb.log_info(f"  PX4 SITL   : {px4_dir}")
        carb.log_info(f"  Vehicle    : Iris quadrotor")
        carb.log_info(f"  Camera     : inspection_camera 640×640 20 Hz ↓")
        carb.log_info("")
        carb.log_info("  Control via external PX4 SITL (MAVLink UDP port 14540):")
        carb.log_info("    - QGroundControl → connect UDP port 14550")
        carb.log_info("    - Offboard ROS2 nodes via px4_ros_com")
        carb.log_info("")
        carb.log_info("  Sensor ROS2 topics (namespace /drone):")
        carb.log_info("    /drone/inspection_camera/color/image_raw")
        carb.log_info("    /drone/inspection_camera/depth")
        carb.log_info("    /drone/inspection_camera/color/camera_info")
        carb.log_info("    /drone/tf")
        carb.log_info("")
        carb.log_info("  AI Inference subscribes to these topics for defect detection.")
        carb.log_info("=" * 60)

    def _load_container_harbor(self):
        """Load our custom container harbor scene."""
        scene_path = "/workspaces/pegasus_ws/scenes/container_harbor.usd"
        import os

        if os.path.exists(scene_path):
            try:
                self.pg.load_asset(scene_path, "/World/harbor")
                carb.log_info("Pegasus: loaded container harbor scene")
            except Exception as exc:
                carb.log_warn(f"Pegasus: harbor load failed ({exc}), using empty stage")
        else:
            carb.log_warn(f"No harbor scene at {scene_path}, using empty stage")

    def run(self):
        """Main simulation loop."""
        self.timeline.play()
        while simulation_app.is_running() and not self.stop_sim:
            self.world.step(render=True)

        carb.log_warn("Pegasus Drone Stack: simulation closing.")
        self.timeline.stop()
        simulation_app.close()


def main():
    pg_app = PegasusDroneStack(
        px4_dir=cli_args.px4_dir,
        environment=cli_args.environment,
    )
    pg_app.run()


if __name__ == "__main__":
    main()
