# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/markovito/projects/Sabina2014

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/markovito/projects/Sabina2014/build

# Include any dependencies generated for this target.
include SharedMemory/CMakeFiles/SharedMemory.dir/depend.make

# Include the progress variables for this target.
include SharedMemory/CMakeFiles/SharedMemory.dir/progress.make

# Include the compile flags for this target's objects.
include SharedMemory/CMakeFiles/SharedMemory.dir/flags.make

SharedMemory/CMakeFiles/SharedMemory.dir/Arm.cpp.o: SharedMemory/CMakeFiles/SharedMemory.dir/flags.make
SharedMemory/CMakeFiles/SharedMemory.dir/Arm.cpp.o: ../SharedMemory/Arm.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object SharedMemory/CMakeFiles/SharedMemory.dir/Arm.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SharedMemory.dir/Arm.cpp.o -c /home/markovito/projects/Sabina2014/SharedMemory/Arm.cpp

SharedMemory/CMakeFiles/SharedMemory.dir/Arm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedMemory.dir/Arm.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/SharedMemory/Arm.cpp > CMakeFiles/SharedMemory.dir/Arm.cpp.i

SharedMemory/CMakeFiles/SharedMemory.dir/Arm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedMemory.dir/Arm.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/SharedMemory/Arm.cpp -o CMakeFiles/SharedMemory.dir/Arm.cpp.s

SharedMemory/CMakeFiles/SharedMemory.dir/Arm.cpp.o.requires:
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/Arm.cpp.o.requires

SharedMemory/CMakeFiles/SharedMemory.dir/Arm.cpp.o.provides: SharedMemory/CMakeFiles/SharedMemory.dir/Arm.cpp.o.requires
	$(MAKE) -f SharedMemory/CMakeFiles/SharedMemory.dir/build.make SharedMemory/CMakeFiles/SharedMemory.dir/Arm.cpp.o.provides.build
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/Arm.cpp.o.provides

SharedMemory/CMakeFiles/SharedMemory.dir/Arm.cpp.o.provides.build: SharedMemory/CMakeFiles/SharedMemory.dir/Arm.cpp.o

SharedMemory/CMakeFiles/SharedMemory.dir/ConfigFile.cpp.o: SharedMemory/CMakeFiles/SharedMemory.dir/flags.make
SharedMemory/CMakeFiles/SharedMemory.dir/ConfigFile.cpp.o: ../SharedMemory/ConfigFile.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object SharedMemory/CMakeFiles/SharedMemory.dir/ConfigFile.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SharedMemory.dir/ConfigFile.cpp.o -c /home/markovito/projects/Sabina2014/SharedMemory/ConfigFile.cpp

SharedMemory/CMakeFiles/SharedMemory.dir/ConfigFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedMemory.dir/ConfigFile.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/SharedMemory/ConfigFile.cpp > CMakeFiles/SharedMemory.dir/ConfigFile.cpp.i

SharedMemory/CMakeFiles/SharedMemory.dir/ConfigFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedMemory.dir/ConfigFile.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/SharedMemory/ConfigFile.cpp -o CMakeFiles/SharedMemory.dir/ConfigFile.cpp.s

SharedMemory/CMakeFiles/SharedMemory.dir/ConfigFile.cpp.o.requires:
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/ConfigFile.cpp.o.requires

SharedMemory/CMakeFiles/SharedMemory.dir/ConfigFile.cpp.o.provides: SharedMemory/CMakeFiles/SharedMemory.dir/ConfigFile.cpp.o.requires
	$(MAKE) -f SharedMemory/CMakeFiles/SharedMemory.dir/build.make SharedMemory/CMakeFiles/SharedMemory.dir/ConfigFile.cpp.o.provides.build
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/ConfigFile.cpp.o.provides

SharedMemory/CMakeFiles/SharedMemory.dir/ConfigFile.cpp.o.provides.build: SharedMemory/CMakeFiles/SharedMemory.dir/ConfigFile.cpp.o

