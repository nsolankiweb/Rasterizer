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
CMAKE_SOURCE_DIR = "/mnt/c/Users/nsola/Documents/prev/CSCE 441/SkeletonCode3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/nsola/Documents/prev/CSCE 441/SkeletonCode3/build"

# Include any dependencies generated for this target.
include CMakeFiles/Assignment3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Assignment3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment3.dir/flags.make

CMakeFiles/Assignment3.dir/src/Triangle.cpp.o: CMakeFiles/Assignment3.dir/flags.make
CMakeFiles/Assignment3.dir/src/Triangle.cpp.o: ../src/Triangle.cpp
CMakeFiles/Assignment3.dir/src/Triangle.cpp.o: CMakeFiles/Assignment3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/nsola/Documents/prev/CSCE 441/SkeletonCode3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assignment3.dir/src/Triangle.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Assignment3.dir/src/Triangle.cpp.o -MF CMakeFiles/Assignment3.dir/src/Triangle.cpp.o.d -o CMakeFiles/Assignment3.dir/src/Triangle.cpp.o -c "/mnt/c/Users/nsola/Documents/prev/CSCE 441/SkeletonCode3/src/Triangle.cpp"

CMakeFiles/Assignment3.dir/src/Triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment3.dir/src/Triangle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/nsola/Documents/prev/CSCE 441/SkeletonCode3/src/Triangle.cpp" > CMakeFiles/Assignment3.dir/src/Triangle.cpp.i

CMakeFiles/Assignment3.dir/src/Triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment3.dir/src/Triangle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/nsola/Documents/prev/CSCE 441/SkeletonCode3/src/Triangle.cpp" -o CMakeFiles/Assignment3.dir/src/Triangle.cpp.s

CMakeFiles/Assignment3.dir/src/main.cpp.o: CMakeFiles/Assignment3.dir/flags.make
CMakeFiles/Assignment3.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/Assignment3.dir/src/main.cpp.o: CMakeFiles/Assignment3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/nsola/Documents/prev/CSCE 441/SkeletonCode3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Assignment3.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Assignment3.dir/src/main.cpp.o -MF CMakeFiles/Assignment3.dir/src/main.cpp.o.d -o CMakeFiles/Assignment3.dir/src/main.cpp.o -c "/mnt/c/Users/nsola/Documents/prev/CSCE 441/SkeletonCode3/src/main.cpp"

CMakeFiles/Assignment3.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment3.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/nsola/Documents/prev/CSCE 441/SkeletonCode3/src/main.cpp" > CMakeFiles/Assignment3.dir/src/main.cpp.i

CMakeFiles/Assignment3.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment3.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/nsola/Documents/prev/CSCE 441/SkeletonCode3/src/main.cpp" -o CMakeFiles/Assignment3.dir/src/main.cpp.s

# Object files for target Assignment3
Assignment3_OBJECTS = \
"CMakeFiles/Assignment3.dir/src/Triangle.cpp.o" \
"CMakeFiles/Assignment3.dir/src/main.cpp.o"

# External object files for target Assignment3
Assignment3_EXTERNAL_OBJECTS =

Assignment3: CMakeFiles/Assignment3.dir/src/Triangle.cpp.o
Assignment3: CMakeFiles/Assignment3.dir/src/main.cpp.o
Assignment3: CMakeFiles/Assignment3.dir/build.make
Assignment3: /root/graphics/glfw-3.3.8/debug/src/libglfw3.a
Assignment3: /root/graphics/glew-2.1.0/lib/libGLEW.a
Assignment3: /usr/lib/x86_64-linux-gnu/librt.a
Assignment3: /usr/lib/x86_64-linux-gnu/libm.so
Assignment3: /usr/lib/x86_64-linux-gnu/libX11.so
Assignment3: CMakeFiles/Assignment3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/nsola/Documents/prev/CSCE 441/SkeletonCode3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Assignment3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Assignment3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment3.dir/build: Assignment3
.PHONY : CMakeFiles/Assignment3.dir/build

CMakeFiles/Assignment3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Assignment3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Assignment3.dir/clean

CMakeFiles/Assignment3.dir/depend:
	cd "/mnt/c/Users/nsola/Documents/prev/CSCE 441/SkeletonCode3/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/nsola/Documents/prev/CSCE 441/SkeletonCode3" "/mnt/c/Users/nsola/Documents/prev/CSCE 441/SkeletonCode3" "/mnt/c/Users/nsola/Documents/prev/CSCE 441/SkeletonCode3/build" "/mnt/c/Users/nsola/Documents/prev/CSCE 441/SkeletonCode3/build" "/mnt/c/Users/nsola/Documents/prev/CSCE 441/SkeletonCode3/build/CMakeFiles/Assignment3.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Assignment3.dir/depend

