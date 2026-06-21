"""
Isaac Sim Replicator Advanced Synthetic Data Generation
Generates synthetic crane defect images with domain randomization.
Standalone mode: uses OpenCV/numpy only (no Isaac Sim required).
Outputs 640x640 images with YOLO format labels and metadata.

Defect classes:
    0 = crack (thin jagged lines)
    1 = corrosion (rust-colored spots/blobs)
    2 = paint_damage (irregular peeling patches)

Domain randomization includes:
    - 5 lighting modes: bright, overcast, dusk, dawn, shadowed
    - 8 camera angles with jitter
    - Crack shape variation (jaggedness, width, length)
    - Gaussian noise, blur, contrast variation

Usage:
    python scripts/isaac_sim_replicator_advanced.py [--num_images 100] [--output_dir ./dataset/synthetic]
"""

import argparse
import json
import math
import os
import random
import sys
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple

import cv2
import numpy as np

# ---------------------------------------------------------------------------
# Constants
# ---------------------------------------------------------------------------
SCRIPT_DIR = Path(__file__).resolve().parent
PROJECT_DIR = SCRIPT_DIR.parent
DEFAULT_OUTPUT_DIR = PROJECT_DIR / "dataset" / "synthetic"

IMAGE_SIZE = (640, 640)  # width, height

CLASS_NAMES = ["crack", "corrosion", "paint_damage"]
CLASS_ID_MAP = {name: idx for idx, name in enumerate(CLASS_NAMES)}

NUM_LIGHTING_MODES = 5  # bright, overcast, dusk, dawn, shadowed
NUM_CAMERA_ANGLES = 8

# Lighting presets: (label, intensity_factor, temperature, shadow_strength)
LIGHTING_MODES = [
    {"name": "bright",     "brightness": 1.0,  "contrast": 1.0,  "shadow": 0.0, "temperature_bias": 0},
    {"name": "overcast",   "brightness": 0.6,  "contrast": 0.7,  "shadow": 0.3, "temperature_bias": -500},
    {"name": "dusk",       "brightness": 0.4,  "contrast": 1.2,  "shadow": 0.5, "temperature_bias": 1500},
    {"name": "dawn",       "brightness": 0.5,  "contrast": 1.1,  "shadow": 0.4, "temperature_bias": 1000},
    {"name": "shadowed",   "brightness": 0.3,  "contrast": 0.9,  "shadow": 0.8, "temperature_bias": -200},
]

# 8 camera angle templates: (label, angle_x_offset, angle_y_offset, distance_factor)
CAMERA_ANGLES = [
    {"name": "front_center", "pan": 0,   "tilt": 0,  "dist": 1.0},
    {"name": "front_left",   "pan": -15, "tilt": 5,  "dist": 1.1},
    {"name": "front_right",  "pan": 15,  "tilt": 5,  "dist": 1.1},
    {"name": "side_left",    "pan": -30, "tilt": 10, "dist": 1.2},
    {"name": "side_right",   "pan": 30,  "tilt": 10, "dist": 1.2},
    {"name": "low_angle",    "pan": 0,   "tilt": 20, "dist": 1.0},
    {"name": "high_angle",   "pan": 0,   "tilt": -15,"dist": 0.9},
    {"name": "corner_view",  "pan": 45,  "tilt": 15, "dist": 1.3},
]

NOISE_STDDEV_RANGE = (0.005, 0.025)   # normalized 0-1
BLUR_KERNEL_RANGE = (0, 3)            # odd kernel sizes, 0 = no blur

# ---------------------------------------------------------------------------
# Domain randomization helpers
# ---------------------------------------------------------------------------

def random_lighting_mode() -> Dict[str, Any]:
    """Pick a random lighting mode and add small per-instance jitter."""
    mode = random.choice(LIGHTING_MODES).copy()
    mode["brightness"] *= random.uniform(0.85, 1.15)
    mode["contrast"] *= random.uniform(0.85, 1.15)
    mode["noise_std"] = random.uniform(*NOISE_STDDEV_RANGE)
    mode["blur_kernel"] = random.choice([0, 1, 3])
    return mode


