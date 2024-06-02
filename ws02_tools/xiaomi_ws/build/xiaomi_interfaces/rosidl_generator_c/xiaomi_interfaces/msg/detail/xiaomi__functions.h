// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from xiaomi_interfaces:msg/Xiaomi.idl
// generated code does not contain a copyright notice

#ifndef XIAOMI_INTERFACES__MSG__DETAIL__XIAOMI__FUNCTIONS_H_
#define XIAOMI_INTERFACES__MSG__DETAIL__XIAOMI__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "xiaomi_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "xiaomi_interfaces/msg/detail/xiaomi__struct.h"

/// Initialize msg/Xiaomi message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * xiaomi_interfaces__msg__Xiaomi
 * )) before or use
 * xiaomi_interfaces__msg__Xiaomi__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_xiaomi_interfaces
bool
xiaomi_interfaces__msg__Xiaomi__init(xiaomi_interfaces__msg__Xiaomi * msg);

/// Finalize msg/Xiaomi message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xiaomi_interfaces
void
xiaomi_interfaces__msg__Xiaomi__fini(xiaomi_interfaces__msg__Xiaomi * msg);

/// Create msg/Xiaomi message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * xiaomi_interfaces__msg__Xiaomi__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xiaomi_interfaces
xiaomi_interfaces__msg__Xiaomi *
xiaomi_interfaces__msg__Xiaomi__create();

/// Destroy msg/Xiaomi message.
/**
 * It calls
 * xiaomi_interfaces__msg__Xiaomi__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xiaomi_interfaces
void
xiaomi_interfaces__msg__Xiaomi__destroy(xiaomi_interfaces__msg__Xiaomi * msg);

/// Check for msg/Xiaomi message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_xiaomi_interfaces
bool
xiaomi_interfaces__msg__Xiaomi__are_equal(const xiaomi_interfaces__msg__Xiaomi * lhs, const xiaomi_interfaces__msg__Xiaomi * rhs);

/// Copy a msg/Xiaomi message.
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
ROSIDL_GENERATOR_C_PUBLIC_xiaomi_interfaces
bool
xiaomi_interfaces__msg__Xiaomi__copy(
  const xiaomi_interfaces__msg__Xiaomi * input,
  xiaomi_interfaces__msg__Xiaomi * output);

/// Initialize array of msg/Xiaomi messages.
/**
 * It allocates the memory for the number of elements and calls
 * xiaomi_interfaces__msg__Xiaomi__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_xiaomi_interfaces
bool
xiaomi_interfaces__msg__Xiaomi__Sequence__init(xiaomi_interfaces__msg__Xiaomi__Sequence * array, size_t size);

/// Finalize array of msg/Xiaomi messages.
/**
 * It calls
 * xiaomi_interfaces__msg__Xiaomi__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xiaomi_interfaces
void
xiaomi_interfaces__msg__Xiaomi__Sequence__fini(xiaomi_interfaces__msg__Xiaomi__Sequence * array);

/// Create array of msg/Xiaomi messages.
/**
 * It allocates the memory for the array and calls
 * xiaomi_interfaces__msg__Xiaomi__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xiaomi_interfaces
xiaomi_interfaces__msg__Xiaomi__Sequence *
xiaomi_interfaces__msg__Xiaomi__Sequence__create(size_t size);

/// Destroy array of msg/Xiaomi messages.
/**
 * It calls
 * xiaomi_interfaces__msg__Xiaomi__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xiaomi_interfaces
void
xiaomi_interfaces__msg__Xiaomi__Sequence__destroy(xiaomi_interfaces__msg__Xiaomi__Sequence * array);

/// Check for msg/Xiaomi message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_xiaomi_interfaces
bool
xiaomi_interfaces__msg__Xiaomi__Sequence__are_equal(const xiaomi_interfaces__msg__Xiaomi__Sequence * lhs, const xiaomi_interfaces__msg__Xiaomi__Sequence * rhs);

/// Copy an array of msg/Xiaomi messages.
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
ROSIDL_GENERATOR_C_PUBLIC_xiaomi_interfaces
bool
xiaomi_interfaces__msg__Xiaomi__Sequence__copy(
  const xiaomi_interfaces__msg__Xiaomi__Sequence * input,
  xiaomi_interfaces__msg__Xiaomi__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // XIAOMI_INTERFACES__MSG__DETAIL__XIAOMI__FUNCTIONS_H_
