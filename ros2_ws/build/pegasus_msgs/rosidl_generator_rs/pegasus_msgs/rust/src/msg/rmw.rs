#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "pegasus_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__pegasus_msgs__msg__DefectDetection() -> *const std::ffi::c_void;
}

#[link(name = "pegasus_msgs__rosidl_generator_c")]
extern "C" {
    fn pegasus_msgs__msg__DefectDetection__init(msg: *mut DefectDetection) -> bool;
    fn pegasus_msgs__msg__DefectDetection__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DefectDetection>, size: usize) -> bool;
    fn pegasus_msgs__msg__DefectDetection__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DefectDetection>);
    fn pegasus_msgs__msg__DefectDetection__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DefectDetection>, out_seq: *mut rosidl_runtime_rs::Sequence<DefectDetection>) -> bool;
}

// Corresponds to pegasus_msgs__msg__DefectDetection
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Single defect detection result

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DefectDetection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// Classification
    /// "crack", "corrosion", "paint_damage"
    pub type_: rosidl_runtime_rs::String,


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
    pub risk_level: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub risk_id: u8,

    /// Optional segmentation mask (compressed PNG)
    pub mask: sensor_msgs::msg::rmw::CompressedImage,

    /// 3D position estimate (if depth available)
    pub position_3d: geometry_msgs::msg::rmw::Point,


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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !pegasus_msgs__msg__DefectDetection__init(&mut msg as *mut _) {
        panic!("Call to pegasus_msgs__msg__DefectDetection__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DefectDetection {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pegasus_msgs__msg__DefectDetection__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pegasus_msgs__msg__DefectDetection__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pegasus_msgs__msg__DefectDetection__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DefectDetection {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DefectDetection where Self: Sized {
  const TYPE_NAME: &'static str = "pegasus_msgs/msg/DefectDetection";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__pegasus_msgs__msg__DefectDetection() }
  }
}


#[link(name = "pegasus_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__pegasus_msgs__msg__DefectArray() -> *const std::ffi::c_void;
}

#[link(name = "pegasus_msgs__rosidl_generator_c")]
extern "C" {
    fn pegasus_msgs__msg__DefectArray__init(msg: *mut DefectArray) -> bool;
    fn pegasus_msgs__msg__DefectArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DefectArray>, size: usize) -> bool;
    fn pegasus_msgs__msg__DefectArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DefectArray>);
    fn pegasus_msgs__msg__DefectArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DefectArray>, out_seq: *mut rosidl_runtime_rs::Sequence<DefectArray>) -> bool;
}

// Corresponds to pegasus_msgs__msg__DefectArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Array of defect detections for a single frame

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DefectArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub drone_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zone_id: rosidl_runtime_rs::String,

    /// All detections in this frame
    pub detections: rosidl_runtime_rs::Sequence<super::super::msg::rmw::DefectDetection>,

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
    pub max_risk_level: rosidl_runtime_rs::String,


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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !pegasus_msgs__msg__DefectArray__init(&mut msg as *mut _) {
        panic!("Call to pegasus_msgs__msg__DefectArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DefectArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pegasus_msgs__msg__DefectArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pegasus_msgs__msg__DefectArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pegasus_msgs__msg__DefectArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DefectArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DefectArray where Self: Sized {
  const TYPE_NAME: &'static str = "pegasus_msgs/msg/DefectArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__pegasus_msgs__msg__DefectArray() }
  }
}


#[link(name = "pegasus_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__pegasus_msgs__msg__InspectionResult() -> *const std::ffi::c_void;
}

#[link(name = "pegasus_msgs__rosidl_generator_c")]
extern "C" {
    fn pegasus_msgs__msg__InspectionResult__init(msg: *mut InspectionResult) -> bool;
    fn pegasus_msgs__msg__InspectionResult__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<InspectionResult>, size: usize) -> bool;
    fn pegasus_msgs__msg__InspectionResult__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<InspectionResult>);
    fn pegasus_msgs__msg__InspectionResult__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<InspectionResult>, out_seq: *mut rosidl_runtime_rs::Sequence<InspectionResult>) -> bool;
}

// Corresponds to pegasus_msgs__msg__InspectionResult
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Complete inspection result for dashboard/backend

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InspectionResult {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub drone_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mission_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zone_id: rosidl_runtime_rs::String,

    /// Drone pose at time of inspection
    pub drone_pose: geometry_msgs::msg::rmw::PoseStamped,

    /// Defects found
    pub defects: super::super::msg::rmw::DefectArray,

    /// Zone coverage info
    pub coverage_percent: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub images_captured: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub images_with_defects: u32,

    /// Overall zone risk
    pub zone_risk_level: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zone_risk_id: u8,

    /// JSON payload (for direct backend ingestion)
    pub json_payload: rosidl_runtime_rs::String,

}