SharedMemory/CMakeFiles/SharedMemory.dir/Kinect.cpp.o: SharedMemory/CMakeFiles/SharedMemory.dir/flags.make
SharedMemory/CMakeFiles/SharedMemory.dir/Kinect.cpp.o: ../SharedMemory/Kinect.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object SharedMemory/CMakeFiles/SharedMemory.dir/Kinect.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SharedMemory.dir/Kinect.cpp.o -c /home/markovito/projects/Sabina2014/SharedMemory/Kinect.cpp

SharedMemory/CMakeFiles/SharedMemory.dir/Kinect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedMemory.dir/Kinect.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/SharedMemory/Kinect.cpp > CMakeFiles/SharedMemory.dir/Kinect.cpp.i

SharedMemory/CMakeFiles/SharedMemory.dir/Kinect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedMemory.dir/Kinect.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/SharedMemory/Kinect.cpp -o CMakeFiles/SharedMemory.dir/Kinect.cpp.s

SharedMemory/CMakeFiles/SharedMemory.dir/Kinect.cpp.o.requires:
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/Kinect.cpp.o.requires

SharedMemory/CMakeFiles/SharedMemory.dir/Kinect.cpp.o.provides: SharedMemory/CMakeFiles/SharedMemory.dir/Kinect.cpp.o.requires
	$(MAKE) -f SharedMemory/CMakeFiles/SharedMemory.dir/build.make SharedMemory/CMakeFiles/SharedMemory.dir/Kinect.cpp.o.provides.build
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/Kinect.cpp.o.provides

SharedMemory/CMakeFiles/SharedMemory.dir/Kinect.cpp.o.provides.build: SharedMemory/CMakeFiles/SharedMemory.dir/Kinect.cpp.o

SharedMemory/CMakeFiles/SharedMemory.dir/Destination.cpp.o: SharedMemory/CMakeFiles/SharedMemory.dir/flags.make
SharedMemory/CMakeFiles/SharedMemory.dir/Destination.cpp.o: ../SharedMemory/Destination.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object SharedMemory/CMakeFiles/SharedMemory.dir/Destination.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SharedMemory.dir/Destination.cpp.o -c /home/markovito/projects/Sabina2014/SharedMemory/Destination.cpp

SharedMemory/CMakeFiles/SharedMemory.dir/Destination.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedMemory.dir/Destination.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/SharedMemory/Destination.cpp > CMakeFiles/SharedMemory.dir/Destination.cpp.i

SharedMemory/CMakeFiles/SharedMemory.dir/Destination.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedMemory.dir/Destination.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/SharedMemory/Destination.cpp -o CMakeFiles/SharedMemory.dir/Destination.cpp.s

SharedMemory/CMakeFiles/SharedMemory.dir/Destination.cpp.o.requires:
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/Destination.cpp.o.requires

SharedMemory/CMakeFiles/SharedMemory.dir/Destination.cpp.o.provides: SharedMemory/CMakeFiles/SharedMemory.dir/Destination.cpp.o.requires
	$(MAKE) -f SharedMemory/CMakeFiles/SharedMemory.dir/build.make SharedMemory/CMakeFiles/SharedMemory.dir/Destination.cpp.o.provides.build
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/Destination.cpp.o.provides

SharedMemory/CMakeFiles/SharedMemory.dir/Destination.cpp.o.provides.build: SharedMemory/CMakeFiles/SharedMemory.dir/Destination.cpp.o

SharedMemory/CMakeFiles/SharedMemory.dir/PTZ.cpp.o: SharedMemory/CMakeFiles/SharedMemory.dir/flags.make
SharedMemory/CMakeFiles/SharedMemory.dir/PTZ.cpp.o: ../SharedMemory/PTZ.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object SharedMemory/CMakeFiles/SharedMemory.dir/PTZ.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SharedMemory.dir/PTZ.cpp.o -c /home/markovito/projects/Sabina2014/SharedMemory/PTZ.cpp

SharedMemory/CMakeFiles/SharedMemory.dir/PTZ.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedMemory.dir/PTZ.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/SharedMemory/PTZ.cpp > CMakeFiles/SharedMemory.dir/PTZ.cpp.i

