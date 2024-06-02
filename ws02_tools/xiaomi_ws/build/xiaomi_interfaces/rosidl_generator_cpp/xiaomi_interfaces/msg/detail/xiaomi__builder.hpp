// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xiaomi_interfaces:msg/Xiaomi.idl
// generated code does not contain a copyright notice

#ifndef XIAOMI_INTERFACES__MSG__DETAIL__XIAOMI__BUILDER_HPP_
#define XIAOMI_INTERFACES__MSG__DETAIL__XIAOMI__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "xiaomi_interfaces/msg/detail/xiaomi__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace xiaomi_interfaces
{

namespace msg
{

namespace builder
{

class Init_Xiaomi_temperaturecode
{
public:
  explicit Init_Xiaomi_temperaturecode(::xiaomi_interfaces::msg::Xiaomi & msg)
  : msg_(msg)
  {}
  ::xiaomi_interfaces::msg::Xiaomi temperaturecode(::xiaomi_interfaces::msg::Xiaomi::_temperaturecode_type arg)
  {
    msg_.temperaturecode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xiaomi_interfaces::msg::Xiaomi msg_;
};

class Init_Xiaomi_torque
{
public:
  explicit Init_Xiaomi_torque(::xiaomi_interfaces::msg::Xiaomi & msg)
  : msg_(msg)
  {}
  Init_Xiaomi_temperaturecode torque(::xiaomi_interfaces::msg::Xiaomi::_torque_type arg)
  {
    msg_.torque = std::move(arg);
    return Init_Xiaomi_temperaturecode(msg_);
  }

private:
  ::xiaomi_interfaces::msg::Xiaomi msg_;
};

class Init_Xiaomi_angle
{
public:
  explicit Init_Xiaomi_angle(::xiaomi_interfaces::msg::Xiaomi & msg)
  : msg_(msg)
  {}
  Init_Xiaomi_torque angle(::xiaomi_interfaces::msg::Xiaomi::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return Init_Xiaomi_torque(msg_);
  }

private:
  ::xiaomi_interfaces::msg::Xiaomi msg_;
};

class Init_Xiaomi_w_speed
{
public:
  explicit Init_Xiaomi_w_speed(::xiaomi_interfaces::msg::Xiaomi & msg)
  : msg_(msg)
  {}
  Init_Xiaomi_angle w_speed(::xiaomi_interfaces::msg::Xiaomi::_w_speed_type arg)
  {
    msg_.w_speed = std::move(arg);
    return Init_Xiaomi_angle(msg_);
  }

private:
  ::xiaomi_interfaces::msg::Xiaomi msg_;
};

class Init_Xiaomi_id
{
public:
  Init_Xiaomi_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Xiaomi_w_speed id(::xiaomi_interfaces::msg::Xiaomi::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Xiaomi_w_speed(msg_);
  }

private:
  ::xiaomi_interfaces::msg::Xiaomi msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xiaomi_interfaces::msg::Xiaomi>()
{
  return xiaomi_interfaces::msg::builder::Init_Xiaomi_id();
}

}  // namespace xiaomi_interfaces

#endif  // XIAOMI_INTERFACES__MSG__DETAIL__XIAOMI__BUILDER_HPP_
