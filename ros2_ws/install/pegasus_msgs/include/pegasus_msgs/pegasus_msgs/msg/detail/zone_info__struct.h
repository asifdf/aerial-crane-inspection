// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pegasus_msgs:msg/ZoneInfo.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__ZONE_INFO__STRUCT_H_
#define PEGASUS_MSGS__MSG__DETAIL__ZONE_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'zone_id'
// Member 'zone_name'
// Member 'zone_type'
// Member 'expected_defects'
#include "rosidl_runtime_c/string.h"
// Member 'zone_center'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'zone_dimensions'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'waypoints_x'
// Member 'waypoints_y'
// Member 'waypoints_z'
// Member 'waypoints_yaw'
// Member 'camera_pitch'
// Member 'camera_yaw'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/ZoneInfo in the package pegasus_msgs.
/**
  * Crane zone definition for mission planning
 */
typedef struct pegasus_msgs__msg__ZoneInfo
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String zone_id;
  rosidl_runtime_c__String zone_name;
  /// "beam", "column", "cable", "joint", "custom"
  rosidl_runtime_c__String zone_type;
  /// 3D bounding box of zone (in world frame)
  geometry_msgs__msg__Pose zone_center;
  geometry_msgs__msg__Vector3 zone_dimensions;
  /// Inspection parameters
  rosidl_runtime_c__float__Sequence waypoints_x;
  rosidl_runtime_c__float__Sequence waypoints_y;
  rosidl_runtime_c__float__Sequence waypoints_z;
  rosidl_runtime_c__float__Sequence waypoints_yaw;
  /// Camera angles for this zone
  rosidl_runtime_c__float__Sequence camera_pitch;
  rosidl_runtime_c__float__Sequence camera_yaw;
  /// Expected defect types in this zone
  rosidl_runtime_c__String__Sequence expected_defects;
  /// Priority
  /// 1=high, 2=medium, 3=low
  uint8_t priority;
} pegasus_msgs__msg__ZoneInfo;

// Struct for a sequence of pegasus_msgs__msg__ZoneInfo.
typedef struct pegasus_msgs__msg__ZoneInfo__Sequence
{
  pegasus_msgs__msg__ZoneInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pegasus_msgs__msg__ZoneInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PEGASUS_MSGS__MSG__DETAIL__ZONE_INFO__STRUCT_H_
