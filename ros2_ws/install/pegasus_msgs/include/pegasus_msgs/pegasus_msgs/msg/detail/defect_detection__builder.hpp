// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pegasus_msgs:msg/DefectDetection.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__DEFECT_DETECTION__BUILDER_HPP_
#define PEGASUS_MSGS__MSG__DETAIL__DEFECT_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pegasus_msgs/msg/detail/defect_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pegasus_msgs
{

namespace msg
{

namespace builder
{

class Init_DefectDetection_has_3d_position
{
public:
  explicit Init_DefectDetection_has_3d_position(::pegasus_msgs::msg::DefectDetection & msg)
  : msg_(msg)
  {}
  ::pegasus_msgs::msg::DefectDetection has_3d_position(::pegasus_msgs::msg::DefectDetection::_has_3d_position_type arg)
  {
    msg_.has_3d_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectDetection msg_;
};

class Init_DefectDetection_position_3d
{
public:
  explicit Init_DefectDetection_position_3d(::pegasus_msgs::msg::DefectDetection & msg)
  : msg_(msg)
  {}
  Init_DefectDetection_has_3d_position position_3d(::pegasus_msgs::msg::DefectDetection::_position_3d_type arg)
  {
    msg_.position_3d = std::move(arg);
    return Init_DefectDetection_has_3d_position(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectDetection msg_;
};

class Init_DefectDetection_mask
{
public:
  explicit Init_DefectDetection_mask(::pegasus_msgs::msg::DefectDetection & msg)
  : msg_(msg)
  {}
  Init_DefectDetection_position_3d mask(::pegasus_msgs::msg::DefectDetection::_mask_type arg)
  {
    msg_.mask = std::move(arg);
    return Init_DefectDetection_position_3d(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectDetection msg_;
};

class Init_DefectDetection_risk_id
{
public:
  explicit Init_DefectDetection_risk_id(::pegasus_msgs::msg::DefectDetection & msg)
  : msg_(msg)
  {}
  Init_DefectDetection_mask risk_id(::pegasus_msgs::msg::DefectDetection::_risk_id_type arg)
  {
    msg_.risk_id = std::move(arg);
    return Init_DefectDetection_mask(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectDetection msg_;
};

class Init_DefectDetection_risk_level
{
public:
  explicit Init_DefectDetection_risk_level(::pegasus_msgs::msg::DefectDetection & msg)
  : msg_(msg)
  {}
  Init_DefectDetection_risk_id risk_level(::pegasus_msgs::msg::DefectDetection::_risk_level_type arg)
  {
    msg_.risk_level = std::move(arg);
    return Init_DefectDetection_risk_id(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectDetection msg_;
};

class Init_DefectDetection_bbox_height_norm
{
public:
  explicit Init_DefectDetection_bbox_height_norm(::pegasus_msgs::msg::DefectDetection & msg)
  : msg_(msg)
  {}
  Init_DefectDetection_risk_level bbox_height_norm(::pegasus_msgs::msg::DefectDetection::_bbox_height_norm_type arg)
  {
    msg_.bbox_height_norm = std::move(arg);
    return Init_DefectDetection_risk_level(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectDetection msg_;
};

class Init_DefectDetection_bbox_width_norm
{
public:
  explicit Init_DefectDetection_bbox_width_norm(::pegasus_msgs::msg::DefectDetection & msg)
  : msg_(msg)
  {}
  Init_DefectDetection_bbox_height_norm bbox_width_norm(::pegasus_msgs::msg::DefectDetection::_bbox_width_norm_type arg)
  {
    msg_.bbox_width_norm = std::move(arg);
    return Init_DefectDetection_bbox_height_norm(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectDetection msg_;
};

class Init_DefectDetection_bbox_y_norm
{
public:
  explicit Init_DefectDetection_bbox_y_norm(::pegasus_msgs::msg::DefectDetection & msg)
  : msg_(msg)
  {}
  Init_DefectDetection_bbox_width_norm bbox_y_norm(::pegasus_msgs::msg::DefectDetection::_bbox_y_norm_type arg)
  {
    msg_.bbox_y_norm = std::move(arg);
    return Init_DefectDetection_bbox_width_norm(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectDetection msg_;
};

class Init_DefectDetection_bbox_x_norm
{
public:
  explicit Init_DefectDetection_bbox_x_norm(::pegasus_msgs::msg::DefectDetection & msg)
  : msg_(msg)
  {}
  Init_DefectDetection_bbox_y_norm bbox_x_norm(::pegasus_msgs::msg::DefectDetection::_bbox_x_norm_type arg)
  {
    msg_.bbox_x_norm = std::move(arg);
    return Init_DefectDetection_bbox_y_norm(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectDetection msg_;
};

class Init_DefectDetection_bbox_height
{
public:
  explicit Init_DefectDetection_bbox_height(::pegasus_msgs::msg::DefectDetection & msg)
  : msg_(msg)
  {}
  Init_DefectDetection_bbox_x_norm bbox_height(::pegasus_msgs::msg::DefectDetection::_bbox_height_type arg)
  {
    msg_.bbox_height = std::move(arg);
    return Init_DefectDetection_bbox_x_norm(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectDetection msg_;
};

class Init_DefectDetection_bbox_width
{
public:
  explicit Init_DefectDetection_bbox_width(::pegasus_msgs::msg::DefectDetection & msg)
  : msg_(msg)
  {}
  Init_DefectDetection_bbox_height bbox_width(::pegasus_msgs::msg::DefectDetection::_bbox_width_type arg)
  {
    msg_.bbox_width = std::move(arg);
    return Init_DefectDetection_bbox_height(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectDetection msg_;
};

class Init_DefectDetection_bbox_y
{
public:
  explicit Init_DefectDetection_bbox_y(::pegasus_msgs::msg::DefectDetection & msg)
  : msg_(msg)
  {}
  Init_DefectDetection_bbox_width bbox_y(::pegasus_msgs::msg::DefectDetection::_bbox_y_type arg)
  {
    msg_.bbox_y = std::move(arg);
    return Init_DefectDetection_bbox_width(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectDetection msg_;
};

class Init_DefectDetection_bbox_x
{
public:
  explicit Init_DefectDetection_bbox_x(::pegasus_msgs::msg::DefectDetection & msg)
  : msg_(msg)
  {}
  Init_DefectDetection_bbox_y bbox_x(::pegasus_msgs::msg::DefectDetection::_bbox_x_type arg)
  {
    msg_.bbox_x = std::move(arg);
    return Init_DefectDetection_bbox_y(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectDetection msg_;
};

class Init_DefectDetection_confidence
{
public:
  explicit Init_DefectDetection_confidence(::pegasus_msgs::msg::DefectDetection & msg)
  : msg_(msg)
  {}
  Init_DefectDetection_bbox_x confidence(::pegasus_msgs::msg::DefectDetection::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_DefectDetection_bbox_x(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectDetection msg_;
};

class Init_DefectDetection_class_id
{
public:
  explicit Init_DefectDetection_class_id(::pegasus_msgs::msg::DefectDetection & msg)
  : msg_(msg)
  {}
  Init_DefectDetection_confidence class_id(::pegasus_msgs::msg::DefectDetection::_class_id_type arg)
  {
    msg_.class_id = std::move(arg);
    return Init_DefectDetection_confidence(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectDetection msg_;
};

class Init_DefectDetection_type
{
public:
  explicit Init_DefectDetection_type(::pegasus_msgs::msg::DefectDetection & msg)
  : msg_(msg)
  {}
  Init_DefectDetection_class_id type(::pegasus_msgs::msg::DefectDetection::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_DefectDetection_class_id(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectDetection msg_;
};

class Init_DefectDetection_header
{
public:
  Init_DefectDetection_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DefectDetection_type header(::pegasus_msgs::msg::DefectDetection::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DefectDetection_type(msg_);
  }

private:
  ::pegasus_msgs::msg::DefectDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pegasus_msgs::msg::DefectDetection>()
{
  return pegasus_msgs::msg::builder::Init_DefectDetection_header();
}

}  // namespace pegasus_msgs

#endif  // PEGASUS_MSGS__MSG__DETAIL__DEFECT_DETECTION__BUILDER_HPP_
