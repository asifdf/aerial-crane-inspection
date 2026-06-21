// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pegasus_msgs:msg/DefectArray.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__DEFECT_ARRAY__BUILDER_HPP_
#define PEGASUS_MSGS__MSG__DETAIL__DEFECT_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pegasus_msgs/msg/detail/defect_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pegasus_msgs
{

namespace msg
{

namespace builder
{

class Init_DefectArray_total_latency
{
public:
  explicit Init_DefectArray_total_latency(::pegasus_msgs::msg::DefectArray & msg)
  : msg_(msg)
  {}
  ::pegasus_msgs::msg::DefectArray total_latency(::pegasus_msgs::msg::DefectArray::_total_latency_type arg)
  {
    msg_.total_latency = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectArray msg_;
};

class Init_DefectArray_inference_latency
{
public:
  explicit Init_DefectArray_inference_latency(::pegasus_msgs::msg::DefectArray & msg)
  : msg_(msg)
  {}
  Init_DefectArray_total_latency inference_latency(::pegasus_msgs::msg::DefectArray::_inference_latency_type arg)
  {
    msg_.inference_latency = std::move(arg);
    return Init_DefectArray_total_latency(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectArray msg_;
};

class Init_DefectArray_max_risk_id
{
public:
  explicit Init_DefectArray_max_risk_id(::pegasus_msgs::msg::DefectArray & msg)
  : msg_(msg)
  {}
  Init_DefectArray_inference_latency max_risk_id(::pegasus_msgs::msg::DefectArray::_max_risk_id_type arg)
  {
    msg_.max_risk_id = std::move(arg);
    return Init_DefectArray_inference_latency(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectArray msg_;
};

class Init_DefectArray_max_risk_level
{
public:
  explicit Init_DefectArray_max_risk_level(::pegasus_msgs::msg::DefectArray & msg)
  : msg_(msg)
  {}
  Init_DefectArray_max_risk_id max_risk_level(::pegasus_msgs::msg::DefectArray::_max_risk_level_type arg)
  {
    msg_.max_risk_level = std::move(arg);
    return Init_DefectArray_max_risk_id(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectArray msg_;
};

class Init_DefectArray_paint_damage_count
{
public:
  explicit Init_DefectArray_paint_damage_count(::pegasus_msgs::msg::DefectArray & msg)
  : msg_(msg)
  {}
  Init_DefectArray_max_risk_level paint_damage_count(::pegasus_msgs::msg::DefectArray::_paint_damage_count_type arg)
  {
    msg_.paint_damage_count = std::move(arg);
    return Init_DefectArray_max_risk_level(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectArray msg_;
};

class Init_DefectArray_corrosion_count
{
public:
  explicit Init_DefectArray_corrosion_count(::pegasus_msgs::msg::DefectArray & msg)
  : msg_(msg)
  {}
  Init_DefectArray_paint_damage_count corrosion_count(::pegasus_msgs::msg::DefectArray::_corrosion_count_type arg)
  {
    msg_.corrosion_count = std::move(arg);
    return Init_DefectArray_paint_damage_count(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectArray msg_;
};

class Init_DefectArray_crack_count
{
public:
  explicit Init_DefectArray_crack_count(::pegasus_msgs::msg::DefectArray & msg)
  : msg_(msg)
  {}
  Init_DefectArray_corrosion_count crack_count(::pegasus_msgs::msg::DefectArray::_crack_count_type arg)
  {
    msg_.crack_count = std::move(arg);
    return Init_DefectArray_corrosion_count(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectArray msg_;
};

class Init_DefectArray_total_count
{
public:
  explicit Init_DefectArray_total_count(::pegasus_msgs::msg::DefectArray & msg)
  : msg_(msg)
  {}
  Init_DefectArray_crack_count total_count(::pegasus_msgs::msg::DefectArray::_total_count_type arg)
  {
    msg_.total_count = std::move(arg);
    return Init_DefectArray_crack_count(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectArray msg_;
};

class Init_DefectArray_detections
{
public:
  explicit Init_DefectArray_detections(::pegasus_msgs::msg::DefectArray & msg)
  : msg_(msg)
  {}
  Init_DefectArray_total_count detections(::pegasus_msgs::msg::DefectArray::_detections_type arg)
  {
    msg_.detections = std::move(arg);
    return Init_DefectArray_total_count(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectArray msg_;
};

class Init_DefectArray_zone_id
{
public:
  explicit Init_DefectArray_zone_id(::pegasus_msgs::msg::DefectArray & msg)
  : msg_(msg)
  {}
  Init_DefectArray_detections zone_id(::pegasus_msgs::msg::DefectArray::_zone_id_type arg)
  {
    msg_.zone_id = std::move(arg);
    return Init_DefectArray_detections(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectArray msg_;
};

class Init_DefectArray_drone_id
{
public:
  explicit Init_DefectArray_drone_id(::pegasus_msgs::msg::DefectArray & msg)
  : msg_(msg)
  {}
  Init_DefectArray_zone_id drone_id(::pegasus_msgs::msg::DefectArray::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_DefectArray_zone_id(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectArray msg_;
};

class Init_DefectArray_header
{
public:
  Init_DefectArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DefectArray_drone_id header(::pegasus_msgs::msg::DefectArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DefectArray_drone_id(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pegasus_msgs::msg::DefectArray>()
{
  return pegasus_msgs::msg::builder::Init_DefectArray_header();
}

}  // namespace pegasus_msgs

#endif  // PEGASUS_MSGS__MSG__DETAIL__DEFECT_ARRAY__BUILDER_HPP_
