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
include CMakeFiles/hnsw_bitset_example.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hnsw_bitset_example.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hnsw_bitset_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hnsw_bitset_example.dir/flags.make

CMakeFiles/hnsw_bitset_example.dir/codegen:
.PHONY : CMakeFiles/hnsw_bitset_example.dir/codegen

CMakeFiles/hnsw_bitset_example.dir/examples/hnsw_bitset_example.cpp.obj: CMakeFiles/hnsw_bitset_example.dir/flags.make
CMakeFiles/hnsw_bitset_example.dir/examples/hnsw_bitset_example.cpp.obj: CMakeFiles/hnsw_bitset_example.dir/includes_CXX.rsp
CMakeFiles/hnsw_bitset_example.dir/examples/hnsw_bitset_example.cpp.obj: C:/Users/farid/OneDrive/Desktop/hnsw/examples/hnsw_bitset_example.cpp
CMakeFiles/hnsw_bitset_example.dir/examples/hnsw_bitset_example.cpp.obj: CMakeFiles/hnsw_bitset_example.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\farid\OneDrive\Desktop\hnsw\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hnsw_bitset_example.dir/examples/hnsw_bitset_example.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hnsw_bitset_example.dir/examples/hnsw_bitset_example.cpp.obj -MF CMakeFiles\hnsw_bitset_example.dir\examples\hnsw_bitset_example.cpp.obj.d -o CMakeFiles\hnsw_bitset_example.dir\examples\hnsw_bitset_example.cpp.obj -c C:\Users\farid\OneDrive\Desktop\hnsw\examples\hnsw_bitset_example.cpp

CMakeFiles/hnsw_bitset_example.dir/examples/hnsw_bitset_example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/hnsw_bitset_example.dir/examples/hnsw_bitset_example.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\farid\OneDrive\Desktop\hnsw\examples\hnsw_bitset_example.cpp > CMakeFiles\hnsw_bitset_example.dir\examples\hnsw_bitset_example.cpp.i

CMakeFiles/hnsw_bitset_example.dir/examples/hnsw_bitset_example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/hnsw_bitset_example.dir/examples/hnsw_bitset_example.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\farid\OneDrive\Desktop\hnsw\examples\hnsw_bitset_example.cpp -o CMakeFiles\hnsw_bitset_example.dir\examples\hnsw_bitset_example.cpp.s

# Object files for target hnsw_bitset_example
hnsw_bitset_example_OBJECTS = \
"CMakeFiles/hnsw_bitset_example.dir/examples/hnsw_bitset_example.cpp.obj"

# External object files for target hnsw_bitset_example
hnsw_bitset_example_EXTERNAL_OBJECTS =

hnsw_bitset_example.exe: CMakeFiles/hnsw_bitset_example.dir/examples/hnsw_bitset_example.cpp.obj
hnsw_bitset_example.exe: CMakeFiles/hnsw_bitset_example.dir/build.make
hnsw_bitset_example.exe: libfilter_lib.a
hnsw_bitset_example.exe: CMakeFiles/hnsw_bitset_example.dir/linkLibs.rsp
hnsw_bitset_example.exe: CMakeFiles/hnsw_bitset_example.dir/objects1.rsp
hnsw_bitset_example.exe: CMakeFiles/hnsw_bitset_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\farid\OneDrive\Desktop\hnsw\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hnsw_bitset_example.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\hnsw_bitset_example.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hnsw_bitset_example.dir/build: hnsw_bitset_example.exe
.PHONY : CMakeFiles/hnsw_bitset_example.dir/build

CMakeFiles/hnsw_bitset_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\hnsw_bitset_example.dir\cmake_clean.cmake
.PHONY : CMakeFiles/hnsw_bitset_example.dir/clean

CMakeFiles/hnsw_bitset_example.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\farid\OneDrive\Desktop\hnsw C:\Users\farid\OneDrive\Desktop\hnsw C:\Users\farid\OneDrive\Desktop\hnsw\build C:\Users\farid\OneDrive\Desktop\hnsw\build C:\Users\farid\OneDrive\Desktop\hnsw\build\CMakeFiles\hnsw_bitset_example.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/hnsw_bitset_example.dir/depend