SharedMemory/CMakeFiles/SharedMemory.dir/PTZ.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedMemory.dir/PTZ.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/SharedMemory/PTZ.cpp -o CMakeFiles/SharedMemory.dir/PTZ.cpp.s

SharedMemory/CMakeFiles/SharedMemory.dir/PTZ.cpp.o.requires:
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/PTZ.cpp.o.requires

SharedMemory/CMakeFiles/SharedMemory.dir/PTZ.cpp.o.provides: SharedMemory/CMakeFiles/SharedMemory.dir/PTZ.cpp.o.requires
	$(MAKE) -f SharedMemory/CMakeFiles/SharedMemory.dir/build.make SharedMemory/CMakeFiles/SharedMemory.dir/PTZ.cpp.o.provides.build
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/PTZ.cpp.o.provides

SharedMemory/CMakeFiles/SharedMemory.dir/PTZ.cpp.o.provides.build: SharedMemory/CMakeFiles/SharedMemory.dir/PTZ.cpp.o

SharedMemory/CMakeFiles/SharedMemory.dir/Laser.cpp.o: SharedMemory/CMakeFiles/SharedMemory.dir/flags.make
SharedMemory/CMakeFiles/SharedMemory.dir/Laser.cpp.o: ../SharedMemory/Laser.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object SharedMemory/CMakeFiles/SharedMemory.dir/Laser.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SharedMemory.dir/Laser.cpp.o -c /home/markovito/projects/Sabina2014/SharedMemory/Laser.cpp

SharedMemory/CMakeFiles/SharedMemory.dir/Laser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedMemory.dir/Laser.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/SharedMemory/Laser.cpp > CMakeFiles/SharedMemory.dir/Laser.cpp.i

SharedMemory/CMakeFiles/SharedMemory.dir/Laser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedMemory.dir/Laser.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/SharedMemory/Laser.cpp -o CMakeFiles/SharedMemory.dir/Laser.cpp.s

SharedMemory/CMakeFiles/SharedMemory.dir/Laser.cpp.o.requires:
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/Laser.cpp.o.requires

SharedMemory/CMakeFiles/SharedMemory.dir/Laser.cpp.o.provides: SharedMemory/CMakeFiles/SharedMemory.dir/Laser.cpp.o.requires
	$(MAKE) -f SharedMemory/CMakeFiles/SharedMemory.dir/build.make SharedMemory/CMakeFiles/SharedMemory.dir/Laser.cpp.o.provides.build
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/Laser.cpp.o.provides

SharedMemory/CMakeFiles/SharedMemory.dir/Laser.cpp.o.provides.build: SharedMemory/CMakeFiles/SharedMemory.dir/Laser.cpp.o

SharedMemory/CMakeFiles/SharedMemory.dir/Location.cpp.o: SharedMemory/CMakeFiles/SharedMemory.dir/flags.make
SharedMemory/CMakeFiles/SharedMemory.dir/Location.cpp.o: ../SharedMemory/Location.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object SharedMemory/CMakeFiles/SharedMemory.dir/Location.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SharedMemory.dir/Location.cpp.o -c /home/markovito/projects/Sabina2014/SharedMemory/Location.cpp

SharedMemory/CMakeFiles/SharedMemory.dir/Location.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedMemory.dir/Location.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/SharedMemory/Location.cpp > CMakeFiles/SharedMemory.dir/Location.cpp.i

SharedMemory/CMakeFiles/SharedMemory.dir/Location.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedMemory.dir/Location.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/SharedMemory/Location.cpp -o CMakeFiles/SharedMemory.dir/Location.cpp.s

SharedMemory/CMakeFiles/SharedMemory.dir/Location.cpp.o.requires:
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/Location.cpp.o.requires

SharedMemory/CMakeFiles/SharedMemory.dir/Location.cpp.o.provides: SharedMemory/CMakeFiles/SharedMemory.dir/Location.cpp.o.requires
	$(MAKE) -f SharedMemory/CMakeFiles/SharedMemory.dir/build.make SharedMemory/CMakeFiles/SharedMemory.dir/Location.cpp.o.provides.build
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/Location.cpp.o.provides

