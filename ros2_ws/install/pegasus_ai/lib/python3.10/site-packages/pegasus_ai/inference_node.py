"""
Pegasus AI Inference Node
TensorRT-accelerated YOLO defect detection for crane inspection drones.
Designed for Jetson Orin Nano Super with ROS2 Humble.
"""

import json
import os
import time
from collections import deque
from typing import Optional

import cv2
import numpy as np
import rclpy
from pegasus_msgs.msg import DefectArray, DefectDetection, NodeHealth
from rclpy.node import Node
from rclpy.qos import QoSHistoryPolicy, QoSProfile, QoSReliabilityPolicy
from sensor_msgs.msg import Image
from std_msgs.msg import String


class YOLOPreprocessor:
    """YOLOv8/v11 preprocessing: letterbox resize, normalize, CHW format."""

    def __init__(self, input_size: tuple[int, int] = (640, 640)):
        self.input_width, self.input_height = input_size

    def __call__(self, image: np.ndarray) -> np.ndarray:
        """Preprocess BGR image to model input tensor."""
        # Letterbox resize
        h, w = image.shape[:2]
        scale = min(self.input_width / w, self.input_height / h)
        new_w, new_h = int(w * scale), int(h * scale)

        resized = cv2.resize(image, (new_w, new_h), interpolation=cv2.INTER_LINEAR)

        # Pad to input size
        padded = np.full((self.input_height, self.input_width, 3), 114, dtype=np.uint8)
        pad_x, pad_y = (self.input_width - new_w) // 2, (self.input_height - new_h) // 2
        padded[pad_y : pad_y + new_h, pad_x : pad_x + new_w] = resized

        # BGR to RGB, normalize, HWC to CHW
        tensor = padded[:, :, ::-1].transpose(2, 0, 1).astype(np.float32) / 255.0
        tensor = np.ascontiguousarray(tensor[None])  # Add batch dim

        # Store preprocessing params for postprocessing
        self._scale = scale
        self._pad_x = pad_x
        self._pad_y = pad_y
        self._orig_shape = (h, w)

        return tensor


