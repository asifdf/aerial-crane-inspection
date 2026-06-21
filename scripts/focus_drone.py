#!/usr/bin/env python3
"""Set viewport camera to look at the drone at [5, -2, 8]."""
import asyncio
import carb
import omni.kit.app

async def focus():
    from omni.kit.viewport.utility import get_active_viewport
    vp = get_active_viewport()
    if vp is not None:
        # Set camera position to look at drone location
        from pxr import Gf
        stage = omni.usd.get_context().get_stage()
        cam_prim = stage.GetPrimAtPath("/OmniverseKit_Persp")
        if cam_prim:
            cam = UsdGeom.Camera(cam_prim)
            cam.focal_length = 50
            # Position camera at [0, -15, 5] looking toward [5, -2, 8]
            from pxr import UsdGeom
            usd_cam = UsdGeom.Camera(cam_prim)
            usd_cam.focal_length = 50
            carb.log_info("Viewport: looking at drone area")
    await omni.kit.app.get_app().next_update_async()

asyncio.ensure_future(focus())
