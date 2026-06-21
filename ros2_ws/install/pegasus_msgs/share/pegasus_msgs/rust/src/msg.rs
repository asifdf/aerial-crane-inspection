#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to pegasus_msgs__msg__DefectDetection
/// Single defect detection result

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DefectDetection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// Classification
    /// "crack", "corrosion", "paint_damage"
    pub type_: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub class_id: u8,

    /// Confidence [0.0, 1.0]
    pub confidence: f32,

    /// Bounding box in pixel coordinates (top-left origin)
    pub bbox_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_width: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_height: f32,

    /// Optional: normalized bbox [0,1] for resolution-invariant use
    pub bbox_x_norm: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_y_norm: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_width_norm: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_height_norm: f32,

    /// Risk assessment
    /// "low", "medium", "high", "critical"
    pub risk_level: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub risk_id: u8,

    /// Optional segmentation mask (compressed PNG)
    pub mask: sensor_msgs::msg::CompressedImage,

    /// 3D position estimate (if depth available)
    pub position_3d: geometry_msgs::msg::Point,


    // This member is not documented.
    #[allow(missing_docs)]
    pub has_3d_position: bool,

}

impl DefectDetection {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CLASS_CRACK: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CLASS_CORROSION: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CLASS_PAINT_DAMAGE: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RISK_LOW: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RISK_MEDIUM: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RISK_HIGH: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RISK_CRITICAL: u8 = 3;

}


impl Default for DefectDetection {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::DefectDetection::default())
  }
}

impl rosidl_runtime_rs::Message for DefectDetection {
  type RmwMsg = super::msg::rmw::DefectDetection;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        type_: msg.type_.as_str().into(),
        class_id: msg.class_id,
        confidence: msg.confidence,
        bbox_x: msg.bbox_x,
        bbox_y: msg.bbox_y,
        bbox_width: msg.bbox_width,
        bbox_height: msg.bbox_height,
        bbox_x_norm: msg.bbox_x_norm,
        bbox_y_norm: msg.bbox_y_norm,
        bbox_width_norm: msg.bbox_width_norm,
        bbox_height_norm: msg.bbox_height_norm,
        risk_level: msg.risk_level.as_str().into(),
        risk_id: msg.risk_id,
        mask: sensor_msgs::msg::CompressedImage::into_rmw_message(std::borrow::Cow::Owned(msg.mask)).into_owned(),
        position_3d: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.position_3d)).into_owned(),
        has_3d_position: msg.has_3d_position,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        type_: msg.type_.as_str().into(),
      class_id: msg.class_id,
      confidence: msg.confidence,
      bbox_x: msg.bbox_x,
      bbox_y: msg.bbox_y,
      bbox_width: msg.bbox_width,
      bbox_height: msg.bbox_height,
      bbox_x_norm: msg.bbox_x_norm,
      bbox_y_norm: msg.bbox_y_norm,
      bbox_width_norm: msg.bbox_width_norm,
      bbox_height_norm: msg.bbox_height_norm,
        risk_level: msg.risk_level.as_str().into(),
      risk_id: msg.risk_id,
        mask: sensor_msgs::msg::CompressedImage::into_rmw_message(std::borrow::Cow::Borrowed(&msg.mask)).into_owned(),
        position_3d: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.position_3d)).into_owned(),
      has_3d_position: msg.has_3d_position,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      type_: msg.type_.to_string(),
      class_id: msg.class_id,
      confidence: msg.confidence,
      bbox_x: msg.bbox_x,
      bbox_y: msg.bbox_y,
      bbox_width: msg.bbox_width,
      bbox_height: msg.bbox_height,
      bbox_x_norm: msg.bbox_x_norm,
      bbox_y_norm: msg.bbox_y_norm,
      bbox_width_norm: msg.bbox_width_norm,
      bbox_height_norm: msg.bbox_height_norm,
      risk_level: msg.risk_level.to_string(),
      risk_id: msg.risk_id,
      mask: sensor_msgs::msg::CompressedImage::from_rmw_message(msg.mask),
      position_3d: geometry_msgs::msg::Point::from_rmw_message(msg.position_3d),
      has_3d_position: msg.has_3d_position,
    }
  }
}


// Corresponds to pegasus_msgs__msg__DefectArray
/// Array of defect detections for a single frame

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DefectArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub drone_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zone_id: std::string::String,

    /// All detections in this frame
    pub detections: Vec<super::msg::DefectDetection>,

    /// Summary counts
    pub total_count: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub crack_count: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub corrosion_count: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub paint_damage_count: u32,

    /// Highest risk in this frame
    pub max_risk_level: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub max_risk_id: u8,

    /// Processing latency (seconds)
    pub inference_latency: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub total_latency: f32,

}



