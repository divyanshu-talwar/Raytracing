# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = "/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code"

# Include any dependencies generated for this target.
include ext/glew/build/cmake/CMakeFiles/glew.dir/depend.make

# Include the progress variables for this target.
include ext/glew/build/cmake/CMakeFiles/glew.dir/progress.make

# Include the compile flags for this target's objects.
include ext/glew/build/cmake/CMakeFiles/glew.dir/flags.make

ext/glew/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o: ext/glew/build/cmake/CMakeFiles/glew.dir/flags.make
ext/glew/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o: ext/glew/src/glew.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object ext/glew/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o"
	cd "/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code/ext/glew/build/cmake" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glew.dir/__/__/src/glew.c.o   -c "/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code/ext/glew/src/glew.c"

ext/glew/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glew.dir/__/__/src/glew.c.i"
	cd "/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code/ext/glew/build/cmake" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code/ext/glew/src/glew.c" > CMakeFiles/glew.dir/__/__/src/glew.c.i

ext/glew/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glew.dir/__/__/src/glew.c.s"
	cd "/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code/ext/glew/build/cmake" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code/ext/glew/src/glew.c" -o CMakeFiles/glew.dir/__/__/src/glew.c.s

ext/glew/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o.requires:

.PHONY : ext/glew/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o.requires

ext/glew/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o.provides: ext/glew/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o.requires
	$(MAKE) -f ext/glew/build/cmake/CMakeFiles/glew.dir/build.make ext/glew/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o.provides.build
.PHONY : ext/glew/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o.provides

ext/glew/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o.provides.build: ext/glew/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o


# Object files for target glew
glew_OBJECTS = \
"CMakeFiles/glew.dir/__/__/src/glew.c.o"

# External object files for target glew
glew_EXTERNAL_OBJECTS =

lib/libGLEW.so.2.1.0: ext/glew/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o
lib/libGLEW.so.2.1.0: ext/glew/build/cmake/CMakeFiles/glew.dir/build.make
lib/libGLEW.so.2.1.0: /usr/lib/x86_64-linux-gnu/libGL.so
lib/libGLEW.so.2.1.0: /usr/lib/x86_64-linux-gnu/libGLU.so
lib/libGLEW.so.2.1.0: ext/glew/build/cmake/CMakeFiles/glew.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library ../../../../lib/libGLEW.so"
	cd "/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code/ext/glew/build/cmake" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glew.dir/link.txt --verbose=$(VERBOSE)
	cd "/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code/ext/glew/build/cmake" && $(CMAKE_COMMAND) -E cmake_symlink_library ../../../../lib/libGLEW.so.2.1.0 ../../../../lib/libGLEW.so.2.1 ../../../../lib/libGLEW.so

lib/libGLEW.so.2.1: lib/libGLEW.so.2.1.0
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libGLEW.so.2.1

lib/libGLEW.so: lib/libGLEW.so.2.1.0
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libGLEW.so

# Rule to build all files generated by this target.
ext/glew/build/cmake/CMakeFiles/glew.dir/build: lib/libGLEW.so

.PHONY : ext/glew/build/cmake/CMakeFiles/glew.dir/build

ext/glew/build/cmake/CMakeFiles/glew.dir/requires: ext/glew/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o.requires

.PHONY : ext/glew/build/cmake/CMakeFiles/glew.dir/requires

ext/glew/build/cmake/CMakeFiles/glew.dir/clean:
	cd "/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code/ext/glew/build/cmake" && $(CMAKE_COMMAND) -P CMakeFiles/glew.dir/cmake_clean.cmake
.PHONY : ext/glew/build/cmake/CMakeFiles/glew.dir/clean

ext/glew/build/cmake/CMakeFiles/glew.dir/depend:
	cd "/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code" "/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code/ext/glew/build/cmake" "/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code" "/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code/ext/glew/build/cmake" "/home/divyanshu/Desktop/IIITD/7th Semester/CG/Assignments/cg_4_assignment/Assignment04_code/ext/glew/build/cmake/CMakeFiles/glew.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : ext/glew/build/cmake/CMakeFiles/glew.dir/depend

