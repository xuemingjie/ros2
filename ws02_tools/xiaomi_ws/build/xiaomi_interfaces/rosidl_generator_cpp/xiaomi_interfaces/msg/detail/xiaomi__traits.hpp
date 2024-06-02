// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from xiaomi_interfaces:msg/Xiaomi.idl
// generated code does not contain a copyright notice

#ifndef XIAOMI_INTERFACES__MSG__DETAIL__XIAOMI__TRAITS_HPP_
#define XIAOMI_INTERFACES__MSG__DETAIL__XIAOMI__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "xiaomi_interfaces/msg/detail/xiaomi__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace xiaomi_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Xiaomi & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: w_speed
  {
    out << "w_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.w_speed, out);
    out << ", ";
  }

  // member: angle
  {
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << ", ";
  }

  // member: torque
  {
    out << "torque: ";
    rosidl_generator_traits::value_to_yaml(msg.torque, out);
    out << ", ";
  }

  // member: temperaturecode
  {
    out << "temperaturecode: ";
    rosidl_generator_traits::value_to_yaml(msg.temperaturecode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Xiaomi & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: w_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "w_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.w_speed, out);
    out << "\n";
  }

  // member: angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << "\n";
  }

  // member: torque
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "torque: ";
    rosidl_generator_traits::value_to_yaml(msg.torque, out);
    out << "\n";
  }

  // member: temperaturecode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperaturecode: ";
    rosidl_generator_traits::value_to_yaml(msg.temperaturecode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Xiaomi & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace xiaomi_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use xiaomi_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const xiaomi_interfaces::msg::Xiaomi & msg,
  std::ostream & out, size_t indentation = 0)
{
  xiaomi_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use xiaomi_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const xiaomi_interfaces::msg::Xiaomi & msg)
{
  return xiaomi_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<xiaomi_interfaces::msg::Xiaomi>()
{
  return "xiaomi_interfaces::msg::Xiaomi";
}

template<>
inline const char * name<xiaomi_interfaces::msg::Xiaomi>()
{
  return "xiaomi_interfaces/msg/Xiaomi";
}

template<>
struct has_fixed_size<xiaomi_interfaces::msg::Xiaomi>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<xiaomi_interfaces::msg::Xiaomi>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<xiaomi_interfaces::msg::Xiaomi>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // XIAOMI_INTERFACES__MSG__DETAIL__XIAOMI__TRAITS_HPP_
