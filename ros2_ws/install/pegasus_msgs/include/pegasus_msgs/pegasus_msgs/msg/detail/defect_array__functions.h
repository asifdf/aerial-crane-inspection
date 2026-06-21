// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from pegasus_msgs:msg/DefectArray.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__DEFECT_ARRAY__FUNCTIONS_H_
#define PEGASUS_MSGS__MSG__DETAIL__DEFECT_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "pegasus_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "pegasus_msgs/msg/detail/defect_array__struct.h"

/// Initialize msg/DefectArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * pegasus_msgs__msg__DefectArray
 * )) before or use
 * pegasus_msgs__msg__DefectArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
bool
pegasus_msgs__msg__DefectArray__init(pegasus_msgs__msg__DefectArray * msg);

/// Finalize msg/DefectArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
void
pegasus_msgs__msg__DefectArray__fini(pegasus_msgs__msg__DefectArray * msg);

/// Create msg/DefectArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * pegasus_msgs__msg__DefectArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
pegasus_msgs__msg__DefectArray *
pegasus_msgs__msg__DefectArray__create();

/// Destroy msg/DefectArray message.
/**
 * It calls
 * pegasus_msgs__msg__DefectArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
void
pegasus_msgs__msg__DefectArray__destroy(pegasus_msgs__msg__DefectArray * msg);

/// Check for msg/DefectArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
bool
pegasus_msgs__msg__DefectArray__are_equal(const pegasus_msgs__msg__DefectArray * lhs, const pegasus_msgs__msg__DefectArray * rhs);

/// Copy a msg/DefectArray message.
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
pegasus_msgs__msg__DefectArray__copy(
  const pegasus_msgs__msg__DefectArray * input,
  pegasus_msgs__msg__DefectArray * output);

/// Initialize array of msg/DefectArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * pegasus_msgs__msg__DefectArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
bool
pegasus_msgs__msg__DefectArray__Sequence__init(pegasus_msgs__msg__DefectArray__Sequence * array, size_t size);

/// Finalize array of msg/DefectArray messages.
/**
 * It calls
 * pegasus_msgs__msg__DefectArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
void
pegasus_msgs__msg__DefectArray__Sequence__fini(pegasus_msgs__msg__DefectArray__Sequence * array);

/// Create array of msg/DefectArray messages.
/**
 * It allocates the memory for the array and calls
 * pegasus_msgs__msg__DefectArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
pegasus_msgs__msg__DefectArray__Sequence *
pegasus_msgs__msg__DefectArray__Sequence__create(size_t size);

/// Destroy array of msg/DefectArray messages.
/**
 * It calls
 * pegasus_msgs__msg__DefectArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
void
pegasus_msgs__msg__DefectArray__Sequence__destroy(pegasus_msgs__msg__DefectArray__Sequence * array);

/// Check for msg/DefectArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pegasus_msgs
bool
pegasus_msgs__msg__DefectArray__Sequence__are_equal(const pegasus_msgs__msg__DefectArray__Sequence * lhs, const pegasus_msgs__msg__DefectArray__Sequence * rhs);

/// Copy an array of msg/DefectArray messages.
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
pegasus_msgs__msg__DefectArray__Sequence__copy(
  const pegasus_msgs__msg__DefectArray__Sequence * input,
  pegasus_msgs__msg__DefectArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // PEGASUS_MSGS__MSG__DETAIL__DEFECT_ARRAY__FUNCTIONS_H_
