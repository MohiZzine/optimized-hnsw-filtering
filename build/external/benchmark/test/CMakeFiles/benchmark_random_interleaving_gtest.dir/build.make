# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = C:\msys64\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\msys64\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\farid\OneDrive\Desktop\hnsw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\farid\OneDrive\Desktop\hnsw\build

# Include any dependencies generated for this target.
include external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/compiler_depend.make

# Include the progress variables for this target.
include external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/progress.make

# Include the compile flags for this target's objects.
include external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/flags.make

external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/codegen:
.PHONY : external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/codegen

external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/benchmark_random_interleaving_gtest.cc.obj: external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/flags.make
external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/benchmark_random_interleaving_gtest.cc.obj: external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/includes_CXX.rsp
external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/benchmark_random_interleaving_gtest.cc.obj: C:/Users/farid/OneDrive/Desktop/hnsw/external/benchmark/test/benchmark_random_interleaving_gtest.cc
external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/benchmark_random_interleaving_gtest.cc.obj: external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\farid\OneDrive\Desktop\hnsw\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/benchmark_random_interleaving_gtest.cc.obj"
	cd /d C:\Users\farid\OneDrive\Desktop\hnsw\build\external\benchmark\test && C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/benchmark_random_interleaving_gtest.cc.obj -MF CMakeFiles\benchmark_random_interleaving_gtest.dir\benchmark_random_interleaving_gtest.cc.obj.d -o CMakeFiles\benchmark_random_interleaving_gtest.dir\benchmark_random_interleaving_gtest.cc.obj -c C:\Users\farid\OneDrive\Desktop\hnsw\external\benchmark\test\benchmark_random_interleaving_gtest.cc

external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/benchmark_random_interleaving_gtest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/benchmark_random_interleaving_gtest.dir/benchmark_random_interleaving_gtest.cc.i"
	cd /d C:\Users\farid\OneDrive\Desktop\hnsw\build\external\benchmark\test && C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\farid\OneDrive\Desktop\hnsw\external\benchmark\test\benchmark_random_interleaving_gtest.cc > CMakeFiles\benchmark_random_interleaving_gtest.dir\benchmark_random_interleaving_gtest.cc.i

external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/benchmark_random_interleaving_gtest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/benchmark_random_interleaving_gtest.dir/benchmark_random_interleaving_gtest.cc.s"
	cd /d C:\Users\farid\OneDrive\Desktop\hnsw\build\external\benchmark\test && C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\farid\OneDrive\Desktop\hnsw\external\benchmark\test\benchmark_random_interleaving_gtest.cc -o CMakeFiles\benchmark_random_interleaving_gtest.dir\benchmark_random_interleaving_gtest.cc.s

# Object files for target benchmark_random_interleaving_gtest
benchmark_random_interleaving_gtest_OBJECTS = \
"CMakeFiles/benchmark_random_interleaving_gtest.dir/benchmark_random_interleaving_gtest.cc.obj"

# External object files for target benchmark_random_interleaving_gtest
benchmark_random_interleaving_gtest_EXTERNAL_OBJECTS =

external/benchmark/test/benchmark_random_interleaving_gtest.exe: external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/benchmark_random_interleaving_gtest.cc.obj
external/benchmark/test/benchmark_random_interleaving_gtest.exe: external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/build.make
external/benchmark/test/benchmark_random_interleaving_gtest.exe: external/benchmark/src/libbenchmark.a
external/benchmark/test/benchmark_random_interleaving_gtest.exe: lib/libgmock_main.a
external/benchmark/test/benchmark_random_interleaving_gtest.exe: lib/libgmock.a
external/benchmark/test/benchmark_random_interleaving_gtest.exe: lib/libgtest.a
external/benchmark/test/benchmark_random_interleaving_gtest.exe: external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/linkLibs.rsp
external/benchmark/test/benchmark_random_interleaving_gtest.exe: external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/objects1.rsp
external/benchmark/test/benchmark_random_interleaving_gtest.exe: external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\farid\OneDrive\Desktop\hnsw\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable benchmark_random_interleaving_gtest.exe"
	cd /d C:\Users\farid\OneDrive\Desktop\hnsw\build\external\benchmark\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\benchmark_random_interleaving_gtest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/build: external/benchmark/test/benchmark_random_interleaving_gtest.exe
.PHONY : external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/build

external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/clean:
	cd /d C:\Users\farid\OneDrive\Desktop\hnsw\build\external\benchmark\test && $(CMAKE_COMMAND) -P CMakeFiles\benchmark_random_interleaving_gtest.dir\cmake_clean.cmake
.PHONY : external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/clean

external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\farid\OneDrive\Desktop\hnsw C:\Users\farid\OneDrive\Desktop\hnsw\external\benchmark\test C:\Users\farid\OneDrive\Desktop\hnsw\build C:\Users\farid\OneDrive\Desktop\hnsw\build\external\benchmark\test C:\Users\farid\OneDrive\Desktop\hnsw\build\external\benchmark\test\CMakeFiles\benchmark_random_interleaving_gtest.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : external/benchmark/test/CMakeFiles/benchmark_random_interleaving_gtest.dir/depend
