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
CMAKE_SOURCE_DIR = /home/xmj/xiaomi_ws/src/xiaomi_interfaces

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xmj/xiaomi_ws/build/xiaomi_interfaces

# Include any dependencies generated for this target.
include CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/flags.make

CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c.o: CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/flags.make
CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c.o: rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c
CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c.o: CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xmj/xiaomi_ws/build/xiaomi_interfaces/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c.o -MF CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c.o.d -o CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c.o -c /home/xmj/xiaomi_ws/build/xiaomi_interfaces/rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c

CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/xmj/xiaomi_ws/build/xiaomi_interfaces/rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c > CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c.i

CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/xmj/xiaomi_ws/build/xiaomi_interfaces/rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c -o CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c.s

# Object files for target xiaomi_interfaces__rosidl_generator_py
xiaomi_interfaces__rosidl_generator_py_OBJECTS = \
"CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c.o"

# External object files for target xiaomi_interfaces__rosidl_generator_py
xiaomi_interfaces__rosidl_generator_py_EXTERNAL_OBJECTS =

rosidl_generator_py/xiaomi_interfaces/libxiaomi_interfaces__rosidl_generator_py.so: CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/rosidl_generator_py/xiaomi_interfaces/msg/_xiaomi_s.c.o
rosidl_generator_py/xiaomi_interfaces/libxiaomi_interfaces__rosidl_generator_py.so: CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/build.make
rosidl_generator_py/xiaomi_interfaces/libxiaomi_interfaces__rosidl_generator_py.so: /usr/lib/x86_64-linux-gnu/libpython3.10.so
rosidl_generator_py/xiaomi_interfaces/libxiaomi_interfaces__rosidl_generator_py.so: libxiaomi_interfaces__rosidl_typesupport_c.so
rosidl_generator_py/xiaomi_interfaces/libxiaomi_interfaces__rosidl_generator_py.so: libxiaomi_interfaces__rosidl_generator_c.so
rosidl_generator_py/xiaomi_interfaces/libxiaomi_interfaces__rosidl_generator_py.so: /opt/ros/humble/lib/librosidl_runtime_c.so
rosidl_generator_py/xiaomi_interfaces/libxiaomi_interfaces__rosidl_generator_py.so: /opt/ros/humble/lib/librcutils.so
rosidl_generator_py/xiaomi_interfaces/libxiaomi_interfaces__rosidl_generator_py.so: CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xmj/xiaomi_ws/build/xiaomi_interfaces/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library rosidl_generator_py/xiaomi_interfaces/libxiaomi_interfaces__rosidl_generator_py.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/build: rosidl_generator_py/xiaomi_interfaces/libxiaomi_interfaces__rosidl_generator_py.so
.PHONY : CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/build

CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/cmake_clean.cmake
.PHONY : CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/clean

CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/depend:
	cd /home/xmj/xiaomi_ws/build/xiaomi_interfaces && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xmj/xiaomi_ws/src/xiaomi_interfaces /home/xmj/xiaomi_ws/src/xiaomi_interfaces /home/xmj/xiaomi_ws/build/xiaomi_interfaces /home/xmj/xiaomi_ws/build/xiaomi_interfaces /home/xmj/xiaomi_ws/build/xiaomi_interfaces/CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xiaomi_interfaces__rosidl_generator_py.dir/depend

