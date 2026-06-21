"""
Aerial Crane Inspection — Full Drone Stack Bringup
====================================================
Launches the complete autonomy stack from AAS (upstream) + Isaac Sim integration.

Architecture:
  Isaac Sim (Pegasus) → PX4 SITL (:4560) → MAVROS → AAS actions → offboard → PX4
  Isaac Sim camera    → /camera/image_raw → inference_node (TensorRT YOLO)
  inference_node      → /detections        → offboard_control

Changes from upstream aerial-autonomy-stack:
  1. MAVROS fcu_url port 4560 (Pegasus default, upstream uses 14540)
  2. Camera input from ROS2 topic (upstream uses GStreamer UDP)
  3. LiDAR (kiss_icp) disabled — not needed for crane inspection
  4. Single-drone, no SwarmObs tracking (upstream supports multi-drone)
  5. Mission: crane_inspection_demo.yaml (upstream uses yalla.yaml swarm demo)

Usage:
  # Terminal 1: Start Isaac Sim with Pegasus drone
  export OMNI_KIT_ALLOW_ROOT=1 DISPLAY=:1
  /workspace/isaacsim/isaac-sim.sh --allow-root -p \\
    /workspace/aerial_ws/scripts/spawn_drone_px4.py

  # Terminal 2: Launch full autonomy stack
  export ROS_DOMAIN_ID=44
  source /opt/ros/humble/setup.bash
  source /workspace/aerial_ws/ros2_ws/install/setup.bash
  ros2 launch pegasus_bringup drone_stack.launch.py

  # Override mission:
  ros2 launch pegasus_bringup drone_stack.launch.py \\
    mission_file:=/workspace/aerial_ws/missions/crane_inspection_demo.yaml
"""

import os

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

# Default paths
_WORKSPACE = os.path.expanduser("/workspace/aerial_ws")


def generate_launch_description():
    # ── Arguments ──────────────────────────────────────────────────────
    fcu_url = LaunchConfiguration(
        "fcu_url",
        default="udp://:4560@localhost:14550",  # ← CHANGE #1: Pegasus port
    )
    gcs_url = LaunchConfiguration(
        "gcs_url", default="udp://:@localhost:14550"
    )
    tgt_system = LaunchConfiguration("tgt_system", default="1")
    drone_id = LaunchConfiguration("drone_id", default="1")
    camera_topic = LaunchConfiguration(
        "camera_topic",
        default="/drone/inspection_camera/color/image_raw",
    )
    model_type = LaunchConfiguration("model_type", default="mock")
    mission_file = LaunchConfiguration(
        "mission_file",
        default=os.path.join(_WORKSPACE, "missions", "crane_inspection_demo.yaml"),
    )

    # ── MAVROS node ────────────────────────────────────────────────────
    mavros_node = Node(
        package="mavros",
        executable="mavros_node",
        name="mavros",
        parameters=[{
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
        }],
        output="screen",
        emulate_tty=True,
    )

    # ── AAS: autopilot_interface (action server) ──────────────────────
    autopilot_interface_node = Node(
        package="autopilot_interface",
        executable="px4_interface",
        name="px4_interface",
        namespace=["Drone", drone_id],
        parameters=[{"use_sim_time": True}],
        output="screen",
        emulate_tty=True,
    )

    # ── AAS: offboard_control (setpoint computation) ──────────────────
    # CHANGE #4: ground_tracks subscription fires but unused (single drone)
    offboard_control_node = Node(
        package="offboard_control",
        executable="px4_offboard",
        name="offboard_control",
        namespace=["Drone", drone_id],
        parameters=[{"use_sim_time": True}],
        output="screen",
        emulate_tty=True,
    )

    # ── AAS: mission (conops executor) ────────────────────────────────
    mission_node = Node(
        package="mission",
        executable="mission",
        name="mission",
        namespace=["Drone", drone_id],
        parameters=[{
            "use_sim_time": True,
        }],
        arguments=["--conops", mission_file],
        output="screen",
        emulate_tty=True,
    )

    # ── pegasus_ai: inference_node (TensorRT YOLO) ────────────────────
    # CHANGE #2: subscribes to ROS2 camera topic from Isaac Sim
    # (upstream yolo_py uses GStreamer UDP, kept here because
    #  Isaac Sim camera output is ROS2-native)
    inference_node = Node(
        package="pegasus_ai",
        executable="inference_node",
        name="defect_inference",
        parameters=[{
            "model_type": model_type,
            "input_image_topic": camera_topic,
            "output_detections_topic": "/detections",
            "max_publish_rate": 20.0,
        }],
        output="screen",
        emulate_tty=True,
    )

    # CHANGE #3: kiss_icp (LiDAR odometry) — NOT launched
    # CHANGE #4: state_sharing (swarm) — NOT launched

    return LaunchDescription([
        # Declare args so they can be overridden from CLI
        DeclareLaunchArgument("fcu_url", default_value="udp://:4560@localhost:14550"),
        DeclareLaunchArgument("gcs_url", default_value="udp://:@localhost:14550"),
        DeclareLaunchArgument("tgt_system", default_value="1"),
        DeclareLaunchArgument("drone_id", default_value="1"),
        DeclareLaunchArgument("camera_topic", default_value="/drone/inspection_camera/color/image_raw"),
        DeclareLaunchArgument("model_type", default_value="mock"),
        DeclareLaunchArgument(
            "mission_file",
            default_value=os.path.join(_WORKSPACE, "missions", "crane_inspection_demo.yaml"),
        ),
        # Nodes
        mavros_node,
        autopilot_interface_node,
        offboard_control_node,
        mission_node,
        inference_node,
    ])
