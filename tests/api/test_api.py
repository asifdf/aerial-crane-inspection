from pathlib import Path

import cv2
import numpy as np
import pytest
from fastapi.testclient import TestClient

from scripts import api_server


class FakeTensor:
    def __init__(self, value):
        self.value = np.array(value)

    def cpu(self):
        return self

    def numpy(self):
        return self.value


class FakeBoxes:
    def __init__(self):
        self.xyxy = FakeTensor([[10.0, 20.0, 110.0, 120.0]])
        self.conf = FakeTensor([0.87654321])
        self.cls = FakeTensor([1])

    def __len__(self):
        return 1


class FakeResult:
    boxes = FakeBoxes()
    names = {0: "crack", 1: "corrosion", 2: "paint_damage"}


class FakeModel:
    names = FakeResult.names

    def __call__(self, image):
        assert image.shape[2] == 3
        return [FakeResult()]


@pytest.fixture
def client(monkeypatch, tmp_path):
    monkeypatch.setattr(api_server, "RUNS_DIR", tmp_path / "runs" / "api")
    monkeypatch.setattr(api_server, "load_yolo_model", lambda _path: FakeModel())
    with TestClient(api_server.app) as test_client:
        yield test_client


def make_jpeg_bytes() -> bytes:
    image = np.zeros((64, 64, 3), dtype=np.uint8)
    image[10:30, 10:30] = (0, 0, 255)
    ok, encoded = cv2.imencode(".jpg", image)
    assert ok
    return encoded.tobytes()


def test_health_reports_loaded_model(client):
    response = client.get("/health")

    assert response.status_code == 200
    body = response.json()
    assert body["status"] == "ok"
    assert body["model_loaded"] is True
    assert body["uptime_seconds"] >= 0


def test_predict_returns_detection_json_and_saves_result(client, tmp_path):
    response = client.post(
        "/predict",
        files={"file": ("crane.jpg", make_jpeg_bytes(), "image/jpeg")},
    )

    assert response.status_code == 200
    body = response.json()
    assert body["filename"] == "crane.jpg"
    assert body["count"] == 1
    assert body["detections"] == [
        {"class": "corrosion", "confidence": 0.876543, "bbox": [10.0, 20.0, 110.0, 120.0]}
    ]
    saved_to = Path(body["saved_to"])
    assert saved_to.exists()
    assert (saved_to / "crane.jpg").exists()
    assert (saved_to / "result.json").exists()
    assert tmp_path in saved_to.parents


def test_batch_predict_accepts_multiple_images(client):
    response = client.post(
        "/batch-predict",
        files=[
            ("files", ("one.jpg", make_jpeg_bytes(), "image/jpeg")),
            ("files", ("two.jpg", make_jpeg_bytes(), "image/jpeg")),
        ],
    )

    assert response.status_code == 200
    body = response.json()
    assert body["count"] == 2
    assert [item["filename"] for item in body["results"]] == ["one.jpg", "two.jpg"]
    assert all(item["detections"][0]["class"] == "corrosion" for item in body["results"])
    assert Path(body["saved_to"], "batch_result.json").exists()


def test_predict_rejects_non_image_upload(client):
    response = client.post(
        "/predict",
        files={"file": ("notes.txt", b"not an image", "text/plain")},
    )

    assert response.status_code == 415
    assert response.json()["error"] == "Upload must be an image file"


def test_predict_rejects_invalid_image_bytes(client):
    response = client.post(
        "/predict",
        files={"file": ("bad.jpg", b"not an image", "image/jpeg")},
    )

    assert response.status_code == 400
    assert response.json()["error"] == "Uploaded file is not a valid image"
