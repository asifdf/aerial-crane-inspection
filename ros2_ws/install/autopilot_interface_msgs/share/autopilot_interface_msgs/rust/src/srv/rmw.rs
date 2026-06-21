#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__srv__SetSpeed_Request() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__srv__SetSpeed_Request__init(msg: *mut SetSpeed_Request) -> bool;
    fn autopilot_interface_msgs__srv__SetSpeed_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetSpeed_Request>, size: usize) -> bool;
    fn autopilot_interface_msgs__srv__SetSpeed_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetSpeed_Request>);
    fn autopilot_interface_msgs__srv__SetSpeed_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetSpeed_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetSpeed_Request>) -> bool;
}

// Corresponds to autopilot_interface_msgs__srv__SetSpeed_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetSpeed_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub speed: f64,

}



impl Default for SetSpeed_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__srv__SetSpeed_Request__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__srv__SetSpeed_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetSpeed_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__srv__SetSpeed_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__srv__SetSpeed_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__srv__SetSpeed_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetSpeed_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetSpeed_Request where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/srv/SetSpeed_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__srv__SetSpeed_Request() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__srv__SetSpeed_Response() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__srv__SetSpeed_Response__init(msg: *mut SetSpeed_Response) -> bool;
    fn autopilot_interface_msgs__srv__SetSpeed_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetSpeed_Response>, size: usize) -> bool;
    fn autopilot_interface_msgs__srv__SetSpeed_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetSpeed_Response>);
    fn autopilot_interface_msgs__srv__SetSpeed_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetSpeed_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetSpeed_Response>) -> bool;
}

// Corresponds to autopilot_interface_msgs__srv__SetSpeed_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetSpeed_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for SetSpeed_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__srv__SetSpeed_Response__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__srv__SetSpeed_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetSpeed_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__srv__SetSpeed_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__srv__SetSpeed_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__srv__SetSpeed_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetSpeed_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetSpeed_Response where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/srv/SetSpeed_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__srv__SetSpeed_Response() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__srv__SetReposition_Request() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__srv__SetReposition_Request__init(msg: *mut SetReposition_Request) -> bool;
    fn autopilot_interface_msgs__srv__SetReposition_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetReposition_Request>, size: usize) -> bool;
    fn autopilot_interface_msgs__srv__SetReposition_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetReposition_Request>);
    fn autopilot_interface_msgs__srv__SetReposition_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetReposition_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetReposition_Request>) -> bool;
}

// Corresponds to autopilot_interface_msgs__srv__SetReposition_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetReposition_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub east: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub north: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub altitude: f64,

}



impl Default for SetReposition_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__srv__SetReposition_Request__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__srv__SetReposition_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetReposition_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__srv__SetReposition_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__srv__SetReposition_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__srv__SetReposition_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetReposition_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetReposition_Request where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/srv/SetReposition_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__srv__SetReposition_Request() }
  }
}


#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__srv__SetReposition_Response() -> *const std::ffi::c_void;
}

#[link(name = "autopilot_interface_msgs__rosidl_generator_c")]
extern "C" {
    fn autopilot_interface_msgs__srv__SetReposition_Response__init(msg: *mut SetReposition_Response) -> bool;
    fn autopilot_interface_msgs__srv__SetReposition_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetReposition_Response>, size: usize) -> bool;
    fn autopilot_interface_msgs__srv__SetReposition_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetReposition_Response>);
    fn autopilot_interface_msgs__srv__SetReposition_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetReposition_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetReposition_Response>) -> bool;
}

// Corresponds to autopilot_interface_msgs__srv__SetReposition_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetReposition_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for SetReposition_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !autopilot_interface_msgs__srv__SetReposition_Response__init(&mut msg as *mut _) {
        panic!("Call to autopilot_interface_msgs__srv__SetReposition_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetReposition_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__srv__SetReposition_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__srv__SetReposition_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { autopilot_interface_msgs__srv__SetReposition_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetReposition_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetReposition_Response where Self: Sized {
  const TYPE_NAME: &'static str = "autopilot_interface_msgs/srv/SetReposition_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__autopilot_interface_msgs__srv__SetReposition_Response() }
  }
}






#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__srv__SetSpeed() -> *const std::ffi::c_void;
}

// Corresponds to autopilot_interface_msgs__srv__SetSpeed
#[allow(missing_docs, non_camel_case_types)]
pub struct SetSpeed;

impl rosidl_runtime_rs::Service for SetSpeed {
    type Request = SetSpeed_Request;
    type Response = SetSpeed_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__srv__SetSpeed() }
    }
}




#[link(name = "autopilot_interface_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__srv__SetReposition() -> *const std::ffi::c_void;
}

// Corresponds to autopilot_interface_msgs__srv__SetReposition
#[allow(missing_docs, non_camel_case_types)]
pub struct SetReposition;

impl rosidl_runtime_rs::Service for SetReposition {
    type Request = SetReposition_Request;
    type Response = SetReposition_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__autopilot_interface_msgs__srv__SetReposition() }
    }
}