class YOLOPostprocessor:
    """YOLOv8/v11 postprocessing: decode, NMS, rescale to original image."""

    def __init__(
        self,
        conf_threshold: float = 0.25,
        iou_threshold: float = 0.45,
        max_detections: int = 100,
        class_names: Optional[list[str]] = None,
    ):
        self.conf_threshold = conf_threshold
        self.iou_threshold = iou_threshold
        self.max_detections = max_detections
        self.class_names = class_names or ["crack", "corrosion", "paint_damage"]

    def __call__(
        self,
        outputs: np.ndarray,
        preprocessor: YOLOPreprocessor,
    ) -> list[dict]:
        """
        Process model outputs to detection list.

        Args:
            outputs: Model output [1, 84, 8400] for YOLOv8 (4 bbox + 80 classes)
                     or [1, 84, 8400] for YOLOv11 (similar format)
            preprocessor: Used to rescale boxes to original image

        Returns:
            List of detection dicts with keys: class_id, confidence, bbox, class_name
        """
        # Output format: [batch, 4+num_classes, num_boxes] -> transpose to [batch, num_boxes, 4+num_classes]
        predictions = outputs[0].T  # [8400, 84]

        # Filter by confidence
        scores = predictions[:, 4:].max(axis=1)
        valid = scores > self.conf_threshold
        predictions = predictions[valid]
        scores = scores[valid]

        if len(predictions) == 0:
            return []

        # Get class IDs
        class_ids = predictions[:, 4:].argmax(axis=1)
        class_scores = predictions[np.arange(len(predictions)), 4 + class_ids]

        # Box format: cx, cy, w, h (normalized to input size)
        boxes = predictions[:, :4]

        # Rescale boxes to original image
        boxes = self._rescale_boxes(boxes, preprocessor)

        # NMS per class
        detections = []
        for class_id in np.unique(class_ids):
            mask = class_ids == class_id
            class_boxes = boxes[mask]
            class_scores = class_scores[mask]

            keep = self._nms(class_boxes, class_scores)
            for idx in keep[: self.max_detections]:
                detections.append(
                    {
                        "class_id": int(class_id),
                        "confidence": float(class_scores[idx]),
                        "bbox": class_boxes[idx].tolist(),  # [x1, y1, x2, y2]
                        "class_name": self.class_names[class_id]
                        if class_id < len(self.class_names)
                        else f"class_{class_id}",
                    }
                )

        return detections

    def _rescale_boxes(self, boxes: np.ndarray, preprocessor: YOLOPreprocessor) -> np.ndarray:
        """Convert normalized cx,cy,w,h to pixel x1,y1,x2,y2 in original image coords."""
        cx, cy, w, h = boxes[:, 0], boxes[:, 1], boxes[:, 2], boxes[:, 3]

        # Denormalize to input size
        cx = cx * preprocessor.input_width
        cy = cy * preprocessor.input_height
        w = w * preprocessor.input_width
        h = h * preprocessor.input_height

        # Remove padding
        cx -= preprocessor._pad_x
        cy -= preprocessor._pad_y

        # Rescale to original
        cx /= preprocessor._scale
        cy /= preprocessor._scale
        w /= preprocessor._scale
        h /= preprocessor._scale

        # Convert to x1,y1,x2,y2
        x1 = cx - w / 2
        y1 = cy - h / 2
        x2 = cx + w / 2
        y2 = cy + h / 2

        # Clip to image bounds
        orig_h, orig_w = preprocessor._orig_shape
        x1 = np.clip(x1, 0, orig_w)
        y1 = np.clip(y1, 0, orig_h)
        x2 = np.clip(x2, 0, orig_w)
        y2 = np.clip(y2, 0, orig_h)

        return np.stack([x1, y1, x2, y2], axis=1)

    def _nms(self, boxes: np.ndarray, scores: np.ndarray) -> np.ndarray:
        """Non-maximum suppression."""
        if len(boxes) == 0:
            return np.array([], dtype=int)

        x1, y1, x2, y2 = boxes[:, 0], boxes[:, 1], boxes[:, 2], boxes[:, 3]
        areas = (x2 - x1) * (y2 - y1)
        order = scores.argsort()[::-1]

        keep = []
        while order.size > 0:
            i = order[0]
            keep.append(i)

            xx1 = np.maximum(x1[i], x1[order[1:]])
            yy1 = np.maximum(y1[i], y1[order[1:]])
            xx2 = np.minimum(x2[i], x2[order[1:]])
            yy2 = np.minimum(y2[i], y2[order[1:]])

            w = np.maximum(0, xx2 - xx1)
            h = np.maximum(0, yy2 - yy1)
            inter = w * h
            iou = inter / (areas[i] + areas[order[1:]] - inter)

            order = order[1:][iou <= self.iou_threshold]

        return np.array(keep)


