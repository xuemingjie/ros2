# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xmj/xiaomi_ws/src/xiaomi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xmj/xiaomi_ws/build/xiaomi

# Include any dependencies generated for this target.
include CMakeFiles/xiaomi_use.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/xiaomi_use.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/xiaomi_use.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/xiaomi_use.dir/flags.make

CMakeFiles/xiaomi_use.dir/src/xiaomi_initial_set.cpp.o: CMakeFiles/xiaomi_use.dir/flags.make
CMakeFiles/xiaomi_use.dir/src/xiaomi_initial_set.cpp.o: /home/xmj/xiaomi_ws/src/xiaomi/src/xiaomi_initial_set.cpp
CMakeFiles/xiaomi_use.dir/src/xiaomi_initial_set.cpp.o: CMakeFiles/xiaomi_use.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xmj/xiaomi_ws/build/xiaomi/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/xiaomi_use.dir/src/xiaomi_initial_set.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/xiaomi_use.dir/src/xiaomi_initial_set.cpp.o -MF CMakeFiles/xiaomi_use.dir/src/xiaomi_initial_set.cpp.o.d -o CMakeFiles/xiaomi_use.dir/src/xiaomi_initial_set.cpp.o -c /home/xmj/xiaomi_ws/src/xiaomi/src/xiaomi_initial_set.cpp

CMakeFiles/xiaomi_use.dir/src/xiaomi_initial_set.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xiaomi_use.dir/src/xiaomi_initial_set.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xmj/xiaomi_ws/src/xiaomi/src/xiaomi_initial_set.cpp > CMakeFiles/xiaomi_use.dir/src/xiaomi_initial_set.cpp.i

CMakeFiles/xiaomi_use.dir/src/xiaomi_initial_set.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xiaomi_use.dir/src/xiaomi_initial_set.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xmj/xiaomi_ws/src/xiaomi/src/xiaomi_initial_set.cpp -o CMakeFiles/xiaomi_use.dir/src/xiaomi_initial_set.cpp.s

CMakeFiles/xiaomi_use.dir/src/xiaomi_use.cpp.o: CMakeFiles/xiaomi_use.dir/flags.make
CMakeFiles/xiaomi_use.dir/src/xiaomi_use.cpp.o: /home/xmj/xiaomi_ws/src/xiaomi/src/xiaomi_use.cpp
CMakeFiles/xiaomi_use.dir/src/xiaomi_use.cpp.o: CMakeFiles/xiaomi_use.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xmj/xiaomi_ws/build/xiaomi/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/xiaomi_use.dir/src/xiaomi_use.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/xiaomi_use.dir/src/xiaomi_use.cpp.o -MF CMakeFiles/xiaomi_use.dir/src/xiaomi_use.cpp.o.d -o CMakeFiles/xiaomi_use.dir/src/xiaomi_use.cpp.o -c /home/xmj/xiaomi_ws/src/xiaomi/src/xiaomi_use.cpp

CMakeFiles/xiaomi_use.dir/src/xiaomi_use.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xiaomi_use.dir/src/xiaomi_use.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xmj/xiaomi_ws/src/xiaomi/src/xiaomi_use.cpp > CMakeFiles/xiaomi_use.dir/src/xiaomi_use.cpp.i

CMakeFiles/xiaomi_use.dir/src/xiaomi_use.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xiaomi_use.dir/src/xiaomi_use.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xmj/xiaomi_ws/src/xiaomi/src/xiaomi_use.cpp -o CMakeFiles/xiaomi_use.dir/src/xiaomi_use.cpp.s

# Object files for target xiaomi_use
xiaomi_use_OBJECTS = \
"CMakeFiles/xiaomi_use.dir/src/xiaomi_initial_set.cpp.o" \
"CMakeFiles/xiaomi_use.dir/src/xiaomi_use.cpp.o"

# External object files for target xiaomi_use
xiaomi_use_EXTERNAL_OBJECTS =

