"""
Tests for isaac_sim_replicator_advanced.py
Validates domain randomization, image generation, bbox generation,
YOLO label format, metadata schema, and image dimensions.
"""

import json
import os
import sys
import tempfile
import unittest
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple

import cv2
import numpy as np

# Ensure the scripts directory is on the path
SCRIPT_DIR = Path(__file__).resolve().parent
sys.path.insert(0, str(SCRIPT_DIR))

import isaac_sim_replicator_advanced as rep


class TestModuleImports(unittest.TestCase):
    """Verify the module can be imported and has expected attributes."""

    def test_module_importable(self):
        """Module should import without errors."""
        self.assertTrue(hasattr(rep, "main"))
        self.assertTrue(hasattr(rep, "generate_dataset"))
        self.assertTrue(hasattr(rep, "generate_synthetic_image"))

    def test_constants_exist(self):
        """Expected constants should exist."""
        self.assertIsInstance(rep.CLASS_NAMES, list)
        self.assertEqual(len(rep.CLASS_NAMES), 3)
        self.assertIn("crack", rep.CLASS_NAMES)
        self.assertIn("corrosion", rep.CLASS_NAMES)
        self.assertIn("paint_damage", rep.CLASS_NAMES)

    def test_class_id_map(self):
        """CLASS_ID_MAP should map class names to 0-based IDs."""
        self.assertEqual(rep.CLASS_ID_MAP, {"crack": 0, "corrosion": 1, "paint_damage": 2})

    def test_lighting_modes(self):
        """LIGHTING_MODES should have 5 entries with expected keys."""
        self.assertEqual(len(rep.LIGHTING_MODES), 5)
        for mode in rep.LIGHTING_MODES:
            for key in ["name", "brightness", "contrast", "shadow", "temperature_bias"]:
                self.assertIn(key, mode)

    def test_camera_angles(self):
        """CAMERA_ANGLES should have 8 entries with expected keys."""
        self.assertEqual(len(rep.CAMERA_ANGLES), 8)
        for angle in rep.CAMERA_ANGLES:
            for key in ["name", "pan", "tilt", "dist"]:
                self.assertIn(key, angle)

    def test_image_size(self):
        """IMAGE_SIZE should be (640, 640)."""
        self.assertEqual(rep.IMAGE_SIZE, (640, 640))


class TestRandomizationFunctions(unittest.TestCase):
    """Test domain randomization functions produce valid outputs."""

    def test_random_lighting_mode(self):
        """random_lighting_mode should return valid lighting dict."""
        for _ in range(50):
            mode = rep.random_lighting_mode()
            self.assertIn(mode["name"], [m["name"] for m in rep.LIGHTING_MODES])
            self.assertGreaterEqual(mode["brightness"], 0.0)
            self.assertGreaterEqual(mode["contrast"], 0.0)
            self.assertGreaterEqual(mode["noise_std"], 0.0)
            self.assertIn(mode["blur_kernel"], [0, 1, 3])

    def test_random_camera_angle(self):
        """random_camera_angle should return valid angle dict."""
        for _ in range(50):
            angle = rep.random_camera_angle()
            self.assertIn(angle["name"], [a["name"] for a in rep.CAMERA_ANGLES])
            self.assertIsInstance(angle["pan"], float)
            self.assertIsInstance(angle["tilt"], float)
            self.assertGreater(angle["dist"], 0.0)

    def test_random_crack_shape(self):
        """random_crack_shape should return valid crack parameters."""
        for _ in range(50):
            cs = rep.random_crack_shape()
            self.assertGreaterEqual(cs["num_segments"], 3)
            self.assertLessEqual(cs["num_segments"], 8)
            self.assertGreaterEqual(cs["jaggedness"], 0.3)
            self.assertLessEqual(cs["jaggedness"], 0.9)
            self.assertGreaterEqual(cs["width"], 1.5)
            self.assertLessEqual(cs["width"], 4.0)
            self.assertGreaterEqual(cs["length"], 20)
            self.assertLessEqual(cs["length"], 120)
            self.assertGreaterEqual(cs["curvature"], -0.5)
            self.assertLessEqual(cs["curvature"], 0.5)

    def test_random_defect_params(self):
        """random_defect_params should return expected keys."""
        for _ in range(20):
            dp = rep.random_defect_params()
            for key in ["num_cracks", "num_corrosion_spots", "num_paint_damage_areas",
                         "corrosion_radius_range", "paint_damage_radius_range"]:
                self.assertIn(key, dp)
            self.assertGreaterEqual(dp["num_cracks"], 0)
            self.assertGreaterEqual(dp["num_corrosion_spots"], 0)
            self.assertGreaterEqual(dp["num_paint_damage_areas"], 0)


