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

# Utility rule file for xiaomi_interfaces.

# Include any custom commands dependencies for this target.
include CMakeFiles/xiaomi_interfaces.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/xiaomi_interfaces.dir/progress.make

CMakeFiles/xiaomi_interfaces: /home/xmj/xiaomi_ws/src/xiaomi_interfaces/msg/Xiaomi.msg

xiaomi_interfaces: CMakeFiles/xiaomi_interfaces
xiaomi_interfaces: CMakeFiles/xiaomi_interfaces.dir/build.make
.PHONY : xiaomi_interfaces

# Rule to build all files generated by this target.
CMakeFiles/xiaomi_interfaces.dir/build: xiaomi_interfaces
.PHONY : CMakeFiles/xiaomi_interfaces.dir/build

CMakeFiles/xiaomi_interfaces.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/xiaomi_interfaces.dir/cmake_clean.cmake
.PHONY : CMakeFiles/xiaomi_interfaces.dir/clean

CMakeFiles/xiaomi_interfaces.dir/depend:
	cd /home/xmj/xiaomi_ws/build/xiaomi_interfaces && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xmj/xiaomi_ws/src/xiaomi_interfaces /home/xmj/xiaomi_ws/src/xiaomi_interfaces /home/xmj/xiaomi_ws/build/xiaomi_interfaces /home/xmj/xiaomi_ws/build/xiaomi_interfaces /home/xmj/xiaomi_ws/build/xiaomi_interfaces/CMakeFiles/xiaomi_interfaces.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xiaomi_interfaces.dir/depend