impl Default for DefectArray {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::DefectArray::default())
  }
}

impl rosidl_runtime_rs::Message for DefectArray {
  type RmwMsg = super::msg::rmw::DefectArray;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        drone_id: msg.drone_id.as_str().into(),
        zone_id: msg.zone_id.as_str().into(),
        detections: msg.detections
          .into_iter()
          .map(|elem| super::msg::DefectDetection::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        total_count: msg.total_count,
        crack_count: msg.crack_count,
        corrosion_count: msg.corrosion_count,
        paint_damage_count: msg.paint_damage_count,
        max_risk_level: msg.max_risk_level.as_str().into(),
        max_risk_id: msg.max_risk_id,
        inference_latency: msg.inference_latency,
        total_latency: msg.total_latency,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        drone_id: msg.drone_id.as_str().into(),
        zone_id: msg.zone_id.as_str().into(),
        detections: msg.detections
          .iter()
          .map(|elem| super::msg::DefectDetection::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      total_count: msg.total_count,
      crack_count: msg.crack_count,
      corrosion_count: msg.corrosion_count,
      paint_damage_count: msg.paint_damage_count,
        max_risk_level: msg.max_risk_level.as_str().into(),
      max_risk_id: msg.max_risk_id,
      inference_latency: msg.inference_latency,
      total_latency: msg.total_latency,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      drone_id: msg.drone_id.to_string(),
      zone_id: msg.zone_id.to_string(),
      detections: msg.detections
          .into_iter()
          .map(super::msg::DefectDetection::from_rmw_message)
          .collect(),
      total_count: msg.total_count,
      crack_count: msg.crack_count,
      corrosion_count: msg.corrosion_count,
      paint_damage_count: msg.paint_damage_count,
      max_risk_level: msg.max_risk_level.to_string(),
      max_risk_id: msg.max_risk_id,
      inference_latency: msg.inference_latency,
      total_latency: msg.total_latency,
    }
  }
}


// Corresponds to pegasus_msgs__msg__InspectionResult
/// Complete inspection result for dashboard/backend

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InspectionResult {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub drone_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mission_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zone_id: std::string::String,

    /// Drone pose at time of inspection
    pub drone_pose: geometry_msgs::msg::PoseStamped,

    /// Defects found
    pub defects: super::msg::DefectArray,

    /// Zone coverage info
    pub coverage_percent: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub images_captured: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub images_with_defects: u32,

    /// Overall zone risk
    pub zone_risk_level: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zone_risk_id: u8,

    /// JSON payload (for direct backend ingestion)
    pub json_payload: std::string::String,

}



impl Default for InspectionResult {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::InspectionResult::default())
  }
}

impl rosidl_runtime_rs::Message for InspectionResult {
  type RmwMsg = super::msg::rmw::InspectionResult;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        drone_id: msg.drone_id.as_str().into(),
        mission_id: msg.mission_id.as_str().into(),
        zone_id: msg.zone_id.as_str().into(),
        drone_pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(msg.drone_pose)).into_owned(),
        defects: super::msg::DefectArray::into_rmw_message(std::borrow::Cow::Owned(msg.defects)).into_owned(),
        coverage_percent: msg.coverage_percent,
        images_captured: msg.images_captured,
        images_with_defects: msg.images_with_defects,
        zone_risk_level: msg.zone_risk_level.as_str().into(),
        zone_risk_id: msg.zone_risk_id,
        json_payload: msg.json_payload.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        drone_id: msg.drone_id.as_str().into(),
        mission_id: msg.mission_id.as_str().into(),
        zone_id: msg.zone_id.as_str().into(),
        drone_pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.drone_pose)).into_owned(),
        defects: super::msg::DefectArray::into_rmw_message(std::borrow::Cow::Borrowed(&msg.defects)).into_owned(),
      coverage_percent: msg.coverage_percent,
      images_captured: msg.images_captured,
      images_with_defects: msg.images_with_defects,
        zone_risk_level: msg.zone_risk_level.as_str().into(),
      zone_risk_id: msg.zone_risk_id,
        json_payload: msg.json_payload.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      drone_id: msg.drone_id.to_string(),
      mission_id: msg.mission_id.to_string(),
      zone_id: msg.zone_id.to_string(),
      drone_pose: geometry_msgs::msg::PoseStamped::from_rmw_message(msg.drone_pose),
      defects: super::msg::DefectArray::from_rmw_message(msg.defects),
      coverage_percent: msg.coverage_percent,
      images_captured: msg.images_captured,
      images_with_defects: msg.images_with_defects,
      zone_risk_level: msg.zone_risk_level.to_string(),
      zone_risk_id: msg.zone_risk_id,
      json_payload: msg.json_payload.to_string(),
    }
  }
}


