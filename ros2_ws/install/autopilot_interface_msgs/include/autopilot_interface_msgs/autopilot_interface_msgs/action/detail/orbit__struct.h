// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from autopilot_interface_msgs:action/Orbit.idl
// generated code does not contain a copyright notice

#ifndef AUTOPILOT_INTERFACE_MSGS__ACTION__DETAIL__ORBIT__STRUCT_H_
#define AUTOPILOT_INTERFACE_MSGS__ACTION__DETAIL__ORBIT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/Orbit in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__action__Orbit_Goal
{
  double east;
  double north;
  double altitude;
  double radius;
} autopilot_interface_msgs__action__Orbit_Goal;

// Struct for a sequence of autopilot_interface_msgs__action__Orbit_Goal.
typedef struct autopilot_interface_msgs__action__Orbit_Goal__Sequence
{
  autopilot_interface_msgs__action__Orbit_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__action__Orbit_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/Orbit in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__action__Orbit_Result
{
  bool success;
} autopilot_interface_msgs__action__Orbit_Result;

// Struct for a sequence of autopilot_interface_msgs__action__Orbit_Result.
typedef struct autopilot_interface_msgs__action__Orbit_Result__Sequence
{
  autopilot_interface_msgs__action__Orbit_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__action__Orbit_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Orbit in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__action__Orbit_Feedback
{
  rosidl_runtime_c__String message;
} autopilot_interface_msgs__action__Orbit_Feedback;

// Struct for a sequence of autopilot_interface_msgs__action__Orbit_Feedback.
typedef struct autopilot_interface_msgs__action__Orbit_Feedback__Sequence
{
  autopilot_interface_msgs__action__Orbit_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__action__Orbit_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "autopilot_interface_msgs/action/detail/orbit__struct.h"

/// Struct defined in action/Orbit in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__action__Orbit_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  autopilot_interface_msgs__action__Orbit_Goal goal;
} autopilot_interface_msgs__action__Orbit_SendGoal_Request;

// Struct for a sequence of autopilot_interface_msgs__action__Orbit_SendGoal_Request.
typedef struct autopilot_interface_msgs__action__Orbit_SendGoal_Request__Sequence
{
  autopilot_interface_msgs__action__Orbit_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__action__Orbit_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Orbit in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__action__Orbit_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} autopilot_interface_msgs__action__Orbit_SendGoal_Response;

// Struct for a sequence of autopilot_interface_msgs__action__Orbit_SendGoal_Response.
typedef struct autopilot_interface_msgs__action__Orbit_SendGoal_Response__Sequence
{
  autopilot_interface_msgs__action__Orbit_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__action__Orbit_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Orbit in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__action__Orbit_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} autopilot_interface_msgs__action__Orbit_GetResult_Request;

// Struct for a sequence of autopilot_interface_msgs__action__Orbit_GetResult_Request.
typedef struct autopilot_interface_msgs__action__Orbit_GetResult_Request__Sequence
{
  autopilot_interface_msgs__action__Orbit_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__action__Orbit_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "autopilot_interface_msgs/action/detail/orbit__struct.h"

/// Struct defined in action/Orbit in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__action__Orbit_GetResult_Response
{
  int8_t status;
  autopilot_interface_msgs__action__Orbit_Result result;
} autopilot_interface_msgs__action__Orbit_GetResult_Response;

// Struct for a sequence of autopilot_interface_msgs__action__Orbit_GetResult_Response.
typedef struct autopilot_interface_msgs__action__Orbit_GetResult_Response__Sequence
{
  autopilot_interface_msgs__action__Orbit_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__action__Orbit_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "autopilot_interface_msgs/action/detail/orbit__struct.h"

/// Struct defined in action/Orbit in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__action__Orbit_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  autopilot_interface_msgs__action__Orbit_Feedback feedback;
} autopilot_interface_msgs__action__Orbit_FeedbackMessage;

// Struct for a sequence of autopilot_interface_msgs__action__Orbit_FeedbackMessage.
typedef struct autopilot_interface_msgs__action__Orbit_FeedbackMessage__Sequence
{
  autopilot_interface_msgs__action__Orbit_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__action__Orbit_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUTOPILOT_INTERFACE_MSGS__ACTION__DETAIL__ORBIT__STRUCT_H_