SharedMemory/CMakeFiles/SharedMemory.dir/Location.cpp.o.provides.build: SharedMemory/CMakeFiles/SharedMemory.dir/Location.cpp.o

SharedMemory/CMakeFiles/SharedMemory.dir/Map.cpp.o: SharedMemory/CMakeFiles/SharedMemory.dir/flags.make
SharedMemory/CMakeFiles/SharedMemory.dir/Map.cpp.o: ../SharedMemory/Map.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object SharedMemory/CMakeFiles/SharedMemory.dir/Map.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SharedMemory.dir/Map.cpp.o -c /home/markovito/projects/Sabina2014/SharedMemory/Map.cpp

SharedMemory/CMakeFiles/SharedMemory.dir/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedMemory.dir/Map.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/SharedMemory/Map.cpp > CMakeFiles/SharedMemory.dir/Map.cpp.i

SharedMemory/CMakeFiles/SharedMemory.dir/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedMemory.dir/Map.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/SharedMemory/Map.cpp -o CMakeFiles/SharedMemory.dir/Map.cpp.s

SharedMemory/CMakeFiles/SharedMemory.dir/Map.cpp.o.requires:
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/Map.cpp.o.requires

SharedMemory/CMakeFiles/SharedMemory.dir/Map.cpp.o.provides: SharedMemory/CMakeFiles/SharedMemory.dir/Map.cpp.o.requires
	$(MAKE) -f SharedMemory/CMakeFiles/SharedMemory.dir/build.make SharedMemory/CMakeFiles/SharedMemory.dir/Map.cpp.o.provides.build
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/Map.cpp.o.provides

SharedMemory/CMakeFiles/SharedMemory.dir/Map.cpp.o.provides.build: SharedMemory/CMakeFiles/SharedMemory.dir/Map.cpp.o

SharedMemory/CMakeFiles/SharedMemory.dir/Objective.cpp.o: SharedMemory/CMakeFiles/SharedMemory.dir/flags.make
SharedMemory/CMakeFiles/SharedMemory.dir/Objective.cpp.o: ../SharedMemory/Objective.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object SharedMemory/CMakeFiles/SharedMemory.dir/Objective.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SharedMemory.dir/Objective.cpp.o -c /home/markovito/projects/Sabina2014/SharedMemory/Objective.cpp

SharedMemory/CMakeFiles/SharedMemory.dir/Objective.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedMemory.dir/Objective.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/SharedMemory/Objective.cpp > CMakeFiles/SharedMemory.dir/Objective.cpp.i

SharedMemory/CMakeFiles/SharedMemory.dir/Objective.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedMemory.dir/Objective.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/SharedMemory/Objective.cpp -o CMakeFiles/SharedMemory.dir/Objective.cpp.s

SharedMemory/CMakeFiles/SharedMemory.dir/Objective.cpp.o.requires:
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/Objective.cpp.o.requires

SharedMemory/CMakeFiles/SharedMemory.dir/Objective.cpp.o.provides: SharedMemory/CMakeFiles/SharedMemory.dir/Objective.cpp.o.requires
	$(MAKE) -f SharedMemory/CMakeFiles/SharedMemory.dir/build.make SharedMemory/CMakeFiles/SharedMemory.dir/Objective.cpp.o.provides.build
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/Objective.cpp.o.provides

SharedMemory/CMakeFiles/SharedMemory.dir/Objective.cpp.o.provides.build: SharedMemory/CMakeFiles/SharedMemory.dir/Objective.cpp.o

SharedMemory/CMakeFiles/SharedMemory.dir/SharedMemory.cpp.o: SharedMemory/CMakeFiles/SharedMemory.dir/flags.make
SharedMemory/CMakeFiles/SharedMemory.dir/SharedMemory.cpp.o: ../SharedMemory/SharedMemory.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object SharedMemory/CMakeFiles/SharedMemory.dir/SharedMemory.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SharedMemory.dir/SharedMemory.cpp.o -c /home/markovito/projects/Sabina2014/SharedMemory/SharedMemory.cpp

