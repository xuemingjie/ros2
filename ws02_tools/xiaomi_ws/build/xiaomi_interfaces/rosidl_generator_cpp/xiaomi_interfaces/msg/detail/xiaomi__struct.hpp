// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xiaomi_interfaces:msg/Xiaomi.idl
// generated code does not contain a copyright notice

#ifndef XIAOMI_INTERFACES__MSG__DETAIL__XIAOMI__STRUCT_HPP_
#define XIAOMI_INTERFACES__MSG__DETAIL__XIAOMI__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__xiaomi_interfaces__msg__Xiaomi __attribute__((deprecated))
#else
# define DEPRECATED__xiaomi_interfaces__msg__Xiaomi __declspec(deprecated)
#endif

namespace xiaomi_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Xiaomi_
{
  using Type = Xiaomi_<ContainerAllocator>;

  explicit Xiaomi_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->w_speed = 0.0f;
      this->angle = 0.0f;
      this->torque = 0.0f;
      this->temperaturecode = 0.0f;
    }
  }

  explicit Xiaomi_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->w_speed = 0.0f;
      this->angle = 0.0f;
      this->torque = 0.0f;
      this->temperaturecode = 0.0f;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _w_speed_type =
    float;
  _w_speed_type w_speed;
  using _angle_type =
    float;
  _angle_type angle;
  using _torque_type =
    float;
  _torque_type torque;
  using _temperaturecode_type =
    float;
  _temperaturecode_type temperaturecode;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__w_speed(
    const float & _arg)
  {
    this->w_speed = _arg;
    return *this;
  }
  Type & set__angle(
    const float & _arg)
  {
    this->angle = _arg;
    return *this;
  }
  Type & set__torque(
    const float & _arg)
  {
    this->torque = _arg;
    return *this;
  }
  Type & set__temperaturecode(
    const float & _arg)
  {
    this->temperaturecode = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xiaomi_interfaces::msg::Xiaomi_<ContainerAllocator> *;
  using ConstRawPtr =
    const xiaomi_interfaces::msg::Xiaomi_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xiaomi_interfaces::msg::Xiaomi_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xiaomi_interfaces::msg::Xiaomi_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xiaomi_interfaces::msg::Xiaomi_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xiaomi_interfaces::msg::Xiaomi_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xiaomi_interfaces::msg::Xiaomi_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xiaomi_interfaces::msg::Xiaomi_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xiaomi_interfaces::msg::Xiaomi_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xiaomi_interfaces::msg::Xiaomi_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xiaomi_interfaces__msg__Xiaomi
    std::shared_ptr<xiaomi_interfaces::msg::Xiaomi_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xiaomi_interfaces__msg__Xiaomi
    std::shared_ptr<xiaomi_interfaces::msg::Xiaomi_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Xiaomi_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->w_speed != other.w_speed) {
      return false;
    }
    if (this->angle != other.angle) {
      return false;
    }
    if (this->torque != other.torque) {
      return false;
    }
    if (this->temperaturecode != other.temperaturecode) {
      return false;
    }
    return true;
  }
  bool operator!=(const Xiaomi_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Xiaomi_

// alias to use template instance with default allocator
using Xiaomi =
  xiaomi_interfaces::msg::Xiaomi_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xiaomi_interfaces

#endif  // XIAOMI_INTERFACES__MSG__DETAIL__XIAOMI__STRUCT_HPP_
