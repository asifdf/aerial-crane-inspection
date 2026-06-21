#!/usr/bin/env python3
"""
Pegasus AI — Isaac Sim ROS2 Bridge Test
=========================================
Minimal test using the official NVIDIA Isaac Sim ROS2 bridge API.
Exactly follows the pattern from isaacsim/standalone_examples/api/isaacsim.ros2.bridge/camera_periodic.py

Run:   export OMNI_KIT_ALLOW_ROOT=1; export ROS_DISTRO=humble; export RMW_IMPLEMENTATION=rmw_fastrtps_cpp; export LD_LIBRARY_PATH=/workspace/isaacsim/exts/isaacsim.ros2.bridge/humble/lib; /workspace/isaacsim/isaac-sim.sh -p /workspaces/pegasus_ws/scripts/isaac_sim_pegasus_test.py

View on VNC: localhost:5900
Check ROS2 topics (separate terminal after sourcing ROS2): ros2 topic list | grep pegasus
"""

import sys

from isaacsim import SimulationApp

CAMERA_STAGE_PATH = "/Camera"
ROS_CAMERA_GRAPH_PATH = "/ROS_CameraGraph"
BACKGROUND_STAGE_PATH = "/background"
BACKGROUND_USD_PATH = "/Isaac/Environments/Simple_Warehouse/warehouse_with_forklifts.usd"

CONFIG = {"renderer": "RayTracedLighting", "headless": False}

simulation_app = SimulationApp(CONFIG)

import carb
import omni
import omni.graph.core as og
import usdrt.Sdf
from isaacsim.core.api import SimulationContext
from isaacsim.core.utils import extensions, stage
from isaacsim.storage.native import get_assets_root_path
from omni.kit.viewport.utility import get_active_viewport
from pxr import Gf, UsdGeom

# Enable ROS2 bridge
extensions.enable_extension("isaacsim.ros2.bridge")
simulation_app.update()

simulation_context = SimulationContext(stage_units_in_meters=1.0)

# Locate assets
assets_root_path = get_assets_root_path()
if assets_root_path is None:
    carb.log_error("Could not find Isaac Sim assets folder")
    simulation_app.close()
    sys.exit(1)

carb.log_info(f"=== Pegasus AI: Assets at {assets_root_path} ===")
carb.log_info("ROS2 topics: /pegasus/rgb, /pegasus/depth, /pegasus/camera_info")
carb.log_info("View on VNC at localhost:5900")

# Load warehouse environment
stage.add_reference_to_stage(assets_root_path + BACKGROUND_USD_PATH, BACKGROUND_STAGE_PATH)

# Create a Camera prim
camera_prim = UsdGeom.Camera(
    omni.usd.get_context().get_stage().DefinePrim(CAMERA_STAGE_PATH, "Camera")
)
xform_api = UsdGeom.XformCommonAPI(camera_prim)
xform_api.SetTranslate(Gf.Vec3d(-1, 5, 1))
xform_api.SetRotate((90, 0, 0), UsdGeom.XformCommonAPI.RotationOrderXYZ)
camera_prim.GetHorizontalApertureAttr().Set(21)
camera_prim.GetVerticalApertureAttr().Set(16)
camera_prim.GetProjectionAttr().Set("perspective")
camera_prim.GetFocalLengthAttr().Set(24)
camera_prim.GetFocusDistanceAttr().Set(400)

simulation_app.update()

