// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from xiaomi_interfaces:msg/Xiaomi.idl
// generated code does not contain a copyright notice

#ifndef XIAOMI_INTERFACES__MSG__DETAIL__XIAOMI__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define XIAOMI_INTERFACES__MSG__DETAIL__XIAOMI__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "xiaomi_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "xiaomi_interfaces/msg/detail/xiaomi__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace xiaomi_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xiaomi_interfaces
cdr_serialize(
  const xiaomi_interfaces::msg::Xiaomi & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xiaomi_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xiaomi_interfaces::msg::Xiaomi & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xiaomi_interfaces
get_serialized_size(
  const xiaomi_interfaces::msg::Xiaomi & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xiaomi_interfaces
max_serialized_size_Xiaomi(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace xiaomi_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xiaomi_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xiaomi_interfaces, msg, Xiaomi)();

#ifdef __cplusplus
}
#endif

#endif  // XIAOMI_INTERFACES__MSG__DETAIL__XIAOMI__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
