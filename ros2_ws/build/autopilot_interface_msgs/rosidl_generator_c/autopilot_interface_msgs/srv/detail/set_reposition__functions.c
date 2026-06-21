// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from autopilot_interface_msgs:srv/SetReposition.idl
// generated code does not contain a copyright notice
#include "autopilot_interface_msgs/srv/detail/set_reposition__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
autopilot_interface_msgs__srv__SetReposition_Request__init(autopilot_interface_msgs__srv__SetReposition_Request * msg)
{
  if (!msg) {
    return false;
  }
  // east
  // north
  // altitude
  return true;
}

void
autopilot_interface_msgs__srv__SetReposition_Request__fini(autopilot_interface_msgs__srv__SetReposition_Request * msg)
{
  if (!msg) {
    return;
  }
  // east
  // north
  // altitude
}

bool
autopilot_interface_msgs__srv__SetReposition_Request__are_equal(const autopilot_interface_msgs__srv__SetReposition_Request * lhs, const autopilot_interface_msgs__srv__SetReposition_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // east
  if (lhs->east != rhs->east) {
    return false;
  }
  // north
  if (lhs->north != rhs->north) {
    return false;
  }
  // altitude
  if (lhs->altitude != rhs->altitude) {
    return false;
  }
  return true;
}

bool
autopilot_interface_msgs__srv__SetReposition_Request__copy(
  const autopilot_interface_msgs__srv__SetReposition_Request * input,
  autopilot_interface_msgs__srv__SetReposition_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // east
  output->east = input->east;
  // north
  output->north = input->north;
  // altitude
  output->altitude = input->altitude;
  return true;
}