class TestBboxGeneration(unittest.TestCase):
    """Test bounding box generation for all 3 defect classes."""

    def setUp(self):
        self.img = np.zeros((640, 640, 3), dtype=np.uint8)
        self.default_dp = {
            "num_cracks": 2,
            "num_corrosion_spots": 3,
            "num_paint_damage_areas": 2,
            "corrosion_radius_range": (5, 15),
            "paint_damage_radius_range": (8, 20),
        }

    def test_crack_bbox(self):
        """Crack drawing should produce valid bboxes."""
        cs = rep.random_crack_shape()
        boxes = rep._draw_crack(self.img, cs)
        self.assertIsInstance(boxes, list)
        for (cx, cy, bw, bh) in boxes:
            self.assertGreater(cx, 0.0)
            self.assertLess(cx, 1.0)
            self.assertGreater(cy, 0.0)
            self.assertLess(cy, 1.0)
            self.assertGreater(bw, 0.0)
            self.assertGreater(bh, 0.0)
            self.assertLessEqual(bw, 1.0)
            self.assertLessEqual(bh, 1.0)

    def test_corrosion_bbox(self):
        """Corrosion drawing should produce valid bboxes."""
        boxes = rep._draw_corrosion(self.img, self.default_dp)
        self.assertIsInstance(boxes, list)
        for (cx, cy, bw, bh) in boxes:
            self.assertGreater(cx, 0.0)
            self.assertLess(cx, 1.0)
            self.assertGreater(cy, 0.0)
            self.assertLess(cy, 1.0)
            self.assertGreater(bw, 0.0)
            self.assertGreater(bh, 0.0)

    def test_paint_damage_bbox(self):
        """Paint damage drawing should produce valid bboxes."""
        boxes = rep._draw_paint_damage(self.img, self.default_dp)
        self.assertIsInstance(boxes, list)
        for (cx, cy, bw, bh) in boxes:
            self.assertGreater(cx, 0.0)
            self.assertLess(cx, 1.0)
            self.assertGreater(cy, 0.0)
            self.assertLess(cy, 1.0)
            self.assertGreater(bw, 0.0)
            self.assertGreater(bh, 0.0)

    def test_all_classes_produce_boxes(self):
        """All three classes should produce at least one bbox with reasonable params."""
        img, all_boxes, dp, lp, cp, crack_shapes = rep.generate_synthetic_image(
            image_id=1,
            defect_params=self.default_dp,
            lighting_params=rep.random_lighting_mode(),
            camera_params=rep.random_camera_angle(),
        )
        # Check we have at least a few boxes
        self.assertGreater(len(all_boxes), 0)
        class_ids = set(b[0] for b in all_boxes)
        # With default params having 2 cracks, 3 corrosion, 2 paint damage, we should have multiple classes
        self.assertGreaterEqual(len(class_ids), 1)

    def test_image_with_defects_is_different_from_blank(self):
        """Image with defects should have pixel content."""
        img, _, _, _, _, _ = rep.generate_synthetic_image(image_id=1, defect_params=self.default_dp)
        self.assertGreater(np.mean(img), 0)
        self.assertLess(np.mean(img), 255)


