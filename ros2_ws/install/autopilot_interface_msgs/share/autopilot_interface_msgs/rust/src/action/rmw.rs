
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Land_Goal() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Land_Goal__init(msg: *mut Land_Goal) -> bool;
    fn autopilot_interface_msgs__action__Land_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Land_Goal>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Land_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Land_Goal>);
    fn autopilot_interface_msgs__action__Land_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Land_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<Land_Goal>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Land_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub landing_altitude: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub vtol_transition_heading: f64,

}



impl Default for Land_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Land_Goal__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Land_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Land_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Land_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Land_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Land_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Land_Goal() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Land_Result() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Land_Result__init(msg: *mut Land_Result) -> bool;
    fn autopilot_interface_msgs__action__Land_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Land_Result>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Land_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Land_Result>);
    fn autopilot_interface_msgs__action__Land_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Land_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<Land_Result>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Land_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Land_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Land_Result__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Land_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Land_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Land_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Land_Result where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Land_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Land_Result() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Land_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Land_Feedback__init(msg: *mut Land_Feedback) -> bool;
    fn autopilot_interface_msgs__action__Land_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Land_Feedback>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Land_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Land_Feedback>);
    fn autopilot_interface_msgs__action__Land_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Land_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<Land_Feedback>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Land_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for Land_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Land_Feedback__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Land_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Land_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Land_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Land_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Land_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Land_Feedback() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Land_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Land_FeedbackMessage__init(msg: *mut Land_FeedbackMessage) -> bool;
    fn autopilot_interface_msgs__action__Land_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Land_FeedbackMessage>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Land_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Land_FeedbackMessage>);
    fn autopilot_interface_msgs__action__Land_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Land_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<Land_FeedbackMessage>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Land_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::Land_Feedback,

}



impl Default for Land_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Land_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Land_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Land_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Land_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Land_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Land_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Land_FeedbackMessage() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Offboard_Goal() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Offboard_Goal__init(msg: *mut Offboard_Goal) -> bool;
    fn autopilot_interface_msgs__action__Offboard_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Offboard_Goal>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Offboard_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Offboard_Goal>);
    fn autopilot_interface_msgs__action__Offboard_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Offboard_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<Offboard_Goal>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Offboard_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Offboard_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub offboard_setpoint_type: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub max_duration_sec: f64,

}

impl Offboard_Goal {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ATTITUDE: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RATES: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRAJECTORY: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VELOCITY: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ACCELERATION: u8 = 4;

}


impl Default for Offboard_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Offboard_Goal__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Offboard_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Offboard_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Offboard_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Offboard_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Offboard_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Offboard_Goal() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Offboard_Result() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Offboard_Result__init(msg: *mut Offboard_Result) -> bool;
    fn autopilot_interface_msgs__action__Offboard_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Offboard_Result>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Offboard_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Offboard_Result>);
    fn autopilot_interface_msgs__action__Offboard_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Offboard_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<Offboard_Result>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Offboard_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Offboard_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Offboard_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Offboard_Result__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Offboard_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Offboard_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Offboard_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Offboard_Result where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Offboard_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Offboard_Result() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Offboard_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Offboard_Feedback__init(msg: *mut Offboard_Feedback) -> bool;
    fn autopilot_interface_msgs__action__Offboard_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Offboard_Feedback>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Offboard_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Offboard_Feedback>);
    fn autopilot_interface_msgs__action__Offboard_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Offboard_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<Offboard_Feedback>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Offboard_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Offboard_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for Offboard_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Offboard_Feedback__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Offboard_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Offboard_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Offboard_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Offboard_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Offboard_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Offboard_Feedback() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Offboard_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Offboard_FeedbackMessage__init(msg: *mut Offboard_FeedbackMessage) -> bool;
    fn autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Offboard_FeedbackMessage>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Offboard_FeedbackMessage>);
    fn autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Offboard_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<Offboard_FeedbackMessage>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Offboard_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Offboard_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::Offboard_Feedback,

}



