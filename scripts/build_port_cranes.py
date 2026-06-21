#!/usr/bin/env python3
"""
Build port crane USD assets using pxr.UsdGeom primitives only.

Crane 1 - Ship-to-Shore Container Crane (C/C): ~70 m tall, ~80 m boom
Crane 2 - RTG Transfer Crane (T/C):            ~22 m tall, ~25 m straddle

Coordinate convention: Y-up, Z toward ship (seaward), X lateral.
"""

import os
from pxr import Usd, UsdGeom, Gf

OUTPUT_DIR = "/workspaces/pegasus_ws/assets/cranes"


def box(stage, prim_path, tx, ty, tz, sx, sy, sz, color):
    """Cube with translate + scale (half-extents) + display color."""
    p = stage.DefinePrim(prim_path, "Cube")
    xf = UsdGeom.Xformable(p)
    xf.AddTranslateOp().Set(Gf.Vec3d(tx, ty, tz))
    xf.AddScaleOp().Set(Gf.Vec3d(sx, sy, sz))
    UsdGeom.Gprim(p).GetDisplayColorAttr().Set([color])
    return p


def cyl(stage, prim_path, tx, ty, tz, radius, height, color,
        rx=0.0, ry=0.0, rz=0.0):
    """Cylinder (default axis Y). Scale maps to (radius, height/2, radius)."""
    p = stage.DefinePrim(prim_path, "Cylinder")
    xf = UsdGeom.Xformable(p)
    xf.AddTranslateOp().Set(Gf.Vec3d(tx, ty, tz))
    if rx or ry or rz:
        xf.AddRotateXYZOp().Set(Gf.Vec3d(rx, ry, rz))
    xf.AddScaleOp().Set(Gf.Vec3d(radius, height / 2.0, radius))
    UsdGeom.Gprim(p).GetDisplayColorAttr().Set([color])
    return p


