// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from xiaomi_interfaces:msg/Xiaomi.idl
// generated code does not contain a copyright notice
#include "xiaomi_interfaces/msg/detail/xiaomi__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
xiaomi_interfaces__msg__Xiaomi__init(xiaomi_interfaces__msg__Xiaomi * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // w_speed
  // angle
  // torque
  // temperaturecode
  return true;
}

void
xiaomi_interfaces__msg__Xiaomi__fini(xiaomi_interfaces__msg__Xiaomi * msg)
{
  if (!msg) {
    return;
  }
  // id
  // w_speed
  // angle
  // torque
  // temperaturecode
}

bool
xiaomi_interfaces__msg__Xiaomi__are_equal(const xiaomi_interfaces__msg__Xiaomi * lhs, const xiaomi_interfaces__msg__Xiaomi * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // w_speed
  if (lhs->w_speed != rhs->w_speed) {
    return false;
  }
  // angle
  if (lhs->angle != rhs->angle) {
    return false;
  }
  // torque
  if (lhs->torque != rhs->torque) {
    return false;
  }
  // temperaturecode
  if (lhs->temperaturecode != rhs->temperaturecode) {
    return false;
  }
  return true;
}

bool
xiaomi_interfaces__msg__Xiaomi__copy(
  const xiaomi_interfaces__msg__Xiaomi * input,
  xiaomi_interfaces__msg__Xiaomi * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // w_speed
  output->w_speed = input->w_speed;
  // angle
  output->angle = input->angle;
  // torque
  output->torque = input->torque;
  // temperaturecode
  output->temperaturecode = input->temperaturecode;
  return true;
}

xiaomi_interfaces__msg__Xiaomi *
xiaomi_interfaces__msg__Xiaomi__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xiaomi_interfaces__msg__Xiaomi * msg = (xiaomi_interfaces__msg__Xiaomi *)allocator.allocate(sizeof(xiaomi_interfaces__msg__Xiaomi), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xiaomi_interfaces__msg__Xiaomi));
  bool success = xiaomi_interfaces__msg__Xiaomi__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
xiaomi_interfaces__msg__Xiaomi__destroy(xiaomi_interfaces__msg__Xiaomi * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    xiaomi_interfaces__msg__Xiaomi__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
xiaomi_interfaces__msg__Xiaomi__Sequence__init(xiaomi_interfaces__msg__Xiaomi__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xiaomi_interfaces__msg__Xiaomi * data = NULL;

  if (size) {
    data = (xiaomi_interfaces__msg__Xiaomi *)allocator.zero_allocate(size, sizeof(xiaomi_interfaces__msg__Xiaomi), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xiaomi_interfaces__msg__Xiaomi__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xiaomi_interfaces__msg__Xiaomi__fini(&data[i - 1]);
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
xiaomi_interfaces__msg__Xiaomi__Sequence__fini(xiaomi_interfaces__msg__Xiaomi__Sequence * array)
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
      xiaomi_interfaces__msg__Xiaomi__fini(&array->data[i]);
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

xiaomi_interfaces__msg__Xiaomi__Sequence *
xiaomi_interfaces__msg__Xiaomi__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xiaomi_interfaces__msg__Xiaomi__Sequence * array = (xiaomi_interfaces__msg__Xiaomi__Sequence *)allocator.allocate(sizeof(xiaomi_interfaces__msg__Xiaomi__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = xiaomi_interfaces__msg__Xiaomi__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
xiaomi_interfaces__msg__Xiaomi__Sequence__destroy(xiaomi_interfaces__msg__Xiaomi__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    xiaomi_interfaces__msg__Xiaomi__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
xiaomi_interfaces__msg__Xiaomi__Sequence__are_equal(const xiaomi_interfaces__msg__Xiaomi__Sequence * lhs, const xiaomi_interfaces__msg__Xiaomi__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xiaomi_interfaces__msg__Xiaomi__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xiaomi_interfaces__msg__Xiaomi__Sequence__copy(
  const xiaomi_interfaces__msg__Xiaomi__Sequence * input,
  xiaomi_interfaces__msg__Xiaomi__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xiaomi_interfaces__msg__Xiaomi);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    xiaomi_interfaces__msg__Xiaomi * data =
      (xiaomi_interfaces__msg__Xiaomi *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xiaomi_interfaces__msg__Xiaomi__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          xiaomi_interfaces__msg__Xiaomi__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xiaomi_interfaces__msg__Xiaomi__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
