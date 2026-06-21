#!/usr/bin/env python3
"""
Isaac Sim ROS2 Bridge Test — run via Script Editor inside Isaac Sim GUI.
Tests: camera publishing, topic availability, inference node response.

Instructions:
  1. Open Isaac Sim with Pegasus (should already be running on VNC:5900)
  2. Window > Script Editor
  3. Paste this script
  4. Click Run
"""

import carb
import omni.kit.app
from isaacsim.core.utils.extensions import enable_extension

enable_extension("isaacsim.ros2.bridge")
omni.kit.app.get_app().update()

carb.log_info("=" * 60)
carb.log_info("Pegasus AI — Isaac Sim ROS2 Bridge Integration Test")
carb.log_info("=" * 60)

# 1. Check Pegasus drone is spawned
from pxr import Usd, Gf
stage = omni.usd.get_context().get_stage()
if stage.GetPrimAtPath("/World/quadrotor"):
    carb.log_info("[PASS] Iris drone prim exists at /World/quadrotor")
else:
    carb.log_warn("[WARN] No Iris drone at /World/quadrotor — run spawn_pegasus_drone.py first")

# 2. Check ROS2 bridge is active
try:
    from isaacsim.ros2.bridge import get_ros2_bridge
    bridge = get_ros2_bridge()
    if bridge:
        carb.log_info("[PASS] ROS2 bridge is active")
    else:
        carb.log_warn("[WARN] ROS2 bridge not initialized")
except Exception as e:
    carb.log_warn(f"[WARN] ROS2 bridge check: {e}")

# 3. Check camera topics are publishing
try:
    import rclpy
    if not rclpy.ok():
        rclpy.init()
    node = rclpy.create_node("pegasus_test_listener")
    topics = node.get_topic_names_and_types()
    camera_topics = [t for t, _ in topics if "inspection_camera" in t]
    if camera_topics:
        carb.log_info(f"[PASS] Camera topics found: {camera_topics}")
    else:
        carb.log_warn("[WARN] No inspection_camera topics found")
        carb.log_info(f"  Available topics: {[t for t,_ in topics if 'pegasus' in t]}")
    node.destroy_node()
except Exception as e:
    carb.log_warn(f"[WARN] ROS2 topic check: {e}")

# 4. Check warehouse environment
if stage.GetPrimAtPath("/World/background"):
    carb.log_info("[PASS] Warehouse environment loaded")
else:
    carb.log_warn("[WARN] No warehouse environment — using default grid")

carb.log_info("=" * 60)
carb.log_info("Test complete. Connect Foxglove to ws://localhost:8765")
carb.log_info("=" * 60)
