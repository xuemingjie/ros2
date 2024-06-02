// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xiaomi_interfaces:msg/Xiaomi.idl
// generated code does not contain a copyright notice

#ifndef XIAOMI_INTERFACES__MSG__DETAIL__XIAOMI__STRUCT_H_
#define XIAOMI_INTERFACES__MSG__DETAIL__XIAOMI__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Xiaomi in the package xiaomi_interfaces.
typedef struct xiaomi_interfaces__msg__Xiaomi
{
  int32_t id;
  float w_speed;
  float angle;
  float torque;
  float temperaturecode;
} xiaomi_interfaces__msg__Xiaomi;

// Struct for a sequence of xiaomi_interfaces__msg__Xiaomi.
typedef struct xiaomi_interfaces__msg__Xiaomi__Sequence
{
  xiaomi_interfaces__msg__Xiaomi * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xiaomi_interfaces__msg__Xiaomi__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XIAOMI_INTERFACES__MSG__DETAIL__XIAOMI__STRUCT_H_
