// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from pegasus_msgs:msg/ZoneInfo.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "pegasus_msgs/msg/detail/zone_info__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace pegasus_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ZoneInfo_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) pegasus_msgs::msg::ZoneInfo(_init);
}

void ZoneInfo_fini_function(void * message_memory)
{
  auto typed_message = static_cast<pegasus_msgs::msg::ZoneInfo *>(message_memory);
  typed_message->~ZoneInfo();
}

size_t size_function__ZoneInfo__waypoints_x(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ZoneInfo__waypoints_x(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__ZoneInfo__waypoints_x(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__ZoneInfo__waypoints_x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__ZoneInfo__waypoints_x(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__ZoneInfo__waypoints_x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__ZoneInfo__waypoints_x(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__ZoneInfo__waypoints_x(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ZoneInfo__waypoints_y(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ZoneInfo__waypoints_y(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__ZoneInfo__waypoints_y(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__ZoneInfo__waypoints_y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__ZoneInfo__waypoints_y(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__ZoneInfo__waypoints_y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__ZoneInfo__waypoints_y(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__ZoneInfo__waypoints_y(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ZoneInfo__waypoints_z(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ZoneInfo__waypoints_z(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__ZoneInfo__waypoints_z(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__ZoneInfo__waypoints_z(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__ZoneInfo__waypoints_z(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__ZoneInfo__waypoints_z(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__ZoneInfo__waypoints_z(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__ZoneInfo__waypoints_z(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ZoneInfo__waypoints_yaw(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ZoneInfo__waypoints_yaw(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__ZoneInfo__waypoints_yaw(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__ZoneInfo__waypoints_yaw(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__ZoneInfo__waypoints_yaw(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__ZoneInfo__waypoints_yaw(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__ZoneInfo__waypoints_yaw(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__ZoneInfo__waypoints_yaw(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ZoneInfo__camera_pitch(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ZoneInfo__camera_pitch(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__ZoneInfo__camera_pitch(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__ZoneInfo__camera_pitch(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__ZoneInfo__camera_pitch(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__ZoneInfo__camera_pitch(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__ZoneInfo__camera_pitch(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__ZoneInfo__camera_pitch(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ZoneInfo__camera_yaw(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ZoneInfo__camera_yaw(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__ZoneInfo__camera_yaw(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__ZoneInfo__camera_yaw(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__ZoneInfo__camera_yaw(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__ZoneInfo__camera_yaw(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__ZoneInfo__camera_yaw(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__ZoneInfo__camera_yaw(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ZoneInfo__expected_defects(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ZoneInfo__expected_defects(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__ZoneInfo__expected_defects(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__ZoneInfo__expected_defects(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__ZoneInfo__expected_defects(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__ZoneInfo__expected_defects(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__ZoneInfo__expected_defects(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__ZoneInfo__expected_defects(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ZoneInfo_message_member_array[14] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs::msg::ZoneInfo, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "zone_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs::msg::ZoneInfo, zone_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "zone_name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs::msg::ZoneInfo, zone_name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "zone_type",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs::msg::ZoneInfo, zone_type),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "zone_center",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Pose>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs::msg::ZoneInfo, zone_center),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "zone_dimensions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Vector3>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs::msg::ZoneInfo, zone_dimensions),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "waypoints_x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs::msg::ZoneInfo, waypoints_x),  // bytes offset in struct
    nullptr,  // default value
    size_function__ZoneInfo__waypoints_x,  // size() function pointer
    get_const_function__ZoneInfo__waypoints_x,  // get_const(index) function pointer
    get_function__ZoneInfo__waypoints_x,  // get(index) function pointer
    fetch_function__ZoneInfo__waypoints_x,  // fetch(index, &value) function pointer
    assign_function__ZoneInfo__waypoints_x,  // assign(index, value) function pointer
    resize_function__ZoneInfo__waypoints_x  // resize(index) function pointer
  },
  {
    "waypoints_y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs::msg::ZoneInfo, waypoints_y),  // bytes offset in struct
    nullptr,  // default value
    size_function__ZoneInfo__waypoints_y,  // size() function pointer
    get_const_function__ZoneInfo__waypoints_y,  // get_const(index) function pointer
    get_function__ZoneInfo__waypoints_y,  // get(index) function pointer
    fetch_function__ZoneInfo__waypoints_y,  // fetch(index, &value) function pointer
    assign_function__ZoneInfo__waypoints_y,  // assign(index, value) function pointer
    resize_function__ZoneInfo__waypoints_y  // resize(index) function pointer
  },
  {
    "waypoints_z",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs::msg::ZoneInfo, waypoints_z),  // bytes offset in struct
    nullptr,  // default value
    size_function__ZoneInfo__waypoints_z,  // size() function pointer
    get_const_function__ZoneInfo__waypoints_z,  // get_const(index) function pointer
    get_function__ZoneInfo__waypoints_z,  // get(index) function pointer
    fetch_function__ZoneInfo__waypoints_z,  // fetch(index, &value) function pointer
    assign_function__ZoneInfo__waypoints_z,  // assign(index, value) function pointer
    resize_function__ZoneInfo__waypoints_z  // resize(index) function pointer
  },
  {
    "waypoints_yaw",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs::msg::ZoneInfo, waypoints_yaw),  // bytes offset in struct
    nullptr,  // default value
    size_function__ZoneInfo__waypoints_yaw,  // size() function pointer
    get_const_function__ZoneInfo__waypoints_yaw,  // get_const(index) function pointer
    get_function__ZoneInfo__waypoints_yaw,  // get(index) function pointer
    fetch_function__ZoneInfo__waypoints_yaw,  // fetch(index, &value) function pointer
    assign_function__ZoneInfo__waypoints_yaw,  // assign(index, value) function pointer
    resize_function__ZoneInfo__waypoints_yaw  // resize(index) function pointer
  },
  {
    "camera_pitch",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs::msg::ZoneInfo, camera_pitch),  // bytes offset in struct
    nullptr,  // default value
    size_function__ZoneInfo__camera_pitch,  // size() function pointer
    get_const_function__ZoneInfo__camera_pitch,  // get_const(index) function pointer
    get_function__ZoneInfo__camera_pitch,  // get(index) function pointer
    fetch_function__ZoneInfo__camera_pitch,  // fetch(index, &value) function pointer
    assign_function__ZoneInfo__camera_pitch,  // assign(index, value) function pointer
    resize_function__ZoneInfo__camera_pitch  // resize(index) function pointer
  },
  {
    "camera_yaw",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs::msg::ZoneInfo, camera_yaw),  // bytes offset in struct
    nullptr,  // default value
    size_function__ZoneInfo__camera_yaw,  // size() function pointer
    get_const_function__ZoneInfo__camera_yaw,  // get_const(index) function pointer
    get_function__ZoneInfo__camera_yaw,  // get(index) function pointer
    fetch_function__ZoneInfo__camera_yaw,  // fetch(index, &value) function pointer
    assign_function__ZoneInfo__camera_yaw,  // assign(index, value) function pointer
    resize_function__ZoneInfo__camera_yaw  // resize(index) function pointer
  },
  {
    "expected_defects",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs::msg::ZoneInfo, expected_defects),  // bytes offset in struct
    nullptr,  // default value
    size_function__ZoneInfo__expected_defects,  // size() function pointer
    get_const_function__ZoneInfo__expected_defects,  // get_const(index) function pointer
    get_function__ZoneInfo__expected_defects,  // get(index) function pointer
    fetch_function__ZoneInfo__expected_defects,  // fetch(index, &value) function pointer
    assign_function__ZoneInfo__expected_defects,  // assign(index, value) function pointer
    resize_function__ZoneInfo__expected_defects  // resize(index) function pointer
  },
  {
    "priority",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs::msg::ZoneInfo, priority),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ZoneInfo_message_members = {
  "pegasus_msgs::msg",  // message namespace
  "ZoneInfo",  // message name
  14,  // number of fields
  sizeof(pegasus_msgs::msg::ZoneInfo),
  ZoneInfo_message_member_array,  // message members
  ZoneInfo_init_function,  // function to initialize message memory (memory has to be allocated)
  ZoneInfo_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ZoneInfo_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ZoneInfo_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace pegasus_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<pegasus_msgs::msg::ZoneInfo>()
{
  return &::pegasus_msgs::msg::rosidl_typesupport_introspection_cpp::ZoneInfo_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, pegasus_msgs, msg, ZoneInfo)() {
  return &::pegasus_msgs::msg::rosidl_typesupport_introspection_cpp::ZoneInfo_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
