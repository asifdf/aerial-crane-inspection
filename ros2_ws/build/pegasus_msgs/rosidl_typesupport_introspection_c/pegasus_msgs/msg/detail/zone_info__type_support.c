// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pegasus_msgs:msg/ZoneInfo.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pegasus_msgs/msg/detail/zone_info__rosidl_typesupport_introspection_c.h"
#include "pegasus_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pegasus_msgs/msg/detail/zone_info__functions.h"
#include "pegasus_msgs/msg/detail/zone_info__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `zone_id`
// Member `zone_name`
// Member `zone_type`
// Member `expected_defects`
#include "rosidl_runtime_c/string_functions.h"
// Member `zone_center`
#include "geometry_msgs/msg/pose.h"
// Member `zone_center`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `zone_dimensions`
#include "geometry_msgs/msg/vector3.h"
// Member `zone_dimensions`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"
// Member `waypoints_x`
// Member `waypoints_y`
// Member `waypoints_z`
// Member `waypoints_yaw`
// Member `camera_pitch`
// Member `camera_yaw`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__ZoneInfo_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pegasus_msgs__msg__ZoneInfo__init(message_memory);
}

void pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__ZoneInfo_fini_function(void * message_memory)
{
  pegasus_msgs__msg__ZoneInfo__fini(message_memory);
}