autopilot_interface_msgs__srv__SetReposition_Request *
autopilot_interface_msgs__srv__SetReposition_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__srv__SetReposition_Request * msg = (autopilot_interface_msgs__srv__SetReposition_Request *)allocator.allocate(sizeof(autopilot_interface_msgs__srv__SetReposition_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(autopilot_interface_msgs__srv__SetReposition_Request));
  bool success = autopilot_interface_msgs__srv__SetReposition_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
autopilot_interface_msgs__srv__SetReposition_Request__destroy(autopilot_interface_msgs__srv__SetReposition_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    autopilot_interface_msgs__srv__SetReposition_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
autopilot_interface_msgs__srv__SetReposition_Request__Sequence__init(autopilot_interface_msgs__srv__SetReposition_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__srv__SetReposition_Request * data = NULL;

  if (size) {
    data = (autopilot_interface_msgs__srv__SetReposition_Request *)allocator.zero_allocate(size, sizeof(autopilot_interface_msgs__srv__SetReposition_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = autopilot_interface_msgs__srv__SetReposition_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        autopilot_interface_msgs__srv__SetReposition_Request__fini(&data[i - 1]);
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
autopilot_interface_msgs__srv__SetReposition_Request__Sequence__fini(autopilot_interface_msgs__srv__SetReposition_Request__Sequence * array)
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
      autopilot_interface_msgs__srv__SetReposition_Request__fini(&array->data[i]);
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

autopilot_interface_msgs__srv__SetReposition_Request__Sequence *
autopilot_interface_msgs__srv__SetReposition_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__srv__SetReposition_Request__Sequence * array = (autopilot_interface_msgs__srv__SetReposition_Request__Sequence *)allocator.allocate(sizeof(autopilot_interface_msgs__srv__SetReposition_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = autopilot_interface_msgs__srv__SetReposition_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
autopilot_interface_msgs__srv__SetReposition_Request__Sequence__destroy(autopilot_interface_msgs__srv__SetReposition_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    autopilot_interface_msgs__srv__SetReposition_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
autopilot_interface_msgs__srv__SetReposition_Request__Sequence__are_equal(const autopilot_interface_msgs__srv__SetReposition_Request__Sequence * lhs, const autopilot_interface_msgs__srv__SetReposition_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!autopilot_interface_msgs__srv__SetReposition_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
autopilot_interface_msgs__srv__SetReposition_Request__Sequence__copy(
  const autopilot_interface_msgs__srv__SetReposition_Request__Sequence * input,
  autopilot_interface_msgs__srv__SetReposition_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(autopilot_interface_msgs__srv__SetReposition_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    autopilot_interface_msgs__srv__SetReposition_Request * data =
      (autopilot_interface_msgs__srv__SetReposition_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!autopilot_interface_msgs__srv__SetReposition_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          autopilot_interface_msgs__srv__SetReposition_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!autopilot_interface_msgs__srv__SetReposition_Request__copy(
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
autopilot_interface_msgs__srv__SetReposition_Response__init(autopilot_interface_msgs__srv__SetReposition_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    autopilot_interface_msgs__srv__SetReposition_Response__fini(msg);
    return false;
  }
  return true;
}

void
autopilot_interface_msgs__srv__SetReposition_Response__fini(autopilot_interface_msgs__srv__SetReposition_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
autopilot_interface_msgs__srv__SetReposition_Response__are_equal(const autopilot_interface_msgs__srv__SetReposition_Response * lhs, const autopilot_interface_msgs__srv__SetReposition_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
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
autopilot_interface_msgs__srv__SetReposition_Response__copy(
  const autopilot_interface_msgs__srv__SetReposition_Response * input,
  autopilot_interface_msgs__srv__SetReposition_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

autopilot_interface_msgs__srv__SetReposition_Response *
autopilot_interface_msgs__srv__SetReposition_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__srv__SetReposition_Response * msg = (autopilot_interface_msgs__srv__SetReposition_Response *)allocator.allocate(sizeof(autopilot_interface_msgs__srv__SetReposition_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(autopilot_interface_msgs__srv__SetReposition_Response));
  bool success = autopilot_interface_msgs__srv__SetReposition_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
autopilot_interface_msgs__srv__SetReposition_Response__destroy(autopilot_interface_msgs__srv__SetReposition_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    autopilot_interface_msgs__srv__SetReposition_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
autopilot_interface_msgs__srv__SetReposition_Response__Sequence__init(autopilot_interface_msgs__srv__SetReposition_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__srv__SetReposition_Response * data = NULL;

  if (size) {
    data = (autopilot_interface_msgs__srv__SetReposition_Response *)allocator.zero_allocate(size, sizeof(autopilot_interface_msgs__srv__SetReposition_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = autopilot_interface_msgs__srv__SetReposition_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        autopilot_interface_msgs__srv__SetReposition_Response__fini(&data[i - 1]);
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
autopilot_interface_msgs__srv__SetReposition_Response__Sequence__fini(autopilot_interface_msgs__srv__SetReposition_Response__Sequence * array)
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
      autopilot_interface_msgs__srv__SetReposition_Response__fini(&array->data[i]);
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

autopilot_interface_msgs__srv__SetReposition_Response__Sequence *
autopilot_interface_msgs__srv__SetReposition_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__srv__SetReposition_Response__Sequence * array = (autopilot_interface_msgs__srv__SetReposition_Response__Sequence *)allocator.allocate(sizeof(autopilot_interface_msgs__srv__SetReposition_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = autopilot_interface_msgs__srv__SetReposition_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
autopilot_interface_msgs__srv__SetReposition_Response__Sequence__destroy(autopilot_interface_msgs__srv__SetReposition_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    autopilot_interface_msgs__srv__SetReposition_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
autopilot_interface_msgs__srv__SetReposition_Response__Sequence__are_equal(const autopilot_interface_msgs__srv__SetReposition_Response__Sequence * lhs, const autopilot_interface_msgs__srv__SetReposition_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!autopilot_interface_msgs__srv__SetReposition_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
autopilot_interface_msgs__srv__SetReposition_Response__Sequence__copy(
  const autopilot_interface_msgs__srv__SetReposition_Response__Sequence * input,
  autopilot_interface_msgs__srv__SetReposition_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(autopilot_interface_msgs__srv__SetReposition_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    autopilot_interface_msgs__srv__SetReposition_Response * data =
      (autopilot_interface_msgs__srv__SetReposition_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!autopilot_interface_msgs__srv__SetReposition_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          autopilot_interface_msgs__srv__SetReposition_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!autopilot_interface_msgs__srv__SetReposition_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
