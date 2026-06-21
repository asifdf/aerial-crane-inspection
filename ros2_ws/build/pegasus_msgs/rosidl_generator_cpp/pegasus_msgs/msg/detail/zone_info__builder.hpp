// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pegasus_msgs:msg/ZoneInfo.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__ZONE_INFO__BUILDER_HPP_
#define PEGASUS_MSGS__MSG__DETAIL__ZONE_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pegasus_msgs/msg/detail/zone_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pegasus_msgs
{

namespace msg
{

namespace builder
{

class Init_ZoneInfo_priority
{
public:
  explicit Init_ZoneInfo_priority(::pegasus_msgs::msg::ZoneInfo & msg)
  : msg_(msg)
  {}
  ::pegasus_msgs::msg::ZoneInfo priority(::pegasus_msgs::msg::ZoneInfo::_priority_type arg)
  {
    msg_.priority = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pegasus_msgs::msg::ZoneInfo msg_;
};

class Init_ZoneInfo_expected_defects
{
public:
  explicit Init_ZoneInfo_expected_defects(::pegasus_msgs::msg::ZoneInfo & msg)
  : msg_(msg)
  {}
  Init_ZoneInfo_priority expected_defects(::pegasus_msgs::msg::ZoneInfo::_expected_defects_type arg)
  {
    msg_.expected_defects = std::move(arg);
    return Init_ZoneInfo_priority(msg_);
  }

private:
  ::pegasus_msgs::msg::ZoneInfo msg_;
};

class Init_ZoneInfo_camera_yaw
{
public:
  explicit Init_ZoneInfo_camera_yaw(::pegasus_msgs::msg::ZoneInfo & msg)
  : msg_(msg)
  {}
  Init_ZoneInfo_expected_defects camera_yaw(::pegasus_msgs::msg::ZoneInfo::_camera_yaw_type arg)
  {
    msg_.camera_yaw = std::move(arg);
    return Init_ZoneInfo_expected_defects(msg_);
  }

private:
  ::pegasus_msgs::msg::ZoneInfo msg_;
};

class Init_ZoneInfo_camera_pitch
{
public:
  explicit Init_ZoneInfo_camera_pitch(::pegasus_msgs::msg::ZoneInfo & msg)
  : msg_(msg)
  {}
  Init_ZoneInfo_camera_yaw camera_pitch(::pegasus_msgs::msg::ZoneInfo::_camera_pitch_type arg)
  {
    msg_.camera_pitch = std::move(arg);
    return Init_ZoneInfo_camera_yaw(msg_);
  }

private:
  ::pegasus_msgs::msg::ZoneInfo msg_;
};

class Init_ZoneInfo_waypoints_yaw
{
public:
  explicit Init_ZoneInfo_waypoints_yaw(::pegasus_msgs::msg::ZoneInfo & msg)
  : msg_(msg)
  {}
  Init_ZoneInfo_camera_pitch waypoints_yaw(::pegasus_msgs::msg::ZoneInfo::_waypoints_yaw_type arg)
  {
    msg_.waypoints_yaw = std::move(arg);
    return Init_ZoneInfo_camera_pitch(msg_);
  }

private:
  ::pegasus_msgs::msg::ZoneInfo msg_;
};

class Init_ZoneInfo_waypoints_z
{
public:
  explicit Init_ZoneInfo_waypoints_z(::pegasus_msgs::msg::ZoneInfo & msg)
  : msg_(msg)
  {}
  Init_ZoneInfo_waypoints_yaw waypoints_z(::pegasus_msgs::msg::ZoneInfo::_waypoints_z_type arg)
  {
    msg_.waypoints_z = std::move(arg);
    return Init_ZoneInfo_waypoints_yaw(msg_);
  }

private:
  ::pegasus_msgs::msg::ZoneInfo msg_;
};

class Init_ZoneInfo_waypoints_y
{
public:
  explicit Init_ZoneInfo_waypoints_y(::pegasus_msgs::msg::ZoneInfo & msg)
  : msg_(msg)
  {}
  Init_ZoneInfo_waypoints_z waypoints_y(::pegasus_msgs::msg::ZoneInfo::_waypoints_y_type arg)
  {
    msg_.waypoints_y = std::move(arg);
    return Init_ZoneInfo_waypoints_z(msg_);
  }

private:
  ::pegasus_msgs::msg::ZoneInfo msg_;
};

class Init_ZoneInfo_waypoints_x
{
public:
  explicit Init_ZoneInfo_waypoints_x(::pegasus_msgs::msg::ZoneInfo & msg)
  : msg_(msg)
  {}
  Init_ZoneInfo_waypoints_y waypoints_x(::pegasus_msgs::msg::ZoneInfo::_waypoints_x_type arg)
  {
    msg_.waypoints_x = std::move(arg);
    return Init_ZoneInfo_waypoints_y(msg_);
  }

private:
  ::pegasus_msgs::msg::ZoneInfo msg_;
};

class Init_ZoneInfo_zone_dimensions
{
public:
  explicit Init_ZoneInfo_zone_dimensions(::pegasus_msgs::msg::ZoneInfo & msg)
  : msg_(msg)
  {}
  Init_ZoneInfo_waypoints_x zone_dimensions(::pegasus_msgs::msg::ZoneInfo::_zone_dimensions_type arg)
  {
    msg_.zone_dimensions = std::move(arg);
    return Init_ZoneInfo_waypoints_x(msg_);
  }

private:
  ::pegasus_msgs::msg::ZoneInfo msg_;
};

class Init_ZoneInfo_zone_center
{
public:
  explicit Init_ZoneInfo_zone_center(::pegasus_msgs::msg::ZoneInfo & msg)
  : msg_(msg)
  {}
  Init_ZoneInfo_zone_dimensions zone_center(::pegasus_msgs::msg::ZoneInfo::_zone_center_type arg)
  {
    msg_.zone_center = std::move(arg);
    return Init_ZoneInfo_zone_dimensions(msg_);
  }

private:
  ::pegasus_msgs::msg::ZoneInfo msg_;
};

class Init_ZoneInfo_zone_type
{
public:
  explicit Init_ZoneInfo_zone_type(::pegasus_msgs::msg::ZoneInfo & msg)
  : msg_(msg)
  {}
  Init_ZoneInfo_zone_center zone_type(::pegasus_msgs::msg::ZoneInfo::_zone_type_type arg)
  {
    msg_.zone_type = std::move(arg);
    return Init_ZoneInfo_zone_center(msg_);
  }

private:
  ::pegasus_msgs::msg::ZoneInfo msg_;
};

class Init_ZoneInfo_zone_name
{
public:
  explicit Init_ZoneInfo_zone_name(::pegasus_msgs::msg::ZoneInfo & msg)
  : msg_(msg)
  {}
  Init_ZoneInfo_zone_type zone_name(::pegasus_msgs::msg::ZoneInfo::_zone_name_type arg)
  {
    msg_.zone_name = std::move(arg);
    return Init_ZoneInfo_zone_type(msg_);
  }

private:
  ::pegasus_msgs::msg::ZoneInfo msg_;
};

class Init_ZoneInfo_zone_id
{
public:
  explicit Init_ZoneInfo_zone_id(::pegasus_msgs::msg::ZoneInfo & msg)
  : msg_(msg)
  {}
  Init_ZoneInfo_zone_name zone_id(::pegasus_msgs::msg::ZoneInfo::_zone_id_type arg)
  {
    msg_.zone_id = std::move(arg);
    return Init_ZoneInfo_zone_name(msg_);
  }

private:
  ::pegasus_msgs::msg::ZoneInfo msg_;
};

class Init_ZoneInfo_header
{
public:
  Init_ZoneInfo_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ZoneInfo_zone_id header(::pegasus_msgs::msg::ZoneInfo::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ZoneInfo_zone_id(msg_);
  }

private:
  ::pegasus_msgs::msg::ZoneInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pegasus_msgs::msg::ZoneInfo>()
{
  return pegasus_msgs::msg::builder::Init_ZoneInfo_header();
}

}  // namespace pegasus_msgs

#endif  // PEGASUS_MSGS__MSG__DETAIL__ZONE_INFO__BUILDER_HPP_
