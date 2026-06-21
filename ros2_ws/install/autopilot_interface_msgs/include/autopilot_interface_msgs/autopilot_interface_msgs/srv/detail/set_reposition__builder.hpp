// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from autopilot_interface_msgs:srv/SetReposition.idl
// generated code does not contain a copyright notice

#ifndef AUTOPILOT_INTERFACE_MSGS__SRV__DETAIL__SET_REPOSITION__BUILDER_HPP_
#define AUTOPILOT_INTERFACE_MSGS__SRV__DETAIL__SET_REPOSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "autopilot_interface_msgs/srv/detail/set_reposition__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace autopilot_interface_msgs
{

namespace srv
{

namespace builder
{

class Init_SetReposition_Request_altitude
{
public:
  explicit Init_SetReposition_Request_altitude(::autopilot_interface_msgs::srv::SetReposition_Request & msg)
  : msg_(msg)
  {}
  ::autopilot_interface_msgs::srv::SetReposition_Request altitude(::autopilot_interface_msgs::srv::SetReposition_Request::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::srv::SetReposition_Request msg_;
};

class Init_SetReposition_Request_north
{
public:
  explicit Init_SetReposition_Request_north(::autopilot_interface_msgs::srv::SetReposition_Request & msg)
  : msg_(msg)
  {}
  Init_SetReposition_Request_altitude north(::autopilot_interface_msgs::srv::SetReposition_Request::_north_type arg)
  {
    msg_.north = std::move(arg);
    return Init_SetReposition_Request_altitude(msg_);
  }

private:
  ::autopilot_interface_msgs::srv::SetReposition_Request msg_;
};

class Init_SetReposition_Request_east
{
public:
  Init_SetReposition_Request_east()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetReposition_Request_north east(::autopilot_interface_msgs::srv::SetReposition_Request::_east_type arg)
  {
    msg_.east = std::move(arg);
    return Init_SetReposition_Request_north(msg_);
  }

private:
  ::autopilot_interface_msgs::srv::SetReposition_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::srv::SetReposition_Request>()
{
  return autopilot_interface_msgs::srv::builder::Init_SetReposition_Request_east();
}

}  // namespace autopilot_interface_msgs


namespace autopilot_interface_msgs
{

namespace srv
{

namespace builder
{

class Init_SetReposition_Response_message
{
public:
  explicit Init_SetReposition_Response_message(::autopilot_interface_msgs::srv::SetReposition_Response & msg)
  : msg_(msg)
  {}
  ::autopilot_interface_msgs::srv::SetReposition_Response message(::autopilot_interface_msgs::srv::SetReposition_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::srv::SetReposition_Response msg_;
};

class Init_SetReposition_Response_success
{
public:
  Init_SetReposition_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetReposition_Response_message success(::autopilot_interface_msgs::srv::SetReposition_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetReposition_Response_message(msg_);
  }

private:
  ::autopilot_interface_msgs::srv::SetReposition_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::srv::SetReposition_Response>()
{
  return autopilot_interface_msgs::srv::builder::Init_SetReposition_Response_success();
}

}  // namespace autopilot_interface_msgs

#endif  // AUTOPILOT_INTERFACE_MSGS__SRV__DETAIL__SET_REPOSITION__BUILDER_HPP_
