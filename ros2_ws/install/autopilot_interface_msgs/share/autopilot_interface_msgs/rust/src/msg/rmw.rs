#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__msg__OffboardFlag() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__msg__OffboardFlag__init(msg: *mut OffboardFlag) -> bool;
    fn autopilot_interface_msgs__msg__OffboardFlag__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<OffboardFlag>, size: usize) -> bool;
    fn autopilot_interface_msgs__msg__OffboardFlag__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<OffboardFlag>);
    fn autopilot_interface_msgs__msg__OffboardFlag__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<OffboardFlag>, out_seq: *mut rosidl_runtime_rs::Sequence<OffboardFlag>) -> bool;
}

// Corresponds to autopilot_interface_msgs__msg__OffboardFlag
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct OffboardFlag {

    // This member is not documented.
    #[allow(missing_docs)]
    pub offboard_flag: u8,

}

impl OffboardFlag {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const INACTIVE: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PX4_QUAD_ATTITUDE: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PX4_VTOL_ATTITUDE: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PX4_QUAD_RATES: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PX4_VTOL_RATES: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PX4_QUAD_TRAJECTORY: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PX4_VTOL_TRAJECTORY: u8 = 6;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const AP_QUAD_VELOCITY: u8 = 7;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const AP_QUAD_ACCELERATION: u8 = 8;

}


impl Default for OffboardFlag {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__msg__OffboardFlag__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__msg__OffboardFlag__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for OffboardFlag {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__msg__OffboardFlag__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__msg__OffboardFlag__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__msg__OffboardFlag__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for OffboardFlag {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for OffboardFlag where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/msg/OffboardFlag";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__msg__OffboardFlag() }
  }
}


