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
include CMakeFiles/run_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/run_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/run_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run_tests.dir/flags.make

CMakeFiles/run_tests.dir/codegen:
.PHONY : CMakeFiles/run_tests.dir/codegen

CMakeFiles/run_tests.dir/tests/test_naive_filter.cpp.obj: CMakeFiles/run_tests.dir/flags.make
CMakeFiles/run_tests.dir/tests/test_naive_filter.cpp.obj: CMakeFiles/run_tests.dir/includes_CXX.rsp
CMakeFiles/run_tests.dir/tests/test_naive_filter.cpp.obj: C:/Users/farid/OneDrive/Desktop/hnsw/tests/test_naive_filter.cpp
CMakeFiles/run_tests.dir/tests/test_naive_filter.cpp.obj: CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\farid\OneDrive\Desktop\hnsw\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/run_tests.dir/tests/test_naive_filter.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_tests.dir/tests/test_naive_filter.cpp.obj -MF CMakeFiles\run_tests.dir\tests\test_naive_filter.cpp.obj.d -o CMakeFiles\run_tests.dir\tests\test_naive_filter.cpp.obj -c C:\Users\farid\OneDrive\Desktop\hnsw\tests\test_naive_filter.cpp

CMakeFiles/run_tests.dir/tests/test_naive_filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/tests/test_naive_filter.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\farid\OneDrive\Desktop\hnsw\tests\test_naive_filter.cpp > CMakeFiles\run_tests.dir\tests\test_naive_filter.cpp.i

CMakeFiles/run_tests.dir/tests/test_naive_filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/tests/test_naive_filter.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\farid\OneDrive\Desktop\hnsw\tests\test_naive_filter.cpp -o CMakeFiles\run_tests.dir\tests\test_naive_filter.cpp.s

# Object files for target run_tests
run_tests_OBJECTS = \
"CMakeFiles/run_tests.dir/tests/test_naive_filter.cpp.obj"

# External object files for target run_tests
run_tests_EXTERNAL_OBJECTS =

run_tests.exe: CMakeFiles/run_tests.dir/tests/test_naive_filter.cpp.obj
run_tests.exe: CMakeFiles/run_tests.dir/build.make
run_tests.exe: libfilter_lib.a
run_tests.exe: CMakeFiles/run_tests.dir/linkLibs.rsp
run_tests.exe: CMakeFiles/run_tests.dir/objects1.rsp
run_tests.exe: CMakeFiles/run_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\farid\OneDrive\Desktop\hnsw\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable run_tests.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\run_tests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run_tests.dir/build: run_tests.exe
.PHONY : CMakeFiles/run_tests.dir/build

CMakeFiles/run_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\run_tests.dir\cmake_clean.cmake
.PHONY : CMakeFiles/run_tests.dir/clean

CMakeFiles/run_tests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\farid\OneDrive\Desktop\hnsw C:\Users\farid\OneDrive\Desktop\hnsw C:\Users\farid\OneDrive\Desktop\hnsw\build C:\Users\farid\OneDrive\Desktop\hnsw\build C:\Users\farid\OneDrive\Desktop\hnsw\build\CMakeFiles\run_tests.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/run_tests.dir/depend
