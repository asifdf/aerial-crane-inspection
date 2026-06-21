import csv
from pathlib import Path

import yaml


RUN_DIR = Path(__file__).parent.parent.parent / "runs" / "yolo_baseline" / "yolo_baseline"
DATA_YAML = Path("/workspaces/pegasus_ws/dataset/synthetic_v2/data.yaml")


def test_synthetic_v2_dataset_config():
    data = yaml.safe_load(DATA_YAML.read_text())

    assert data["train"] == "images"
    assert data["val"] == "images"
    assert data["nc"] == 3
    assert data["names"] == ["crack", "corrosion", "paint_damage"]


def test_yolo_baseline_artifacts_exist():
    assert (RUN_DIR / "weights" / "best.pt").is_file()
    assert (RUN_DIR / "weights" / "best.onnx").is_file()
    assert (RUN_DIR / "results.csv").is_file()


def test_yolo_baseline_map50_is_positive():
    with (RUN_DIR / "results.csv").open(newline="") as results_file:
        results = list(csv.DictReader(results_file))

    columns = results[0].keys()
    map50_columns = [column for column in columns if "mAP50" in column and "mAP50-95" not in column]

    assert map50_columns, f"No mAP50 column found in results.csv columns: {list(columns)}"
    assert max(float(row[map50_columns[0]]) for row in results) > 0