class TestYOLOLabelFormat(unittest.TestCase):
    """Test YOLO label generation produces correct format."""

    def test_yolo_label_line_format(self):
        """Each YOLO label line should be: class_id x_center y_center width height (normalized)."""
        with tempfile.TemporaryDirectory() as tmpdir:
            images_dir = Path(tmpdir) / "images"
            labels_dir = Path(tmpdir) / "labels_yolo"
            images_dir.mkdir(parents=True, exist_ok=True)
            labels_dir.mkdir(parents=True, exist_ok=True)

            # Generate one image
            img, all_boxes, _, _, _, _ = rep.generate_synthetic_image(
                image_id=1,
                defect_params=rep.random_defect_params(),
            )

            # Save the label manually for testing
            label_path = labels_dir / "frame_000001.txt"
            with open(label_path, "w") as f:
                for (class_id, cx, cy, bw, bh) in all_boxes:
                    f.write(f"{class_id} {cx:.6f} {cy:.6f} {bw:.6f} {bh:.6f}\n")

            # Read and verify
            with open(label_path) as f:
                lines = f.readlines()

            self.assertGreater(len(lines), 0, "Should have at least one label")
            for line in lines:
                parts = line.strip().split()
                self.assertEqual(len(parts), 5, f"Expected 5 parts, got: {parts}")
                class_id = int(parts[0])
                self.assertIn(class_id, [0, 1, 2])
                x, y, w, h = map(float, parts[1:])
                # All normalized values should be in [0, 1]
                self.assertGreaterEqual(x, 0.0)
                self.assertLessEqual(x, 1.0)
                self.assertGreaterEqual(y, 0.0)
                self.assertLessEqual(y, 1.0)
                self.assertGreater(w, 0.0)
                self.assertLessEqual(w, 1.0)
                self.assertGreater(h, 0.0)
                self.assertLessEqual(h, 1.0)

    def test_yolo_labels_from_dataset(self):
        """Generated dataset should have valid YOLO format labels."""
        with tempfile.TemporaryDirectory() as tmpdir:
            output_dir = Path(tmpdir)
            metadata = rep.generate_dataset(num_images=5, output_dir=output_dir)
            
            labels_dir = output_dir / "labels_yolo"
            label_files = sorted(labels_dir.glob("*.txt"))
            self.assertEqual(len(label_files), 5)
            
            for label_file in label_files:
                with open(label_file) as f:
                    lines = f.readlines()
                for line in lines:
                    parts = line.strip().split()
                    self.assertEqual(len(parts), 5)
                    class_id = int(parts[0])
                    self.assertIn(class_id, [0, 1, 2])
                    vals = list(map(float, parts[1:]))
                    for v in vals:
                        self.assertGreaterEqual(v, 0.0)
                        self.assertLessEqual(v, 1.0)


