// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pegasus_msgs:msg/InspectionResult.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__INSPECTION_RESULT__BUILDER_HPP_
#define PEGASUS_MSGS__MSG__DETAIL__INSPECTION_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pegasus_msgs/msg/detail/inspection_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pegasus_msgs
{

namespace msg
{

namespace builder
{

class Init_InspectionResult_json_payload
{
public:
  explicit Init_InspectionResult_json_payload(::pegasus_msgs::msg::InspectionResult & msg)
  : msg_(msg)
  {}
  ::pegasus_msgs::msg::InspectionResult json_payload(::pegasus_msgs::msg::InspectionResult::_json_payload_type arg)
  {
    msg_.json_payload = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pegasus_msgs::msg::InspectionResult msg_;
};

class Init_InspectionResult_zone_risk_id
{
public:
  explicit Init_InspectionResult_zone_risk_id(::pegasus_msgs::msg::InspectionResult & msg)
  : msg_(msg)
  {}
  Init_InspectionResult_json_payload zone_risk_id(::pegasus_msgs::msg::InspectionResult::_zone_risk_id_type arg)
  {
    msg_.zone_risk_id = std::move(arg);
    return Init_InspectionResult_json_payload(msg_);
  }

private:
  ::pegasus_msgs::msg::InspectionResult msg_;
};

class Init_InspectionResult_zone_risk_level
{
public:
  explicit Init_InspectionResult_zone_risk_level(::pegasus_msgs::msg::InspectionResult & msg)
  : msg_(msg)
  {}
  Init_InspectionResult_zone_risk_id zone_risk_level(::pegasus_msgs::msg::InspectionResult::_zone_risk_level_type arg)
  {
    msg_.zone_risk_level = std::move(arg);
    return Init_InspectionResult_zone_risk_id(msg_);
  }

private:
  ::pegasus_msgs::msg::InspectionResult msg_;
};

class Init_InspectionResult_images_with_defects
{
public:
  explicit Init_InspectionResult_images_with_defects(::pegasus_msgs::msg::InspectionResult & msg)
  : msg_(msg)
  {}
  Init_InspectionResult_zone_risk_level images_with_defects(::pegasus_msgs::msg::InspectionResult::_images_with_defects_type arg)
  {
    msg_.images_with_defects = std::move(arg);
    return Init_InspectionResult_zone_risk_level(msg_);
  }

private:
  ::pegasus_msgs::msg::InspectionResult msg_;
};

class Init_InspectionResult_images_captured
{
public:
  explicit Init_InspectionResult_images_captured(::pegasus_msgs::msg::InspectionResult & msg)
  : msg_(msg)
  {}
  Init_InspectionResult_images_with_defects images_captured(::pegasus_msgs::msg::InspectionResult::_images_captured_type arg)
  {
    msg_.images_captured = std::move(arg);
    return Init_InspectionResult_images_with_defects(msg_);
  }

private:
  ::pegasus_msgs::msg::InspectionResult msg_;
};

class Init_InspectionResult_coverage_percent
{
public:
  explicit Init_InspectionResult_coverage_percent(::pegasus_msgs::msg::InspectionResult & msg)
  : msg_(msg)
  {}
  Init_InspectionResult_images_captured coverage_percent(::pegasus_msgs::msg::InspectionResult::_coverage_percent_type arg)
  {
    msg_.coverage_percent = std::move(arg);
    return Init_InspectionResult_images_captured(msg_);
  }

private:
  ::pegasus_msgs::msg::InspectionResult msg_;
};

class Init_InspectionResult_defects
{
public:
  explicit Init_InspectionResult_defects(::pegasus_msgs::msg::InspectionResult & msg)
  : msg_(msg)
  {}
  Init_InspectionResult_coverage_percent defects(::pegasus_msgs::msg::InspectionResult::_defects_type arg)
  {
    msg_.defects = std::move(arg);
    return Init_InspectionResult_coverage_percent(msg_);
  }

private:
  ::pegasus_msgs::msg::InspectionResult msg_;
};

class Init_InspectionResult_drone_pose
{
public:
  explicit Init_InspectionResult_drone_pose(::pegasus_msgs::msg::InspectionResult & msg)
  : msg_(msg)
  {}
  Init_InspectionResult_defects drone_pose(::pegasus_msgs::msg::InspectionResult::_drone_pose_type arg)
  {
    msg_.drone_pose = std::move(arg);
    return Init_InspectionResult_defects(msg_);
  }

private:
  ::pegasus_msgs::msg::InspectionResult msg_;
};

class Init_InspectionResult_zone_id
{
public:
  explicit Init_InspectionResult_zone_id(::pegasus_msgs::msg::InspectionResult & msg)
  : msg_(msg)
  {}
  Init_InspectionResult_drone_pose zone_id(::pegasus_msgs::msg::InspectionResult::_zone_id_type arg)
  {
    msg_.zone_id = std::move(arg);
    return Init_InspectionResult_drone_pose(msg_);
  }

private:
  ::pegasus_msgs::msg::InspectionResult msg_;
};

class Init_InspectionResult_mission_id
{
public:
  explicit Init_InspectionResult_mission_id(::pegasus_msgs::msg::InspectionResult & msg)
  : msg_(msg)
  {}
  Init_InspectionResult_zone_id mission_id(::pegasus_msgs::msg::InspectionResult::_mission_id_type arg)
  {
    msg_.mission_id = std::move(arg);
    return Init_InspectionResult_zone_id(msg_);
  }

private:
  ::pegasus_msgs::msg::InspectionResult msg_;
};

class Init_InspectionResult_drone_id
{
public:
  explicit Init_InspectionResult_drone_id(::pegasus_msgs::msg::InspectionResult & msg)
  : msg_(msg)
  {}
  Init_InspectionResult_mission_id drone_id(::pegasus_msgs::msg::InspectionResult::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_InspectionResult_mission_id(msg_);
  }

private:
  ::pegasus_msgs::msg::InspectionResult msg_;
};

class Init_InspectionResult_header
{
public:
  Init_InspectionResult_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_InspectionResult_drone_id header(::pegasus_msgs::msg::InspectionResult::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_InspectionResult_drone_id(msg_);
  }

private:
  ::pegasus_msgs::msg::InspectionResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pegasus_msgs::msg::InspectionResult>()
{
  return pegasus_msgs::msg::builder::Init_InspectionResult_header();
}

}  // namespace pegasus_msgs

#endif  // PEGASUS_MSGS__MSG__DETAIL__INSPECTION_RESULT__BUILDER_HPP_
