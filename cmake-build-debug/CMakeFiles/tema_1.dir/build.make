# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/limelier/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.32/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/limelier/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.32/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/limelier/college/retele/tema-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/limelier/college/retele/tema-1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tema_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tema_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tema_1.dir/flags.make

CMakeFiles/tema_1.dir/main.c.o: CMakeFiles/tema_1.dir/flags.make
CMakeFiles/tema_1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/limelier/college/retele/tema-1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tema_1.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tema_1.dir/main.c.o   -c /home/limelier/college/retele/tema-1/main.c

CMakeFiles/tema_1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tema_1.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/limelier/college/retele/tema-1/main.c > CMakeFiles/tema_1.dir/main.c.i

CMakeFiles/tema_1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tema_1.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/limelier/college/retele/tema-1/main.c -o CMakeFiles/tema_1.dir/main.c.s

CMakeFiles/tema_1.dir/init.c.o: CMakeFiles/tema_1.dir/flags.make
CMakeFiles/tema_1.dir/init.c.o: ../init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/limelier/college/retele/tema-1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/tema_1.dir/init.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tema_1.dir/init.c.o   -c /home/limelier/college/retele/tema-1/init.c

CMakeFiles/tema_1.dir/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tema_1.dir/init.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/limelier/college/retele/tema-1/init.c > CMakeFiles/tema_1.dir/init.c.i

CMakeFiles/tema_1.dir/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tema_1.dir/init.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/limelier/college/retele/tema-1/init.c -o CMakeFiles/tema_1.dir/init.c.s

CMakeFiles/tema_1.dir/parent.c.o: CMakeFiles/tema_1.dir/flags.make
CMakeFiles/tema_1.dir/parent.c.o: ../parent.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/limelier/college/retele/tema-1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/tema_1.dir/parent.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tema_1.dir/parent.c.o   -c /home/limelier/college/retele/tema-1/parent.c

CMakeFiles/tema_1.dir/parent.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tema_1.dir/parent.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/limelier/college/retele/tema-1/parent.c > CMakeFiles/tema_1.dir/parent.c.i

CMakeFiles/tema_1.dir/parent.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tema_1.dir/parent.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/limelier/college/retele/tema-1/parent.c -o CMakeFiles/tema_1.dir/parent.c.s

# Object files for target tema_1
tema_1_OBJECTS = \
"CMakeFiles/tema_1.dir/main.c.o" \
"CMakeFiles/tema_1.dir/init.c.o" \
"CMakeFiles/tema_1.dir/parent.c.o"

# External object files for target tema_1
tema_1_EXTERNAL_OBJECTS =

tema_1: CMakeFiles/tema_1.dir/main.c.o
tema_1: CMakeFiles/tema_1.dir/init.c.o
tema_1: CMakeFiles/tema_1.dir/parent.c.o
tema_1: CMakeFiles/tema_1.dir/build.make
tema_1: CMakeFiles/tema_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/limelier/college/retele/tema-1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable tema_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tema_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tema_1.dir/build: tema_1

.PHONY : CMakeFiles/tema_1.dir/build

CMakeFiles/tema_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tema_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tema_1.dir/clean

CMakeFiles/tema_1.dir/depend:
	cd /home/limelier/college/retele/tema-1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/limelier/college/retele/tema-1 /home/limelier/college/retele/tema-1 /home/limelier/college/retele/tema-1/cmake-build-debug /home/limelier/college/retele/tema-1/cmake-build-debug /home/limelier/college/retele/tema-1/cmake-build-debug/CMakeFiles/tema_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tema_1.dir/depend