def build_container_crane():
    """Ship-to-Shore gantry crane: ~70 m tall, boom ~80 m over water."""
    path = os.path.join(OUTPUT_DIR, "container_crane.usd")
    stage = Usd.Stage.CreateNew(path)
    stage.SetMetadata("upAxis", "Y")
    stage.SetMetadata("metersPerUnit", 1.0)
    stage.DefinePrim("/ContainerCrane", "Xform")
    R = "/ContainerCrane"

    GRAY   = (0.40, 0.40, 0.45)
    ORANGE = (1.00, 0.55, 0.00)
    BLUE   = (0.10, 0.30, 0.60)

    # Portal legs - 4 corners, 70 m tall
    leg_x, leg_z = 12.0, 8.0
    leg_w = leg_d = 1.5
    leg_h = 70.0
    for tag, x, z in [("FL", -leg_x,  leg_z), ("FR",  leg_x,  leg_z),
                       ("BL", -leg_x, -leg_z), ("BR",  leg_x, -leg_z)]:
        box(stage, f"{R}/Leg_{tag}",
            x, leg_h / 2, z,
            leg_w / 2, leg_h / 2, leg_d / 2, GRAY)

    # Sill beams (base frame)
    sill_h = 1.2
    for tag, z, sx in [("Front", leg_z, leg_x), ("Back", -leg_z, leg_x)]:
        box(stage, f"{R}/Sill_{tag}",
            0, sill_h / 2, z,
            sx, sill_h / 2, leg_d / 2, GRAY)
    for tag, x in [("Left", -leg_x), ("Right", leg_x)]:
        box(stage, f"{R}/Sill_{tag}",
            x, sill_h / 2, 0,
            leg_w / 2, sill_h / 2, leg_z, GRAY)

    # Main girder / boom: gray Z=-20->+45 (65m), orange tip Z=+45->+60 (15m)
    boom_y     = leg_h
    boom_h     = 3.0
    boom_w     = leg_x * 2     # 24 m
    gray_len   = 65.0
    orange_len = 15.0
    z_back     = -20.0
    z_front    = 60.0

    box(stage, f"{R}/MainGirder",
        0, boom_y + boom_h / 2, z_back + gray_len / 2,
        boom_w / 2, boom_h / 2, gray_len / 2, GRAY)
    box(stage, f"{R}/BoomTip",
        0, boom_y + boom_h / 2, z_front - orange_len / 2,
        boom_w / 2, boom_h / 2, orange_len / 2, ORANGE)

    # Machinery house (rear, on top of boom)
    mh_w, mh_h, mh_d = 20.0, 7.0, 12.0
    box(stage, f"{R}/MachineryHouse",
        0, boom_y + boom_h + mh_h / 2, z_back + mh_d / 2,
        mh_w / 2, mh_h / 2, mh_d / 2, GRAY)

    # Operator cabin (seaward, under boom)
    cab_w, cab_h, cab_d = 3.0, 3.5, 3.0
    box(stage, f"{R}/OperatorCabin",
        0, boom_y - cab_h / 2, 42.0,
        cab_w / 2, cab_h / 2, cab_d / 2, BLUE)

    # Trolley
    troll_w, troll_h, troll_d = 6.0, 2.0, 4.0
    troll_z = 22.0
    troll_y = boom_y - troll_h / 2
    box(stage, f"{R}/Trolley",
        0, troll_y, troll_z,
        troll_w / 2, troll_h / 2, troll_d / 2, GRAY)

    # Spreader (hangs 18 m below trolley)
    sp_w, sp_h, sp_d = 13.0, 0.8, 6.5
    sp_y = troll_y - 18.0
    box(stage, f"{R}/Spreader",
        0, sp_y, troll_z,
        sp_w / 2, sp_h / 2, sp_d / 2, ORANGE)

    # Hoist cables (4 vertical cylinders)
    cable_len   = troll_y - sp_y
    cable_mid_y = (troll_y + sp_y) / 2.0
    for tag, cx, cz_off in [
        ("LL", -(sp_w / 2 - 1.0), -(sp_d / 2 - 0.5)),
        ("LR", -(sp_w / 2 - 1.0),  (sp_d / 2 - 0.5)),
        ("RL",  (sp_w / 2 - 1.0), -(sp_d / 2 - 0.5)),
        ("RR",  (sp_w / 2 - 1.0),  (sp_d / 2 - 0.5)),
    ]:
        cyl(stage, f"{R}/Cable_{tag}",
            cx, cable_mid_y, troll_z + cz_off,
            0.12, cable_len, GRAY)

    stage.GetRootLayer().Save()
    # Set defaultPrim so AddReference(path) works without explicit primPath
    stage.SetDefaultPrim(stage.GetPrimAtPath("/ContainerCrane"))
    stage.GetRootLayer().Save()
    n = sum(1 for _ in stage.TraverseAll())
    print(f"[C/C] Container Crane  -> {n:3d} prims  ->  {path}")
    return n