class TRTEngine:
    """TensorRT engine wrapper for YOLO inference."""

    def __init__(self, engine_path: str):
        self.engine_path = engine_path
        self.logger = None
        self.runtime = None
        self.engine = None
        self.context = None
        self.inputs = []
        self.outputs = []
        self.bindings = []
        self.stream = None

        self._load_engine()

    def _load_engine(self):
        """Load TensorRT engine and allocate buffers."""
        try:
            import pycuda.autoinit  # noqa: F401
            import pycuda.driver as cuda
            import tensorrt as trt

            self.logger = trt.Logger(trt.Logger.WARNING)
            self.runtime = trt.Runtime(self.logger)

            with open(self.engine_path, "rb") as f:
                self.engine = self.runtime.deserialize_cuda_engine(f.read())

            self.context = self.engine.create_execution_context()

            # Allocate buffers
            self.stream = cuda.Stream()
            for binding in self.engine:
                shape = self.engine.get_binding_shape(binding)
                dtype = trt.nptype(self.engine.get_binding_dtype(binding))
                size = trt.volume(shape)

                if self.engine.binding_is_input(binding):
                    self.inputs.append(
                        {
                            "name": binding,
                            "shape": shape,
                            "dtype": dtype,
                            "host": np.empty(size, dtype=dtype),
                            "device": cuda.mem_alloc(size * np.dtype(dtype).itemsize),
                        }
                    )
                else:
                    self.outputs.append(
                        {
                            "name": binding,
                            "shape": shape,
                            "dtype": dtype,
                            "host": np.empty(size, dtype=dtype),
                            "device": cuda.mem_alloc(size * np.dtype(dtype).itemsize),
                        }
                    )

                self.bindings.append(
                    int(self.inputs[-1]["device"])
                    if self.engine.binding_is_input(binding)
                    else int(self.outputs[-1]["device"])
                )

            self.get_logger().info(f"Loaded TensorRT engine: {self.engine_path}")

        except ImportError:
            self.get_logger().warn("TensorRT/pycuda not available, using fallback")
            self.engine = None

    def get_logger(self):
        """Lazy logger for use before Node init."""
        import logging

        return logging.getLogger("TRTEngine")

    def infer(self, input_tensor: np.ndarray) -> np.ndarray:
        """Run inference on input tensor."""
        if self.engine is None:
            raise RuntimeError("TensorRT engine not loaded")

        import pycuda.driver as cuda

        # Copy input to device
        np.copyto(self.inputs[0]["host"], input_tensor.ravel())
        cuda.memcpy_htod_async(self.inputs[0]["device"], self.inputs[0]["host"], self.stream)

        # Execute
        self.context.execute_async_v2(bindings=self.bindings, stream_handle=self.stream.handle)

        # Copy output back
        for out in self.outputs:
            cuda.memcpy_dtoh_async(out["host"], out["device"], self.stream)

        self.stream.synchronize()

        # Return first output reshaped
        output = self.outputs[0]["host"].reshape(self.outputs[0]["shape"])
        return output


