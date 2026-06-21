#!/usr/bin/env python3
"""
Pegasus AI — Container Harbor Scene + Drone Spawn
==================================================
Loads warehouse, scatters SimReady shipping containers/pallets/drums,
and spawns the Iris drone for crane inspection testing.

Assets from: assets/container_harbor/ (SimReady Containers & Shipping 01 + 02)

Run via --exec:
    /workspace/isaacsim/isaac-sim.sh --allow-root \
      --ext-path .../pegasus.simulator --enable pegasus.simulator \
      --/isaac/startup/ros_bridge_extension=isaacsim.ros2.bridge \
      --exec /workspaces/pegasus_ws/scripts/setup_container_harbor.py
"""

import asyncio
import random
import os

import carb
import omni.kit.app
import numpy as np
from isaacsim.core.utils.extensions import enable_extension

enable_extension("pegasus.simulator")
enable_extension("isaacsim.ros2.bridge")
omni.kit.app.get_app().update()

from pegasus.simulator.logic.interface.pegasus_interface import PegasusInterface
from pegasus.simulator.logic.vehicles.multirotor import Multirotor, MultirotorConfig
from pegasus.simulator.logic.backends.ros2_backend import ROS2Backend
from pegasus.simulator.logic.graphical_sensors.monocular_camera import MonocularCamera
from scipy.spatial.transform import Rotation

# ── Reproducibility ───────────────────────────────────────────────────────
random.seed(42)

# ── Container Harbor Asset Paths ───────────────────────────────────────────
ASSETS_ROOT = "/workspaces/pegasus_ws/assets/container_harbor"
PROPS_ROOT = os.path.join(ASSETS_ROOT, "Assets/simready_content/common_assets/props")

# Key SimReady props for the scene
CONTAINER_PROPS = [
    # Shipping containers
    "container_a01/container_a01.usd",
    "container_a02/container_a02.usd",
    "container_a03/container_a03.usd",
    "container_a04/container_a04.usd",
    "container_b02/container_b02.usd",
    "container_b03/container_b03.usd",
    "container_b04/container_b04.usd",
    "container_c01/container_c01.usd",
    "container_c02/container_c02.usd",
    "container_c03/container_c03.usd",
    # Pallets
    "blockpallet_a01/blockpallet_a01.usd",
    "blockpallet_a02/blockpallet_a02.usd",
    "woodpalletcollarasm_a09/woodpalletcollarasm_a09.usd",
    "woodpalletcollarasm_a10/woodpalletcollarasm_a10.usd",
    # IBC tanks
    "ibctankheater_a01/ibctankheater_a01.usd",
    "stainlesssteelibctank_a01/stainlesssteelibctank_a01.usd",
    # Drums
    "steeldrum_a01/steeldrum_a01.usd",
    "steeldrum_a02/steeldrum_a02.usd",
    "plasticdrum_a01/plasticdrum_a01.usd",
    "plasticdrum_a02/plasticdrum_a02.usd",
    # Crates
    "plywoodcrate_a01/plywoodcrate_a01.usd",
    "standardwoodcrate_a01/standardwoodcrate_a01.usd",
    # Totes
    "tote_a01/tote_a01.usd",
    "tote_b01/tote_b01.usd",
]


def _prop_exists(rel_path: str) -> bool:
    return os.path.exists(os.path.join(PROPS_ROOT, rel_path))