def random_camera_angle() -> Dict[str, Any]:
    """Pick a random camera angle and add jitter."""
    angle = random.choice(CAMERA_ANGLES).copy()
    angle["pan"] += random.uniform(-5, 5)
    angle["tilt"] += random.uniform(-3, 3)
    angle["dist"] *= random.uniform(0.9, 1.1)
    return angle


def random_crack_shape() -> Dict[str, Any]:
    """Generate random parameters for a crack shape."""
    return {
        "num_segments": random.randint(3, 8),
        "jaggedness": random.uniform(0.3, 0.9),
        "width": random.uniform(1.5, 4.0),
        "length": random.uniform(20, 120),
        "curvature": random.uniform(-0.5, 0.5),
    }


def random_defect_params() -> Dict[str, Any]:
    """Generate random defect parameters for the current frame."""
    return {
        "num_cracks": random.randint(0, 4),
        "num_corrosion_spots": random.randint(0, 6),
        "num_paint_damage_areas": random.randint(0, 3),
        "corrosion_radius_range": (random.uniform(3, 8), random.uniform(10, 25)),
        "paint_damage_radius_range": (random.uniform(5, 12), random.uniform(15, 35)),
    }


# ---------------------------------------------------------------------------
# Image generation
# ---------------------------------------------------------------------------

def _metal_background(w: int, h: int) -> np.ndarray:
    """Generate a metal beam background image (grayscale, then convert to BGR)."""
    # Base steel color components (as plain Python ints to avoid uint8 overflow)
    b0, g0, r0 = 100, 110, 120  # BGR: blue-ish grey steel
    
    # Create image with slight gradient to simulate lighting
    img = np.full((h, w, 3), [b0, g0, r0], dtype=np.uint8)
    
    # Add horizontal beam texture (typical crane arm)
    for y in range(0, h, 4):
        shade = random.randint(-15, 15)
        cv2.line(img, (0, y), (w, y), 
                 (int(max(0, min(255, b0 + shade))),
                  int(max(0, min(255, g0 + shade))),
                  int(max(0, min(255, r0 + shade)))), 1)
    
    # Add rivet/bolt patterns (common on crane beams)
    for _ in range(random.randint(4, 12)):
        rx = random.randint(20, w - 20)
        ry = random.randint(20, h - 20)
        cv2.circle(img, (rx, ry), random.randint(2, 5), 
                   (80, 90, 100), -1)
        # Highlight around rivet
        cv2.circle(img, (rx, ry), random.randint(3, 7),
                   (130, 140, 150), 1)
    
    # Add subtle horizontal line patterns (beam ridges)
    for _ in range(random.randint(2, 5)):
        ry = random.randint(10, h - 10)
        cv2.line(img, (0, ry), (w, ry), (85, 95, 105), 1)
    
    # Add some random noise for texture
    noise = np.random.randint(-10, 11, (h, w, 3), dtype=np.int8)
    img = np.clip(img.astype(np.int16) + noise.astype(np.int16), 0, 255).astype(np.uint8)
    
    return img


