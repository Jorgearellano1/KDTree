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
CMAKE_SOURCE_DIR = /home/.idea/KD_Tree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/.idea/KD_Tree/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/KD_Tree.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/KD_Tree.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/KD_Tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/KD_Tree.dir/flags.make

CMakeFiles/KD_Tree.dir/main.cpp.o: CMakeFiles/KD_Tree.dir/flags.make
CMakeFiles/KD_Tree.dir/main.cpp.o: ../main.cpp
CMakeFiles/KD_Tree.dir/main.cpp.o: CMakeFiles/KD_Tree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/.idea/KD_Tree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/KD_Tree.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/KD_Tree.dir/main.cpp.o -MF CMakeFiles/KD_Tree.dir/main.cpp.o.d -o CMakeFiles/KD_Tree.dir/main.cpp.o -c /home/.idea/KD_Tree/main.cpp

CMakeFiles/KD_Tree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KD_Tree.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/.idea/KD_Tree/main.cpp > CMakeFiles/KD_Tree.dir/main.cpp.i

CMakeFiles/KD_Tree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KD_Tree.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/.idea/KD_Tree/main.cpp -o CMakeFiles/KD_Tree.dir/main.cpp.s

CMakeFiles/KD_Tree.dir/KDTree.cpp.o: CMakeFiles/KD_Tree.dir/flags.make
CMakeFiles/KD_Tree.dir/KDTree.cpp.o: ../KDTree.cpp
CMakeFiles/KD_Tree.dir/KDTree.cpp.o: CMakeFiles/KD_Tree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/.idea/KD_Tree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/KD_Tree.dir/KDTree.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/KD_Tree.dir/KDTree.cpp.o -MF CMakeFiles/KD_Tree.dir/KDTree.cpp.o.d -o CMakeFiles/KD_Tree.dir/KDTree.cpp.o -c /home/.idea/KD_Tree/KDTree.cpp

CMakeFiles/KD_Tree.dir/KDTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KD_Tree.dir/KDTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/.idea/KD_Tree/KDTree.cpp > CMakeFiles/KD_Tree.dir/KDTree.cpp.i

CMakeFiles/KD_Tree.dir/KDTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KD_Tree.dir/KDTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/.idea/KD_Tree/KDTree.cpp -o CMakeFiles/KD_Tree.dir/KDTree.cpp.s

# Object files for target KD_Tree
KD_Tree_OBJECTS = \
"CMakeFiles/KD_Tree.dir/main.cpp.o" \
"CMakeFiles/KD_Tree.dir/KDTree.cpp.o"

# External object files for target KD_Tree
KD_Tree_EXTERNAL_OBJECTS =

KD_Tree: CMakeFiles/KD_Tree.dir/main.cpp.o
KD_Tree: CMakeFiles/KD_Tree.dir/KDTree.cpp.o
KD_Tree: CMakeFiles/KD_Tree.dir/build.make
KD_Tree: CMakeFiles/KD_Tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/.idea/KD_Tree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable KD_Tree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/KD_Tree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/KD_Tree.dir/build: KD_Tree
.PHONY : CMakeFiles/KD_Tree.dir/build

CMakeFiles/KD_Tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/KD_Tree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/KD_Tree.dir/clean

CMakeFiles/KD_Tree.dir/depend:
	cd /home/.idea/KD_Tree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/.idea/KD_Tree /home/.idea/KD_Tree /home/.idea/KD_Tree/cmake-build-debug /home/.idea/KD_Tree/cmake-build-debug /home/.idea/KD_Tree/cmake-build-debug/CMakeFiles/KD_Tree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/KD_Tree.dir/depend

