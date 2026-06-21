#!/usr/bin/env python3
"""Debug: step by step to find the crash point."""

import sys
import os

DEBUG = "/tmp/pegasus_debug.log"
def log(msg):
    with open(DEBUG, "a") as f:
        f.write(f"{msg}\n")

log("START")

from isaacsim import SimulationApp

CONFIG = {"renderer": "RayTracedLighting", "headless": False}
simulation_app = SimulationApp(CONFIG)
log("SimulationApp created")

import carb
log("carb imported")

from isaacsim.core.utils import extensions
log("extensions imported")

try:
    extensions.enable_extension("pegasus.simulator")
    log("pegasus.simulator enabled")
except Exception as e:
    log(f"FAIL enable pegasus: {e}")

try:
    extensions.enable_extension("isaacsim.ros2.bridge")
    log("ros2.bridge enabled")
except Exception as e:
    log(f"FAIL enable ros2: {e}")

simulation_app.update()
log("app updated")

try:
    from pegasus.simulator.logic.vehicles.multirotor import Multirotor, MultirotorConfig
    log("imported Multirotor")
except Exception as e:
    log(f"FAIL import Multirotor: {e}")
    simulation_app.close()
    sys.exit(1)

try:
    from pegasus.simulator.logic.backends.ros2_backend import ROS2Backend
    log("imported ROS2Backend")
except Exception as e:
    log(f"FAIL import ROS2Backend: {e}")

try:
    from pegasus.simulator.logic.graphical_sensors.monocular_camera import MonocularCamera
    log("imported MonocularCamera")
except Exception as e:
    log(f"FAIL import MonocularCamera: {e}")

try:
    from scipy.spatial.transform import Rotation
    log("imported Rotation")
except Exception as e:
    log(f"FAIL import Rotation: {e}")

# Try constructing
try:
    ros2_config = {
        "namespace": "pegasus",
        "pub_pose": True, "pub_twist": True, "pub_accel": True,
        "pub_imu": True, "pub_mag": True, "pub_gps": True,
        "pub_graphical_sensors": True, "pub_sensors": True,
        "pub_state": True, "pub_tf": True, "sub_control": True,
    }
    log("ros2_config created")
except Exception as e:
    log(f"FAIL ros2_config: {e}")

try:
    config_mr = MultirotorConfig()
    log("MultirotorConfig created")
except Exception as e:
    log(f"FAIL MultirotorConfig: {e}")

try:
    backend = ROS2Backend(vehicle_id=0, num_rotors=4, config=ros2_config)
    config_mr.backends = [backend]
    log(f"ROS2Backend created, vehicle_id={backend._id}")
except Exception as e:
    log(f"FAIL ROS2Backend init: {e}")

try:
    cam = MonocularCamera("inspection_camera", config={
        "depth": True,
        "position": [0.0, 0.0, -0.15],
        "orientation": [0.0, 90.0, 0.0],
        "resolution": (640, 640),
        "frequency": 20,
    })
    config_mr.graphical_sensors = [cam]
    log("MonocularCamera created")
except Exception as e:
    log(f"FAIL MonocularCamera: {e}")

USD_FILE = "/workspace/pegasus/PegasusSimulator/extensions/pegasus.simulator/pegasus/simulator/assets/Robots/Iris/iris.usd"
log(f"USD_FILE exists: {os.path.exists(USD_FILE)}")

try:
    from isaacsim.core.api import SimulationContext
    sim_context = SimulationContext(stage_units_in_meters=1.0)
    log("SimulationContext created")
except Exception as e:
    log(f"FAIL SimulationContext: {e}")

try:
    from isaacsim.storage.native import get_assets_root_path
    assets = get_assets_root_path()
    log(f"assets_root: {assets}")
except Exception as e:
    log(f"FAIL get_assets: {e}")

try:
    drone = Multirotor(
        "/World/quadrotor",
        USD_FILE,
        vehicle_id=0,
        init_pos=[5.0, -2.0, 8.0],
        init_orientation=Rotation.from_euler("XYZ", [0, 0, 0], degrees=True).as_quat(),
        config=config_mr,
    )
    log("MULTIROTOR SPAWNED SUCCESSFULLY")
except Exception as e:
    log(f"FAIL Multirotor spawn: {e}")
    import traceback
    log(traceback.format_exc())

simulation_app.update()
log("app updated after spawn")

# Main loop
try:
    carb.log_info("=" * 60)
    carb.log_info("Pegasus AI — Drone Spawned!")
    carb.log_info("ROS2 topics publishing...")
    carb.log_info("=" * 60)

    sim_context.initialize_physics()
    sim_context.play()
    log("physics initialized, entering loop")

    import math
    frame_count = 0
    while simulation_app.is_running():
        sim_context.step(render=True)
        frame_count += 1
        if frame_count % 600 == 0:
            carb.log_info(f"[{frame_count}] Running...")
            log(f"Frame {frame_count}")

    sim_context.stop()
    simulation_app.close()
except Exception as e:
    log(f"FAIL in main loop: {e}")
    import traceback
    log(traceback.format_exc())