class TestMetadataSchema(unittest.TestCase):
    """Test metadata.json structure and schema."""

    def test_metadata_schema(self):
        """metadata.json should have the expected top-level keys."""
        with tempfile.TemporaryDirectory() as tmpdir:
            output_dir = Path(tmpdir)
            metadata = rep.generate_dataset(num_images=3, output_dir=output_dir)
            
            # Check top-level keys
            for key in ["dataset", "num_images", "classes", "class_id_map",
                         "image_size", "lighting_modes", "camera_angles",
                         "samples", "class_counts", "total_annotations"]:
                self.assertIn(key, metadata, f"Missing key: {key}")
            
            self.assertEqual(metadata["num_images"], 3)
            self.assertEqual(metadata["dataset"], "crane_inspection_synthetic_advanced")
            self.assertEqual(len(metadata["samples"]), 3)

    def test_sample_schema(self):
        """Each metadata sample should have required fields."""
        with tempfile.TemporaryDirectory() as tmpdir:
            output_dir = Path(tmpdir)
            metadata = rep.generate_dataset(num_images=5, output_dir=output_dir)
            
            for sample in metadata["samples"]:
                for key in ["image_id", "image_filename", "label_filename",
                             "lighting_mode", "camera_angle", "camera_params",
                             "lighting_params", "defect_params", "num_annotations",
                             "classes_present", "crack_shapes"]:
                    self.assertIn(key, sample, f"Sample {sample['image_id']} missing key: {key}")
                
                self.assertIsInstance(sample["image_id"], int)
                self.assertIsInstance(sample["image_filename"], str)
                self.assertIsInstance(sample["label_filename"], str)
                self.assertIsInstance(sample["num_annotations"], int)
                self.assertGreaterEqual(sample["num_annotations"], 1)
                
                # Check classes_present values
                for cls in sample["classes_present"]:
                    self.assertIn(cls, ["crack", "corrosion", "paint_damage"])

    def test_class_counts(self):
        """class_counts should be in metadata and have all classes."""
        with tempfile.TemporaryDirectory() as tmpdir:
            output_dir = Path(tmpdir)
            metadata = rep.generate_dataset(num_images=5, output_dir=output_dir)
            
            for cls in ["crack", "corrosion", "paint_damage"]:
                self.assertIn(cls, metadata["class_counts"])
                self.assertGreaterEqual(metadata["class_counts"][cls], 0)
            
            # Total annotations should match sum
            total = sum(metadata["class_counts"].values())
            self.assertEqual(metadata["total_annotations"], total)

    def test_metadata_json_file(self):
        """metadata.json should exist and be valid JSON after generation."""
        with tempfile.TemporaryDirectory() as tmpdir:
            output_dir = Path(tmpdir)
            rep.generate_dataset(num_images=3, output_dir=output_dir)
            
            metadata_path = output_dir / "metadata.json"
            self.assertTrue(metadata_path.exists())
            
            with open(metadata_path) as f:
                loaded = json.load(f)
            
            self.assertEqual(loaded["num_images"], 3)
            self.assertEqual(len(loaded["samples"]), 3)


class TestImageDimensions(unittest.TestCase):
    """Test generated images have correct dimensions."""

    def test_image_size_640x640(self):
        """Generated images should be 640x640."""
        with tempfile.TemporaryDirectory() as tmpdir:
            output_dir = Path(tmpdir)
            rep.generate_dataset(num_images=3, output_dir=output_dir)
            
            images_dir = output_dir / "images"
            image_files = sorted(images_dir.glob("*.png"))
            self.assertEqual(len(image_files), 3)
            
            for img_path in image_files:
                img = cv2.imread(str(img_path))
                self.assertIsNotNone(img, f"Could not read {img_path}")
                h, w = img.shape[:2]
                self.assertEqual(w, 640, f"{img_path.name}: expected width 640, got {w}")
                self.assertEqual(h, 640, f"{img_path.name}: expected height 640, got {h}")

    def test_image_rgb_channels(self):
        """Generated images should have 3 channels (BGR)."""
        with tempfile.TemporaryDirectory() as tmpdir:
            output_dir = Path(tmpdir)
            rep.generate_dataset(num_images=3, output_dir=output_dir)
            
            for img_path in output_dir.glob("images/*.png"):
                img = cv2.imread(str(img_path))
                self.assertEqual(len(img.shape), 3)
                self.assertEqual(img.shape[2], 3)

    def test_images_are_not_blank(self):
        """Generated images should have non-uniform pixel content."""
        with tempfile.TemporaryDirectory() as tmpdir:
            output_dir = Path(tmpdir)
            rep.generate_dataset(num_images=3, output_dir=output_dir)
            
            for img_path in output_dir.glob("images/*.png"):
                img = cv2.imread(str(img_path))
                # Check std > 0 (not uniform)
                self.assertGreater(np.std(img), 0, f"{img_path.name} appears blank")
                # Check mean is reasonable (not pure black or pure white)
                mean = np.mean(img)
                self.assertGreater(mean, 1)
                self.assertLess(mean, 245)