async def spawn_drone():
    """Initialize world, load warehouse + container props, spawn drone."""

    carb.log_info("=" * 60)
    carb.log_info("Pegasus AI — Container Harbor Scene Setup")
    carb.log_info("=" * 60)

    # ── 1. PegasusInterface init ─────────────────────────────────────────
    pegasus_iface = PegasusInterface()
    pegasus_iface.initialize_world()
    world = pegasus_iface.world

    await world.initialize_simulation_context_async()
    carb.log_info("[1/5] Physics context ready")

    await world.reset_async()

    # ── 2. Load warehouse background ─────────────────────────────────────
    try:
        from isaacsim.storage.native import get_assets_root_path
        assets_root = get_assets_root_path()
        if assets_root:
            pegasus_iface.load_asset(
                assets_root + "/Isaac/Environments/Simple_Warehouse/warehouse_with_forklifts.usd",
                "/World/background",
            )
            carb.log_info("[2/5] Warehouse loaded")
    except Exception as exc:
        carb.log_warn(f"Warehouse load skipped — {exc}")

    await omni.kit.app.get_app().next_update_async()

    # ── 2.5. Load port cranes (OUTSIDE, not in warehouse) ──────────────
    stage = omni.usd.get_context().get_stage()
    from pxr import UsdGeom, Gf
    cranes_loaded = 0
    crane_assets_dir = "/workspaces/pegasus_ws/assets/cranes"
    cranes = [
        # (filename, prim_path, position, description, root_prim)
        # root_prim MUST be explicit: neither USD file sets defaultPrim metadata,
        # so AddReference(path) without a primPath silently produces a composition
        # error — the Xform prim is created but has no geometry children.
        ("container_crane.usd", "/World/container_crane_cc", (-25.0, -20.0, 0.0), "C/C Ship-to-Shore", "/ContainerCrane"),
        ("transfer_crane.usd", "/World/transfer_crane_tc", (15.0, -15.0, 0.0), "T/C RTG Transfer", "/TransferCrane"),
    ]
    for crane_file, prim_path, pos, desc, root_prim in cranes:
        crane_path = os.path.join(crane_assets_dir, crane_file)
        if not os.path.exists(crane_path):
            carb.log_warn(f"  Crane not found, skipping: {crane_file}")
            continue
        try:
            prim = stage.DefinePrim(prim_path, "Xform")
            # Pass the explicit primPath so USD knows which prim to compose.
            # Without this, missing defaultPrim causes a silent composition error.
            prim.GetReferences().AddReference(crane_path, root_prim)
            xform = UsdGeom.Xformable(prim)
            xform.AddTranslateOp().Set(Gf.Vec3d(*pos))
            cranes_loaded += 1
            carb.log_info(f"  {desc} crane loaded at {pos} (root: {root_prim})")
        except Exception as exc:
            carb.log_warn(f"  Failed to load {crane_file}: {exc}")
            import traceback
            traceback.print_exc()

    carb.log_info(f"[2.5/5] {cranes_loaded} cranes loaded (outdoor area)")
    # Two update frames: first lets USD resolve the reference arcs,
    # second lets the renderer register the new prims before we continue.
    await omni.kit.app.get_app().next_update_async()
    await omni.kit.app.get_app().next_update_async()

    # ── 3. Load container harbor props ───────────────────────────────────
    loaded_count = 0

    # Scatter layout: grid of containers spaced 3-5m apart
    container_spacing = 4.0
    rows = 3
    cols = 5
    base_x, base_y = -6.0, -8.0

    for i, prop_rel in enumerate(CONTAINER_PROPS):
        usd_path = os.path.join(PROPS_ROOT, prop_rel)
        if not _prop_exists(prop_rel):
            carb.log_warn(f"  Prop not found, skipping: {prop_rel}")
            continue

        # Distribute in grid with slight jitter
        row = i // cols
        col = i % cols
        x = base_x + col * container_spacing + random.uniform(-0.5, 0.5)
        y = base_y + row * container_spacing + random.uniform(-0.5, 0.5)
        z = 0.0  # warehouse floor

        prim_path = f"/World/container_prop_{i:03d}"
        try:
            stage.DefinePrim(prim_path, "Xform")
            stage.GetPrimAtPath(prim_path).GetReferences().AddReference(usd_path)

            # Set position
            from pxr import UsdGeom, Gf
            xform = UsdGeom.Xformable(stage.GetPrimAtPath(prim_path))
            xform_op = xform.AddTranslateOp()
            xform_op.Set(Gf.Vec3d(x, y, z))

            loaded_count += 1
        except Exception as exc:
            carb.log_warn(f"  Failed to load {prop_rel}: {exc}")

    carb.log_info(f"[3/5] {loaded_count} container props loaded")

    await omni.kit.app.get_app().next_update_async()

    # ── 4. ROS2 backend ─────────────────────────────────────────────────
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

    # ── 5. Drone config: Iris + downward-facing inspection camera ───────
    config_mr = MultirotorConfig()
    config_mr.backends = [backend]
    config_mr.graphical_sensors = [
        MonocularCamera(
            "inspection_camera",
            config={
                "depth": True,
                "position": np.array([0.0, 0.0, -0.15]),
                "orientation": np.array([0.0, 90.0, 0.0]),  # pitch 90° → points down
                "resolution": (640, 640),
                "frequency": 20,
            },
        )
    ]

    # ── 6. Spawn Iris quadrotor ─────────────────────────────────────────
    USD_FILE = (
        "/workspace/pegasus/PegasusSimulator/extensions/pegasus.simulator"
        "/pegasus/simulator/assets/Robots/Iris/iris.usd"
    )
    init_pos = [5.0, -2.0, 8.0]
    init_quat = Rotation.from_euler("XYZ", [0, 0, 0], degrees=True).as_quat()

    carb.log_info("[4/5] Spawning Iris drone at [5, -2, 8] m…")
    Multirotor(
        "/World/quadrotor",
        USD_FILE,
        vehicle_id=0,
        init_pos=init_pos,
        init_orientation=init_quat,
        config=config_mr,
    )

    # ── 7. Final reset ──────────────────────────────────────────────────
    await omni.kit.app.get_app().next_update_async()
    await world.reset_async()

    carb.log_info("[5/5] System ready!")
    carb.log_info("=" * 60)
    carb.log_info("Pegasus AI — Container Harbor Scene LIVE")
    carb.log_info(f"  Container props : {loaded_count}")
    carb.log_info("  Vehicle         : Iris quadrotor @ [5, -2, 8] m")
    carb.log_info("  Camera          : inspection_camera 640x640 20Hz (downward)")
    carb.log_info("")
    carb.log_info("  ROS2 topics (domain 42):")
    carb.log_info("    /pegasus/state/pose")
    carb.log_info("    /pegasus/state/twist")
    carb.log_info("    /pegasus/sensors/imu")
    carb.log_info("    /pegasus/inspection_camera/color/image_raw")
    carb.log_info("    /pegasus/inspection_camera/depth")
    carb.log_info("    /pegasus/inspection_camera/color/camera_info")
    carb.log_info("  Foxglove : ws://localhost:8765")
    carb.log_info("  VNC      : localhost:5900")
    carb.log_info("=" * 60)


def _on_spawn_done(task: asyncio.Task):
    """Log completion or propagate exceptions from the async spawn coroutine."""
    try:
        task.result()
    except Exception as exc:
        carb.log_error(f"Scene setup failed: {exc}")
        import traceback
        traceback.print_exc()


asyncio.ensure_future(spawn_drone()).add_done_callback(_on_spawn_done)