def _draw_crack(img: np.ndarray, crack_params: Dict[str, Any]) -> List[Tuple[float, float, float, float]]:
    """
    Draw a single crack as a thin jagged line.
    Returns the bounding box (x_center, y_center, width, height) normalized.
    """
    h, w = img.shape[:2]
    
    num_seg = crack_params["num_segments"]
    jaggedness = crack_params["jaggedness"]
    crack_width = crack_params["width"]
    crack_len = crack_params["length"]
    curvature = crack_params["curvature"]
    
    # Start point
    margin = 30
    sx = random.randint(margin, w - margin)
    sy = random.randint(margin, h - margin)
    
    # Direction
    angle = random.uniform(0, 2 * math.pi)
    
    points = [(sx, sy)]
    seg_len = crack_len / num_seg
    
    for i in range(num_seg):
        px, py = points[-1]
        # Add jitter to direction
        jitter = random.uniform(-jaggedness, jaggedness) * math.pi * 0.4
        seg_angle = angle + jitter + curvature * (i / num_seg) * math.pi * 0.3
        nx = px + seg_len * math.cos(seg_angle)
        ny = py + seg_len * math.sin(seg_angle)
        # Stay within image bounds
        nx = max(margin, min(w - margin, nx))
        ny = max(margin, min(h - margin, ny))
        points.append((int(nx), int(ny)))
    
    # Draw the crack as a thick polyline with varying width
    color = (20, 20, 20)  # dark grey/black
    
    for i in range(len(points) - 1):
        width_variation = crack_width * random.uniform(0.6, 1.4)
        thickness = max(1, int(width_variation))
        cv2.line(img, points[i], points[i + 1], color, thickness)
        # Add thinner inner line for depth
        if thickness > 2:
            inner_color = (10, 10, 10)
            cv2.line(img, points[i], points[i + 1], inner_color, max(1, thickness - 1))
    
    # Add small branching cracks
    for _ in range(random.randint(0, 2)):
        branch_idx = random.randint(0, len(points) - 2)
        bp = points[branch_idx]
        branch_angle = angle + random.uniform(-1.5, 1.5)
        branch_len = crack_len * random.uniform(0.1, 0.3)
        bex = bp[0] + branch_len * math.cos(branch_angle)
        bey = bp[1] + branch_len * math.sin(branch_angle)
        bex = max(margin, min(w - margin, bex))
        bey = max(margin, min(h - margin, bey))
        cv2.line(img, bp, (int(bex), int(bey)), color, max(1, int(crack_width * 0.5)))
    
    # Compute bounding box from all points
    all_x = [p[0] for p in points]
    all_y = [p[1] for p in points]
    min_x = max(0, min(all_x) - int(crack_width * 3))
    max_x = min(w, max(all_x) + int(crack_width * 3))
    min_y = max(0, min(all_y) - int(crack_width * 3))
    max_y = min(h, max(all_y) + int(crack_width * 3))
    
    # Expand to ensure visibility
    box_w = max_x - min_x
    box_h = max_y - min_y
    if box_w < 10 or box_h < 5:
        return []  # too small, skip
    
    cx = (min_x + max_x) / 2 / w
    cy = (min_y + max_y) / 2 / h
    bw = box_w / w
    bh = box_h / h
    
    return [(cx, cy, bw, bh)]


def _draw_corrosion(img: np.ndarray, params: Dict[str, Any]) -> List[Tuple[float, float, float, float]]:
    """
    Draw corrosion as rust-colored spotted blobs.
    Returns list of (x_center, y_center, width, height) normalized.
    """
    h, w = img.shape[:2]
    boxes = []
    
    num_spots = params.get("num_corrosion_spots", 3)
    r_min, r_max = params.get("corrosion_radius_range", (3, 20))
    
    for _ in range(num_spots):
        cx = random.randint(10, w - 10)
        cy = random.randint(10, h - 10)
        radius = random.uniform(r_min, r_max)
        
        # Rust colors (BGR): orange-brown shades
        rust_base = (
            random.randint(40, 80),   # B
            random.randint(60, 130),  # G
            random.randint(120, 200), # R
        )
        
        # Draw multiple overlapping irregular circles for realistic corrosion
        for _ in range(random.randint(3, 8)):
            ox = int(cx + random.uniform(-radius * 0.6, radius * 0.6))
            oy = int(cy + random.uniform(-radius * 0.6, radius * 0.6))
            orad = random.uniform(radius * 0.3, radius * 0.8)
            color_variation = (
                random.randint(-20, 20),
                random.randint(-20, 20),
                random.randint(-20, 20),
            )
            color = (
                max(0, min(255, rust_base[0] + color_variation[0])),
                max(0, min(255, rust_base[1] + color_variation[1])),
                max(0, min(255, rust_base[2] + color_variation[2])),
            )
            cv2.circle(img, (ox, oy), int(orad), color, -1)
        
        # Compute bounding box
        min_x = max(0, cx - int(radius * 1.2))
        max_x = min(w, cx + int(radius * 1.2))
        min_y = max(0, cy - int(radius * 1.2))
        max_y = min(h, cy + int(radius * 1.2))
        
        box_w = max_x - min_x
        box_h = max_y - min_y
        if box_w < 5 or box_h < 5:
            continue
        
        boxes.append((
            (min_x + max_x) / 2 / w,
            (min_y + max_y) / 2 / h,
            box_w / w,
            box_h / h,
        ))
    
    return boxes


