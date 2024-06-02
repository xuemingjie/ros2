// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from xiaomi_interfaces:msg/Xiaomi.idl
// generated code does not contain a copyright notice
#include "xiaomi_interfaces/msg/detail/xiaomi__rosidl_typesupport_fastrtps_cpp.hpp"
#include "xiaomi_interfaces/msg/detail/xiaomi__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: id
  cdr << ros_message.id;
  // Member: w_speed
  cdr << ros_message.w_speed;
  // Member: angle
  cdr << ros_message.angle;
  // Member: torque
  cdr << ros_message.torque;
  // Member: temperaturecode
  cdr << ros_message.temperaturecode;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xiaomi_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xiaomi_interfaces::msg::Xiaomi & ros_message)
{
  // Member: id
  cdr >> ros_message.id;

  // Member: w_speed
  cdr >> ros_message.w_speed;

  // Member: angle
  cdr >> ros_message.angle;

  // Member: torque
  cdr >> ros_message.torque;

  // Member: temperaturecode
  cdr >> ros_message.temperaturecode;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xiaomi_interfaces
get_serialized_size(
  const xiaomi_interfaces::msg::Xiaomi & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: id
  {
    size_t item_size = sizeof(ros_message.id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: w_speed
  {
    size_t item_size = sizeof(ros_message.w_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: angle
  {
    size_t item_size = sizeof(ros_message.angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: torque
  {
    size_t item_size = sizeof(ros_message.torque);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: temperaturecode
  {
    size_t item_size = sizeof(ros_message.temperaturecode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xiaomi_interfaces
max_serialized_size_Xiaomi(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: w_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: angle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: torque
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: temperaturecode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = xiaomi_interfaces::msg::Xiaomi;
    is_plain =
      (
      offsetof(DataType, temperaturecode) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Xiaomi__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const xiaomi_interfaces::msg::Xiaomi *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Xiaomi__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<xiaomi_interfaces::msg::Xiaomi *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Xiaomi__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const xiaomi_interfaces::msg::Xiaomi *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Xiaomi__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Xiaomi(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Xiaomi__callbacks = {
  "xiaomi_interfaces::msg",
  "Xiaomi",
  _Xiaomi__cdr_serialize,
  _Xiaomi__cdr_deserialize,
  _Xiaomi__get_serialized_size,
  _Xiaomi__max_serialized_size
};

static rosidl_message_type_support_t _Xiaomi__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Xiaomi__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace xiaomi_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_xiaomi_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<xiaomi_interfaces::msg::Xiaomi>()
{
  return &xiaomi_interfaces::msg::typesupport_fastrtps_cpp::_Xiaomi__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xiaomi_interfaces, msg, Xiaomi)() {
  return &xiaomi_interfaces::msg::typesupport_fastrtps_cpp::_Xiaomi__handle;
}

#ifdef __cplusplus
}
#endif
