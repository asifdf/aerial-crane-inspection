// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pegasus_msgs:msg/InspectionResult.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__INSPECTION_RESULT__STRUCT_H_
#define PEGASUS_MSGS__MSG__DETAIL__INSPECTION_RESULT__STRUCT_H_

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
// Member 'drone_id'
// Member 'mission_id'
// Member 'zone_id'
// Member 'zone_risk_level'
// Member 'json_payload'
#include "rosidl_runtime_c/string.h"
// Member 'drone_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"
// Member 'defects'
#include "pegasus_msgs/msg/detail/defect_array__struct.h"

/// Struct defined in msg/InspectionResult in the package pegasus_msgs.
/**
  * Complete inspection result for dashboard/backend
 */
typedef struct pegasus_msgs__msg__InspectionResult
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String drone_id;
  rosidl_runtime_c__String mission_id;
  rosidl_runtime_c__String zone_id;
  /// Drone pose at time of inspection
  geometry_msgs__msg__PoseStamped drone_pose;
  /// Defects found
  pegasus_msgs__msg__DefectArray defects;
  /// Zone coverage info
  float coverage_percent;
  uint32_t images_captured;
  uint32_t images_with_defects;
  /// Overall zone risk
  rosidl_runtime_c__String zone_risk_level;
  uint8_t zone_risk_id;
  /// JSON payload (for direct backend ingestion)
  rosidl_runtime_c__String json_payload;
} pegasus_msgs__msg__InspectionResult;

// Struct for a sequence of pegasus_msgs__msg__InspectionResult.
typedef struct pegasus_msgs__msg__InspectionResult__Sequence
{
  pegasus_msgs__msg__InspectionResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pegasus_msgs__msg__InspectionResult__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PEGASUS_MSGS__MSG__DETAIL__INSPECTION_RESULT__STRUCT_H_
