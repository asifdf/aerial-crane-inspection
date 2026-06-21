// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pegasus_msgs:msg/DefectArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pegasus_msgs/msg/detail/defect_array__rosidl_typesupport_introspection_c.h"
#include "pegasus_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pegasus_msgs/msg/detail/defect_array__functions.h"
#include "pegasus_msgs/msg/detail/defect_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `drone_id`
// Member `zone_id`
// Member `max_risk_level`
#include "rosidl_runtime_c/string_functions.h"
// Member `detections`
#include "pegasus_msgs/msg/defect_detection.h"
// Member `detections`
#include "pegasus_msgs/msg/detail/defect_detection__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__DefectArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pegasus_msgs__msg__DefectArray__init(message_memory);
}

void pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__DefectArray_fini_function(void * message_memory)
{
  pegasus_msgs__msg__DefectArray__fini(message_memory);
}

size_t pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__size_function__DefectArray__detections(
  const void * untyped_member)
{
  const pegasus_msgs__msg__DefectDetection__Sequence * member =
    (const pegasus_msgs__msg__DefectDetection__Sequence *)(untyped_member);
  return member->size;
}

const void * pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__get_const_function__DefectArray__detections(
  const void * untyped_member, size_t index)
{
  const pegasus_msgs__msg__DefectDetection__Sequence * member =
    (const pegasus_msgs__msg__DefectDetection__Sequence *)(untyped_member);
  return &member->data[index];
}

void * pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__get_function__DefectArray__detections(
  void * untyped_member, size_t index)
{
  pegasus_msgs__msg__DefectDetection__Sequence * member =
    (pegasus_msgs__msg__DefectDetection__Sequence *)(untyped_member);
  return &member->data[index];
}

void pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__fetch_function__DefectArray__detections(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const pegasus_msgs__msg__DefectDetection * item =
    ((const pegasus_msgs__msg__DefectDetection *)
    pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__get_const_function__DefectArray__detections(untyped_member, index));
  pegasus_msgs__msg__DefectDetection * value =
    (pegasus_msgs__msg__DefectDetection *)(untyped_value);
  *value = *item;
}

void pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__assign_function__DefectArray__detections(
  void * untyped_member, size_t index, const void * untyped_value)
{
  pegasus_msgs__msg__DefectDetection * item =
    ((pegasus_msgs__msg__DefectDetection *)
    pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__get_function__DefectArray__detections(untyped_member, index));
  const pegasus_msgs__msg__DefectDetection * value =
    (const pegasus_msgs__msg__DefectDetection *)(untyped_value);
  *item = *value;
}

bool pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__resize_function__DefectArray__detections(
  void * untyped_member, size_t size)
{
  pegasus_msgs__msg__DefectDetection__Sequence * member =
    (pegasus_msgs__msg__DefectDetection__Sequence *)(untyped_member);
  pegasus_msgs__msg__DefectDetection__Sequence__fini(member);
  return pegasus_msgs__msg__DefectDetection__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__DefectArray_message_member_array[12] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__DefectArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "drone_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__DefectArray, drone_id),  // bytes offset in struct
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
    offsetof(pegasus_msgs__msg__DefectArray, zone_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "detections",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__DefectArray, detections),  // bytes offset in struct
    NULL,  // default value
    pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__size_function__DefectArray__detections,  // size() function pointer
    pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__get_const_function__DefectArray__detections,  // get_const(index) function pointer
    pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__get_function__DefectArray__detections,  // get(index) function pointer
    pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__fetch_function__DefectArray__detections,  // fetch(index, &value) function pointer
    pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__assign_function__DefectArray__detections,  // assign(index, value) function pointer
    pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__resize_function__DefectArray__detections  // resize(index) function pointer
  },
  {
    "total_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__DefectArray, total_count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "crack_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__DefectArray, crack_count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "corrosion_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__DefectArray, corrosion_count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "paint_damage_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__DefectArray, paint_damage_count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_risk_level",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__DefectArray, max_risk_level),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_risk_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__DefectArray, max_risk_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "inference_latency",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__DefectArray, inference_latency),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "total_latency",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pegasus_msgs__msg__DefectArray, total_latency),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__DefectArray_message_members = {
  "pegasus_msgs__msg",  // message namespace
  "DefectArray",  // message name
  12,  // number of fields
  sizeof(pegasus_msgs__msg__DefectArray),
  pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__DefectArray_message_member_array,  // message members
  pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__DefectArray_init_function,  // function to initialize message memory (memory has to be allocated)
  pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__DefectArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__DefectArray_message_type_support_handle = {
  0,
  &pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__DefectArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pegasus_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pegasus_msgs, msg, DefectArray)() {
  pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__DefectArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__DefectArray_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pegasus_msgs, msg, DefectDetection)();
  if (!pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__DefectArray_message_type_support_handle.typesupport_identifier) {
    pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__DefectArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pegasus_msgs__msg__DefectArray__rosidl_typesupport_introspection_c__DefectArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