# Create ROS2 camera publisher graph (exact pattern from official example)
keys = og.Controller.Keys
(ros_camera_graph, _, _, _) = og.Controller.edit(
    {
        "graph_path": ROS_CAMERA_GRAPH_PATH,
        "evaluator_name": "push",
        "pipeline_stage": og.GraphPipelineStage.GRAPH_PIPELINE_STAGE_ONDEMAND,
    },
    {
        keys.CREATE_NODES: [
            ("OnTick", "omni.graph.action.OnTick"),
            ("createViewport", "isaacsim.core.nodes.IsaacCreateViewport"),
            ("getRenderProduct", "isaacsim.core.nodes.IsaacGetViewportRenderProduct"),
            ("setCamera", "isaacsim.core.nodes.IsaacSetCameraOnRenderProduct"),
            ("cameraHelperRgb", "isaacsim.ros2.bridge.ROS2CameraHelper"),
            ("cameraHelperInfo", "isaacsim.ros2.bridge.ROS2CameraInfoHelper"),
            ("cameraHelperDepth", "isaacsim.ros2.bridge.ROS2CameraHelper"),
        ],
        keys.CONNECT: [
            ("OnTick.outputs:tick", "createViewport.inputs:execIn"),
            ("createViewport.outputs:execOut", "getRenderProduct.inputs:execIn"),
            ("createViewport.outputs:viewport", "getRenderProduct.inputs:viewport"),
            ("getRenderProduct.outputs:execOut", "setCamera.inputs:execIn"),
            ("getRenderProduct.outputs:renderProductPath", "setCamera.inputs:renderProductPath"),
            ("setCamera.outputs:execOut", "cameraHelperRgb.inputs:execIn"),
            ("setCamera.outputs:execOut", "cameraHelperInfo.inputs:execIn"),
            ("setCamera.outputs:execOut", "cameraHelperDepth.inputs:execIn"),
            ("getRenderProduct.outputs:renderProductPath", "cameraHelperRgb.inputs:renderProductPath"),
            ("getRenderProduct.outputs:renderProductPath", "cameraHelperInfo.inputs:renderProductPath"),
            ("getRenderProduct.outputs:renderProductPath", "cameraHelperDepth.inputs:renderProductPath"),
        ],
        keys.SET_VALUES: [
            ("createViewport.inputs:viewportId", 0),
            ("cameraHelperRgb.inputs:frameId", "pegasus_camera"),
            ("cameraHelperRgb.inputs:topicName", "pegasus/rgb"),
            ("cameraHelperRgb.inputs:type", "rgb"),
            ("cameraHelperInfo.inputs:frameId", "pegasus_camera"),
            ("cameraHelperInfo.inputs:topicName", "pegasus/camera_info"),
            ("cameraHelperDepth.inputs:frameId", "pegasus_camera"),
            ("cameraHelperDepth.inputs:topicName", "pegasus/depth"),
            ("cameraHelperDepth.inputs:type", "depth"),
            ("setCamera.inputs:cameraPrim", [usdrt.Sdf.Path(CAMERA_STAGE_PATH)]),
        ],
    },
)

# Evaluate once to initialize publishers
og.Controller.evaluate_sync(ros_camera_graph)
simulation_app.update()

# Configure publish rates
viewport_api = get_active_viewport()
if viewport_api is not None:
    import omni.syntheticdata._syntheticdata as sd

    render_product = viewport_api.get_render_product_path()

    # RGB: every 5 frames
    rv_rgb = omni.syntheticdata.SyntheticData.convert_sensor_type_to_rendervar(sd.SensorType.Rgb.name)
    rgb_gate = omni.syntheticdata.SyntheticData._get_node_path(
        rv_rgb + "IsaacSimulationGate", render_product
    )
    og.Controller.attribute(rgb_gate + ".inputs:step").set(5)

    # Depth: every 60 frames
    rv_depth = omni.syntheticdata.SyntheticData.convert_sensor_type_to_rendervar(
        sd.SensorType.DistanceToImagePlane.name
    )
    depth_gate = omni.syntheticdata.SyntheticData._get_node_path(
        rv_depth + "IsaacSimulationGate", render_product
    )
    og.Controller.attribute(depth_gate + ".inputs:step").set(60)

    # Camera info: every frame
    info_gate = omni.syntheticdata.SyntheticData._get_node_path(
        "PostProcessDispatch" + "IsaacSimulationGate", render_product
    )
    og.Controller.attribute(info_gate + ".inputs:step").set(1)

# Initialize and run
simulation_context.initialize_physics()
simulation_context.play()

frame_count = 0
while simulation_app.is_running():
    simulation_context.step(render=True)
    frame_count += 1

    # Rotate camera every 200 frames for varied views
    if frame_count % 200 == 0:
        import math
        angle = (frame_count // 200) * 30
        radius = 4.0
        x = radius * math.cos(math.radians(angle))
        y = radius * math.sin(math.radians(angle))
        xform_api.SetTranslate(Gf.Vec3d(x, y, 2.0))
        xform_api.SetRotate((90, angle, 0), UsdGeom.XformCommonAPI.RotationOrderXYZ)
        carb.log_info(f"[Pegasus] Frame {frame_count} — camera angle {angle}°")

simulation_context.stop()
simulation_app.close()
