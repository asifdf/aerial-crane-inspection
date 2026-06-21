// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from autopilot_interface_msgs:srv/SetReposition.idl
// generated code does not contain a copyright notice

#ifndef AUTOPILOT_INTERFACE_MSGS__SRV__DETAIL__SET_REPOSITION__FUNCTIONS_H_
#define AUTOPILOT_INTERFACE_MSGS__SRV__DETAIL__SET_REPOSITION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "autopilot_interface_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "autopilot_interface_msgs/srv/detail/set_reposition__struct.h"

/// Initialize srv/SetReposition message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * autopilot_interface_msgs__srv__SetReposition_Request
 * )) before or use
 * autopilot_interface_msgs__srv__SetReposition_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
bool
autopilot_interface_msgs__srv__SetReposition_Request__init(autopilot_interface_msgs__srv__SetReposition_Request * msg);

/// Finalize srv/SetReposition message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
void
autopilot_interface_msgs__srv__SetReposition_Request__fini(autopilot_interface_msgs__srv__SetReposition_Request * msg);

/// Create srv/SetReposition message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * autopilot_interface_msgs__srv__SetReposition_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
autopilot_interface_msgs__srv__SetReposition_Request *
autopilot_interface_msgs__srv__SetReposition_Request__create();

/// Destroy srv/SetReposition message.
/**
 * It calls
 * autopilot_interface_msgs__srv__SetReposition_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
void
autopilot_interface_msgs__srv__SetReposition_Request__destroy(autopilot_interface_msgs__srv__SetReposition_Request * msg);

/// Check for srv/SetReposition message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
bool
autopilot_interface_msgs__srv__SetReposition_Request__are_equal(const autopilot_interface_msgs__srv__SetReposition_Request * lhs, const autopilot_interface_msgs__srv__SetReposition_Request * rhs);

/// Copy a srv/SetReposition message.
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
autopilot_interface_msgs__srv__SetReposition_Request__copy(
  const autopilot_interface_msgs__srv__SetReposition_Request * input,
  autopilot_interface_msgs__srv__SetReposition_Request * output);

/// Initialize array of srv/SetReposition messages.
/**
 * It allocates the memory for the number of elements and calls
 * autopilot_interface_msgs__srv__SetReposition_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
bool
autopilot_interface_msgs__srv__SetReposition_Request__Sequence__init(autopilot_interface_msgs__srv__SetReposition_Request__Sequence * array, size_t size);

/// Finalize array of srv/SetReposition messages.
/**
 * It calls
 * autopilot_interface_msgs__srv__SetReposition_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
void
autopilot_interface_msgs__srv__SetReposition_Request__Sequence__fini(autopilot_interface_msgs__srv__SetReposition_Request__Sequence * array);

/// Create array of srv/SetReposition messages.
/**
 * It allocates the memory for the array and calls
 * autopilot_interface_msgs__srv__SetReposition_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
autopilot_interface_msgs__srv__SetReposition_Request__Sequence *
autopilot_interface_msgs__srv__SetReposition_Request__Sequence__create(size_t size);

/// Destroy array of srv/SetReposition messages.
/**
 * It calls
 * autopilot_interface_msgs__srv__SetReposition_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
void
autopilot_interface_msgs__srv__SetReposition_Request__Sequence__destroy(autopilot_interface_msgs__srv__SetReposition_Request__Sequence * array);

/// Check for srv/SetReposition message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
bool
autopilot_interface_msgs__srv__SetReposition_Request__Sequence__are_equal(const autopilot_interface_msgs__srv__SetReposition_Request__Sequence * lhs, const autopilot_interface_msgs__srv__SetReposition_Request__Sequence * rhs);

/// Copy an array of srv/SetReposition messages.
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
autopilot_interface_msgs__srv__SetReposition_Request__Sequence__copy(
  const autopilot_interface_msgs__srv__SetReposition_Request__Sequence * input,
  autopilot_interface_msgs__srv__SetReposition_Request__Sequence * output);

/// Initialize srv/SetReposition message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * autopilot_interface_msgs__srv__SetReposition_Response
 * )) before or use
 * autopilot_interface_msgs__srv__SetReposition_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
bool
autopilot_interface_msgs__srv__SetReposition_Response__init(autopilot_interface_msgs__srv__SetReposition_Response * msg);

/// Finalize srv/SetReposition message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
void
autopilot_interface_msgs__srv__SetReposition_Response__fini(autopilot_interface_msgs__srv__SetReposition_Response * msg);

/// Create srv/SetReposition message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * autopilot_interface_msgs__srv__SetReposition_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
autopilot_interface_msgs__srv__SetReposition_Response *
autopilot_interface_msgs__srv__SetReposition_Response__create();

/// Destroy srv/SetReposition message.
/**
 * It calls
 * autopilot_interface_msgs__srv__SetReposition_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
void
autopilot_interface_msgs__srv__SetReposition_Response__destroy(autopilot_interface_msgs__srv__SetReposition_Response * msg);

/// Check for srv/SetReposition message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
bool
autopilot_interface_msgs__srv__SetReposition_Response__are_equal(const autopilot_interface_msgs__srv__SetReposition_Response * lhs, const autopilot_interface_msgs__srv__SetReposition_Response * rhs);

/// Copy a srv/SetReposition message.
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
autopilot_interface_msgs__srv__SetReposition_Response__copy(
  const autopilot_interface_msgs__srv__SetReposition_Response * input,
  autopilot_interface_msgs__srv__SetReposition_Response * output);

/// Initialize array of srv/SetReposition messages.
/**
 * It allocates the memory for the number of elements and calls
 * autopilot_interface_msgs__srv__SetReposition_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
bool
autopilot_interface_msgs__srv__SetReposition_Response__Sequence__init(autopilot_interface_msgs__srv__SetReposition_Response__Sequence * array, size_t size);

/// Finalize array of srv/SetReposition messages.
/**
 * It calls
 * autopilot_interface_msgs__srv__SetReposition_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
void
autopilot_interface_msgs__srv__SetReposition_Response__Sequence__fini(autopilot_interface_msgs__srv__SetReposition_Response__Sequence * array);

/// Create array of srv/SetReposition messages.
/**
 * It allocates the memory for the array and calls
 * autopilot_interface_msgs__srv__SetReposition_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
autopilot_interface_msgs__srv__SetReposition_Response__Sequence *
autopilot_interface_msgs__srv__SetReposition_Response__Sequence__create(size_t size);

/// Destroy array of srv/SetReposition messages.
/**
 * It calls
 * autopilot_interface_msgs__srv__SetReposition_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
void
autopilot_interface_msgs__srv__SetReposition_Response__Sequence__destroy(autopilot_interface_msgs__srv__SetReposition_Response__Sequence * array);

/// Check for srv/SetReposition message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_autopilot_interface_msgs
bool
autopilot_interface_msgs__srv__SetReposition_Response__Sequence__are_equal(const autopilot_interface_msgs__srv__SetReposition_Response__Sequence * lhs, const autopilot_interface_msgs__srv__SetReposition_Response__Sequence * rhs);

/// Copy an array of srv/SetReposition messages.
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
autopilot_interface_msgs__srv__SetReposition_Response__Sequence__copy(
  const autopilot_interface_msgs__srv__SetReposition_Response__Sequence * input,
  autopilot_interface_msgs__srv__SetReposition_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // AUTOPILOT_INTERFACE_MSGS__SRV__DETAIL__SET_REPOSITION__FUNCTIONS_H_