def _draw_paint_damage(img: np.ndarray, params: Dict[str, Any]) -> List[Tuple[float, float, float, float]]:
    """
    Draw paint damage as irregular peeling patches.
    Returns list of (x_center, y_center, width, height) normalized.
    """
    h, w = img.shape[:2]
    boxes = []
    
    num_areas = params.get("num_paint_damage_areas", 2)
    r_min, r_max = params.get("paint_damage_radius_range", (5, 30))
    
    for _ in range(num_areas):
        cx = random.randint(15, w - 15)
        cy = random.randint(15, h - 15)
        radius = random.uniform(r_min, r_max)
        
        # Paint damage exposes lighter/rusted metal underneath
        exposed_color = (
            random.randint(80, 130),   # B
            random.randint(100, 150),  # G
            random.randint(130, 180),  # R
        )
        
        # Create irregular polygon for peeling paint
        num_vertices = random.randint(5, 10)
        vertices = []
        for i in range(num_vertices):
            angle = 2 * math.pi * i / num_vertices + random.uniform(-0.3, 0.3)
            r = radius * random.uniform(0.6, 1.2)
            vx = int(cx + r * math.cos(angle))
            vy = int(cy + r * math.sin(angle))
            vertices.append([vx, vy])
        vertices = np.array(vertices, dtype=np.int32)
        
        # Fill the damaged area
        cv2.fillPoly(img, [vertices], exposed_color)
        
        # Add dark edge border (paint edge)
        cv2.polylines(img, [vertices], True, (50, 50, 50), max(1, int(radius * 0.1)))
        
        # Add some lighter spots inside (variation in exposed metal)
        for _ in range(random.randint(2, 5)):
            sx = cx + random.randint(-int(radius * 0.5), int(radius * 0.5))
            sy = cy + random.randint(-int(radius * 0.5), int(radius * 0.5))
            sr = random.randint(2, max(3, int(radius * 0.2)))
            lighter = (
                min(255, exposed_color[0] + 30),
                min(255, exposed_color[1] + 30),
                min(255, exposed_color[2] + 30),
            )
            cv2.circle(img, (sx, sy), sr, lighter, -1)
        
        # Compute bounding box
        min_x = max(0, cx - int(radius * 1.3))
        max_x = min(w, cx + int(radius * 1.3))
        min_y = max(0, cy - int(radius * 1.3))
        max_y = min(h, cy + int(radius * 1.3))
        
        box_w = max_x - min_x
        box_h = max_y - min_y
        if box_w < 5 or box_h < 5:
            continue
        
        boxes.append((
            (min_x + max_x) / 2 / w,
            (min_y + max_y) / 2 / h,
            box_w / w,
            box_h / h,
        ))
    
    return boxes


def apply_lighting(img: np.ndarray, lighting: Dict[str, Any]) -> np.ndarray:
    """Apply lighting mode effects to the image."""
    brightness = lighting["brightness"]
    contrast = lighting["contrast"]
    noise_std = lighting.get("noise_std", 0.01)
    blur_kernel = lighting.get("blur_kernel", 0)
    shadow = lighting.get("shadow", 0.0)
    
    # Apply brightness/contrast
    img_float = img.astype(np.float32)
    img_float = img_float * contrast + (brightness - 1.0) * 128
    img_float = np.clip(img_float, 0, 255)
    
    # Apply shadow effect (darken bottom portion of image)
    if shadow > 0:
        h, w = img_float.shape[:2]
        shadow_mask = np.ones((h, w), dtype=np.float32)
        for y in range(h):
            factor = 1.0 - shadow * 0.5 * (1 - y / h)
            shadow_mask[y, :] = factor
        for c in range(3):
            img_float[:, :, c] *= shadow_mask
    
    # Add Gaussian noise
    if noise_std > 0:
        noise = np.random.randn(*img_float.shape).astype(np.float32) * noise_std * 255
        img_float += noise
    
    img_float = np.clip(img_float, 0, 255).astype(np.uint8)
    
    # Apply Gaussian blur (simulate focus variation)
    if blur_kernel > 1 and blur_kernel % 2 == 1:
        img_float = cv2.GaussianBlur(img_float, (blur_kernel, blur_kernel), 0)
    
    return img_float