impl Default for InspectionResult {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !pegasus_msgs__msg__InspectionResult__init(&mut msg as *mut _) {
        panic!("Call to pegasus_msgs__msg__InspectionResult__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for InspectionResult {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pegasus_msgs__msg__InspectionResult__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pegasus_msgs__msg__InspectionResult__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pegasus_msgs__msg__InspectionResult__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for InspectionResult {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for InspectionResult where Self: Sized {
  const TYPE_NAME: &'static str = "pegasus_msgs/msg/InspectionResult";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__pegasus_msgs__msg__InspectionResult() }
  }
}


#[link(name = "pegasus_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__pegasus_msgs__msg__ZoneInfo() -> *const std::ffi::c_void;
}

#[link(name = "pegasus_msgs__rosidl_generator_c")]
extern "C" {
    fn pegasus_msgs__msg__ZoneInfo__init(msg: *mut ZoneInfo) -> bool;
    fn pegasus_msgs__msg__ZoneInfo__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ZoneInfo>, size: usize) -> bool;
    fn pegasus_msgs__msg__ZoneInfo__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ZoneInfo>);
    fn pegasus_msgs__msg__ZoneInfo__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ZoneInfo>, out_seq: *mut rosidl_runtime_rs::Sequence<ZoneInfo>) -> bool;
}

// Corresponds to pegasus_msgs__msg__ZoneInfo
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Crane zone definition for mission planning

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ZoneInfo {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zone_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zone_name: rosidl_runtime_rs::String,

    /// "beam", "column", "cable", "joint", "custom"
    pub zone_type: rosidl_runtime_rs::String,

    /// 3D bounding box of zone (in world frame)
    pub zone_center: geometry_msgs::msg::rmw::Pose,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zone_dimensions: geometry_msgs::msg::rmw::Vector3,

    /// Inspection parameters
    pub waypoints_x: rosidl_runtime_rs::Sequence<f32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub waypoints_y: rosidl_runtime_rs::Sequence<f32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub waypoints_z: rosidl_runtime_rs::Sequence<f32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub waypoints_yaw: rosidl_runtime_rs::Sequence<f32>,

    /// Camera angles for this zone
    pub camera_pitch: rosidl_runtime_rs::Sequence<f32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub camera_yaw: rosidl_runtime_rs::Sequence<f32>,

    /// Expected defect types in this zone
    pub expected_defects: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

    /// Priority
    /// 1=high, 2=medium, 3=low
    pub priority: u8,

}



impl Default for ZoneInfo {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !pegasus_msgs__msg__ZoneInfo__init(&mut msg as *mut _) {
        panic!("Call to pegasus_msgs__msg__ZoneInfo__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ZoneInfo {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pegasus_msgs__msg__ZoneInfo__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pegasus_msgs__msg__ZoneInfo__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pegasus_msgs__msg__ZoneInfo__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ZoneInfo {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ZoneInfo where Self: Sized {
  const TYPE_NAME: &'static str = "pegasus_msgs/msg/ZoneInfo";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__pegasus_msgs__msg__ZoneInfo() }
  }
}


#[link(name = "pegasus_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__pegasus_msgs__msg__NodeHealth() -> *const std::ffi::c_void;
}

#[link(name = "pegasus_msgs__rosidl_generator_c")]
extern "C" {
    fn pegasus_msgs__msg__NodeHealth__init(msg: *mut NodeHealth) -> bool;
    fn pegasus_msgs__msg__NodeHealth__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NodeHealth>, size: usize) -> bool;
    fn pegasus_msgs__msg__NodeHealth__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NodeHealth>);
    fn pegasus_msgs__msg__NodeHealth__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NodeHealth>, out_seq: *mut rosidl_runtime_rs::Sequence<NodeHealth>) -> bool;
}

// Corresponds to pegasus_msgs__msg__NodeHealth
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// AI inference node health status

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NodeHealth {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub node_name: rosidl_runtime_rs::String,

    /// e.g., "jetson_orin_nano_super"
    pub device_id: rosidl_runtime_rs::String,

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
    pub model_path: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub model_version: rosidl_runtime_rs::String,

    /// "fp32", "fp16", "int8"
    pub precision: rosidl_runtime_rs::String,


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
    pub status: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub active_alerts: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

}



impl Default for NodeHealth {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !pegasus_msgs__msg__NodeHealth__init(&mut msg as *mut _) {
        panic!("Call to pegasus_msgs__msg__NodeHealth__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NodeHealth {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pegasus_msgs__msg__NodeHealth__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pegasus_msgs__msg__NodeHealth__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { pegasus_msgs__msg__NodeHealth__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NodeHealth {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NodeHealth where Self: Sized {
  const TYPE_NAME: &'static str = "pegasus_msgs/msg/NodeHealth";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__pegasus_msgs__msg__NodeHealth() }
  }
}