impl Default for Offboard_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Offboard_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Offboard_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Offboard_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Offboard_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Offboard_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Offboard_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Offboard_FeedbackMessage() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Orbit_Goal() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Orbit_Goal__init(msg: *mut Orbit_Goal) -> bool;
    fn autopilot_interface_msgs__action__Orbit_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Orbit_Goal>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Orbit_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Orbit_Goal>);
    fn autopilot_interface_msgs__action__Orbit_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Orbit_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<Orbit_Goal>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Orbit_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Orbit_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub east: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub north: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub altitude: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub radius: f64,

}



impl Default for Orbit_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Orbit_Goal__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Orbit_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Orbit_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Orbit_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Orbit_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Orbit_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Orbit_Goal() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Orbit_Result() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Orbit_Result__init(msg: *mut Orbit_Result) -> bool;
    fn autopilot_interface_msgs__action__Orbit_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Orbit_Result>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Orbit_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Orbit_Result>);
    fn autopilot_interface_msgs__action__Orbit_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Orbit_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<Orbit_Result>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Orbit_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Orbit_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Orbit_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Orbit_Result__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Orbit_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Orbit_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Orbit_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Orbit_Result where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Orbit_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Orbit_Result() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Orbit_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Orbit_Feedback__init(msg: *mut Orbit_Feedback) -> bool;
    fn autopilot_interface_msgs__action__Orbit_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Orbit_Feedback>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Orbit_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Orbit_Feedback>);
    fn autopilot_interface_msgs__action__Orbit_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Orbit_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<Orbit_Feedback>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Orbit_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Orbit_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for Orbit_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Orbit_Feedback__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Orbit_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Orbit_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Orbit_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Orbit_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Orbit_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Orbit_Feedback() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Orbit_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Orbit_FeedbackMessage__init(msg: *mut Orbit_FeedbackMessage) -> bool;
    fn autopilot_interface_msgs__action__Orbit_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Orbit_FeedbackMessage>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Orbit_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Orbit_FeedbackMessage>);
    fn autopilot_interface_msgs__action__Orbit_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Orbit_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<Orbit_FeedbackMessage>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Orbit_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Orbit_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::Orbit_Feedback,

}



impl Default for Orbit_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Orbit_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Orbit_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Orbit_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Orbit_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Orbit_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Orbit_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Orbit_FeedbackMessage() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Takeoff_Goal() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Takeoff_Goal__init(msg: *mut Takeoff_Goal) -> bool;
    fn autopilot_interface_msgs__action__Takeoff_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_Goal>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Takeoff_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_Goal>);
    fn autopilot_interface_msgs__action__Takeoff_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Takeoff_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<Takeoff_Goal>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Takeoff_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub takeoff_altitude: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub vtol_transition_heading: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub vtol_loiter_nord: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub vtol_loiter_east: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub vtol_loiter_alt: f64,

}



impl Default for Takeoff_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Takeoff_Goal__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Takeoff_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Takeoff_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Takeoff_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Takeoff_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Takeoff_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Takeoff_Goal() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Takeoff_Result() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Takeoff_Result__init(msg: *mut Takeoff_Result) -> bool;
    fn autopilot_interface_msgs__action__Takeoff_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_Result>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Takeoff_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_Result>);
    fn autopilot_interface_msgs__action__Takeoff_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Takeoff_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<Takeoff_Result>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Takeoff_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Takeoff_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Takeoff_Result__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Takeoff_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Takeoff_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Takeoff_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Takeoff_Result where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Takeoff_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Takeoff_Result() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Takeoff_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Takeoff_Feedback__init(msg: *mut Takeoff_Feedback) -> bool;
    fn autopilot_interface_msgs__action__Takeoff_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_Feedback>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Takeoff_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_Feedback>);
    fn autopilot_interface_msgs__action__Takeoff_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Takeoff_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<Takeoff_Feedback>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Takeoff_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for Takeoff_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Takeoff_Feedback__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Takeoff_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Takeoff_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Takeoff_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Takeoff_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Takeoff_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Takeoff_Feedback() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Takeoff_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Takeoff_FeedbackMessage__init(msg: *mut Takeoff_FeedbackMessage) -> bool;
    fn autopilot_interface_msgs__action__Takeoff_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_FeedbackMessage>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Takeoff_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_FeedbackMessage>);
    fn autopilot_interface_msgs__action__Takeoff_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Takeoff_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<Takeoff_FeedbackMessage>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Takeoff_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::Takeoff_Feedback,

}



