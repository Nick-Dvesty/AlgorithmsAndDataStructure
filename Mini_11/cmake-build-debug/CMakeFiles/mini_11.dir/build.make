# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /app/extra/clion/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /app/extra/clion/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/modnick/CLionProject/AlgorithmsAndDataStructure/mini_11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/modnick/CLionProject/AlgorithmsAndDataStructure/mini_11/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mini_11.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mini_11.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mini_11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mini_11.dir/flags.make

CMakeFiles/mini_11.dir/main.c.o: CMakeFiles/mini_11.dir/flags.make
CMakeFiles/mini_11.dir/main.c.o: /home/modnick/CLionProject/AlgorithmsAndDataStructure/mini_11/main.c
CMakeFiles/mini_11.dir/main.c.o: CMakeFiles/mini_11.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/modnick/CLionProject/AlgorithmsAndDataStructure/mini_11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mini_11.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mini_11.dir/main.c.o -MF CMakeFiles/mini_11.dir/main.c.o.d -o CMakeFiles/mini_11.dir/main.c.o -c /home/modnick/CLionProject/AlgorithmsAndDataStructure/mini_11/main.c

CMakeFiles/mini_11.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/mini_11.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/modnick/CLionProject/AlgorithmsAndDataStructure/mini_11/main.c > CMakeFiles/mini_11.dir/main.c.i

CMakeFiles/mini_11.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/mini_11.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/modnick/CLionProject/AlgorithmsAndDataStructure/mini_11/main.c -o CMakeFiles/mini_11.dir/main.c.s

# Object files for target mini_11
mini_11_OBJECTS = \
"CMakeFiles/mini_11.dir/main.c.o"

# External object files for target mini_11
mini_11_EXTERNAL_OBJECTS =

mini_11: CMakeFiles/mini_11.dir/main.c.o
mini_11: CMakeFiles/mini_11.dir/build.make
mini_11: CMakeFiles/mini_11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/modnick/CLionProject/AlgorithmsAndDataStructure/mini_11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable mini_11"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mini_11.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mini_11.dir/build: mini_11
.PHONY : CMakeFiles/mini_11.dir/build

CMakeFiles/mini_11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mini_11.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mini_11.dir/clean

CMakeFiles/mini_11.dir/depend:
	cd /home/modnick/CLionProject/AlgorithmsAndDataStructure/mini_11/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/modnick/CLionProject/AlgorithmsAndDataStructure/mini_11 /home/modnick/CLionProject/AlgorithmsAndDataStructure/mini_11 /home/modnick/CLionProject/AlgorithmsAndDataStructure/mini_11/cmake-build-debug /home/modnick/CLionProject/AlgorithmsAndDataStructure/mini_11/cmake-build-debug /home/modnick/CLionProject/AlgorithmsAndDataStructure/mini_11/cmake-build-debug/CMakeFiles/mini_11.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/mini_11.dir/depend
