// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from autopilot_interface_msgs:action/Offboard.idl
// generated code does not contain a copyright notice
#include "autopilot_interface_msgs/action/detail/offboard__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
autopilot_interface_msgs__action__Offboard_Goal__init(autopilot_interface_msgs__action__Offboard_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // offboard_setpoint_type
  // max_duration_sec
  msg->max_duration_sec = 3.0l;
  return true;
}

void
autopilot_interface_msgs__action__Offboard_Goal__fini(autopilot_interface_msgs__action__Offboard_Goal * msg)
{
  if (!msg) {
    return;
  }
  // offboard_setpoint_type
  // max_duration_sec
}

bool
autopilot_interface_msgs__action__Offboard_Goal__are_equal(const autopilot_interface_msgs__action__Offboard_Goal * lhs, const autopilot_interface_msgs__action__Offboard_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // offboard_setpoint_type
  if (lhs->offboard_setpoint_type != rhs->offboard_setpoint_type) {
    return false;
  }
  // max_duration_sec
  if (lhs->max_duration_sec != rhs->max_duration_sec) {
    return false;
  }
  return true;
}

bool
autopilot_interface_msgs__action__Offboard_Goal__copy(
  const autopilot_interface_msgs__action__Offboard_Goal * input,
  autopilot_interface_msgs__action__Offboard_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // offboard_setpoint_type
  output->offboard_setpoint_type = input->offboard_setpoint_type;
  // max_duration_sec
  output->max_duration_sec = input->max_duration_sec;
  return true;
}

