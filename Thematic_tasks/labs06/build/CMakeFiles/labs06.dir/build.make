# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/repos/a7a9acdb-gr22-repo/Thematic_tasks/labs06

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/repos/a7a9acdb-gr22-repo/Thematic_tasks/labs06/build

# Include any dependencies generated for this target.
include CMakeFiles/labs06.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/labs06.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/labs06.dir/flags.make

CMakeFiles/labs06.dir/src/main.cpp.o: CMakeFiles/labs06.dir/flags.make
CMakeFiles/labs06.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/repos/a7a9acdb-gr22-repo/Thematic_tasks/labs06/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/labs06.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/labs06.dir/src/main.cpp.o -c /home/ubuntu/repos/a7a9acdb-gr22-repo/Thematic_tasks/labs06/src/main.cpp

CMakeFiles/labs06.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/labs06.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/repos/a7a9acdb-gr22-repo/Thematic_tasks/labs06/src/main.cpp > CMakeFiles/labs06.dir/src/main.cpp.i

CMakeFiles/labs06.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/labs06.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/repos/a7a9acdb-gr22-repo/Thematic_tasks/labs06/src/main.cpp -o CMakeFiles/labs06.dir/src/main.cpp.s

CMakeFiles/labs06.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/labs06.dir/src/main.cpp.o.requires

CMakeFiles/labs06.dir/src/main.cpp.o.provides: CMakeFiles/labs06.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/labs06.dir/build.make CMakeFiles/labs06.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/labs06.dir/src/main.cpp.o.provides

CMakeFiles/labs06.dir/src/main.cpp.o.provides.build: CMakeFiles/labs06.dir/src/main.cpp.o


# Object files for target labs06
labs06_OBJECTS = \
"CMakeFiles/labs06.dir/src/main.cpp.o"

# External object files for target labs06
labs06_EXTERNAL_OBJECTS =

labs06: CMakeFiles/labs06.dir/src/main.cpp.o
labs06: CMakeFiles/labs06.dir/build.make
labs06: CMakeFiles/labs06.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/repos/a7a9acdb-gr22-repo/Thematic_tasks/labs06/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable labs06"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/labs06.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/labs06.dir/build: labs06

.PHONY : CMakeFiles/labs06.dir/build

CMakeFiles/labs06.dir/requires: CMakeFiles/labs06.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/labs06.dir/requires

CMakeFiles/labs06.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/labs06.dir/cmake_clean.cmake
.PHONY : CMakeFiles/labs06.dir/clean

CMakeFiles/labs06.dir/depend:
	cd /home/ubuntu/repos/a7a9acdb-gr22-repo/Thematic_tasks/labs06/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/repos/a7a9acdb-gr22-repo/Thematic_tasks/labs06 /home/ubuntu/repos/a7a9acdb-gr22-repo/Thematic_tasks/labs06 /home/ubuntu/repos/a7a9acdb-gr22-repo/Thematic_tasks/labs06/build /home/ubuntu/repos/a7a9acdb-gr22-repo/Thematic_tasks/labs06/build /home/ubuntu/repos/a7a9acdb-gr22-repo/Thematic_tasks/labs06/build/CMakeFiles/labs06.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/labs06.dir/depend

