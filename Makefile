# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.27.7/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.27.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/malcolmkrolick/Documents/GitHub/ProductiveMidtermProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/malcolmkrolick/Documents/GitHub/ProductiveMidtermProject

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.27.7/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.27.7/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Install the project..."
	/usr/local/Cellar/cmake/3.27.7/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Install the project..."
	/usr/local/Cellar/cmake/3.27.7/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing only the local directory..."
	/usr/local/Cellar/cmake/3.27.7/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing only the local directory..."
	/usr/local/Cellar/cmake/3.27.7/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing the project stripped..."
	/usr/local/Cellar/cmake/3.27.7/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing the project stripped..."
	/usr/local/Cellar/cmake/3.27.7/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/malcolmkrolick/Documents/GitHub/ProductiveMidtermProject/CMakeFiles /Users/malcolmkrolick/Documents/GitHub/ProductiveMidtermProject//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/malcolmkrolick/Documents/GitHub/ProductiveMidtermProject/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named midterm-project_LIB

# Build rule for target.
midterm-project_LIB: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 midterm-project_LIB
.PHONY : midterm-project_LIB

# fast build rule for target.
midterm-project_LIB/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/midterm-project_LIB.dir/build.make CMakeFiles/midterm-project_LIB.dir/build
.PHONY : midterm-project_LIB/fast

#=============================================================================
# Target rules for targets named midterm-project

# Build rule for target.
midterm-project: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 midterm-project
.PHONY : midterm-project

# fast build rule for target.
midterm-project/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/midterm-project.dir/build.make CMakeFiles/midterm-project.dir/build
.PHONY : midterm-project/fast

#=============================================================================
# Target rules for targets named test

# Build rule for target.
test: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test
.PHONY : test

# fast build rule for target.
test/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/build
.PHONY : test/fast

include/ppmio/ppm_io.o: include/ppmio/ppm_io.c.o
.PHONY : include/ppmio/ppm_io.o

# target to build an object file
include/ppmio/ppm_io.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/midterm-project_LIB.dir/build.make CMakeFiles/midterm-project_LIB.dir/include/ppmio/ppm_io.c.o
.PHONY : include/ppmio/ppm_io.c.o

include/ppmio/ppm_io.i: include/ppmio/ppm_io.c.i
.PHONY : include/ppmio/ppm_io.i

# target to preprocess a source file
include/ppmio/ppm_io.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/midterm-project_LIB.dir/build.make CMakeFiles/midterm-project_LIB.dir/include/ppmio/ppm_io.c.i
.PHONY : include/ppmio/ppm_io.c.i

include/ppmio/ppm_io.s: include/ppmio/ppm_io.c.s
.PHONY : include/ppmio/ppm_io.s

# target to generate assembly for a file
include/ppmio/ppm_io.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/midterm-project_LIB.dir/build.make CMakeFiles/midterm-project_LIB.dir/include/ppmio/ppm_io.c.s
.PHONY : include/ppmio/ppm_io.c.s

src/puzzle.o: src/puzzle.c.o
.PHONY : src/puzzle.o

# target to build an object file
src/puzzle.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/midterm-project.dir/build.make CMakeFiles/midterm-project.dir/src/puzzle.c.o
.PHONY : src/puzzle.c.o

src/puzzle.i: src/puzzle.c.i
.PHONY : src/puzzle.i

# target to preprocess a source file
src/puzzle.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/midterm-project.dir/build.make CMakeFiles/midterm-project.dir/src/puzzle.c.i
.PHONY : src/puzzle.c.i

src/puzzle.s: src/puzzle.c.s
.PHONY : src/puzzle.s

# target to generate assembly for a file
src/puzzle.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/midterm-project.dir/build.make CMakeFiles/midterm-project.dir/src/puzzle.c.s
.PHONY : src/puzzle.c.s

src/utils/puzzle_funcs.o: src/utils/puzzle_funcs.c.o
.PHONY : src/utils/puzzle_funcs.o

# target to build an object file
src/utils/puzzle_funcs.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/midterm-project_LIB.dir/build.make CMakeFiles/midterm-project_LIB.dir/src/utils/puzzle_funcs.c.o
.PHONY : src/utils/puzzle_funcs.c.o

src/utils/puzzle_funcs.i: src/utils/puzzle_funcs.c.i
.PHONY : src/utils/puzzle_funcs.i

# target to preprocess a source file
src/utils/puzzle_funcs.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/midterm-project_LIB.dir/build.make CMakeFiles/midterm-project_LIB.dir/src/utils/puzzle_funcs.c.i
.PHONY : src/utils/puzzle_funcs.c.i

src/utils/puzzle_funcs.s: src/utils/puzzle_funcs.c.s
.PHONY : src/utils/puzzle_funcs.s

# target to generate assembly for a file
src/utils/puzzle_funcs.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/midterm-project_LIB.dir/build.make CMakeFiles/midterm-project_LIB.dir/src/utils/puzzle_funcs.c.s
.PHONY : src/utils/puzzle_funcs.c.s

src/utils/read_utils.o: src/utils/read_utils.c.o
.PHONY : src/utils/read_utils.o

# target to build an object file
src/utils/read_utils.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/midterm-project_LIB.dir/build.make CMakeFiles/midterm-project_LIB.dir/src/utils/read_utils.c.o
.PHONY : src/utils/read_utils.c.o

src/utils/read_utils.i: src/utils/read_utils.c.i
.PHONY : src/utils/read_utils.i

# target to preprocess a source file
src/utils/read_utils.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/midterm-project_LIB.dir/build.make CMakeFiles/midterm-project_LIB.dir/src/utils/read_utils.c.i
.PHONY : src/utils/read_utils.c.i

src/utils/read_utils.s: src/utils/read_utils.c.s
.PHONY : src/utils/read_utils.s

# target to generate assembly for a file
src/utils/read_utils.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/midterm-project_LIB.dir/build.make CMakeFiles/midterm-project_LIB.dir/src/utils/read_utils.c.s
.PHONY : src/utils/read_utils.c.s

tests/puzzle_tests.o: tests/puzzle_tests.c.o
.PHONY : tests/puzzle_tests.o

# target to build an object file
tests/puzzle_tests.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/tests/puzzle_tests.c.o
.PHONY : tests/puzzle_tests.c.o

tests/puzzle_tests.i: tests/puzzle_tests.c.i
.PHONY : tests/puzzle_tests.i

# target to preprocess a source file
tests/puzzle_tests.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/tests/puzzle_tests.c.i
.PHONY : tests/puzzle_tests.c.i

tests/puzzle_tests.s: tests/puzzle_tests.c.s
.PHONY : tests/puzzle_tests.s

# target to generate assembly for a file
tests/puzzle_tests.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/tests/puzzle_tests.c.s
.PHONY : tests/puzzle_tests.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... midterm-project"
	@echo "... midterm-project_LIB"
	@echo "... test"
	@echo "... include/ppmio/ppm_io.o"
	@echo "... include/ppmio/ppm_io.i"
	@echo "... include/ppmio/ppm_io.s"
	@echo "... src/puzzle.o"
	@echo "... src/puzzle.i"
	@echo "... src/puzzle.s"
	@echo "... src/utils/puzzle_funcs.o"
	@echo "... src/utils/puzzle_funcs.i"
	@echo "... src/utils/puzzle_funcs.s"
	@echo "... src/utils/read_utils.o"
	@echo "... src/utils/read_utils.i"
	@echo "... src/utils/read_utils.s"
	@echo "... tests/puzzle_tests.o"
	@echo "... tests/puzzle_tests.i"
	@echo "... tests/puzzle_tests.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

