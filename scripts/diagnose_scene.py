#!/usr/bin/env python3
"""Diagnostic: check what's actually loaded in the scene."""
import carb
import omni

stage = omni.usd.get_context().get_stage()

carb.log_info("=" * 60)
carb.log_info("SCENE DIAGNOSTIC")
carb.log_info("=" * 60)

# Check all top-level prims
carb.log_info("\n--- World children ---")
world = stage.GetPrimAtPath("/World")
if world:
    for child in world.GetChildren():
        name = child.GetName()
        kind = child.GetTypeName()
        has_refs = bool(child.GetReferences().GetPrimPaths())
        carb.log_info(f"  {name}  [{kind}]  refs={has_refs}")

# Check cranes specifically
carb.log_info("\n--- Crane prims ---")
for crane_path in ["/World/container_crane_cc", "/World/transfer_crane_tc"]:
    prim = stage.GetPrimAtPath(crane_path)
    if prim:
        refs = prim.GetReferences().GetPrimPaths()
        children = list(prim.GetChildren())
        carb.log_info(f"  {crane_path}: {len(children)} children, refs={refs}")
    else:
        carb.log_error(f"  {crane_path}: NOT FOUND")

# Check drone
carb.log_info("\n--- Drone ---")
drone = stage.GetPrimAtPath("/World/quadrotor")
if drone:
    children = list(drone.GetChildren())
    carb.log_info(f"  quadrotor: {len(children)} children")
else:
    carb.log_error("  quadrotor: NOT FOUND")

# Move viewport to overview
try:
    from omni.kit.viewport.utility import get_active_viewport
    from pxr import UsdGeom, Gf
    vp = get_active_viewport()
    if vp:
        cam_prim = stage.GetPrimAtPath("/OmniverseKit_Persp")
        if cam_prim:
            cam = UsdGeom.Camera(cam_prim)
            cam.GetFocalLengthAttr().Set(35)
            xform = UsdGeom.Xformable(cam_prim)
            # Clear existing ops
            for op in xform.GetOrderedXformOps():
                if op.GetOpName() == "xformOp:translate":
                    op.Set(Gf.Vec3d(0, -30, 20))
            carb.log_info("\n  Viewport: moved to overview [0, -30, 20]")
except Exception as e:
    carb.log_warn(f"  Viewport move failed: {e}")

carb.log_info("\n" + "=" * 60)
carb.log_info("Paste into Isaac Sim Script Editor and click Run")
carb.log_info("=" * 60)
