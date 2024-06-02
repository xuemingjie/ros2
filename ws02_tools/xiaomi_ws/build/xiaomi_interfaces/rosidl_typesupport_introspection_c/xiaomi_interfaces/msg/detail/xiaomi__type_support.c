// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from xiaomi_interfaces:msg/Xiaomi.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "xiaomi_interfaces/msg/detail/xiaomi__rosidl_typesupport_introspection_c.h"
#include "xiaomi_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "xiaomi_interfaces/msg/detail/xiaomi__functions.h"
#include "xiaomi_interfaces/msg/detail/xiaomi__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void xiaomi_interfaces__msg__Xiaomi__rosidl_typesupport_introspection_c__Xiaomi_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  xiaomi_interfaces__msg__Xiaomi__init(message_memory);
}

void xiaomi_interfaces__msg__Xiaomi__rosidl_typesupport_introspection_c__Xiaomi_fini_function(void * message_memory)
{
  xiaomi_interfaces__msg__Xiaomi__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember xiaomi_interfaces__msg__Xiaomi__rosidl_typesupport_introspection_c__Xiaomi_message_member_array[5] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xiaomi_interfaces__msg__Xiaomi, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "w_speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xiaomi_interfaces__msg__Xiaomi, w_speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xiaomi_interfaces__msg__Xiaomi, angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "torque",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xiaomi_interfaces__msg__Xiaomi, torque),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "temperaturecode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xiaomi_interfaces__msg__Xiaomi, temperaturecode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers xiaomi_interfaces__msg__Xiaomi__rosidl_typesupport_introspection_c__Xiaomi_message_members = {
  "xiaomi_interfaces__msg",  // message namespace
  "Xiaomi",  // message name
  5,  // number of fields
  sizeof(xiaomi_interfaces__msg__Xiaomi),
  xiaomi_interfaces__msg__Xiaomi__rosidl_typesupport_introspection_c__Xiaomi_message_member_array,  // message members
  xiaomi_interfaces__msg__Xiaomi__rosidl_typesupport_introspection_c__Xiaomi_init_function,  // function to initialize message memory (memory has to be allocated)
  xiaomi_interfaces__msg__Xiaomi__rosidl_typesupport_introspection_c__Xiaomi_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t xiaomi_interfaces__msg__Xiaomi__rosidl_typesupport_introspection_c__Xiaomi_message_type_support_handle = {
  0,
  &xiaomi_interfaces__msg__Xiaomi__rosidl_typesupport_introspection_c__Xiaomi_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_xiaomi_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, xiaomi_interfaces, msg, Xiaomi)() {
  if (!xiaomi_interfaces__msg__Xiaomi__rosidl_typesupport_introspection_c__Xiaomi_message_type_support_handle.typesupport_identifier) {
    xiaomi_interfaces__msg__Xiaomi__rosidl_typesupport_introspection_c__Xiaomi_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &xiaomi_interfaces__msg__Xiaomi__rosidl_typesupport_introspection_c__Xiaomi_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