def build_transfer_crane():
    """RTG rubber-tired gantry: ~22 m tall, ~25 m wide straddle."""
    path = os.path.join(OUTPUT_DIR, "transfer_crane.usd")
    stage = Usd.Stage.CreateNew(path)
    stage.SetMetadata("upAxis", "Y")
    stage.SetMetadata("metersPerUnit", 1.0)
    stage.DefinePrim("/TransferCrane", "Xform")
    R = "/TransferCrane"

    GRAY   = (0.40, 0.40, 0.45)
    ORANGE = (1.00, 0.55, 0.00)
    BLACK  = (0.10, 0.10, 0.10)
    BLUE   = (0.10, 0.30, 0.60)

    straddle = 25.0
    depth    = 8.0
    leg_h    = 18.0
    leg_w    = leg_d = 1.0
    lx = straddle / 2
    lz = depth / 2

    # Legs (4 corners, 18 m tall)
    for tag, x, z in [("FL", -lx,  lz), ("FR",  lx,  lz),
                       ("BL", -lx, -lz), ("BR",  lx, -lz)]:
        box(stage, f"{R}/Leg_{tag}",
            x, leg_h / 2, z,
            leg_w / 2, leg_h / 2, leg_d / 2, GRAY)

    # Upper cross-beams (fore/aft)
    for tag, z in [("Front", lz), ("Back", -lz)]:
        box(stage, f"{R}/CrossBeam_{tag}",
            0, leg_h, z,
            straddle / 2, 0.5, leg_d / 2, GRAY)

    # Main girder (straddle width + 1 m overhang each side)
    girder_y = leg_h + 1.0
    girder_h = 2.0
    box(stage, f"{R}/MainGirder",
        0, girder_y + girder_h / 2, 0,
        (straddle + 2.0) / 2, girder_h / 2, depth / 2, GRAY)

    # Orange end caps
    for tag, x in [("L", -(straddle / 2 + 1.0)), ("R", straddle / 2 + 1.0)]:
        box(stage, f"{R}/GirderCap_{tag}",
            x, girder_y + girder_h / 2, 0,
            0.75, girder_h / 2, depth / 2, ORANGE)

    # Trolley
    troll_w, troll_h, troll_d = 4.0, 1.5, 3.5
    troll_y = girder_y - troll_h / 2
    box(stage, f"{R}/Trolley",
        0, troll_y, 0,
        troll_w / 2, troll_h / 2, troll_d / 2, GRAY)

    # Spreader (hangs 8 m below trolley)
    sp_drop = 8.0
    sp_y    = troll_y - sp_drop
    sp_w, sp_h, sp_d = straddle * 0.65, 0.5, 6.0
    box(stage, f"{R}/Spreader",
        0, sp_y, 0,
        sp_w / 2, sp_h / 2, sp_d / 2, ORANGE)

    # Hoist cables (4 vertical)
    cable_len   = sp_drop
    cable_mid_y = troll_y - sp_drop / 2.0
    for tag, cx, cz in [
        ("LL", -(sp_w / 2 - 1.0), -(sp_d / 2 - 0.5)),
        ("LR", -(sp_w / 2 - 1.0),  (sp_d / 2 - 0.5)),
        ("RL",  (sp_w / 2 - 1.0), -(sp_d / 2 - 0.5)),
        ("RR",  (sp_w / 2 - 1.0),  (sp_d / 2 - 0.5)),
    ]:
        cyl(stage, f"{R}/Cable_{tag}",
            cx, cable_mid_y, cz,
            0.10, cable_len, GRAY)

    # Operator cabin (top of girder, starboard end)
    cab_w, cab_h, cab_d = 2.5, 2.0, 2.5
    box(stage, f"{R}/OperatorCabin",
        straddle / 2 - 1.5, girder_y + girder_h + cab_h / 2, 0,
        cab_w / 2, cab_h / 2, cab_d / 2, BLUE)

    # Rubber wheels (8 tires, 2 per corner, fore/aft)
    # Crane travels in Z; axle along X -> rotate Y-cylinder 90 deg about Z
    wheel_r = 0.6
    tire_w  = 0.45
    wheel_y = wheel_r
    wz_off  = 1.4

    for leg_tag, lx_pos, lz_pos in [("FL", -lx,  lz), ("FR",  lx,  lz),
                                      ("BL", -lx, -lz), ("BR",  lx, -lz)]:
        for wt, sign in [("F", 1), ("B", -1)]:
            cyl(stage, f"{R}/Wheel_{leg_tag}_{wt}",
                lx_pos, wheel_y, lz_pos + sign * wz_off,
                wheel_r, tire_w, BLACK, rz=90.0)

    stage.GetRootLayer().Save()
    # Set defaultPrim so AddReference(path) works without explicit primPath
    stage.SetDefaultPrim(stage.GetPrimAtPath("/TransferCrane"))
    stage.GetRootLayer().Save()
    n = sum(1 for _ in stage.TraverseAll())
    print(f"[T/C] Transfer Crane   -> {n:3d} prims  ->  {path}")
    return n


if __name__ == "__main__":
    os.makedirs(OUTPUT_DIR, exist_ok=True)
    print(f"\nGenerating port crane USD assets\nOutput: {OUTPUT_DIR}\n")
    c1 = build_container_crane()
    c2 = build_transfer_crane()
    print(f"\nDone. Total prims across both files: {c1 + c2}")