class DefectInferenceNode(Node):
    """ROS2 node for AI defect detection inference."""

    def __init__(self):
        super().__init__("defect_inference")

        # Declare parameters
        self.declare_parameter("model_path", "/opt/models/hybrid_fp16.trt")
        self.declare_parameter("model_type", "tensorrt")
        self.declare_parameter("precision", "fp16")
        self.declare_parameter("input_width", 640)
        self.declare_parameter("input_height", 640)
        self.declare_parameter("conf_threshold", 0.25)
        self.declare_parameter("iou_threshold", 0.45)
        self.declare_parameter("max_detections", 100)
        self.declare_parameter("classes", ["crack", "corrosion", "paint_damage"])
        self.declare_parameter("input_image_topic", "/camera/image_raw")
        self.declare_parameter("output_detections_topic", "/ai/defect_detections")
        self.declare_parameter("output_defect_array_topic", "/ai/defect_array")
        self.declare_parameter("output_json_topic", "/ai/defect_json")
        self.declare_parameter("output_health_topic", "/ai/node_health")
        self.declare_parameter("use_cuda_graph", True)
        self.declare_parameter("batch_size", 1)
        self.declare_parameter("warmup_iterations", 10)
        self.declare_parameter("max_publish_rate", 30.0)
        self.declare_parameter("skip_frames", 0)
        self.declare_parameter("enable_zone_mapping", False)
        self.declare_parameter("zone_config_path", "")
        self.declare_parameter("publish_annotated_image", False)
        self.declare_parameter("annotated_image_topic", "/ai/annotated_image")
        self.declare_parameter("log_level", "INFO")

        # Get parameters
        self._load_parameters()

        # Image conversion is handled with numpy directly so mock mode does not
        # import cv_bridge in ROS2 Humble/Numpy 2.x setups.
        self.preprocessor = YOLOPreprocessor((self.input_width, self.input_height))
        self.postprocessor = YOLOPostprocessor(
            conf_threshold=self.conf_threshold,
            iou_threshold=self.iou_threshold,
            max_detections=self.max_detections,
            class_names=self.classes,
        )

        # Metrics
        self.latencies = deque(maxlen=100)
        self.frame_count = 0
        self.detection_count = 0
        self.error_count = 0
        self.last_error_time = 0.0
        self.start_time = time.time()
        self.last_publish_time = 0
        self.active_alerts = []

        # Frame skipping
        self.frame_skip_counter = 0

        # Load model
        self._load_model()

        # QoS for sensor data — match Pegasus publisher (RELIABLE, depth 1)
        sensor_qos = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=5,
        )

        # Subscribers
        self.image_sub = self.create_subscription(
            Image,
            self.input_image_topic,
            self.image_callback,
            sensor_qos,
        )

        # Publishers
        self.detections_pub = self.create_publisher(DefectArray, self.output_detections_topic, 10)
        self.defect_array_pub = self.create_publisher(DefectArray, self.output_defect_array_topic, 10)
        self.json_pub = self.create_publisher(String, self.output_json_topic, 10)
        self.health_pub = self.create_publisher(NodeHealth, self.output_health_topic, 1)

        if self.publish_annotated_image:
            self.annotated_pub = self.create_publisher(Image, self.annotated_image_topic, 10)

        self.health_timer = self.create_timer(1.0, self.publish_health)

        self.get_logger().info("DefectInferenceNode started")
        self.get_logger().info(f"  Model type: {self.model_type}")
        self.get_logger().info(f"  Model: {self.model_path}")
        self.get_logger().info(f"  Input: {self.input_width}x{self.input_height}")
        self.get_logger().info(f"  Classes: {self.classes}")
        self.get_logger().info(f"  Subscribing to: {self.input_image_topic}")
        self.get_logger().info(f"  Publishing detections to: {self.output_detections_topic}")
        self.get_logger().info(f"  Publishing JSON to: {self.output_json_topic}")

    def _load_parameters(self):
        """Load all parameters from ROS2 parameter server."""
        self.model_path = self.get_parameter("model_path").value
        self.model_type = self.get_parameter("model_type").value
        self.precision = self.get_parameter("precision").value
        self.input_width = self.get_parameter("input_width").value
        self.input_height = self.get_parameter("input_height").value
        self.conf_threshold = self.get_parameter("conf_threshold").value
        self.iou_threshold = self.get_parameter("iou_threshold").value
        self.max_detections = self.get_parameter("max_detections").value
        self.classes = self.get_parameter("classes").value
        self.input_image_topic = self.get_parameter("input_image_topic").value
        self.output_detections_topic = self.get_parameter("output_detections_topic").value
        self.output_defect_array_topic = self.get_parameter("output_defect_array_topic").value
        self.output_json_topic = self.get_parameter("output_json_topic").value
        self.output_health_topic = self.get_parameter("output_health_topic").value
        self.use_cuda_graph = self.get_parameter("use_cuda_graph").value
        self.batch_size = self.get_parameter("batch_size").value
        self.warmup_iterations = self.get_parameter("warmup_iterations").value
        self.max_publish_rate = self.get_parameter("max_publish_rate").value
        self.skip_frames = self.get_parameter("skip_frames").value
        self.enable_zone_mapping = self.get_parameter("enable_zone_mapping").value
        self.zone_config_path = self.get_parameter("zone_config_path").value
        self.publish_annotated_image = self.get_parameter("publish_annotated_image").value
        self.annotated_image_topic = self.get_parameter("annotated_image_topic").value
        log_level = self.get_parameter("log_level").value
        self.get_logger().set_level(getattr(rclpy.logging.LoggingSeverity, log_level))

    def _load_model(self):
        """Load configured inference backend, falling back to mock on failure."""
        if self.model_type == "tensorrt":
            if not os.path.exists(self.model_path):
                self._switch_to_mock_mode(f"TensorRT engine not found: {self.model_path}")
                return

            try:
                self.engine = TRTEngine(self.model_path)

                # Warmup validates CUDA/TensorRT availability before subscriptions start.
                self.get_logger().info(
                    f"Warming up model ({self.warmup_iterations} iterations)..."
                )
                dummy_input = np.random.randn(1, 3, self.input_height, self.input_width).astype(
                    np.float32
                )
                for _ in range(self.warmup_iterations):
                    _ = self.engine.infer(dummy_input)
                self.get_logger().info("Model warmup complete")
            except Exception as exc:
                self._switch_to_mock_mode(f"TensorRT model load failed: {exc}")

        elif self.model_type == "yolo":
            try:
                from ultralytics import YOLO
                self.get_logger().info(f"Loading YOLO model from {self.model_path}")
                self.yolo_model = YOLO(self.model_path)
                self.get_logger().info("YOLO model loaded successfully")
            except Exception as exc:
                self._switch_to_mock_mode(f"YOLO model load failed: {exc}")

        elif self.model_type == "mock":
            self.get_logger().info("Using mock model for testing")
            self.engine = None

        else:
            raise NotImplementedError(f"Model type {self.model_type} not implemented")

    def _switch_to_mock_mode(self, reason: str):
        """Enable deterministic mock detections after backend initialization failure."""
        self.get_logger().warn(f"{reason}; switching to mock mode")
        self.model_type = "mock"
        self.engine = None
        self.active_alerts.append(reason)

    def image_callback(self, msg: Image):
        """Process incoming camera image."""
        # Frame skipping
        if self.skip_frames > 0:
            self.frame_skip_counter += 1
            if self.frame_skip_counter % (self.skip_frames + 1) != 0:
                return

        # Rate limiting
        if self.max_publish_rate > 0:
            now = time.time()
            min_interval = 1.0 / self.max_publish_rate
            if now - self.last_publish_time < min_interval:
                return
            self.last_publish_time = now

        t0 = time.perf_counter()

        try:
            cv_image = self._image_msg_to_numpy(msg)

            if self.model_type == "yolo":
                # YOLO inference
                results = self.yolo_model(cv_image, verbose=False)
                detections = []
                for r in results:
                    for box in r.boxes:
                        detections.append({
                            "class_id": int(box.cls[0]),
                            "class_name": self.classes[int(box.cls[0])],
                            "confidence": float(box.conf[0]),
                            "bbox": box.xyxy[0].tolist(),
                        })
            elif self.model_type != "mock" and self.engine is not None:
                # Preprocess
                input_tensor = self.preprocessor(cv_image)

                # Inference
                outputs = self.engine.infer(input_tensor)

                # Postprocess
                detections = self.postprocessor(outputs, self.preprocessor)
            else:
                detections = self._mock_detections(cv_image)

            # Publish results
            self.publish_detections(detections, msg.header, cv_image.shape[:2])
            self.publish_json(detections, msg.header)

            # Annotated image (optional)
            if self.publish_annotated_image:
                self.publish_annotated(detections, msg.header, cv_image)

            # Update metrics
            latency = time.perf_counter() - t0
            self.latencies.append(latency * 1000)  # ms
            self.frame_count += 1
            self.detection_count += len(detections)

            self.publish_health()

        except Exception as e:
            self.error_count += 1
            self.last_error_time = time.time()
            self.get_logger().error(f"Inference error: {e}")

    def _image_msg_to_numpy(self, msg: Image) -> np.ndarray:
        """Convert common ROS Image encodings to BGR numpy arrays without cv_bridge."""
        encoding = msg.encoding.lower()
        channels_by_encoding = {
            "bgr8": 3,
            "rgb8": 3,
            "mono8": 1,
            "8uc1": 1,
            "8uc3": 3,
        }
        if encoding not in channels_by_encoding:
            raise ValueError(f"Unsupported image encoding for numpy conversion: {msg.encoding}")

        channels = channels_by_encoding[encoding]
        expected_row_bytes = msg.width * channels
        if msg.step < expected_row_bytes:
            raise ValueError(
                f"Image step {msg.step} is smaller than expected row size {expected_row_bytes}"
            )

        array = np.frombuffer(msg.data, dtype=np.uint8)
        array = array.reshape((msg.height, msg.step))[:, :expected_row_bytes]

        if channels == 1:
            gray = array.reshape((msg.height, msg.width))
            return cv2.cvtColor(gray, cv2.COLOR_GRAY2BGR)

        image = array.reshape((msg.height, msg.width, channels))
        if encoding == "rgb8":
            return cv2.cvtColor(image, cv2.COLOR_RGB2BGR)
        return image.copy()

    def _numpy_to_image_msg(self, image: np.ndarray, header, encoding: str = "bgr8") -> Image:
        """Convert a uint8 BGR numpy image to a ROS Image message without cv_bridge."""
        msg = Image()
        msg.header = header
        msg.height = int(image.shape[0])
        msg.width = int(image.shape[1])
        msg.encoding = encoding
        msg.is_bigendian = False
        msg.step = int(image.shape[1] * image.shape[2])
        msg.data = np.ascontiguousarray(image).tobytes()
        return msg

    def _mock_detections(self, image: np.ndarray) -> list[dict]:
        """Generate deterministic synthetic detections directly from a numpy image."""
        h, w = image.shape[:2]
        boxes = [
            (0, "crack", 0.85, 0.18, 0.20, 0.34, 0.34),
            (1, "corrosion", 0.72, 0.52, 0.48, 0.70, 0.68),
        ]
        detections = []
        for class_id, class_name, confidence, x1n, y1n, x2n, y2n in boxes:
            detections.append(
                {
                    "class_id": class_id,
                    "confidence": confidence,
                    "bbox": [
                        float(max(0, min(w - 1, round(x1n * w)))),
                        float(max(0, min(h - 1, round(y1n * h)))),
                        float(max(1, min(w, round(x2n * w)))),
                        float(max(1, min(h, round(y2n * h)))),
                    ],
                    "class_name": class_name,
                }
            )
        return detections

    def publish_detections(self, detections: list[dict], header, img_shape: tuple[int, int]):
        """Publish DefectArray message."""
        h, w = img_shape

        defect_array = DefectArray()
        defect_array.header = header
        defect_array.drone_id = self.get_namespace().strip("/") or "drone_01"
        defect_array.zone_id = "unknown"  # TODO: integrate with zone mapping

        risk_map = {"low": 0, "medium": 1, "high": 2, "critical": 3}
        risk_rev = {v: k for k, v in risk_map.items()}

        max_risk_id = 0
        counts = {"crack": 0, "corrosion": 0, "paint_damage": 0}

        for det in detections:
            detection = DefectDetection()
            detection.header = header
            detection.type = det["class_name"]
            detection.class_id = det["class_id"]
            detection.confidence = det["confidence"]

            # BBox in pixels (x1, y1, x2, y2)
            x1, y1, x2, y2 = det["bbox"]
            detection.bbox_x = float(x1)
            detection.bbox_y = float(y1)
            detection.bbox_width = float(x2 - x1)
            detection.bbox_height = float(y2 - y1)

            # Normalized bbox
            detection.bbox_x_norm = float(x1 / w)
            detection.bbox_y_norm = float(y1 / h)
            detection.bbox_width_norm = float((x2 - x1) / w)
            detection.bbox_height_norm = float((y2 - y1) / h)

            # Risk assessment based on confidence and class
            risk = self._assess_risk(det["class_name"], det["confidence"])
            detection.risk_level = risk
            detection.risk_id = risk_map.get(risk, 0)
            max_risk_id = max(max_risk_id, detection.risk_id)

            counts[det["class_name"]] = counts.get(det["class_name"], 0) + 1

            defect_array.detections.append(detection)

        defect_array.total_count = len(detections)
        defect_array.crack_count = counts.get("crack", 0)
        defect_array.corrosion_count = counts.get("corrosion", 0)
        defect_array.paint_damage_count = counts.get("paint_damage", 0)
        defect_array.max_risk_level = risk_rev.get(max_risk_id, "low")
        defect_array.max_risk_id = max_risk_id
        defect_array.inference_latency = self.latencies[-1] / 1000.0 if self.latencies else 0.0
        defect_array.total_latency = 0.0  # Will be updated by downstream

        self.detections_pub.publish(defect_array)
        self.defect_array_pub.publish(defect_array)

    def _assess_risk(self, class_name: str, confidence: float) -> str:
        """Assess risk level based on defect type and confidence."""
        if class_name == "crack":
            if confidence > 0.8:
                return "high"
            elif confidence > 0.5:
                return "medium"
            return "low"
        elif class_name == "corrosion":
            if confidence > 0.7:
                return "medium"
            return "low"
        else:  # paint_damage
            return "low"

    def publish_json(self, detections: list[dict], header):
        """Publish JSON string for backend/dashboard."""
        json_data = {
            "drone_id": self.get_namespace().strip("/") or "drone_01",
            "timestamp": self._header_to_iso(header),
            "zone_id": "unknown",
            "position": {"x": 0.0, "y": 0.0, "z": 0.0},  # TODO: from MAVROS
            "defects": [],
        }

        for det in detections:
            x1, y1, x2, y2 = det["bbox"]
            json_data["defects"].append(
                {
                    "type": det["class_name"],
                    "confidence": round(det["confidence"], 3),
                    "bbox": [round(x1), round(y1), round(x2 - x1), round(y2 - y1)],
                    "risk": self._assess_risk(det["class_name"], det["confidence"]),
                }
            )

        msg = String()
        msg.data = json.dumps(json_data)
        self.json_pub.publish(msg)

    def _header_to_iso(self, header) -> str:
        """Convert ROS2 header timestamp to ISO format."""
        sec = header.stamp.sec
        nanosec = header.stamp.nanosec
        from datetime import datetime, timezone

        dt = datetime.fromtimestamp(sec + nanosec * 1e-9, tz=timezone.utc)
        return dt.isoformat()

    def publish_annotated(self, detections: list[dict], header, image: np.ndarray):
        """Publish annotated image with bounding boxes."""
        annotated = image.copy()

        colors = {
            "crack": (0, 0, 255),  # Red
            "corrosion": (0, 165, 255),  # Orange
            "paint_damage": (0, 255, 255),  # Yellow
        }

        for det in detections:
            x1, y1, x2, y2 = map(int, det["bbox"])
            color = colors.get(det["class_name"], (255, 255, 255))

            cv2.rectangle(annotated, (x1, y1), (x2, y2), color, 2)

            label = f"{det['class_name']} {det['confidence']:.2f}"
            (tw, th), _ = cv2.getTextSize(label, cv2.FONT_HERSHEY_SIMPLEX, 0.5, 1)
            cv2.rectangle(annotated, (x1, y1 - th - 4), (x1 + tw, y1), color, -1)
            cv2.putText(annotated, label, (x1, y1 - 2), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 0), 1)

        annotated_msg = self._numpy_to_image_msg(annotated, header, encoding="bgr8")
        self.annotated_pub.publish(annotated_msg)

    def publish_health(self):
        """Publish node health metrics."""
        health = NodeHealth()
        health.header.stamp = self.get_clock().now().to_msg()
        health.node_name = "defect_inference"
        health.device_id = "desktop_rtx4060"
        health.status = "healthy"

        if self.latencies:
            health.fps = 1000.0 / (sum(self.latencies) / len(self.latencies))
            health.avg_latency_ms = sum(self.latencies) / len(self.latencies)
            health.p95_latency_ms = float(np.percentile(self.latencies, 95))
            health.p99_latency_ms = float(np.percentile(self.latencies, 99))
        else:
            health.fps = 0.0
            health.avg_latency_ms = 0.0
            health.p95_latency_ms = 0.0
            health.p99_latency_ms = 0.0

        # GPU/CPU stats (simplified - would use tegrastats in production)
        health.gpu_util_percent = 0.0
        health.gpu_mem_used_mb = 0.0
        health.gpu_mem_total_mb = 12288.0  # RTX 4060 Ti 12GB
        health.cpu_util_percent = 0.0
        health.cpu_mem_used_mb = 0.0
        health.cpu_mem_total_mb = 0.0
        health.temperature_c = 0.0
        health.cpu_util_percent = 0.0
        health.cpu_mem_used_mb = 0.0
        health.cpu_mem_total_mb = 0.0
        health.temperature_c = 0.0

        health.model_path = self.model_path
        health.model_version = os.path.basename(self.model_path)
        health.precision = self.precision
        health.input_width = self.input_width
        health.input_height = self.input_height

        health.frames_processed = self.frame_count
        health.detections_published = self.detection_count
        health.errors_count = self.error_count
        health.last_error_time = int(self.last_error_time)

        health.status = "healthy" if self.error_count == 0 else "degraded"
        health.active_alerts = self.active_alerts

        self.health_pub.publish(health)


def main(args=None):
    rclpy.init(args=args)

    try:
        node = DefectInferenceNode()
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    except Exception as e:
        print(f"Node error: {e}")
        raise
    finally:
        rclpy.shutdown()


if __name__ == "__main__":
    main()