xiaomi_use: CMakeFiles/xiaomi_use.dir/src/xiaomi_initial_set.cpp.o
xiaomi_use: CMakeFiles/xiaomi_use.dir/src/xiaomi_use.cpp.o
xiaomi_use: CMakeFiles/xiaomi_use.dir/build.make
xiaomi_use: /opt/ros/humble/lib/librclcpp.so
xiaomi_use: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_fastrtps_c.so
xiaomi_use: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_fastrtps_cpp.so
xiaomi_use: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_introspection_c.so
xiaomi_use: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_introspection_cpp.so
xiaomi_use: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_cpp.so
xiaomi_use: /opt/ros/humble/lib/libstd_msgs__rosidl_generator_py.so
xiaomi_use: /usr/local/lib/libserial.so
xiaomi_use: /opt/ros/humble/lib/liblibstatistics_collector.so
xiaomi_use: /opt/ros/humble/lib/librcl.so
xiaomi_use: /opt/ros/humble/lib/librmw_implementation.so
xiaomi_use: /opt/ros/humble/lib/libament_index_cpp.so
xiaomi_use: /opt/ros/humble/lib/librcl_logging_spdlog.so
xiaomi_use: /opt/ros/humble/lib/librcl_logging_interface.so
xiaomi_use: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_fastrtps_c.so
xiaomi_use: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_introspection_c.so
xiaomi_use: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_fastrtps_cpp.so
xiaomi_use: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_introspection_cpp.so
xiaomi_use: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_cpp.so
xiaomi_use: /opt/ros/humble/lib/librcl_interfaces__rosidl_generator_py.so
xiaomi_use: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_c.so
xiaomi_use: /opt/ros/humble/lib/librcl_interfaces__rosidl_generator_c.so
xiaomi_use: /opt/ros/humble/lib/librcl_yaml_param_parser.so
xiaomi_use: /opt/ros/humble/lib/libyaml.so
xiaomi_use: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_fastrtps_c.so
xiaomi_use: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_fastrtps_cpp.so
xiaomi_use: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_introspection_c.so
xiaomi_use: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_introspection_cpp.so
xiaomi_use: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_cpp.so
xiaomi_use: /opt/ros/humble/lib/librosgraph_msgs__rosidl_generator_py.so
xiaomi_use: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_c.so
xiaomi_use: /opt/ros/humble/lib/librosgraph_msgs__rosidl_generator_c.so
xiaomi_use: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_fastrtps_c.so
xiaomi_use: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_fastrtps_cpp.so
xiaomi_use: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_introspection_c.so
xiaomi_use: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_introspection_cpp.so
xiaomi_use: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_cpp.so
xiaomi_use: /opt/ros/humble/lib/libstatistics_msgs__rosidl_generator_py.so
xiaomi_use: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_c.so
xiaomi_use: /opt/ros/humble/lib/libstatistics_msgs__rosidl_generator_c.so
xiaomi_use: /opt/ros/humble/lib/libtracetools.so
xiaomi_use: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_fastrtps_c.so
xiaomi_use: /opt/ros/humble/lib/librosidl_typesupport_fastrtps_c.so
xiaomi_use: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_fastrtps_cpp.so
xiaomi_use: /opt/ros/humble/lib/librosidl_typesupport_fastrtps_cpp.so
xiaomi_use: /opt/ros/humble/lib/libfastcdr.so.1.0.24
xiaomi_use: /opt/ros/humble/lib/librmw.so
xiaomi_use: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_c.so
xiaomi_use: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_cpp.so
xiaomi_use: /opt/ros/humble/lib/librosidl_typesupport_introspection_cpp.so
xiaomi_use: /opt/ros/humble/lib/librosidl_typesupport_introspection_c.so
xiaomi_use: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_cpp.so
xiaomi_use: /opt/ros/humble/lib/librosidl_typesupport_cpp.so
xiaomi_use: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_c.so
xiaomi_use: /opt/ros/humble/lib/libstd_msgs__rosidl_generator_c.so
xiaomi_use: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_generator_py.so
xiaomi_use: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_c.so
xiaomi_use: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_generator_c.so
xiaomi_use: /opt/ros/humble/lib/librosidl_typesupport_c.so
xiaomi_use: /opt/ros/humble/lib/librcpputils.so
xiaomi_use: /opt/ros/humble/lib/librosidl_runtime_c.so
xiaomi_use: /opt/ros/humble/lib/librcutils.so
xiaomi_use: /usr/lib/x86_64-linux-gnu/libpython3.10.so
xiaomi_use: CMakeFiles/xiaomi_use.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xmj/xiaomi_ws/build/xiaomi/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable xiaomi_use"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xiaomi_use.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/xiaomi_use.dir/build: xiaomi_use
.PHONY : CMakeFiles/xiaomi_use.dir/build

CMakeFiles/xiaomi_use.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/xiaomi_use.dir/cmake_clean.cmake
.PHONY : CMakeFiles/xiaomi_use.dir/clean

CMakeFiles/xiaomi_use.dir/depend:
	cd /home/xmj/xiaomi_ws/build/xiaomi && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xmj/xiaomi_ws/src/xiaomi /home/xmj/xiaomi_ws/src/xiaomi /home/xmj/xiaomi_ws/build/xiaomi /home/xmj/xiaomi_ws/build/xiaomi /home/xmj/xiaomi_ws/build/xiaomi/CMakeFiles/xiaomi_use.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xiaomi_use.dir/depend