SharedMemory/CMakeFiles/SharedMemory.dir/SharedMemory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedMemory.dir/SharedMemory.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/SharedMemory/SharedMemory.cpp > CMakeFiles/SharedMemory.dir/SharedMemory.cpp.i

SharedMemory/CMakeFiles/SharedMemory.dir/SharedMemory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedMemory.dir/SharedMemory.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/SharedMemory/SharedMemory.cpp -o CMakeFiles/SharedMemory.dir/SharedMemory.cpp.s

SharedMemory/CMakeFiles/SharedMemory.dir/SharedMemory.cpp.o.requires:
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/SharedMemory.cpp.o.requires

SharedMemory/CMakeFiles/SharedMemory.dir/SharedMemory.cpp.o.provides: SharedMemory/CMakeFiles/SharedMemory.dir/SharedMemory.cpp.o.requires
	$(MAKE) -f SharedMemory/CMakeFiles/SharedMemory.dir/build.make SharedMemory/CMakeFiles/SharedMemory.dir/SharedMemory.cpp.o.provides.build
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/SharedMemory.cpp.o.provides

SharedMemory/CMakeFiles/SharedMemory.dir/SharedMemory.cpp.o.provides.build: SharedMemory/CMakeFiles/SharedMemory.dir/SharedMemory.cpp.o

SharedMemory/CMakeFiles/SharedMemory.dir/Synthesis.cpp.o: SharedMemory/CMakeFiles/SharedMemory.dir/flags.make
SharedMemory/CMakeFiles/SharedMemory.dir/Synthesis.cpp.o: ../SharedMemory/Synthesis.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object SharedMemory/CMakeFiles/SharedMemory.dir/Synthesis.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SharedMemory.dir/Synthesis.cpp.o -c /home/markovito/projects/Sabina2014/SharedMemory/Synthesis.cpp

SharedMemory/CMakeFiles/SharedMemory.dir/Synthesis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedMemory.dir/Synthesis.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/SharedMemory/Synthesis.cpp > CMakeFiles/SharedMemory.dir/Synthesis.cpp.i

SharedMemory/CMakeFiles/SharedMemory.dir/Synthesis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedMemory.dir/Synthesis.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/SharedMemory/Synthesis.cpp -o CMakeFiles/SharedMemory.dir/Synthesis.cpp.s

SharedMemory/CMakeFiles/SharedMemory.dir/Synthesis.cpp.o.requires:
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/Synthesis.cpp.o.requires

SharedMemory/CMakeFiles/SharedMemory.dir/Synthesis.cpp.o.provides: SharedMemory/CMakeFiles/SharedMemory.dir/Synthesis.cpp.o.requires
	$(MAKE) -f SharedMemory/CMakeFiles/SharedMemory.dir/build.make SharedMemory/CMakeFiles/SharedMemory.dir/Synthesis.cpp.o.provides.build
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/Synthesis.cpp.o.provides

SharedMemory/CMakeFiles/SharedMemory.dir/Synthesis.cpp.o.provides.build: SharedMemory/CMakeFiles/SharedMemory.dir/Synthesis.cpp.o

SharedMemory/CMakeFiles/SharedMemory.dir/Voice.cpp.o: SharedMemory/CMakeFiles/SharedMemory.dir/flags.make
SharedMemory/CMakeFiles/SharedMemory.dir/Voice.cpp.o: ../SharedMemory/Voice.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object SharedMemory/CMakeFiles/SharedMemory.dir/Voice.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SharedMemory.dir/Voice.cpp.o -c /home/markovito/projects/Sabina2014/SharedMemory/Voice.cpp

SharedMemory/CMakeFiles/SharedMemory.dir/Voice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedMemory.dir/Voice.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/SharedMemory/Voice.cpp > CMakeFiles/SharedMemory.dir/Voice.cpp.i

SharedMemory/CMakeFiles/SharedMemory.dir/Voice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedMemory.dir/Voice.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/SharedMemory/Voice.cpp -o CMakeFiles/SharedMemory.dir/Voice.cpp.s

SharedMemory/CMakeFiles/SharedMemory.dir/Voice.cpp.o.requires:
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/Voice.cpp.o.requires