def generate_synthetic_image(
    image_id: int,
    defect_params: Optional[Dict[str, Any]] = None,
    lighting_params: Optional[Dict[str, Any]] = None,
    camera_params: Optional[Dict[str, Any]] = None,
) -> Dict[str, Any]:
    """
    Generate a synthetic crane defect image with OpenCV/numpy.
    
    Returns metadata dict including paths and per-image generation params.
    """
    w, h = IMAGE_SIZE
    
    if defect_params is None:
        defect_params = random_defect_params()
    if lighting_params is None:
        lighting_params = random_lighting_mode()
    if camera_params is None:
        camera_params = random_camera_angle()
    
    # Generate background: metal beam surface
    img = _metal_background(w, h)
    
    # Draw defects
    all_boxes = []  # (class_id, x_center, y_center, width, height)
    crack_shapes = []
    
    # Cracks (class 0)
    num_cracks = defect_params.get("num_cracks", 0)
    for _ in range(num_cracks):
        cs = random_crack_shape()
        crack_shapes.append(cs)
        boxes = _draw_crack(img, cs)
        for (cx, cy, bw, bh) in boxes:
            all_boxes.append((0, cx, cy, bw, bh))
    
    # Corrosion (class 1)
    boxes = _draw_corrosion(img, defect_params)
    for (cx, cy, bw, bh) in boxes:
        all_boxes.append((1, cx, cy, bw, bh))
    
    # Paint damage (class 2)
    boxes = _draw_paint_damage(img, defect_params)
    for (cx, cy, bw, bh) in boxes:
        all_boxes.append((2, cx, cy, bw, bh))
    
    # Apply lighting/domain randomization
    img = apply_lighting(img, lighting_params)
    
    # Ensure at least some defects per image
    if not all_boxes:
        # Force at least one defect
        fallback_params = {
            "num_cracks": 1,
            "num_corrosion_spots": 1,
            "num_paint_damage_areas": 1,
            "corrosion_radius_range": (5, 15),
            "paint_damage_radius_range": (8, 20),
        }
        # Add one crack
        cs = random_crack_shape()
        crack_shapes.append(cs)
        boxes = _draw_crack(img, cs)
        for (cx, cy, bw, bh) in boxes:
            all_boxes.append((0, cx, cy, bw, bh))
        # Add one corrosion
        boxes = _draw_corrosion(img, fallback_params)
        for (cx, cy, bw, bh) in boxes:
            all_boxes.append((1, cx, cy, bw, bh))
        # Add one paint damage
        boxes = _draw_paint_damage(img, fallback_params)
        for (cx, cy, bw, bh) in boxes:
            all_boxes.append((2, cx, cy, bw, bh))
    
    return img, all_boxes, defect_params, lighting_params, camera_params, crack_shapes


