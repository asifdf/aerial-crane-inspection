// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from autopilot_interface_msgs:msg/OffboardFlag.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "autopilot_interface_msgs/msg/detail/offboard_flag__rosidl_typesupport_introspection_c.h"
#include "autopilot_interface_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "autopilot_interface_msgs/msg/detail/offboard_flag__functions.h"
#include "autopilot_interface_msgs/msg/detail/offboard_flag__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void autopilot_interface_msgs__msg__OffboardFlag__rosidl_typesupport_introspection_c__OffboardFlag_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  autopilot_interface_msgs__msg__OffboardFlag__init(message_memory);
}

void autopilot_interface_msgs__msg__OffboardFlag__rosidl_typesupport_introspection_c__OffboardFlag_fini_function(void * message_memory)
{
  autopilot_interface_msgs__msg__OffboardFlag__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember autopilot_interface_msgs__msg__OffboardFlag__rosidl_typesupport_introspection_c__OffboardFlag_message_member_array[1] = {
  {
    "offboard_flag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autopilot_interface_msgs__msg__OffboardFlag, offboard_flag),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers autopilot_interface_msgs__msg__OffboardFlag__rosidl_typesupport_introspection_c__OffboardFlag_message_members = {
  "autopilot_interface_msgs__msg",  // message namespace
  "OffboardFlag",  // message name
  1,  // number of fields
  sizeof(autopilot_interface_msgs__msg__OffboardFlag),
  autopilot_interface_msgs__msg__OffboardFlag__rosidl_typesupport_introspection_c__OffboardFlag_message_member_array,  // message members
  autopilot_interface_msgs__msg__OffboardFlag__rosidl_typesupport_introspection_c__OffboardFlag_init_function,  // function to initialize message memory (memory has to be allocated)
  autopilot_interface_msgs__msg__OffboardFlag__rosidl_typesupport_introspection_c__OffboardFlag_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t autopilot_interface_msgs__msg__OffboardFlag__rosidl_typesupport_introspection_c__OffboardFlag_message_type_support_handle = {
  0,
  &autopilot_interface_msgs__msg__OffboardFlag__rosidl_typesupport_introspection_c__OffboardFlag_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_autopilot_interface_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, autopilot_interface_msgs, msg, OffboardFlag)() {
  if (!autopilot_interface_msgs__msg__OffboardFlag__rosidl_typesupport_introspection_c__OffboardFlag_message_type_support_handle.typesupport_identifier) {
    autopilot_interface_msgs__msg__OffboardFlag__rosidl_typesupport_introspection_c__OffboardFlag_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &autopilot_interface_msgs__msg__OffboardFlag__rosidl_typesupport_introspection_c__OffboardFlag_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