impl Default for Takeoff_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Takeoff_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Takeoff_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Takeoff_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Takeoff_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Takeoff_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Takeoff_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Takeoff_FeedbackMessage() }
  }
}




#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Land_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Land_SendGoal_Request__init(msg: *mut Land_SendGoal_Request) -> bool;
    fn autopilot_interface_msgs__action__Land_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Land_SendGoal_Request>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Land_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Land_SendGoal_Request>);
    fn autopilot_interface_msgs__action__Land_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Land_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Land_SendGoal_Request>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Land_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::Land_Goal,

}



impl Default for Land_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Land_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Land_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Land_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Land_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Land_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Land_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Land_SendGoal_Request() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Land_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Land_SendGoal_Response__init(msg: *mut Land_SendGoal_Response) -> bool;
    fn autopilot_interface_msgs__action__Land_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Land_SendGoal_Response>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Land_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Land_SendGoal_Response>);
    fn autopilot_interface_msgs__action__Land_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Land_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Land_SendGoal_Response>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Land_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for Land_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Land_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Land_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Land_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Land_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Land_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Land_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Land_SendGoal_Response() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Land_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Land_GetResult_Request__init(msg: *mut Land_GetResult_Request) -> bool;
    fn autopilot_interface_msgs__action__Land_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Land_GetResult_Request>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Land_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Land_GetResult_Request>);
    fn autopilot_interface_msgs__action__Land_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Land_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Land_GetResult_Request>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Land_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for Land_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Land_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Land_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Land_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Land_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Land_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Land_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Land_GetResult_Request() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Land_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Land_GetResult_Response__init(msg: *mut Land_GetResult_Response) -> bool;
    fn autopilot_interface_msgs__action__Land_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Land_GetResult_Response>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Land_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Land_GetResult_Response>);
    fn autopilot_interface_msgs__action__Land_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Land_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Land_GetResult_Response>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Land_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::Land_Result,

}



impl Default for Land_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Land_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Land_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Land_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Land_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Land_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Land_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Land_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Land_GetResult_Response() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Offboard_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Offboard_SendGoal_Request__init(msg: *mut Offboard_SendGoal_Request) -> bool;
    fn autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Offboard_SendGoal_Request>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Offboard_SendGoal_Request>);
    fn autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Offboard_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Offboard_SendGoal_Request>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Offboard_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Offboard_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::Offboard_Goal,

}



impl Default for Offboard_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Offboard_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Offboard_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Offboard_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Offboard_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Offboard_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Offboard_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Offboard_SendGoal_Request() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Offboard_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Offboard_SendGoal_Response__init(msg: *mut Offboard_SendGoal_Response) -> bool;
    fn autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Offboard_SendGoal_Response>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Offboard_SendGoal_Response>);
    fn autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Offboard_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Offboard_SendGoal_Response>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Offboard_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Offboard_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for Offboard_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Offboard_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Offboard_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Offboard_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Offboard_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Offboard_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Offboard_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Offboard_SendGoal_Response() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Offboard_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Offboard_GetResult_Request__init(msg: *mut Offboard_GetResult_Request) -> bool;
    fn autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Offboard_GetResult_Request>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Offboard_GetResult_Request>);
    fn autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Offboard_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Offboard_GetResult_Request>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Offboard_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Offboard_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for Offboard_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Offboard_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Offboard_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Offboard_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Offboard_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Offboard_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Offboard_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Offboard_GetResult_Request() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Offboard_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Offboard_GetResult_Response__init(msg: *mut Offboard_GetResult_Response) -> bool;
    fn autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Offboard_GetResult_Response>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Offboard_GetResult_Response>);
    fn autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Offboard_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Offboard_GetResult_Response>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Offboard_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Offboard_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::Offboard_Result,

}



