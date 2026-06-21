#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to autopilot_interface_msgs__msg__OffboardFlag

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::OffboardFlag::default())
  }
}

impl rosidl_runtime_rs::Message for OffboardFlag {
  type RmwMsg = super::msg::rmw::OffboardFlag;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        offboard_flag: msg.offboard_flag,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      offboard_flag: msg.offboard_flag,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      offboard_flag: msg.offboard_flag,
    }
  }
}