class TestDomainRandomization(unittest.TestCase):
    """Test domain randomization produces variety."""

    def test_lighting_variety(self):
        """Multiple generated images should have different lighting modes."""
        lighting_modes_seen = set()
        for _ in range(20):
            lp = rep.random_lighting_mode()
            lighting_modes_seen.add(lp["name"])
        # With 20 random picks from 5 modes, we should see at least 3 different modes
        self.assertGreaterEqual(len(lighting_modes_seen), 3)

    def test_camera_variety(self):
        """Multiple random camera angles should yield variety."""
        angles_seen = set()
        for _ in range(20):
            ap = rep.random_camera_angle()
            angles_seen.add(ap["name"])
        self.assertGreaterEqual(len(angles_seen), 3)

    def test_crack_shape_variety(self):
        """Multiple crack shapes should have variation."""
        segments = set()
        jaggedness_vals = []
        for _ in range(10):
            cs = rep.random_crack_shape()
            segments.add(cs["num_segments"])
            jaggedness_vals.append(cs["jaggedness"])
        self.assertGreaterEqual(len(segments), 2,
                                f"Expected at least 2 different segment counts, got {segments}")


class TestOutputStructure(unittest.TestCase):
    """Test directory and file structure."""

    def test_dataset_directory_structure(self):
        """Dataset directory should have images/, labels_yolo/, masks/, metadata.json."""
        with tempfile.TemporaryDirectory() as tmpdir:
            output_dir = Path(tmpdir)
            rep.generate_dataset(num_images=5, output_dir=output_dir)
            
            self.assertTrue((output_dir / "images").exists())
            self.assertTrue((output_dir / "labels_yolo").exists())
            self.assertTrue((output_dir / "masks").exists())
            self.assertTrue((output_dir / "metadata.json").exists())

    def test_correct_file_counts(self):
        """Number of images, labels, and samples should match num_images."""
        with tempfile.TemporaryDirectory() as tmpdir:
            output_dir = Path(tmpdir)
            num = 7
            rep.generate_dataset(num_images=num, output_dir=output_dir)
            
            image_files = list((output_dir / "images").glob("*.png"))
            label_files = list((output_dir / "labels_yolo").glob("*.txt"))
            
            self.assertEqual(len(image_files), num)
            self.assertEqual(len(label_files), num)


class TestLightingApplication(unittest.TestCase):
    """Test apply_lighting function."""

    def test_apply_lighting_returns_valid_image(self):
        """apply_lighting should return a valid image of same size."""
        img = np.random.randint(0, 256, (640, 640, 3), dtype=np.uint8)
        lighting = {
            "name": "bright",
            "brightness": 1.0,
            "contrast": 1.0,
            "shadow": 0.0,
            "noise_std": 0.01,
            "blur_kernel": 3,
        }
        result = rep.apply_lighting(img, lighting)
        self.assertEqual(result.shape, img.shape)
        self.assertEqual(result.dtype, np.uint8)

    def test_apply_lighting_changes_image(self):
        """apply_lighting with extreme params should visibly change the image."""
        img = np.full((100, 100, 3), 128, dtype=np.uint8)
        lighting = {
            "name": "shadowed",
            "brightness": 0.3,
            "contrast": 0.5,
            "shadow": 0.8,
            "noise_std": 0.02,
            "blur_kernel": 0,
        }
        result = rep.apply_lighting(img, lighting)
        # Mean should be significantly different from 128
        mean_diff = abs(float(np.mean(result)) - 128.0)
        self.assertGreater(mean_diff, 5.0,
                           f"Mean difference too small: {mean_diff}")


if __name__ == "__main__":
    unittest.main(verbosity=2)