impl Default for Offboard_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Offboard_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Offboard_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Offboard_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Offboard_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Offboard_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Offboard_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Offboard_GetResult_Response() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Orbit_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Orbit_SendGoal_Request__init(msg: *mut Orbit_SendGoal_Request) -> bool;
    fn autopilot_interface_msgs__action__Orbit_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Orbit_SendGoal_Request>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Orbit_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Orbit_SendGoal_Request>);
    fn autopilot_interface_msgs__action__Orbit_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Orbit_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Orbit_SendGoal_Request>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Orbit_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Orbit_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::Orbit_Goal,

}



impl Default for Orbit_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Orbit_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Orbit_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Orbit_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Orbit_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Orbit_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Orbit_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Orbit_SendGoal_Request() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Orbit_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Orbit_SendGoal_Response__init(msg: *mut Orbit_SendGoal_Response) -> bool;
    fn autopilot_interface_msgs__action__Orbit_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Orbit_SendGoal_Response>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Orbit_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Orbit_SendGoal_Response>);
    fn autopilot_interface_msgs__action__Orbit_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Orbit_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Orbit_SendGoal_Response>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Orbit_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Orbit_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for Orbit_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Orbit_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Orbit_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Orbit_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Orbit_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Orbit_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Orbit_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Orbit_SendGoal_Response() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Orbit_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Orbit_GetResult_Request__init(msg: *mut Orbit_GetResult_Request) -> bool;
    fn autopilot_interface_msgs__action__Orbit_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Orbit_GetResult_Request>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Orbit_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Orbit_GetResult_Request>);
    fn autopilot_interface_msgs__action__Orbit_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Orbit_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Orbit_GetResult_Request>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Orbit_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Orbit_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for Orbit_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Orbit_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Orbit_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Orbit_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Orbit_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Orbit_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Orbit_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Orbit_GetResult_Request() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Orbit_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Orbit_GetResult_Response__init(msg: *mut Orbit_GetResult_Response) -> bool;
    fn autopilot_interface_msgs__action__Orbit_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Orbit_GetResult_Response>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Orbit_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Orbit_GetResult_Response>);
    fn autopilot_interface_msgs__action__Orbit_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Orbit_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Orbit_GetResult_Response>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Orbit_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Orbit_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::Orbit_Result,

}



impl Default for Orbit_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Orbit_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Orbit_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Orbit_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Orbit_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Orbit_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Orbit_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Orbit_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Orbit_GetResult_Response() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Takeoff_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Takeoff_SendGoal_Request__init(msg: *mut Takeoff_SendGoal_Request) -> bool;
    fn autopilot_interface_msgs__action__Takeoff_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_SendGoal_Request>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Takeoff_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_SendGoal_Request>);
    fn autopilot_interface_msgs__action__Takeoff_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Takeoff_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Takeoff_SendGoal_Request>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Takeoff_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::Takeoff_Goal,

}