// Corresponds to pegasus_msgs__msg__ZoneInfo
/// Crane zone definition for mission planning

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ZoneInfo {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zone_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zone_name: std::string::String,

    /// "beam", "column", "cable", "joint", "custom"
    pub zone_type: std::string::String,

    /// 3D bounding box of zone (in world frame)
    pub zone_center: geometry_msgs::msg::Pose,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zone_dimensions: geometry_msgs::msg::Vector3,

    /// Inspection parameters
    pub waypoints_x: Vec<f32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub waypoints_y: Vec<f32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub waypoints_z: Vec<f32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub waypoints_yaw: Vec<f32>,

    /// Camera angles for this zone
    pub camera_pitch: Vec<f32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub camera_yaw: Vec<f32>,

    /// Expected defect types in this zone
    pub expected_defects: Vec<std::string::String>,

    /// Priority
    /// 1=high, 2=medium, 3=low
    pub priority: u8,

}



impl Default for ZoneInfo {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ZoneInfo::default())
  }
}

impl rosidl_runtime_rs::Message for ZoneInfo {
  type RmwMsg = super::msg::rmw::ZoneInfo;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        zone_id: msg.zone_id.as_str().into(),
        zone_name: msg.zone_name.as_str().into(),
        zone_type: msg.zone_type.as_str().into(),
        zone_center: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.zone_center)).into_owned(),
        zone_dimensions: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Owned(msg.zone_dimensions)).into_owned(),
        waypoints_x: msg.waypoints_x.into(),
        waypoints_y: msg.waypoints_y.into(),
        waypoints_z: msg.waypoints_z.into(),
        waypoints_yaw: msg.waypoints_yaw.into(),
        camera_pitch: msg.camera_pitch.into(),
        camera_yaw: msg.camera_yaw.into(),
        expected_defects: msg.expected_defects
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        priority: msg.priority,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        zone_id: msg.zone_id.as_str().into(),
        zone_name: msg.zone_name.as_str().into(),
        zone_type: msg.zone_type.as_str().into(),
        zone_center: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.zone_center)).into_owned(),
        zone_dimensions: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Borrowed(&msg.zone_dimensions)).into_owned(),
        waypoints_x: msg.waypoints_x.as_slice().into(),
        waypoints_y: msg.waypoints_y.as_slice().into(),
        waypoints_z: msg.waypoints_z.as_slice().into(),
        waypoints_yaw: msg.waypoints_yaw.as_slice().into(),
        camera_pitch: msg.camera_pitch.as_slice().into(),
        camera_yaw: msg.camera_yaw.as_slice().into(),
        expected_defects: msg.expected_defects
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      priority: msg.priority,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      zone_id: msg.zone_id.to_string(),
      zone_name: msg.zone_name.to_string(),
      zone_type: msg.zone_type.to_string(),
      zone_center: geometry_msgs::msg::Pose::from_rmw_message(msg.zone_center),
      zone_dimensions: geometry_msgs::msg::Vector3::from_rmw_message(msg.zone_dimensions),
      waypoints_x: msg.waypoints_x
          .into_iter()
          .collect(),
      waypoints_y: msg.waypoints_y
          .into_iter()
          .collect(),
      waypoints_z: msg.waypoints_z
          .into_iter()
          .collect(),
      waypoints_yaw: msg.waypoints_yaw
          .into_iter()
          .collect(),
      camera_pitch: msg.camera_pitch
          .into_iter()
          .collect(),
      camera_yaw: msg.camera_yaw
          .into_iter()
          .collect(),
      expected_defects: msg.expected_defects
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      priority: msg.priority,
    }
  }
}


