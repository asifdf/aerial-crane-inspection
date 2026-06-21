// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from autopilot_interface_msgs:srv/SetReposition.idl
// generated code does not contain a copyright notice

#ifndef AUTOPILOT_INTERFACE_MSGS__SRV__DETAIL__SET_REPOSITION__STRUCT_H_
#define AUTOPILOT_INTERFACE_MSGS__SRV__DETAIL__SET_REPOSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetReposition in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__srv__SetReposition_Request
{
  double east;
  double north;
  double altitude;
} autopilot_interface_msgs__srv__SetReposition_Request;

// Struct for a sequence of autopilot_interface_msgs__srv__SetReposition_Request.
typedef struct autopilot_interface_msgs__srv__SetReposition_Request__Sequence
{
  autopilot_interface_msgs__srv__SetReposition_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__srv__SetReposition_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetReposition in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__srv__SetReposition_Response
{
  bool success;
  rosidl_runtime_c__String message;
} autopilot_interface_msgs__srv__SetReposition_Response;

// Struct for a sequence of autopilot_interface_msgs__srv__SetReposition_Response.
typedef struct autopilot_interface_msgs__srv__SetReposition_Response__Sequence
{
  autopilot_interface_msgs__srv__SetReposition_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__srv__SetReposition_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUTOPILOT_INTERFACE_MSGS__SRV__DETAIL__SET_REPOSITION__STRUCT_H_
