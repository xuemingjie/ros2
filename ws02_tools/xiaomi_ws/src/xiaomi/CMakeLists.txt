cmake_minimum_required(VERSION 3.8)
project(xiaomi)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(serial REQUIRED)
find_package(xiaomi_interfaces REQUIRED)

add_executable(xiaomi_able
    src/xiaomi_initial_set.cpp
    src/xiaomi_able.cpp
    )
target_include_directories(xiaomi_able PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(xiaomi_able PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  xiaomi_able
  "rclcpp"
  "std_msgs"
  "serial"
)

install(TARGETS xiaomi_able
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()


install(DIRECTORY launch
        DESTINATION share/${PROJECT_NAME})


set_target_properties(xiaomi_able PROPERTIES
    INSTALL_RPATH "/usr/local/lib"  # 设置安装后的共享库路径
    INSTALL_RPATH_USE_LINK_PATH TRUE  # 使用链接路径
)
add_executable(xiaomi_use
    src/xiaomi_initial_set.cpp
    src/xiaomi_use.cpp
    )
ament_target_dependencies(
  xiaomi_use
  "rclcpp"
  "std_msgs"
  "serial"
)
target_include_directories(xiaomi_use PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

install(TARGETS xiaomi_use
  DESTINATION lib/${PROJECT_NAME})

add_executable(xiaomi_sub
    src/xiaomi_initial_set.cpp
    src/xiaomi_sub.cpp
    )
ament_target_dependencies(
  xiaomi_sub
  "rclcpp"
  "std_msgs"
  "serial"
)
target_include_directories(xiaomi_sub PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

install(TARGETS xiaomi_sub
  DESTINATION lib/${PROJECT_NAME})


add_executable(xiaomi_msg_pub
  src/xiaomi_initial_set.cpp
  src/xiaomi_msg_pub.cpp
  )
ament_target_dependencies(
xiaomi_msg_pub
"rclcpp"
"std_msgs"
"serial"
"xiaomi_interfaces"
)
target_include_directories(xiaomi_msg_pub PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
$<INSTALL_INTERFACE:include>)

install(TARGETS xiaomi_msg_pub
DESTINATION lib/${PROJECT_NAME})



add_executable(xiaomi_msg_sub
  src/xiaomi_initial_set.cpp
  src/xiaomi_msg_sub.cpp
  )
ament_target_dependencies(
xiaomi_msg_sub
"rclcpp"
"std_msgs"
"serial"
"xiaomi_interfaces"
)
target_include_directories(xiaomi_msg_sub PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
$<INSTALL_INTERFACE:include>)

install(TARGETS xiaomi_msg_sub
DESTINATION lib/${PROJECT_NAME})