impl Default for Takeoff_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Takeoff_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Takeoff_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Takeoff_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Takeoff_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Takeoff_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Takeoff_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Takeoff_SendGoal_Request() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Takeoff_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Takeoff_SendGoal_Response__init(msg: *mut Takeoff_SendGoal_Response) -> bool;
    fn autopilot_interface_msgs__action__Takeoff_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_SendGoal_Response>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Takeoff_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_SendGoal_Response>);
    fn autopilot_interface_msgs__action__Takeoff_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Takeoff_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Takeoff_SendGoal_Response>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Takeoff_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for Takeoff_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Takeoff_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Takeoff_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Takeoff_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Takeoff_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Takeoff_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Takeoff_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Takeoff_SendGoal_Response() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Takeoff_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Takeoff_GetResult_Request__init(msg: *mut Takeoff_GetResult_Request) -> bool;
    fn autopilot_interface_msgs__action__Takeoff_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_GetResult_Request>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Takeoff_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_GetResult_Request>);
    fn autopilot_interface_msgs__action__Takeoff_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Takeoff_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Takeoff_GetResult_Request>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Takeoff_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for Takeoff_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Takeoff_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Takeoff_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Takeoff_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Takeoff_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Takeoff_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Takeoff_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Takeoff_GetResult_Request() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Takeoff_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__action__Takeoff_GetResult_Response__init(msg: *mut Takeoff_GetResult_Response) -> bool;
    fn autopilot_interface_msgs__action__Takeoff_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_GetResult_Response>, size: usize) -> bool;
    fn autopilot_interface_msgs__action__Takeoff_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_GetResult_Response>);
    fn autopilot_interface_msgs__action__Takeoff_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Takeoff_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Takeoff_GetResult_Response>) -> bool;
}

// Corresponds to autopilot_interface_msgs__action__Takeoff_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::Takeoff_Result,

}



impl Default for Takeoff_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__action__Takeoff_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__action__Takeoff_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Takeoff_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__action__Takeoff_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Takeoff_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Takeoff_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/action/Takeoff_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__action__Takeoff_GetResult_Response() }
  }
}






#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__action__Land_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to autopilot_interface_msgs__action__Land_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct Land_SendGoal;

impl rosidl_runtime_rs::Service for Land_SendGoal {
    type Request = Land_SendGoal_Request;
    type Response = Land_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__action__Land_SendGoal() }
    }
}




#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__action__Land_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to autopilot_interface_msgs__action__Land_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct Land_GetResult;

impl rosidl_runtime_rs::Service for Land_GetResult {
    type Request = Land_GetResult_Request;
    type Response = Land_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__action__Land_GetResult() }
    }
}




#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__action__Offboard_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to autopilot_interface_msgs__action__Offboard_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct Offboard_SendGoal;

impl rosidl_runtime_rs::Service for Offboard_SendGoal {
    type Request = Offboard_SendGoal_Request;
    type Response = Offboard_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__action__Offboard_SendGoal() }
    }
}




#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__action__Offboard_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to autopilot_interface_msgs__action__Offboard_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct Offboard_GetResult;

impl rosidl_runtime_rs::Service for Offboard_GetResult {
    type Request = Offboard_GetResult_Request;
    type Response = Offboard_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__action__Offboard_GetResult() }
    }
}




#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__action__Orbit_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to autopilot_interface_msgs__action__Orbit_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct Orbit_SendGoal;

impl rosidl_runtime_rs::Service for Orbit_SendGoal {
    type Request = Orbit_SendGoal_Request;
    type Response = Orbit_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__action__Orbit_SendGoal() }
    }
}




#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__action__Orbit_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to autopilot_interface_msgs__action__Orbit_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct Orbit_GetResult;

impl rosidl_runtime_rs::Service for Orbit_GetResult {
    type Request = Orbit_GetResult_Request;
    type Response = Orbit_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__action__Orbit_GetResult() }
    }
}




#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__action__Takeoff_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to autopilot_interface_msgs__action__Takeoff_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct Takeoff_SendGoal;

impl rosidl_runtime_rs::Service for Takeoff_SendGoal {
    type Request = Takeoff_SendGoal_Request;
    type Response = Takeoff_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__action__Takeoff_SendGoal() }
    }
}




#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__action__Takeoff_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to autopilot_interface_msgs__action__Takeoff_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct Takeoff_GetResult;

impl rosidl_runtime_rs::Service for Takeoff_GetResult {
    type Request = Takeoff_GetResult_Request;
    type Response = Takeoff_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__action__Takeoff_GetResult() }
    }
}


