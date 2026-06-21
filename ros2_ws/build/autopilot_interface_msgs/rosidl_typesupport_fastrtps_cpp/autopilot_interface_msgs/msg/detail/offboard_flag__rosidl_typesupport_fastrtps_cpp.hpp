// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from autopilot_interface_msgs:msg/OffboardFlag.idl
// generated code does not contain a copyright notice

#ifndef AUTOPILOT_INTERFACE_MSGS__MSG__DETAIL__OFFBOARD_FLAG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define AUTOPILOT_INTERFACE_MSGS__MSG__DETAIL__OFFBOARD_FLAG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "autopilot_interface_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "autopilot_interface_msgs/msg/detail/offboard_flag__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace autopilot_interface_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_autopilot_interface_msgs
cdr_serialize(
  const autopilot_interface_msgs::msg::OffboardFlag & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_autopilot_interface_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  autopilot_interface_msgs::msg::OffboardFlag & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_autopilot_interface_msgs
get_serialized_size(
  const autopilot_interface_msgs::msg::OffboardFlag & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_autopilot_interface_msgs
max_serialized_size_OffboardFlag(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace autopilot_interface_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_autopilot_interface_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, autopilot_interface_msgs, msg, OffboardFlag)();

#ifdef __cplusplus
}
#endif

#endif  // AUTOPILOT_INTERFACE_MSGS__MSG__DETAIL__OFFBOARD_FLAG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