autopilot_interface_msgs__action__Offboard_Goal *
autopilot_interface_msgs__action__Offboard_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_Goal * msg = (autopilot_interface_msgs__action__Offboard_Goal *)allocator.allocate(sizeof(autopilot_interface_msgs__action__Offboard_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(autopilot_interface_msgs__action__Offboard_Goal));
  bool success = autopilot_interface_msgs__action__Offboard_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
autopilot_interface_msgs__action__Offboard_Goal__destroy(autopilot_interface_msgs__action__Offboard_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    autopilot_interface_msgs__action__Offboard_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
autopilot_interface_msgs__action__Offboard_Goal__Sequence__init(autopilot_interface_msgs__action__Offboard_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_Goal * data = NULL;

  if (size) {
    data = (autopilot_interface_msgs__action__Offboard_Goal *)allocator.zero_allocate(size, sizeof(autopilot_interface_msgs__action__Offboard_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = autopilot_interface_msgs__action__Offboard_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        autopilot_interface_msgs__action__Offboard_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
autopilot_interface_msgs__action__Offboard_Goal__Sequence__fini(autopilot_interface_msgs__action__Offboard_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      autopilot_interface_msgs__action__Offboard_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

autopilot_interface_msgs__action__Offboard_Goal__Sequence *
autopilot_interface_msgs__action__Offboard_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_Goal__Sequence * array = (autopilot_interface_msgs__action__Offboard_Goal__Sequence *)allocator.allocate(sizeof(autopilot_interface_msgs__action__Offboard_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = autopilot_interface_msgs__action__Offboard_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
autopilot_interface_msgs__action__Offboard_Goal__Sequence__destroy(autopilot_interface_msgs__action__Offboard_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    autopilot_interface_msgs__action__Offboard_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
autopilot_interface_msgs__action__Offboard_Goal__Sequence__are_equal(const autopilot_interface_msgs__action__Offboard_Goal__Sequence * lhs, const autopilot_interface_msgs__action__Offboard_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!autopilot_interface_msgs__action__Offboard_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
autopilot_interface_msgs__action__Offboard_Goal__Sequence__copy(
  const autopilot_interface_msgs__action__Offboard_Goal__Sequence * input,
  autopilot_interface_msgs__action__Offboard_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(autopilot_interface_msgs__action__Offboard_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    autopilot_interface_msgs__action__Offboard_Goal * data =
      (autopilot_interface_msgs__action__Offboard_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!autopilot_interface_msgs__action__Offboard_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          autopilot_interface_msgs__action__Offboard_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!autopilot_interface_msgs__action__Offboard_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
autopilot_interface_msgs__action__Offboard_Result__init(autopilot_interface_msgs__action__Offboard_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
autopilot_interface_msgs__action__Offboard_Result__fini(autopilot_interface_msgs__action__Offboard_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
autopilot_interface_msgs__action__Offboard_Result__are_equal(const autopilot_interface_msgs__action__Offboard_Result * lhs, const autopilot_interface_msgs__action__Offboard_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
autopilot_interface_msgs__action__Offboard_Result__copy(
  const autopilot_interface_msgs__action__Offboard_Result * input,
  autopilot_interface_msgs__action__Offboard_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

autopilot_interface_msgs__action__Offboard_Result *
autopilot_interface_msgs__action__Offboard_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_Result * msg = (autopilot_interface_msgs__action__Offboard_Result *)allocator.allocate(sizeof(autopilot_interface_msgs__action__Offboard_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(autopilot_interface_msgs__action__Offboard_Result));
  bool success = autopilot_interface_msgs__action__Offboard_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
autopilot_interface_msgs__action__Offboard_Result__destroy(autopilot_interface_msgs__action__Offboard_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    autopilot_interface_msgs__action__Offboard_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
autopilot_interface_msgs__action__Offboard_Result__Sequence__init(autopilot_interface_msgs__action__Offboard_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_Result * data = NULL;

  if (size) {
    data = (autopilot_interface_msgs__action__Offboard_Result *)allocator.zero_allocate(size, sizeof(autopilot_interface_msgs__action__Offboard_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = autopilot_interface_msgs__action__Offboard_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        autopilot_interface_msgs__action__Offboard_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
autopilot_interface_msgs__action__Offboard_Result__Sequence__fini(autopilot_interface_msgs__action__Offboard_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      autopilot_interface_msgs__action__Offboard_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

autopilot_interface_msgs__action__Offboard_Result__Sequence *
autopilot_interface_msgs__action__Offboard_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_Result__Sequence * array = (autopilot_interface_msgs__action__Offboard_Result__Sequence *)allocator.allocate(sizeof(autopilot_interface_msgs__action__Offboard_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = autopilot_interface_msgs__action__Offboard_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
autopilot_interface_msgs__action__Offboard_Result__Sequence__destroy(autopilot_interface_msgs__action__Offboard_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    autopilot_interface_msgs__action__Offboard_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
autopilot_interface_msgs__action__Offboard_Result__Sequence__are_equal(const autopilot_interface_msgs__action__Offboard_Result__Sequence * lhs, const autopilot_interface_msgs__action__Offboard_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!autopilot_interface_msgs__action__Offboard_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
autopilot_interface_msgs__action__Offboard_Result__Sequence__copy(
  const autopilot_interface_msgs__action__Offboard_Result__Sequence * input,
  autopilot_interface_msgs__action__Offboard_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(autopilot_interface_msgs__action__Offboard_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    autopilot_interface_msgs__action__Offboard_Result * data =
      (autopilot_interface_msgs__action__Offboard_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!autopilot_interface_msgs__action__Offboard_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          autopilot_interface_msgs__action__Offboard_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!autopilot_interface_msgs__action__Offboard_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
autopilot_interface_msgs__action__Offboard_Feedback__init(autopilot_interface_msgs__action__Offboard_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    autopilot_interface_msgs__action__Offboard_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
autopilot_interface_msgs__action__Offboard_Feedback__fini(autopilot_interface_msgs__action__Offboard_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
autopilot_interface_msgs__action__Offboard_Feedback__are_equal(const autopilot_interface_msgs__action__Offboard_Feedback * lhs, const autopilot_interface_msgs__action__Offboard_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
autopilot_interface_msgs__action__Offboard_Feedback__copy(
  const autopilot_interface_msgs__action__Offboard_Feedback * input,
  autopilot_interface_msgs__action__Offboard_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

autopilot_interface_msgs__action__Offboard_Feedback *
autopilot_interface_msgs__action__Offboard_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_Feedback * msg = (autopilot_interface_msgs__action__Offboard_Feedback *)allocator.allocate(sizeof(autopilot_interface_msgs__action__Offboard_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(autopilot_interface_msgs__action__Offboard_Feedback));
  bool success = autopilot_interface_msgs__action__Offboard_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
autopilot_interface_msgs__action__Offboard_Feedback__destroy(autopilot_interface_msgs__action__Offboard_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    autopilot_interface_msgs__action__Offboard_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
autopilot_interface_msgs__action__Offboard_Feedback__Sequence__init(autopilot_interface_msgs__action__Offboard_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_Feedback * data = NULL;

  if (size) {
    data = (autopilot_interface_msgs__action__Offboard_Feedback *)allocator.zero_allocate(size, sizeof(autopilot_interface_msgs__action__Offboard_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = autopilot_interface_msgs__action__Offboard_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        autopilot_interface_msgs__action__Offboard_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
autopilot_interface_msgs__action__Offboard_Feedback__Sequence__fini(autopilot_interface_msgs__action__Offboard_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      autopilot_interface_msgs__action__Offboard_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

autopilot_interface_msgs__action__Offboard_Feedback__Sequence *
autopilot_interface_msgs__action__Offboard_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_Feedback__Sequence * array = (autopilot_interface_msgs__action__Offboard_Feedback__Sequence *)allocator.allocate(sizeof(autopilot_interface_msgs__action__Offboard_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = autopilot_interface_msgs__action__Offboard_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
autopilot_interface_msgs__action__Offboard_Feedback__Sequence__destroy(autopilot_interface_msgs__action__Offboard_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    autopilot_interface_msgs__action__Offboard_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
autopilot_interface_msgs__action__Offboard_Feedback__Sequence__are_equal(const autopilot_interface_msgs__action__Offboard_Feedback__Sequence * lhs, const autopilot_interface_msgs__action__Offboard_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!autopilot_interface_msgs__action__Offboard_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
autopilot_interface_msgs__action__Offboard_Feedback__Sequence__copy(
  const autopilot_interface_msgs__action__Offboard_Feedback__Sequence * input,
  autopilot_interface_msgs__action__Offboard_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(autopilot_interface_msgs__action__Offboard_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    autopilot_interface_msgs__action__Offboard_Feedback * data =
      (autopilot_interface_msgs__action__Offboard_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!autopilot_interface_msgs__action__Offboard_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          autopilot_interface_msgs__action__Offboard_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!autopilot_interface_msgs__action__Offboard_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "autopilot_interface_msgs/action/detail/offboard__functions.h"

bool
autopilot_interface_msgs__action__Offboard_SendGoal_Request__init(autopilot_interface_msgs__action__Offboard_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    autopilot_interface_msgs__action__Offboard_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!autopilot_interface_msgs__action__Offboard_Goal__init(&msg->goal)) {
    autopilot_interface_msgs__action__Offboard_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
autopilot_interface_msgs__action__Offboard_SendGoal_Request__fini(autopilot_interface_msgs__action__Offboard_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  autopilot_interface_msgs__action__Offboard_Goal__fini(&msg->goal);
}

bool
autopilot_interface_msgs__action__Offboard_SendGoal_Request__are_equal(const autopilot_interface_msgs__action__Offboard_SendGoal_Request * lhs, const autopilot_interface_msgs__action__Offboard_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!autopilot_interface_msgs__action__Offboard_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
autopilot_interface_msgs__action__Offboard_SendGoal_Request__copy(
  const autopilot_interface_msgs__action__Offboard_SendGoal_Request * input,
  autopilot_interface_msgs__action__Offboard_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!autopilot_interface_msgs__action__Offboard_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

autopilot_interface_msgs__action__Offboard_SendGoal_Request *
autopilot_interface_msgs__action__Offboard_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_SendGoal_Request * msg = (autopilot_interface_msgs__action__Offboard_SendGoal_Request *)allocator.allocate(sizeof(autopilot_interface_msgs__action__Offboard_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(autopilot_interface_msgs__action__Offboard_SendGoal_Request));
  bool success = autopilot_interface_msgs__action__Offboard_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
autopilot_interface_msgs__action__Offboard_SendGoal_Request__destroy(autopilot_interface_msgs__action__Offboard_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    autopilot_interface_msgs__action__Offboard_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence__init(autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_SendGoal_Request * data = NULL;

  if (size) {
    data = (autopilot_interface_msgs__action__Offboard_SendGoal_Request *)allocator.zero_allocate(size, sizeof(autopilot_interface_msgs__action__Offboard_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = autopilot_interface_msgs__action__Offboard_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        autopilot_interface_msgs__action__Offboard_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence__fini(autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      autopilot_interface_msgs__action__Offboard_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence *
autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence * array = (autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence *)allocator.allocate(sizeof(autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence__destroy(autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence__are_equal(const autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence * lhs, const autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!autopilot_interface_msgs__action__Offboard_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence__copy(
  const autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence * input,
  autopilot_interface_msgs__action__Offboard_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(autopilot_interface_msgs__action__Offboard_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    autopilot_interface_msgs__action__Offboard_SendGoal_Request * data =
      (autopilot_interface_msgs__action__Offboard_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!autopilot_interface_msgs__action__Offboard_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          autopilot_interface_msgs__action__Offboard_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!autopilot_interface_msgs__action__Offboard_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
autopilot_interface_msgs__action__Offboard_SendGoal_Response__init(autopilot_interface_msgs__action__Offboard_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    autopilot_interface_msgs__action__Offboard_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
autopilot_interface_msgs__action__Offboard_SendGoal_Response__fini(autopilot_interface_msgs__action__Offboard_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
autopilot_interface_msgs__action__Offboard_SendGoal_Response__are_equal(const autopilot_interface_msgs__action__Offboard_SendGoal_Response * lhs, const autopilot_interface_msgs__action__Offboard_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
autopilot_interface_msgs__action__Offboard_SendGoal_Response__copy(
  const autopilot_interface_msgs__action__Offboard_SendGoal_Response * input,
  autopilot_interface_msgs__action__Offboard_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

autopilot_interface_msgs__action__Offboard_SendGoal_Response *
autopilot_interface_msgs__action__Offboard_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_SendGoal_Response * msg = (autopilot_interface_msgs__action__Offboard_SendGoal_Response *)allocator.allocate(sizeof(autopilot_interface_msgs__action__Offboard_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(autopilot_interface_msgs__action__Offboard_SendGoal_Response));
  bool success = autopilot_interface_msgs__action__Offboard_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
autopilot_interface_msgs__action__Offboard_SendGoal_Response__destroy(autopilot_interface_msgs__action__Offboard_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    autopilot_interface_msgs__action__Offboard_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence__init(autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_SendGoal_Response * data = NULL;

  if (size) {
    data = (autopilot_interface_msgs__action__Offboard_SendGoal_Response *)allocator.zero_allocate(size, sizeof(autopilot_interface_msgs__action__Offboard_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = autopilot_interface_msgs__action__Offboard_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        autopilot_interface_msgs__action__Offboard_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence__fini(autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      autopilot_interface_msgs__action__Offboard_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence *
autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence * array = (autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence *)allocator.allocate(sizeof(autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence__destroy(autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence__are_equal(const autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence * lhs, const autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!autopilot_interface_msgs__action__Offboard_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence__copy(
  const autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence * input,
  autopilot_interface_msgs__action__Offboard_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(autopilot_interface_msgs__action__Offboard_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    autopilot_interface_msgs__action__Offboard_SendGoal_Response * data =
      (autopilot_interface_msgs__action__Offboard_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!autopilot_interface_msgs__action__Offboard_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          autopilot_interface_msgs__action__Offboard_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!autopilot_interface_msgs__action__Offboard_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
autopilot_interface_msgs__action__Offboard_GetResult_Request__init(autopilot_interface_msgs__action__Offboard_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    autopilot_interface_msgs__action__Offboard_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
autopilot_interface_msgs__action__Offboard_GetResult_Request__fini(autopilot_interface_msgs__action__Offboard_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
autopilot_interface_msgs__action__Offboard_GetResult_Request__are_equal(const autopilot_interface_msgs__action__Offboard_GetResult_Request * lhs, const autopilot_interface_msgs__action__Offboard_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
autopilot_interface_msgs__action__Offboard_GetResult_Request__copy(
  const autopilot_interface_msgs__action__Offboard_GetResult_Request * input,
  autopilot_interface_msgs__action__Offboard_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

autopilot_interface_msgs__action__Offboard_GetResult_Request *
autopilot_interface_msgs__action__Offboard_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_GetResult_Request * msg = (autopilot_interface_msgs__action__Offboard_GetResult_Request *)allocator.allocate(sizeof(autopilot_interface_msgs__action__Offboard_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(autopilot_interface_msgs__action__Offboard_GetResult_Request));
  bool success = autopilot_interface_msgs__action__Offboard_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
autopilot_interface_msgs__action__Offboard_GetResult_Request__destroy(autopilot_interface_msgs__action__Offboard_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    autopilot_interface_msgs__action__Offboard_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence__init(autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_GetResult_Request * data = NULL;

  if (size) {
    data = (autopilot_interface_msgs__action__Offboard_GetResult_Request *)allocator.zero_allocate(size, sizeof(autopilot_interface_msgs__action__Offboard_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = autopilot_interface_msgs__action__Offboard_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        autopilot_interface_msgs__action__Offboard_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence__fini(autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      autopilot_interface_msgs__action__Offboard_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence *
autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence * array = (autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence *)allocator.allocate(sizeof(autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence__destroy(autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence__are_equal(const autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence * lhs, const autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!autopilot_interface_msgs__action__Offboard_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence__copy(
  const autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence * input,
  autopilot_interface_msgs__action__Offboard_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(autopilot_interface_msgs__action__Offboard_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    autopilot_interface_msgs__action__Offboard_GetResult_Request * data =
      (autopilot_interface_msgs__action__Offboard_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!autopilot_interface_msgs__action__Offboard_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          autopilot_interface_msgs__action__Offboard_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!autopilot_interface_msgs__action__Offboard_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "autopilot_interface_msgs/action/detail/offboard__functions.h"

bool
autopilot_interface_msgs__action__Offboard_GetResult_Response__init(autopilot_interface_msgs__action__Offboard_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!autopilot_interface_msgs__action__Offboard_Result__init(&msg->result)) {
    autopilot_interface_msgs__action__Offboard_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
autopilot_interface_msgs__action__Offboard_GetResult_Response__fini(autopilot_interface_msgs__action__Offboard_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  autopilot_interface_msgs__action__Offboard_Result__fini(&msg->result);
}

bool
autopilot_interface_msgs__action__Offboard_GetResult_Response__are_equal(const autopilot_interface_msgs__action__Offboard_GetResult_Response * lhs, const autopilot_interface_msgs__action__Offboard_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!autopilot_interface_msgs__action__Offboard_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
autopilot_interface_msgs__action__Offboard_GetResult_Response__copy(
  const autopilot_interface_msgs__action__Offboard_GetResult_Response * input,
  autopilot_interface_msgs__action__Offboard_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!autopilot_interface_msgs__action__Offboard_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

autopilot_interface_msgs__action__Offboard_GetResult_Response *
autopilot_interface_msgs__action__Offboard_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_GetResult_Response * msg = (autopilot_interface_msgs__action__Offboard_GetResult_Response *)allocator.allocate(sizeof(autopilot_interface_msgs__action__Offboard_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(autopilot_interface_msgs__action__Offboard_GetResult_Response));
  bool success = autopilot_interface_msgs__action__Offboard_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
autopilot_interface_msgs__action__Offboard_GetResult_Response__destroy(autopilot_interface_msgs__action__Offboard_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    autopilot_interface_msgs__action__Offboard_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence__init(autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_GetResult_Response * data = NULL;

  if (size) {
    data = (autopilot_interface_msgs__action__Offboard_GetResult_Response *)allocator.zero_allocate(size, sizeof(autopilot_interface_msgs__action__Offboard_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = autopilot_interface_msgs__action__Offboard_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        autopilot_interface_msgs__action__Offboard_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence__fini(autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      autopilot_interface_msgs__action__Offboard_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence *
autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence * array = (autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence *)allocator.allocate(sizeof(autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence__destroy(autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence__are_equal(const autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence * lhs, const autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!autopilot_interface_msgs__action__Offboard_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence__copy(
  const autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence * input,
  autopilot_interface_msgs__action__Offboard_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(autopilot_interface_msgs__action__Offboard_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    autopilot_interface_msgs__action__Offboard_GetResult_Response * data =
      (autopilot_interface_msgs__action__Offboard_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!autopilot_interface_msgs__action__Offboard_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          autopilot_interface_msgs__action__Offboard_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!autopilot_interface_msgs__action__Offboard_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "autopilot_interface_msgs/action/detail/offboard__functions.h"

bool
autopilot_interface_msgs__action__Offboard_FeedbackMessage__init(autopilot_interface_msgs__action__Offboard_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    autopilot_interface_msgs__action__Offboard_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!autopilot_interface_msgs__action__Offboard_Feedback__init(&msg->feedback)) {
    autopilot_interface_msgs__action__Offboard_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
autopilot_interface_msgs__action__Offboard_FeedbackMessage__fini(autopilot_interface_msgs__action__Offboard_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  autopilot_interface_msgs__action__Offboard_Feedback__fini(&msg->feedback);
}

bool
autopilot_interface_msgs__action__Offboard_FeedbackMessage__are_equal(const autopilot_interface_msgs__action__Offboard_FeedbackMessage * lhs, const autopilot_interface_msgs__action__Offboard_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!autopilot_interface_msgs__action__Offboard_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
autopilot_interface_msgs__action__Offboard_FeedbackMessage__copy(
  const autopilot_interface_msgs__action__Offboard_FeedbackMessage * input,
  autopilot_interface_msgs__action__Offboard_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!autopilot_interface_msgs__action__Offboard_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

autopilot_interface_msgs__action__Offboard_FeedbackMessage *
autopilot_interface_msgs__action__Offboard_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_FeedbackMessage * msg = (autopilot_interface_msgs__action__Offboard_FeedbackMessage *)allocator.allocate(sizeof(autopilot_interface_msgs__action__Offboard_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(autopilot_interface_msgs__action__Offboard_FeedbackMessage));
  bool success = autopilot_interface_msgs__action__Offboard_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
autopilot_interface_msgs__action__Offboard_FeedbackMessage__destroy(autopilot_interface_msgs__action__Offboard_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    autopilot_interface_msgs__action__Offboard_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence__init(autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_FeedbackMessage * data = NULL;

  if (size) {
    data = (autopilot_interface_msgs__action__Offboard_FeedbackMessage *)allocator.zero_allocate(size, sizeof(autopilot_interface_msgs__action__Offboard_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = autopilot_interface_msgs__action__Offboard_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        autopilot_interface_msgs__action__Offboard_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence__fini(autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      autopilot_interface_msgs__action__Offboard_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence *
autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence * array = (autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence *)allocator.allocate(sizeof(autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence__destroy(autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence__are_equal(const autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence * lhs, const autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!autopilot_interface_msgs__action__Offboard_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence__copy(
  const autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence * input,
  autopilot_interface_msgs__action__Offboard_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(autopilot_interface_msgs__action__Offboard_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    autopilot_interface_msgs__action__Offboard_FeedbackMessage * data =
      (autopilot_interface_msgs__action__Offboard_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!autopilot_interface_msgs__action__Offboard_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          autopilot_interface_msgs__action__Offboard_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!autopilot_interface_msgs__action__Offboard_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