def generate_dataset(
    num_images: int = 100,
    output_dir: Optional[Path] = None,
) -> Dict[str, Any]:
    """
    Main function to generate the full synthetic dataset with metadata.
    
    Args:
        num_images: Number of images to generate.
        output_dir: Output directory (default: dataset/synthetic/ in project root).
    
    Returns:
        metadata dict with overall counts and per-image parameters.
    """
    if output_dir is None:
        output_dir = DEFAULT_OUTPUT_DIR
    
    images_dir = output_dir / "images"
    labels_dir = output_dir / "labels_yolo"
    masks_dir = output_dir / "masks"
    metadata_path = output_dir / "metadata.json"
    
    os.makedirs(images_dir, exist_ok=True)
    os.makedirs(labels_dir, exist_ok=True)
    os.makedirs(masks_dir, exist_ok=True)
    
    metadata: Dict[str, Any] = {
        "dataset": "crane_inspection_synthetic_advanced",
        "num_images": num_images,
        "classes": CLASS_NAMES,
        "class_id_map": CLASS_ID_MAP,
        "image_size": list(IMAGE_SIZE),
        "lighting_modes": [m["name"] for m in LIGHTING_MODES],
        "camera_angles": [a["name"] for a in CAMERA_ANGLES],
        "generation_params": {
            "description": "Advanced synthetic data generator with OpenCV-based rendering",
            "defect_types": CLASS_NAMES,
            "num_lighting_modes": NUM_LIGHTING_MODES,
            "num_camera_angles": NUM_CAMERA_ANGLES,
        },
        "samples": [],
        "class_counts": {name: 0 for name in CLASS_NAMES},
        "total_annotations": 0,
    }
    
    print(f"Generating {num_images} synthetic crane defect images ({IMAGE_SIZE[0]}x{IMAGE_SIZE[1]})...")
    
    for img_id in range(1, num_images + 1):
        defect_params = random_defect_params()
        lighting_params = random_lighting_mode()
        camera_params = random_camera_angle()
        
        img, all_boxes, dp, lp, cp, crack_shapes = generate_synthetic_image(
            image_id=img_id,
            defect_params=defect_params,
            lighting_params=lighting_params,
            camera_params=camera_params,
        )
        
        # Save image
        image_filename = f"frame_{img_id:06d}.png"
        image_path = images_dir / image_filename
        cv2.imwrite(str(image_path), img)
        
        # Write YOLO label file
        label_filename = f"frame_{img_id:06d}.txt"
        label_path = labels_dir / label_filename
        
        with open(label_path, "w") as f:
            for (class_id, cx, cy, bw, bh) in all_boxes:
                f.write(f"{class_id} {cx:.6f} {cy:.6f} {bw:.6f} {bh:.6f}\n")
        
        # Track class counts
        classes_present = []
        for (class_id, _, _, _, _) in all_boxes:
            class_name = CLASS_NAMES[class_id]
            classes_present.append(class_name)
            metadata["class_counts"][class_name] += 1
        metadata["total_annotations"] += len(all_boxes)
        
        # Create metadata entry
        entry = {
            "image_id": img_id,
            "image_filename": image_filename,
            "label_filename": label_filename,
            "lighting_mode": lp["name"],
            "camera_angle": cp["name"],
            "camera_params": {
                "pan": round(cp["pan"], 2),
                "tilt": round(cp["tilt"], 2),
                "dist": round(cp["dist"], 3),
            },
            "lighting_params": {
                "brightness": round(lp["brightness"], 3),
                "contrast": round(lp["contrast"], 3),
                "noise_std": round(lp["noise_std"], 4),
                "blur_kernel": lp["blur_kernel"],
                "shadow": round(lp["shadow"], 2),
            },
            "defect_params": {
                "num_cracks": dp["num_cracks"],
                "num_corrosion_spots": dp["num_corrosion_spots"],
                "num_paint_damage_areas": dp["num_paint_damage_areas"],
            },
            "num_annotations": len(all_boxes),
            "classes_present": list(set(classes_present)),
            "crack_shapes": [
                {
                    "num_segments": cs["num_segments"],
                    "jaggedness": round(cs["jaggedness"], 3),
                    "width": round(cs["width"], 2),
                    "length": round(cs["length"], 1),
                }
                for cs in crack_shapes
            ],
        }
        metadata["samples"].append(entry)
        
        if img_id % 20 == 0 or img_id == num_images:
            print(f"  Generated {img_id}/{num_images} samples ({len(all_boxes)} annotations)")
    
    # Write metadata
    with open(metadata_path, "w") as f:
        json.dump(metadata, f, indent=2)
    
    print(f"\nDone! Generated {num_images} images with {metadata['total_annotations']} total annotations.")
    print(f"Output directory: {output_dir}")
    print(f"Class distribution: {metadata['class_counts']}")
    
    return metadata


# ---------------------------------------------------------------------------
# Main entry point
# ---------------------------------------------------------------------------

def parse_args(argv: Optional[List[str]] = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Isaac Sim Replicator Advanced - Synthetic Crane Defect Data Generator"
    )
    parser.add_argument(
        "--num_images", type=int, default=100,
        help="Number of synthetic images to generate (default: 100)"
    )
    parser.add_argument(
        "--output_dir", type=str, default=None,
        help="Output directory (default: dataset/synthetic/ in project root)"
    )
    return parser.parse_args(argv)


def main(argv: Optional[List[str]] = None):
    args = parse_args(argv)
    output_dir = Path(args.output_dir) if args.output_dir else DEFAULT_OUTPUT_DIR
    generate_dataset(num_images=args.num_images, output_dir=output_dir)


if __name__ == "__main__":
    main()
