// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from pegasus_msgs:msg/DefectDetection.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__DEFECT_DETECTION__FUNCTIONS_H_
#define PEGASUS_MSGS__MSG__DETAIL__DEFECT_DETECTION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "pegasus_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "pegasus_msgs/msg/detail/defect_detection__struct.h"

/// Initialize msg/DefectDetection message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * pegasus_msgs__msg__DefectDetection
 * )) before or use
 * pegasus_msgs__msg__DefectDetection__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
bool
pegasus_msgs__msg__DefectDetection__init(pegasus_msgs__msg__DefectDetection * msg);

/// Finalize msg/DefectDetection message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
void
pegasus_msgs__msg__DefectDetection__fini(pegasus_msgs__msg__DefectDetection * msg);

/// Create msg/DefectDetection message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * pegasus_msgs__msg__DefectDetection__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
pegasus_msgs__msg__DefectDetection *
pegasus_msgs__msg__DefectDetection__create();

/// Destroy msg/DefectDetection message.
/**
 * It calls
 * pegasus_msgs__msg__DefectDetection__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
void
pegasus_msgs__msg__DefectDetection__destroy(pegasus_msgs__msg__DefectDetection * msg);

/// Check for msg/DefectDetection message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
bool
pegasus_msgs__msg__DefectDetection__are_equal(const pegasus_msgs__msg__DefectDetection * lhs, const pegasus_msgs__msg__DefectDetection * rhs);

/// Copy a msg/DefectDetection message.
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
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
bool
pegasus_msgs__msg__DefectDetection__copy(
  const pegasus_msgs__msg__DefectDetection * input,
  pegasus_msgs__msg__DefectDetection * output);

/// Initialize array of msg/DefectDetection messages.
/**
 * It allocates the memory for the number of elements and calls
 * pegasus_msgs__msg__DefectDetection__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
bool
pegasus_msgs__msg__DefectDetection__Sequence__init(pegasus_msgs__msg__DefectDetection__Sequence * array, size_t size);

/// Finalize array of msg/DefectDetection messages.
/**
 * It calls
 * pegasus_msgs__msg__DefectDetection__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
void
pegasus_msgs__msg__DefectDetection__Sequence__fini(pegasus_msgs__msg__DefectDetection__Sequence * array);

/// Create array of msg/DefectDetection messages.
/**
 * It allocates the memory for the array and calls
 * pegasus_msgs__msg__DefectDetection__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
pegasus_msgs__msg__DefectDetection__Sequence *
pegasus_msgs__msg__DefectDetection__Sequence__create(size_t size);

/// Destroy array of msg/DefectDetection messages.
/**
 * It calls
 * pegasus_msgs__msg__DefectDetection__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
void
pegasus_msgs__msg__DefectDetection__Sequence__destroy(pegasus_msgs__msg__DefectDetection__Sequence * array);

/// Check for msg/DefectDetection message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
bool
pegasus_msgs__msg__DefectDetection__Sequence__are_equal(const pegasus_msgs__msg__DefectDetection__Sequence * lhs, const pegasus_msgs__msg__DefectDetection__Sequence * rhs);

/// Copy an array of msg/DefectDetection messages.
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
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
bool
pegasus_msgs__msg__DefectDetection__Sequence__copy(
  const pegasus_msgs__msg__DefectDetection__Sequence * input,
  pegasus_msgs__msg__DefectDetection__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // PEGASUS_MSGS__MSG__DETAIL__DEFECT_DETECTION__FUNCTIONS_H_
