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
include CMakeFiles/test_bitset.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_bitset.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_bitset.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_bitset.dir/flags.make

CMakeFiles/test_bitset.dir/codegen:
.PHONY : CMakeFiles/test_bitset.dir/codegen

CMakeFiles/test_bitset.dir/tests/test_bitset_filter.cpp.obj: CMakeFiles/test_bitset.dir/flags.make
CMakeFiles/test_bitset.dir/tests/test_bitset_filter.cpp.obj: CMakeFiles/test_bitset.dir/includes_CXX.rsp
CMakeFiles/test_bitset.dir/tests/test_bitset_filter.cpp.obj: C:/Users/farid/OneDrive/Desktop/hnsw/tests/test_bitset_filter.cpp
CMakeFiles/test_bitset.dir/tests/test_bitset_filter.cpp.obj: CMakeFiles/test_bitset.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\farid\OneDrive\Desktop\hnsw\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_bitset.dir/tests/test_bitset_filter.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_bitset.dir/tests/test_bitset_filter.cpp.obj -MF CMakeFiles\test_bitset.dir\tests\test_bitset_filter.cpp.obj.d -o CMakeFiles\test_bitset.dir\tests\test_bitset_filter.cpp.obj -c C:\Users\farid\OneDrive\Desktop\hnsw\tests\test_bitset_filter.cpp

CMakeFiles/test_bitset.dir/tests/test_bitset_filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_bitset.dir/tests/test_bitset_filter.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\farid\OneDrive\Desktop\hnsw\tests\test_bitset_filter.cpp > CMakeFiles\test_bitset.dir\tests\test_bitset_filter.cpp.i

CMakeFiles/test_bitset.dir/tests/test_bitset_filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_bitset.dir/tests/test_bitset_filter.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\farid\OneDrive\Desktop\hnsw\tests\test_bitset_filter.cpp -o CMakeFiles\test_bitset.dir\tests\test_bitset_filter.cpp.s

# Object files for target test_bitset
test_bitset_OBJECTS = \
"CMakeFiles/test_bitset.dir/tests/test_bitset_filter.cpp.obj"

# External object files for target test_bitset
test_bitset_EXTERNAL_OBJECTS =

test_bitset.exe: CMakeFiles/test_bitset.dir/tests/test_bitset_filter.cpp.obj
test_bitset.exe: CMakeFiles/test_bitset.dir/build.make
test_bitset.exe: libfilter_lib.a
test_bitset.exe: CMakeFiles/test_bitset.dir/linkLibs.rsp
test_bitset.exe: CMakeFiles/test_bitset.dir/objects1.rsp
test_bitset.exe: CMakeFiles/test_bitset.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\farid\OneDrive\Desktop\hnsw\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_bitset.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test_bitset.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_bitset.dir/build: test_bitset.exe
.PHONY : CMakeFiles/test_bitset.dir/build

CMakeFiles/test_bitset.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test_bitset.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test_bitset.dir/clean

CMakeFiles/test_bitset.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\farid\OneDrive\Desktop\hnsw C:\Users\farid\OneDrive\Desktop\hnsw C:\Users\farid\OneDrive\Desktop\hnsw\build C:\Users\farid\OneDrive\Desktop\hnsw\build C:\Users\farid\OneDrive\Desktop\hnsw\build\CMakeFiles\test_bitset.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test_bitset.dir/depend