SharedMemory/CMakeFiles/SharedMemory.dir/Voice.cpp.o.provides: SharedMemory/CMakeFiles/SharedMemory.dir/Voice.cpp.o.requires
	$(MAKE) -f SharedMemory/CMakeFiles/SharedMemory.dir/build.make SharedMemory/CMakeFiles/SharedMemory.dir/Voice.cpp.o.provides.build
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/Voice.cpp.o.provides

SharedMemory/CMakeFiles/SharedMemory.dir/Voice.cpp.o.provides.build: SharedMemory/CMakeFiles/SharedMemory.dir/Voice.cpp.o

# Object files for target SharedMemory
SharedMemory_OBJECTS = \
"CMakeFiles/SharedMemory.dir/Arm.cpp.o" \
"CMakeFiles/SharedMemory.dir/ConfigFile.cpp.o" \
"CMakeFiles/SharedMemory.dir/Kinect.cpp.o" \
"CMakeFiles/SharedMemory.dir/Destination.cpp.o" \
"CMakeFiles/SharedMemory.dir/PTZ.cpp.o" \
"CMakeFiles/SharedMemory.dir/Laser.cpp.o" \
"CMakeFiles/SharedMemory.dir/Location.cpp.o" \
"CMakeFiles/SharedMemory.dir/Map.cpp.o" \
"CMakeFiles/SharedMemory.dir/Objective.cpp.o" \
"CMakeFiles/SharedMemory.dir/SharedMemory.cpp.o" \
"CMakeFiles/SharedMemory.dir/Synthesis.cpp.o" \
"CMakeFiles/SharedMemory.dir/Voice.cpp.o"

# External object files for target SharedMemory
SharedMemory_EXTERNAL_OBJECTS =

SharedMemory/libSharedMemory.so: SharedMemory/CMakeFiles/SharedMemory.dir/Arm.cpp.o
SharedMemory/libSharedMemory.so: SharedMemory/CMakeFiles/SharedMemory.dir/ConfigFile.cpp.o
SharedMemory/libSharedMemory.so: SharedMemory/CMakeFiles/SharedMemory.dir/Kinect.cpp.o
SharedMemory/libSharedMemory.so: SharedMemory/CMakeFiles/SharedMemory.dir/Destination.cpp.o
SharedMemory/libSharedMemory.so: SharedMemory/CMakeFiles/SharedMemory.dir/PTZ.cpp.o
SharedMemory/libSharedMemory.so: SharedMemory/CMakeFiles/SharedMemory.dir/Laser.cpp.o
SharedMemory/libSharedMemory.so: SharedMemory/CMakeFiles/SharedMemory.dir/Location.cpp.o
SharedMemory/libSharedMemory.so: SharedMemory/CMakeFiles/SharedMemory.dir/Map.cpp.o
SharedMemory/libSharedMemory.so: SharedMemory/CMakeFiles/SharedMemory.dir/Objective.cpp.o
SharedMemory/libSharedMemory.so: SharedMemory/CMakeFiles/SharedMemory.dir/SharedMemory.cpp.o
SharedMemory/libSharedMemory.so: SharedMemory/CMakeFiles/SharedMemory.dir/Synthesis.cpp.o
SharedMemory/libSharedMemory.so: SharedMemory/CMakeFiles/SharedMemory.dir/Voice.cpp.o
SharedMemory/libSharedMemory.so: /usr/local/lib/libopencv_calib3d.so
SharedMemory/libSharedMemory.so: /usr/local/lib/libopencv_contrib.so
SharedMemory/libSharedMemory.so: /usr/local/lib/libopencv_core.so
SharedMemory/libSharedMemory.so: /usr/local/lib/libopencv_features2d.so
SharedMemory/libSharedMemory.so: /usr/local/lib/libopencv_flann.so
SharedMemory/libSharedMemory.so: /usr/local/lib/libopencv_gpu.so
SharedMemory/libSharedMemory.so: /usr/local/lib/libopencv_highgui.so
SharedMemory/libSharedMemory.so: /usr/local/lib/libopencv_imgproc.so
SharedMemory/libSharedMemory.so: /usr/local/lib/libopencv_legacy.so
SharedMemory/libSharedMemory.so: /usr/local/lib/libopencv_ml.so
SharedMemory/libSharedMemory.so: /usr/local/lib/libopencv_nonfree.so
SharedMemory/libSharedMemory.so: /usr/local/lib/libopencv_objdetect.so
SharedMemory/libSharedMemory.so: /usr/local/lib/libopencv_photo.so
SharedMemory/libSharedMemory.so: /usr/local/lib/libopencv_stitching.so
SharedMemory/libSharedMemory.so: /usr/local/lib/libopencv_superres.so
SharedMemory/libSharedMemory.so: /usr/local/lib/libopencv_ts.so
SharedMemory/libSharedMemory.so: /usr/local/lib/libopencv_video.so
SharedMemory/libSharedMemory.so: /usr/local/lib/libopencv_videostab.so
SharedMemory/libSharedMemory.so: SharedMemory/CMakeFiles/SharedMemory.dir/build.make
SharedMemory/libSharedMemory.so: SharedMemory/CMakeFiles/SharedMemory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libSharedMemory.so"
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SharedMemory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
SharedMemory/CMakeFiles/SharedMemory.dir/build: SharedMemory/libSharedMemory.so
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/build

