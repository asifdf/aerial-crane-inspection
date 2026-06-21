// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from autopilot_interface_msgs:msg/OffboardFlag.idl
// generated code does not contain a copyright notice

#ifndef AUTOPILOT_INTERFACE_MSGS__MSG__DETAIL__OFFBOARD_FLAG__FUNCTIONS_H_
#define AUTOPILOT_INTERFACE_MSGS__MSG__DETAIL__OFFBOARD_FLAG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "autopilot_interface_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "autopilot_interface_msgs/msg/detail/offboard_flag__struct.h"

/// Initialize msg/OffboardFlag message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * autopilot_interface_msgs__msg__OffboardFlag
 * )) before or use
 * autopilot_interface_msgs__msg__OffboardFlag__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
bool
autopilot_interface_msgs__msg__OffboardFlag__init(autopilot_interface_msgs__msg__OffboardFlag * msg);

/// Finalize msg/OffboardFlag message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
void
autopilot_interface_msgs__msg__OffboardFlag__fini(autopilot_interface_msgs__msg__OffboardFlag * msg);

/// Create msg/OffboardFlag message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * autopilot_interface_msgs__msg__OffboardFlag__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
autopilot_interface_msgs__msg__OffboardFlag *
autopilot_interface_msgs__msg__OffboardFlag__create();

/// Destroy msg/OffboardFlag message.
/**
 * It calls
 * autopilot_interface_msgs__msg__OffboardFlag__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
void
autopilot_interface_msgs__msg__OffboardFlag__destroy(autopilot_interface_msgs__msg__OffboardFlag * msg);

/// Check for msg/OffboardFlag message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
bool
autopilot_interface_msgs__msg__OffboardFlag__are_equal(const autopilot_interface_msgs__msg__OffboardFlag * lhs, const autopilot_interface_msgs__msg__OffboardFlag * rhs);

/// Copy a msg/OffboardFlag message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
bool
autopilot_interface_msgs__msg__OffboardFlag__copy(
  const autopilot_interface_msgs__msg__OffboardFlag * input,
  autopilot_interface_msgs__msg__OffboardFlag * output);

/// Initialize array of msg/OffboardFlag messages.
/**
 * It allocates the memory for the number of elements and calls
 * autopilot_interface_msgs__msg__OffboardFlag__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
bool
autopilot_interface_msgs__msg__OffboardFlag__Sequence__init(autopilot_interface_msgs__msg__OffboardFlag__Sequence * array, size_t size);

/// Finalize array of msg/OffboardFlag messages.
/**
 * It calls
 * autopilot_interface_msgs__msg__OffboardFlag__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
void
autopilot_interface_msgs__msg__OffboardFlag__Sequence__fini(autopilot_interface_msgs__msg__OffboardFlag__Sequence * array);

/// Create array of msg/OffboardFlag messages.
/**
 * It allocates the memory for the array and calls
 * autopilot_interface_msgs__msg__OffboardFlag__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
autopilot_interface_msgs__msg__OffboardFlag__Sequence *
autopilot_interface_msgs__msg__OffboardFlag__Sequence__create(size_t size);

/// Destroy array of msg/OffboardFlag messages.
/**
 * It calls
 * autopilot_interface_msgs__msg__OffboardFlag__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
void
autopilot_interface_msgs__msg__OffboardFlag__Sequence__destroy(autopilot_interface_msgs__msg__OffboardFlag__Sequence * array);

/// Check for msg/OffboardFlag message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
bool
autopilot_interface_msgs__msg__OffboardFlag__Sequence__are_equal(const autopilot_interface_msgs__msg__OffboardFlag__Sequence * lhs, const autopilot_interface_msgs__msg__OffboardFlag__Sequence * rhs);

/// Copy an array of msg/OffboardFlag messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
bool
autopilot_interface_msgs__msg__OffboardFlag__Sequence__copy(
  const autopilot_interface_msgs__msg__OffboardFlag__Sequence * input,
  autopilot_interface_msgs__msg__OffboardFlag__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // AUTOPILOT_INTERFACE_MSGS__MSG__DETAIL__OFFBOARD_FLAG__FUNCTIONS_H_
