# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /snap/clion/39/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/39/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/hgfs/Study/Computer Science/CSCI3431/A01/A01_pgm"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/hgfs/Study/Computer Science/CSCI3431/A01/A01_pgm/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/A01_pgm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/A01_pgm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/A01_pgm.dir/flags.make

CMakeFiles/A01_pgm.dir/main.cpp.o: CMakeFiles/A01_pgm.dir/flags.make
CMakeFiles/A01_pgm.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/hgfs/Study/Computer Science/CSCI3431/A01/A01_pgm/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/A01_pgm.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/A01_pgm.dir/main.cpp.o -c "/mnt/hgfs/Study/Computer Science/CSCI3431/A01/A01_pgm/main.cpp"

CMakeFiles/A01_pgm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A01_pgm.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/hgfs/Study/Computer Science/CSCI3431/A01/A01_pgm/main.cpp" > CMakeFiles/A01_pgm.dir/main.cpp.i

CMakeFiles/A01_pgm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A01_pgm.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/hgfs/Study/Computer Science/CSCI3431/A01/A01_pgm/main.cpp" -o CMakeFiles/A01_pgm.dir/main.cpp.s

# Object files for target A01_pgm
A01_pgm_OBJECTS = \
"CMakeFiles/A01_pgm.dir/main.cpp.o"

# External object files for target A01_pgm
A01_pgm_EXTERNAL_OBJECTS =

A01_pgm: CMakeFiles/A01_pgm.dir/main.cpp.o
A01_pgm: CMakeFiles/A01_pgm.dir/build.make
A01_pgm: CMakeFiles/A01_pgm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/hgfs/Study/Computer Science/CSCI3431/A01/A01_pgm/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable A01_pgm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/A01_pgm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/A01_pgm.dir/build: A01_pgm

.PHONY : CMakeFiles/A01_pgm.dir/build

CMakeFiles/A01_pgm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/A01_pgm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/A01_pgm.dir/clean

CMakeFiles/A01_pgm.dir/depend:
	cd "/mnt/hgfs/Study/Computer Science/CSCI3431/A01/A01_pgm/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/hgfs/Study/Computer Science/CSCI3431/A01/A01_pgm" "/mnt/hgfs/Study/Computer Science/CSCI3431/A01/A01_pgm" "/mnt/hgfs/Study/Computer Science/CSCI3431/A01/A01_pgm/cmake-build-debug" "/mnt/hgfs/Study/Computer Science/CSCI3431/A01/A01_pgm/cmake-build-debug" "/mnt/hgfs/Study/Computer Science/CSCI3431/A01/A01_pgm/cmake-build-debug/CMakeFiles/A01_pgm.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/A01_pgm.dir/depend

