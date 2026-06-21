// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from autopilot_interface_msgs:action/Offboard.idl
// generated code does not contain a copyright notice

#ifndef AUTOPILOT_INTERFACE_MSGS__ACTION__DETAIL__OFFBOARD__STRUCT_H_
#define AUTOPILOT_INTERFACE_MSGS__ACTION__DETAIL__OFFBOARD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'ATTITUDE'.
enum
{
  autopilot_interface_msgs__action__Offboard_Goal__ATTITUDE = 0
};

/// Constant 'RATES'.
enum
{
  autopilot_interface_msgs__action__Offboard_Goal__RATES = 1
};

/// Constant 'TRAJECTORY'.
enum
{
  autopilot_interface_msgs__action__Offboard_Goal__TRAJECTORY = 2
};

/// Constant 'VELOCITY'.
enum
{
  autopilot_interface_msgs__action__Offboard_Goal__VELOCITY = 3
};

/// Constant 'ACCELERATION'.
enum
{
  autopilot_interface_msgs__action__Offboard_Goal__ACCELERATION = 4
};

/// Struct defined in action/Offboard in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__action__Offboard_Goal
{
  uint8_t offboard_setpoint_type;
  double max_duration_sec;
} autopilot_interface_msgs__action__Offboard_Goal;

// Struct for a sequence of autopilot_interface_msgs__action__Offboard_Goal.
typedef struct autopilot_interface_msgs__action__Offboard_Goal__Sequence
{
  autopilot_interface_msgs__action__Offboard_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__action__Offboard_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/Offboard in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__action__Offboard_Result
{
  bool success;
} autopilot_interface_msgs__action__Offboard_Result;

// Struct for a sequence of autopilot_interface_msgs__action__Offboard_Result.
typedef struct autopilot_interface_msgs__action__Offboard_Result__Sequence
{
  autopilot_interface_msgs__action__Offboard_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__action__Offboard_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Offboard in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__action__Offboard_Feedback
{
  rosidl_runtime_c__String message;
} autopilot_interface_msgs__action__Offboard_Feedback;

// Struct for a sequence of autopilot_interface_msgs__action__Offboard_Feedback.
typedef struct autopilot_interface_msgs__action__Offboard_Feedback__Sequence
{
  autopilot_interface_msgs__action__Offboard_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__action__Offboard_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "autopilot_interface_msgs/action/detail/offboard__struct.h"

/// Struct defined in action/Offboard in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__action__Offboard_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  autopilot_interface_msgs__action__Offboard_Goal goal;
} autopilot_interface_msgs__action__Offboard_SendGoal_Request;

// Struct for a sequence of autopilot_interface_msgs__action__Offboard_SendGoal_Request.
typedef struct autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence
{
  autopilot_interface_msgs__action__Offboard_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Offboard in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__action__Offboard_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} autopilot_interface_msgs__action__Offboard_SendGoal_Response;

// Struct for a sequence of autopilot_interface_msgs__action__Offboard_SendGoal_Response.
typedef struct autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence
{
  autopilot_interface_msgs__action__Offboard_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Offboard in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__action__Offboard_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} autopilot_interface_msgs__action__Offboard_GetResult_Request;

// Struct for a sequence of autopilot_interface_msgs__action__Offboard_GetResult_Request.
typedef struct autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence
{
  autopilot_interface_msgs__action__Offboard_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "autopilot_interface_msgs/action/detail/offboard__struct.h"

/// Struct defined in action/Offboard in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__action__Offboard_GetResult_Response
{
  int8_t status;
  autopilot_interface_msgs__action__Offboard_Result result;
} autopilot_interface_msgs__action__Offboard_GetResult_Response;

// Struct for a sequence of autopilot_interface_msgs__action__Offboard_GetResult_Response.
typedef struct autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence
{
  autopilot_interface_msgs__action__Offboard_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "autopilot_interface_msgs/action/detail/offboard__struct.h"

/// Struct defined in action/Offboard in the package autopilot_interface_msgs.
typedef struct autopilot_interface_msgs__action__Offboard_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  autopilot_interface_msgs__action__Offboard_Feedback feedback;
} autopilot_interface_msgs__action__Offboard_FeedbackMessage;

// Struct for a sequence of autopilot_interface_msgs__action__Offboard_FeedbackMessage.
typedef struct autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence
{
  autopilot_interface_msgs__action__Offboard_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUTOPILOT_INTERFACE_MSGS__ACTION__DETAIL__OFFBOARD__STRUCT_H_
