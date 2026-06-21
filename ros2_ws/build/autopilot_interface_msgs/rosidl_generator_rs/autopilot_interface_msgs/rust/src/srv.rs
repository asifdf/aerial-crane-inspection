#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to autopilot_interface_msgs__srv__SetSpeed_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetSpeed_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub speed: f64,

}



impl Default for SetSpeed_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetSpeed_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetSpeed_Request {
  type RmwMsg = super::srv::rmw::SetSpeed_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        speed: msg.speed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      speed: msg.speed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      speed: msg.speed,
    }
  }
}


// Corresponds to autopilot_interface_msgs__srv__SetSpeed_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetSpeed_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for SetSpeed_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetSpeed_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetSpeed_Response {
  type RmwMsg = super::srv::rmw::SetSpeed_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
  }
}


// Corresponds to autopilot_interface_msgs__srv__SetReposition_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetReposition_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetReposition_Request {
  type RmwMsg = super::srv::rmw::SetReposition_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        east: msg.east,
        north: msg.north,
        altitude: msg.altitude,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      east: msg.east,
      north: msg.north,
      altitude: msg.altitude,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      east: msg.east,
      north: msg.north,
      altitude: msg.altitude,
    }
  }
}


// Corresponds to autopilot_interface_msgs__srv__SetReposition_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetReposition_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for SetReposition_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetReposition_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetReposition_Response {
  type RmwMsg = super::srv::rmw::SetReposition_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
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