// Corresponds to pegasus_msgs__msg__NodeHealth
/// AI inference node health status

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NodeHealth {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub node_name: std::string::String,

    /// e.g., "jetson_orin_nano_super"
    pub device_id: std::string::String,

    /// Performance metrics
    pub fps: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub avg_latency_ms: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p95_latency_ms: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p99_latency_ms: f32,

    /// Resource usage
    pub gpu_util_percent: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gpu_mem_used_mb: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gpu_mem_total_mb: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cpu_util_percent: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cpu_mem_used_mb: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cpu_mem_total_mb: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub temperature_c: f32,

    /// Model info
    pub model_path: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub model_version: std::string::String,

    /// "fp32", "fp16", "int8"
    pub precision: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub input_width: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub input_height: u32,

    /// Counters
    pub frames_processed: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub detections_published: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub errors_count: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub last_error_time: u64,

    /// Status
    /// "healthy", "degraded", "error", "starting"
    pub status: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub active_alerts: Vec<std::string::String>,

}



impl Default for NodeHealth {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::NodeHealth::default())
  }
}

impl rosidl_runtime_rs::Message for NodeHealth {
  type RmwMsg = super::msg::rmw::NodeHealth;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        node_name: msg.node_name.as_str().into(),
        device_id: msg.device_id.as_str().into(),
        fps: msg.fps,
        avg_latency_ms: msg.avg_latency_ms,
        p95_latency_ms: msg.p95_latency_ms,
        p99_latency_ms: msg.p99_latency_ms,
        gpu_util_percent: msg.gpu_util_percent,
        gpu_mem_used_mb: msg.gpu_mem_used_mb,
        gpu_mem_total_mb: msg.gpu_mem_total_mb,
        cpu_util_percent: msg.cpu_util_percent,
        cpu_mem_used_mb: msg.cpu_mem_used_mb,
        cpu_mem_total_mb: msg.cpu_mem_total_mb,
        temperature_c: msg.temperature_c,
        model_path: msg.model_path.as_str().into(),
        model_version: msg.model_version.as_str().into(),
        precision: msg.precision.as_str().into(),
        input_width: msg.input_width,
        input_height: msg.input_height,
        frames_processed: msg.frames_processed,
        detections_published: msg.detections_published,
        errors_count: msg.errors_count,
        last_error_time: msg.last_error_time,
        status: msg.status.as_str().into(),
        active_alerts: msg.active_alerts
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        node_name: msg.node_name.as_str().into(),
        device_id: msg.device_id.as_str().into(),
      fps: msg.fps,
      avg_latency_ms: msg.avg_latency_ms,
      p95_latency_ms: msg.p95_latency_ms,
      p99_latency_ms: msg.p99_latency_ms,
      gpu_util_percent: msg.gpu_util_percent,
      gpu_mem_used_mb: msg.gpu_mem_used_mb,
      gpu_mem_total_mb: msg.gpu_mem_total_mb,
      cpu_util_percent: msg.cpu_util_percent,
      cpu_mem_used_mb: msg.cpu_mem_used_mb,
      cpu_mem_total_mb: msg.cpu_mem_total_mb,
      temperature_c: msg.temperature_c,
        model_path: msg.model_path.as_str().into(),
        model_version: msg.model_version.as_str().into(),
        precision: msg.precision.as_str().into(),
      input_width: msg.input_width,
      input_height: msg.input_height,
      frames_processed: msg.frames_processed,
      detections_published: msg.detections_published,
      errors_count: msg.errors_count,
      last_error_time: msg.last_error_time,
        status: msg.status.as_str().into(),
        active_alerts: msg.active_alerts
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      node_name: msg.node_name.to_string(),
      device_id: msg.device_id.to_string(),
      fps: msg.fps,
      avg_latency_ms: msg.avg_latency_ms,
      p95_latency_ms: msg.p95_latency_ms,
      p99_latency_ms: msg.p99_latency_ms,
      gpu_util_percent: msg.gpu_util_percent,
      gpu_mem_used_mb: msg.gpu_mem_used_mb,
      gpu_mem_total_mb: msg.gpu_mem_total_mb,
      cpu_util_percent: msg.cpu_util_percent,
      cpu_mem_used_mb: msg.cpu_mem_used_mb,
      cpu_mem_total_mb: msg.cpu_mem_total_mb,
      temperature_c: msg.temperature_c,
      model_path: msg.model_path.to_string(),
      model_version: msg.model_version.to_string(),
      precision: msg.precision.to_string(),
      input_width: msg.input_width,
      input_height: msg.input_height,
      frames_processed: msg.frames_processed,
      detections_published: msg.detections_published,
      errors_count: msg.errors_count,
      last_error_time: msg.last_error_time,
      status: msg.status.to_string(),
      active_alerts: msg.active_alerts
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
    }
  }
}


