# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\23125\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\23125\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\chengxvyuan\self-fun

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\chengxvyuan\self-fun\cmake-build-debug

# Include any dependencies generated for this target.
include self-learn/CMakeFiles/searchmine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include self-learn/CMakeFiles/searchmine.dir/compiler_depend.make

# Include the progress variables for this target.
include self-learn/CMakeFiles/searchmine.dir/progress.make

# Include the compile flags for this target's objects.
include self-learn/CMakeFiles/searchmine.dir/flags.make

self-learn/CMakeFiles/searchmine.dir/searchmine.c.obj: self-learn/CMakeFiles/searchmine.dir/flags.make
self-learn/CMakeFiles/searchmine.dir/searchmine.c.obj: D:/chengxvyuan/self-fun/self-learn/searchmine.c
self-learn/CMakeFiles/searchmine.dir/searchmine.c.obj: self-learn/CMakeFiles/searchmine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\chengxvyuan\self-fun\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object self-learn/CMakeFiles/searchmine.dir/searchmine.c.obj"
	cd /d D:\chengxvyuan\self-fun\cmake-build-debug\self-learn && C:\Users\23125\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT self-learn/CMakeFiles/searchmine.dir/searchmine.c.obj -MF CMakeFiles\searchmine.dir\searchmine.c.obj.d -o CMakeFiles\searchmine.dir\searchmine.c.obj -c D:\chengxvyuan\self-fun\self-learn\searchmine.c

self-learn/CMakeFiles/searchmine.dir/searchmine.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/searchmine.dir/searchmine.c.i"
	cd /d D:\chengxvyuan\self-fun\cmake-build-debug\self-learn && C:\Users\23125\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\chengxvyuan\self-fun\self-learn\searchmine.c > CMakeFiles\searchmine.dir\searchmine.c.i

self-learn/CMakeFiles/searchmine.dir/searchmine.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/searchmine.dir/searchmine.c.s"
	cd /d D:\chengxvyuan\self-fun\cmake-build-debug\self-learn && C:\Users\23125\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\chengxvyuan\self-fun\self-learn\searchmine.c -o CMakeFiles\searchmine.dir\searchmine.c.s

# Object files for target searchmine
searchmine_OBJECTS = \
"CMakeFiles/searchmine.dir/searchmine.c.obj"

# External object files for target searchmine
searchmine_EXTERNAL_OBJECTS =

self-learn/searchmine.exe: self-learn/CMakeFiles/searchmine.dir/searchmine.c.obj
self-learn/searchmine.exe: self-learn/CMakeFiles/searchmine.dir/build.make
self-learn/searchmine.exe: self-learn/CMakeFiles/searchmine.dir/linkLibs.rsp
self-learn/searchmine.exe: self-learn/CMakeFiles/searchmine.dir/objects1.rsp
self-learn/searchmine.exe: self-learn/CMakeFiles/searchmine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\chengxvyuan\self-fun\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable searchmine.exe"
	cd /d D:\chengxvyuan\self-fun\cmake-build-debug\self-learn && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\searchmine.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
self-learn/CMakeFiles/searchmine.dir/build: self-learn/searchmine.exe
.PHONY : self-learn/CMakeFiles/searchmine.dir/build

self-learn/CMakeFiles/searchmine.dir/clean:
	cd /d D:\chengxvyuan\self-fun\cmake-build-debug\self-learn && $(CMAKE_COMMAND) -P CMakeFiles\searchmine.dir\cmake_clean.cmake
.PHONY : self-learn/CMakeFiles/searchmine.dir/clean

self-learn/CMakeFiles/searchmine.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\chengxvyuan\self-fun D:\chengxvyuan\self-fun\self-learn D:\chengxvyuan\self-fun\cmake-build-debug D:\chengxvyuan\self-fun\cmake-build-debug\self-learn D:\chengxvyuan\self-fun\cmake-build-debug\self-learn\CMakeFiles\searchmine.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : self-learn/CMakeFiles/searchmine.dir/depend