SharedMemory/CMakeFiles/SharedMemory.dir/requires: SharedMemory/CMakeFiles/SharedMemory.dir/Arm.cpp.o.requires
SharedMemory/CMakeFiles/SharedMemory.dir/requires: SharedMemory/CMakeFiles/SharedMemory.dir/ConfigFile.cpp.o.requires
SharedMemory/CMakeFiles/SharedMemory.dir/requires: SharedMemory/CMakeFiles/SharedMemory.dir/Kinect.cpp.o.requires
SharedMemory/CMakeFiles/SharedMemory.dir/requires: SharedMemory/CMakeFiles/SharedMemory.dir/Destination.cpp.o.requires
SharedMemory/CMakeFiles/SharedMemory.dir/requires: SharedMemory/CMakeFiles/SharedMemory.dir/PTZ.cpp.o.requires
SharedMemory/CMakeFiles/SharedMemory.dir/requires: SharedMemory/CMakeFiles/SharedMemory.dir/Laser.cpp.o.requires
SharedMemory/CMakeFiles/SharedMemory.dir/requires: SharedMemory/CMakeFiles/SharedMemory.dir/Location.cpp.o.requires
SharedMemory/CMakeFiles/SharedMemory.dir/requires: SharedMemory/CMakeFiles/SharedMemory.dir/Map.cpp.o.requires
SharedMemory/CMakeFiles/SharedMemory.dir/requires: SharedMemory/CMakeFiles/SharedMemory.dir/Objective.cpp.o.requires
SharedMemory/CMakeFiles/SharedMemory.dir/requires: SharedMemory/CMakeFiles/SharedMemory.dir/SharedMemory.cpp.o.requires
SharedMemory/CMakeFiles/SharedMemory.dir/requires: SharedMemory/CMakeFiles/SharedMemory.dir/Synthesis.cpp.o.requires
SharedMemory/CMakeFiles/SharedMemory.dir/requires: SharedMemory/CMakeFiles/SharedMemory.dir/Voice.cpp.o.requires
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/requires

SharedMemory/CMakeFiles/SharedMemory.dir/clean:
	cd /home/markovito/projects/Sabina2014/build/SharedMemory && $(CMAKE_COMMAND) -P CMakeFiles/SharedMemory.dir/cmake_clean.cmake
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/clean

SharedMemory/CMakeFiles/SharedMemory.dir/depend:
	cd /home/markovito/projects/Sabina2014/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/markovito/projects/Sabina2014 /home/markovito/projects/Sabina2014/SharedMemory /home/markovito/projects/Sabina2014/build /home/markovito/projects/Sabina2014/build/SharedMemory /home/markovito/projects/Sabina2014/build/SharedMemory/CMakeFiles/SharedMemory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : SharedMemory/CMakeFiles/SharedMemory.dir/depend

