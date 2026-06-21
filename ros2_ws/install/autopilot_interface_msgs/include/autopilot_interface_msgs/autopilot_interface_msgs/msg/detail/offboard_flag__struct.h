// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from autopilot_interface_msgs:msg/OffboardFlag.idl
// generated code does not contain a copyright notice

#ifndef AUTOPILOT_INTERFACE_MSGS__MSG__DETAIL__OFFBOARD_FLAG__STRUCT_H_
#define AUTOPILOT_INTERFACE_MSGS__MSG__DETAIL__OFFBOARD_FLAG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'INACTIVE'.
enum
{
  autopilot_interface_msgs__msg__OffboardFlag__INACTIVE = 0
};

/// Constant 'PX4_QUAD_ATTITUDE'.
enum
{
  autopilot_interface_msgs__msg__OffboardFlag__PX4_QUAD_ATTITUDE = 1
};

/// Constant 'PX4_VTOL_ATTITUDE'.
enum
{
  autopilot_interface_msgs__msg__OffboardFlag__PX4_VTOL_ATTITUDE = 2
};

/// Constant 'PX4_QUAD_RATES'.
enum
{
  autopilot_interface_msgs__msg__OffboardFlag__PX4_QUAD_RATES = 3
};

/// Constant 'PX4_VTOL_RATES'.
enum
{
  autopilot_interface_msgs__msg__OffboardFlag__PX4_VTOL_RATES = 4
};

/// Constant 'PX4_QUAD_TRAJECTORY'.
enum
{
  autopilot_interface_msgs__msg__OffboardFlag__PX4_QUAD_TRAJECTORY = 5
};

/// Constant 'PX4_VTOL_TRAJECTORY'.
enum
{
  autopilot_interface_msgs__msg__OffboardFlag__PX4_VTOL_TRAJECTORY = 6
};

/// Constant 'AP_QUAD_VELOCITY'.
enum
{
  autopilot_interface_msgs__msg__OffboardFlag__AP_QUAD_VELOCITY = 7
};

/// Constant 'AP_QUAD_ACCELERATION'.
enum
{
  autopilot_interface_msgs__msg__OffboardFlag__AP_QUAD_ACCELERATION = 8
};

/// Struct defined in msg/OffboardFlag in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__msg__OffboardFlag
{
  uint8_t offboard_flag;
} autopilot_interface_msgs__msg__OffboardFlag;

// Struct for a sequence of autopilot_interface_msgs__msg__OffboardFlag.
typedef struct autopilot_interface_msgs__msg__OffboardFlag__Sequence
{
  autopilot_interface_msgs__msg__OffboardFlag * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__msg__OffboardFlag__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUTOPILOT_INTERFACE_MSGS__MSG__DETAIL__OFFBOARD_FLAG__STRUCT_H_
