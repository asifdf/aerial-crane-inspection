"""
Pegasus AI — Full Drone Stack Bringup
======================================
Launches the complete simulation stack:
  1. PX4 SITL (flight controller) — started separately
  2. MAVROS (MAVLink↔ROS2 bridge)
  3. pegasus_ai nodes (offboard control + mission executor + inference)

Usage:
  # Terminal 1: Start PX4 SITL
  cd /workspace/PX4-Autopilot
  make px4_sitl none

  # Terminal 2: Launch full stack
  source /opt/ros/humble/setup.bash
  source /workspaces/pegasus_ws/ros2_ws/install/setup.bash
  ros2 launch pegasus_bringup drone_stack.launch.py

  # Terminal 3 (optional): Start inference
  ros2 run pegasus_ai inference_node --ros-args -p model_type:=mock
"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    # ── Arguments ──────────────────────────────────────────────────
    fcu_url = LaunchConfiguration("fcu_url", default="udp://:14540@localhost:14550")
    gcs_url = LaunchConfiguration("gcs_url", default="udp://:@localhost:14550")
    tgt_system = LaunchConfiguration("tgt_system", default="1")
    mission_file = LaunchConfiguration(
        "mission_file",
        default=os.path.join(
            get_package_share_directory("pegasus_bringup"),
            "../../../missions/crane_inspection_demo.yaml",
        ),
    )

    # ── MAVROS node ────────────────────────────────────────────────
    mavros_node = Node(
        package="mavros",
        executable="mavros_node",
        name="mavros",
        parameters=[
            {
                "fcu_url": fcu_url,
                "gcs_url": gcs_url,
                "tgt_system": tgt_system,
                "plugin_allowlist": [
                    "sys_status",
                    "command",
                    "setpoint_position",
                    "setpoint_raw",
                    "local_position",
                    "global_position",
                    "imu",
                    "param",
                    "home_position",
                    "manual_control",
                ],
            }
        ],
        output="screen",
        emulate_tty=True,
    )

    # ── Offboard control node ──────────────────────────────────────
    offboard_node = Node(
        package="pegasus_ai",
        executable="offboard_control",
        name="offboard_control",
        parameters=[
            {
                "takeoff_height": 8.0,
                "auto_arm": False,
            }
        ],
        output="screen",
        emulate_tty=True,
    )

    # ── Mission executor node ──────────────────────────────────────
    mission_node = Node(
        package="pegasus_ai",
        executable="mission_executor",
        name="mission_executor",
        parameters=[
            {
                "mission_file": "/workspaces/pegasus_ws/missions/crane_inspection_demo.yaml",
                "default_takeoff_height": 8.0,
                "waypoint_tolerance": 0.5,
                "auto_start": False,
            }
        ],
        output="screen",
        emulate_tty=True,
    )

    # ── AI Inference node (mock mode for testing) ──────────────────
    inference_node = Node(
        package="pegasus_ai",
        executable="inference_node",
        name="defect_inference",
        parameters=[
            {
                "model_type": "mock",
                "input_image_topic": "/drone/inspection_camera/color/image_raw",
                "output_detections_topic": "/pegasus/ai/defect_detections",
                "output_defect_array_topic": "/pegasus/ai/defect_array",
                "output_json_topic": "/pegasus/ai/defect_json",
                "output_health_topic": "/pegasus/ai/node_health",
                "max_publish_rate": 10.0,
            }
        ],
        output="screen",
        emulate_tty=True,
    )

    return LaunchDescription(
        [
            # Declare args
            DeclareLaunchArgument("fcu_url", default_value="udp://:14540@localhost:14550"),
            DeclareLaunchArgument("gcs_url", default_value="udp://:@localhost:14550"),
            DeclareLaunchArgument("tgt_system", default_value="1"),
            # Nodes
            mavros_node,
            offboard_node,
            mission_node,
            inference_node,
        ]
    )