size_t pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__size_function__ZoneInfo__waypoints_x(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__waypoints_x(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__waypoints_x(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__fetch_function__ZoneInfo__waypoints_x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__waypoints_x(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__assign_function__ZoneInfo__waypoints_x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__waypoints_x(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__resize_function__ZoneInfo__waypoints_x(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__size_function__ZoneInfo__waypoints_y(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__waypoints_y(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__waypoints_y(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__fetch_function__ZoneInfo__waypoints_y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__waypoints_y(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__assign_function__ZoneInfo__waypoints_y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__waypoints_y(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__resize_function__ZoneInfo__waypoints_y(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__size_function__ZoneInfo__waypoints_z(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__waypoints_z(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__waypoints_z(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__fetch_function__ZoneInfo__waypoints_z(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__waypoints_z(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__assign_function__ZoneInfo__waypoints_z(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__waypoints_z(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__resize_function__ZoneInfo__waypoints_z(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__size_function__ZoneInfo__waypoints_yaw(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__waypoints_yaw(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__waypoints_yaw(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__fetch_function__ZoneInfo__waypoints_yaw(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__waypoints_yaw(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__assign_function__ZoneInfo__waypoints_yaw(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__waypoints_yaw(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__resize_function__ZoneInfo__waypoints_yaw(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__size_function__ZoneInfo__camera_pitch(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__camera_pitch(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__camera_pitch(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__fetch_function__ZoneInfo__camera_pitch(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__camera_pitch(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__assign_function__ZoneInfo__camera_pitch(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__camera_pitch(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__resize_function__ZoneInfo__camera_pitch(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__size_function__ZoneInfo__camera_yaw(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__camera_yaw(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__camera_yaw(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__fetch_function__ZoneInfo__camera_yaw(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__camera_yaw(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__assign_function__ZoneInfo__camera_yaw(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__camera_yaw(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__resize_function__ZoneInfo__camera_yaw(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__size_function__ZoneInfo__expected_defects(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__expected_defects(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__expected_defects(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__fetch_function__ZoneInfo__expected_defects(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__expected_defects(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__assign_function__ZoneInfo__expected_defects(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__expected_defects(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__resize_function__ZoneInfo__expected_defects(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__ZoneInfo_message_member_array[14] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__ZoneInfo, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zone_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__ZoneInfo, zone_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zone_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__ZoneInfo, zone_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zone_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__ZoneInfo, zone_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zone_center",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__ZoneInfo, zone_center),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zone_dimensions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__ZoneInfo, zone_dimensions),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "waypoints_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__ZoneInfo, waypoints_x),  // bytes offset in struct
    NULL,  // default value
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__size_function__ZoneInfo__waypoints_x,  // size() function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__waypoints_x,  // get_const(index) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__waypoints_x,  // get(index) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__fetch_function__ZoneInfo__waypoints_x,  // fetch(index, &value) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__assign_function__ZoneInfo__waypoints_x,  // assign(index, value) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__resize_function__ZoneInfo__waypoints_x  // resize(index) function pointer
  },
  {
    "waypoints_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__ZoneInfo, waypoints_y),  // bytes offset in struct
    NULL,  // default value
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__size_function__ZoneInfo__waypoints_y,  // size() function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__waypoints_y,  // get_const(index) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__waypoints_y,  // get(index) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__fetch_function__ZoneInfo__waypoints_y,  // fetch(index, &value) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__assign_function__ZoneInfo__waypoints_y,  // assign(index, value) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__resize_function__ZoneInfo__waypoints_y  // resize(index) function pointer
  },
  {
    "waypoints_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__ZoneInfo, waypoints_z),  // bytes offset in struct
    NULL,  // default value
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__size_function__ZoneInfo__waypoints_z,  // size() function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__waypoints_z,  // get_const(index) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__waypoints_z,  // get(index) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__fetch_function__ZoneInfo__waypoints_z,  // fetch(index, &value) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__assign_function__ZoneInfo__waypoints_z,  // assign(index, value) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__resize_function__ZoneInfo__waypoints_z  // resize(index) function pointer
  },
  {
    "waypoints_yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__ZoneInfo, waypoints_yaw),  // bytes offset in struct
    NULL,  // default value
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__size_function__ZoneInfo__waypoints_yaw,  // size() function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__waypoints_yaw,  // get_const(index) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__waypoints_yaw,  // get(index) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__fetch_function__ZoneInfo__waypoints_yaw,  // fetch(index, &value) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__assign_function__ZoneInfo__waypoints_yaw,  // assign(index, value) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__resize_function__ZoneInfo__waypoints_yaw  // resize(index) function pointer
  },
  {
    "camera_pitch",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__ZoneInfo, camera_pitch),  // bytes offset in struct
    NULL,  // default value
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__size_function__ZoneInfo__camera_pitch,  // size() function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__camera_pitch,  // get_const(index) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__camera_pitch,  // get(index) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__fetch_function__ZoneInfo__camera_pitch,  // fetch(index, &value) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__assign_function__ZoneInfo__camera_pitch,  // assign(index, value) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__resize_function__ZoneInfo__camera_pitch  // resize(index) function pointer
  },
  {
    "camera_yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__ZoneInfo, camera_yaw),  // bytes offset in struct
    NULL,  // default value
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__size_function__ZoneInfo__camera_yaw,  // size() function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__camera_yaw,  // get_const(index) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__camera_yaw,  // get(index) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__fetch_function__ZoneInfo__camera_yaw,  // fetch(index, &value) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__assign_function__ZoneInfo__camera_yaw,  // assign(index, value) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__resize_function__ZoneInfo__camera_yaw  // resize(index) function pointer
  },
  {
    "expected_defects",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__ZoneInfo, expected_defects),  // bytes offset in struct
    NULL,  // default value
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__size_function__ZoneInfo__expected_defects,  // size() function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_const_function__ZoneInfo__expected_defects,  // get_const(index) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__get_function__ZoneInfo__expected_defects,  // get(index) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__fetch_function__ZoneInfo__expected_defects,  // fetch(index, &value) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__assign_function__ZoneInfo__expected_defects,  // assign(index, value) function pointer
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__resize_function__ZoneInfo__expected_defects  // resize(index) function pointer
  },
  {
    "priority",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__ZoneInfo, priority),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__ZoneInfo_message_members = {
  "pegasus_msgs__msg",  // message namespace
  "ZoneInfo",  // message name
  14,  // number of fields
  sizeof(pegasus_msgs__msg__ZoneInfo),
  pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__ZoneInfo_message_member_array,  // message members
  pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__ZoneInfo_init_function,  // function to initialize message memory (memory has to be allocated)
  pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__ZoneInfo_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__ZoneInfo_message_type_support_handle = {
  0,
  &pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__ZoneInfo_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pegasus_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pegasus_msgs, msg, ZoneInfo)() {
  pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__ZoneInfo_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__ZoneInfo_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__ZoneInfo_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__ZoneInfo_message_type_support_handle.typesupport_identifier) {
    pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__ZoneInfo_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pegasus_msgs__msg__ZoneInfo__rosidl_typesupport_introspection_c__ZoneInfo_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
