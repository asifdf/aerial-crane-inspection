#!/usr/bin/env python3
"""
Pegasus AI — Spawn Iris Drone (exec mode for already-running Isaac Sim)
=======================================================================
Use with --exec flag when Isaac Sim is already running as a GUI app.
Does NOT create a SimulationApp — uses the existing one.

Run:
    export DISPLAY=:1 OMNI_KIT_ALLOW_ROOT=1
    export ROS_DISTRO=humble RMW_IMPLEMENTATION=rmw_fastrtps_cpp
    export LD_LIBRARY_PATH=/workspace/isaacsim/exts/isaacsim.ros2.bridge/humble/lib
    export ROS_DOMAIN_ID=42

    /workspace/isaacsim/isaac-sim.sh --allow-root \
      --ext-path /workspace/pegasus/PegasusSimulator/extensions/pegasus.simulator \
      --enable pegasus.simulator \
      --/isaac/startup/ros_bridge_extension=isaacsim.ros2.bridge \
      --exec /workspaces/pegasus_ws/scripts/spawn_pegasus_drone.py

Root-cause of the crash
-----------------------
When running via --exec (GUI/extension mode), ISAAC_LAUNCHED_FROM_TERMINAL=True
so the SimulationContext __init__ skips _init_stage() and leaves
_physics_context=None.  world.reset() (sync) then dies on
    _physics_context._physx_interface  ->  AttributeError: NoneType

Fix: drive everything through the async path
(initialize_simulation_context_async) which always calls _initialize_stage_async
and creates a real PhysicsContext.  We schedule the coroutine on Isaac Sim's
own event loop with asyncio.ensure_future() so the GUI keeps running.
"""

import asyncio
import numpy as np

import carb
import omni.kit.app
from isaacsim.core.utils.extensions import enable_extension

# Enable extensions (idempotent if already loaded)
enable_extension("pegasus.simulator")
enable_extension("isaacsim.ros2.bridge")
omni.kit.app.get_app().update()

# Top-level imports after extensions are enabled
from pegasus.simulator.logic.interface.pegasus_interface import PegasusInterface
from pegasus.simulator.logic.vehicles.multirotor import Multirotor, MultirotorConfig
from pegasus.simulator.logic.backends.ros2_backend import ROS2Backend
from pegasus.simulator.logic.graphical_sensors.monocular_camera import MonocularCamera
from scipy.spatial.transform import Rotation


async def spawn_drone():
    """
    Mirror the Pegasus UI flow:
      1. initialize_world()          – stores World singleton in PegasusInterface
      2. initialize_simulation_context_async()  – creates PhysicsContext (THE FIX)
      3. reset_async()               – brings physics online
      4. load environment USD
      5. construct Multirotor        – Vehicle.__init__ calls PegasusInterface().world.stage (now safe)
      6. reset_async() again         – starts the simulation
    """

    carb.log_info("Pegasus: async spawn starting…")

    # ── 1. Give PegasusInterface a reference to the World singleton ──────────
    pegasus_iface = PegasusInterface()
    pegasus_iface.initialize_world()          # sets pegasus_iface._world = World.instance()
    world = pegasus_iface.world

    # ── 2. Initialize physics context (the key fix) ──────────────────────────
    # In GUI/extension mode _physics_context starts as None.
    # initialize_simulation_context_async() always calls _initialize_stage_async()
    # which creates the PhysicsContext and populates _physx_interface.
    await world.initialize_simulation_context_async()
    carb.log_info("Pegasus: physics context ready.")

    # ── 3. Reset so physics is in a clean, runnable state ───────────────────
    await world.reset_async()
    carb.log_info("Pegasus: world reset complete.")

    # ── 4. Load warehouse environment (optional, non-fatal) ─────────────────
    try:
        from isaacsim.storage.native import get_assets_root_path
        assets_root = get_assets_root_path()
        if assets_root:
            pegasus_iface.load_asset(
                assets_root + "/Isaac/Environments/Simple_Warehouse/warehouse_with_forklifts.usd",
                "/World/background",
            )
            carb.log_info("Pegasus: warehouse loaded.")
    except Exception as exc:
        carb.log_warn(f"Pegasus: warehouse load skipped — {exc}")

    await omni.kit.app.get_app().next_update_async()

    # ── 5. ROS2 backend ─────────────────────────────────────────────────────
    backend = ROS2Backend(
        vehicle_id=0,
        num_rotors=4,
        config={
            "namespace": "pegasus",
            "pub_pose": True,
            "pub_twist": True,
            "pub_accel": True,
            "pub_imu": True,
            "pub_mag": True,
            "pub_gps": True,
            "pub_graphical_sensors": True,
            "pub_sensors": True,
            "pub_state": True,
            "pub_tf": True,
            "sub_control": True,
        },
    )

    # ── 6. Drone config: Iris + downward-facing camera ───────────────────────
    config_mr = MultirotorConfig()
    config_mr.backends = [backend]
    config_mr.graphical_sensors = [
        MonocularCamera(
            "inspection_camera",
            config={
                "depth": True,
                "position": np.array([0.0, 0.0, -0.15]),
                "orientation": np.array([0.0, 90.0, 0.0]),   # pitch 90° → points down
                "resolution": (640, 640),
                "frequency": 20,
            },
        )
    ]

    # ── 7. Spawn Iris quadrotor ──────────────────────────────────────────────
    USD_FILE = (
        "/workspace/pegasus/PegasusSimulator/extensions/pegasus.simulator"
        "/pegasus/simulator/assets/Robots/Iris/iris.usd"
    )
    init_pos = [5.0, -2.0, 8.0]
    init_quat = Rotation.from_euler("XYZ", [0, 0, 0], degrees=True).as_quat()

    carb.log_info("Pegasus: spawning Iris drone at [5, -2, 8] m…")
    Multirotor(
        "/World/quadrotor",
        USD_FILE,
        vehicle_id=0,
        init_pos=init_pos,
        init_orientation=init_quat,
        config=config_mr,
    )
    carb.log_info("Pegasus: Iris drone spawned.")

    # ── 8. Final reset to start the simulation ───────────────────────────────
    await omni.kit.app.get_app().next_update_async()
    await world.reset_async()

    carb.log_info("=" * 60)
    carb.log_info("Pegasus AI — Drone is live!")
    carb.log_info("  Vehicle : Iris quadrotor  @ [5, -2, 8] m")
    carb.log_info("  Camera  : inspection_camera  640×640  20 Hz  pointing down")
    carb.log_info("")
    carb.log_info("  ROS2 topics (domain 42):")
    carb.log_info("    /pegasus/state/pose")
    carb.log_info("    /pegasus/state/twist")
    carb.log_info("    /pegasus/sensors/imu")
    carb.log_info("    /pegasus/inspection_camera/color/image_raw")
    carb.log_info("    /pegasus/inspection_camera/depth")
    carb.log_info("    /pegasus/inspection_camera/color/camera_info")
    carb.log_info("")
    carb.log_info("  Foxglove : ws://localhost:8765")
    carb.log_info("  VNC      : localhost:5900")
    carb.log_info("=" * 60)


# Schedule on Isaac Sim's Kit event loop.
# The exec script returns immediately; the coroutine runs in the next
# event-loop tick while the GUI stays open.
asyncio.ensure_future(spawn_drone())
