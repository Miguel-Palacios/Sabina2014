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
include FaceRecognition/CMakeFiles/FaceRecognition.dir/depend.make

# Include the progress variables for this target.
include FaceRecognition/CMakeFiles/FaceRecognition.dir/progress.make

# Include the compile flags for this target's objects.
include FaceRecognition/CMakeFiles/FaceRecognition.dir/flags.make

FaceRecognition/CMakeFiles/FaceRecognition.dir/main.cpp.o: FaceRecognition/CMakeFiles/FaceRecognition.dir/flags.make
FaceRecognition/CMakeFiles/FaceRecognition.dir/main.cpp.o: ../FaceRecognition/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object FaceRecognition/CMakeFiles/FaceRecognition.dir/main.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FaceRecognition.dir/main.cpp.o -c /home/markovito/projects/Sabina2014/FaceRecognition/main.cpp

FaceRecognition/CMakeFiles/FaceRecognition.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FaceRecognition.dir/main.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/FaceRecognition/main.cpp > CMakeFiles/FaceRecognition.dir/main.cpp.i

FaceRecognition/CMakeFiles/FaceRecognition.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FaceRecognition.dir/main.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/FaceRecognition/main.cpp -o CMakeFiles/FaceRecognition.dir/main.cpp.s

FaceRecognition/CMakeFiles/FaceRecognition.dir/main.cpp.o.requires:
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/main.cpp.o.requires

FaceRecognition/CMakeFiles/FaceRecognition.dir/main.cpp.o.provides: FaceRecognition/CMakeFiles/FaceRecognition.dir/main.cpp.o.requires
	$(MAKE) -f FaceRecognition/CMakeFiles/FaceRecognition.dir/build.make FaceRecognition/CMakeFiles/FaceRecognition.dir/main.cpp.o.provides.build
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/main.cpp.o.provides

FaceRecognition/CMakeFiles/FaceRecognition.dir/main.cpp.o.provides.build: FaceRecognition/CMakeFiles/FaceRecognition.dir/main.cpp.o

FaceRecognition/CMakeFiles/FaceRecognition.dir/sift.cpp.o: FaceRecognition/CMakeFiles/FaceRecognition.dir/flags.make
FaceRecognition/CMakeFiles/FaceRecognition.dir/sift.cpp.o: ../FaceRecognition/sift.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object FaceRecognition/CMakeFiles/FaceRecognition.dir/sift.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FaceRecognition.dir/sift.cpp.o -c /home/markovito/projects/Sabina2014/FaceRecognition/sift.cpp

FaceRecognition/CMakeFiles/FaceRecognition.dir/sift.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FaceRecognition.dir/sift.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/FaceRecognition/sift.cpp > CMakeFiles/FaceRecognition.dir/sift.cpp.i

FaceRecognition/CMakeFiles/FaceRecognition.dir/sift.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FaceRecognition.dir/sift.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/FaceRecognition/sift.cpp -o CMakeFiles/FaceRecognition.dir/sift.cpp.s

FaceRecognition/CMakeFiles/FaceRecognition.dir/sift.cpp.o.requires:
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/sift.cpp.o.requires

FaceRecognition/CMakeFiles/FaceRecognition.dir/sift.cpp.o.provides: FaceRecognition/CMakeFiles/FaceRecognition.dir/sift.cpp.o.requires
	$(MAKE) -f FaceRecognition/CMakeFiles/FaceRecognition.dir/build.make FaceRecognition/CMakeFiles/FaceRecognition.dir/sift.cpp.o.provides.build
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/sift.cpp.o.provides

FaceRecognition/CMakeFiles/FaceRecognition.dir/sift.cpp.o.provides.build: FaceRecognition/CMakeFiles/FaceRecognition.dir/sift.cpp.o

FaceRecognition/CMakeFiles/FaceRecognition.dir/facedetect.cpp.o: FaceRecognition/CMakeFiles/FaceRecognition.dir/flags.make
FaceRecognition/CMakeFiles/FaceRecognition.dir/facedetect.cpp.o: ../FaceRecognition/facedetect.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object FaceRecognition/CMakeFiles/FaceRecognition.dir/facedetect.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FaceRecognition.dir/facedetect.cpp.o -c /home/markovito/projects/Sabina2014/FaceRecognition/facedetect.cpp

FaceRecognition/CMakeFiles/FaceRecognition.dir/facedetect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FaceRecognition.dir/facedetect.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/FaceRecognition/facedetect.cpp > CMakeFiles/FaceRecognition.dir/facedetect.cpp.i

FaceRecognition/CMakeFiles/FaceRecognition.dir/facedetect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FaceRecognition.dir/facedetect.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/FaceRecognition/facedetect.cpp -o CMakeFiles/FaceRecognition.dir/facedetect.cpp.s

FaceRecognition/CMakeFiles/FaceRecognition.dir/facedetect.cpp.o.requires:
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/facedetect.cpp.o.requires

FaceRecognition/CMakeFiles/FaceRecognition.dir/facedetect.cpp.o.provides: FaceRecognition/CMakeFiles/FaceRecognition.dir/facedetect.cpp.o.requires
	$(MAKE) -f FaceRecognition/CMakeFiles/FaceRecognition.dir/build.make FaceRecognition/CMakeFiles/FaceRecognition.dir/facedetect.cpp.o.provides.build
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/facedetect.cpp.o.provides

FaceRecognition/CMakeFiles/FaceRecognition.dir/facedetect.cpp.o.provides.build: FaceRecognition/CMakeFiles/FaceRecognition.dir/facedetect.cpp.o

FaceRecognition/CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.o: FaceRecognition/CMakeFiles/FaceRecognition.dir/flags.make
FaceRecognition/CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.o: ../FaceRecognition/imgfeatures.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object FaceRecognition/CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.o -c /home/markovito/projects/Sabina2014/FaceRecognition/imgfeatures.cpp

FaceRecognition/CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/FaceRecognition/imgfeatures.cpp > CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.i

FaceRecognition/CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/FaceRecognition/imgfeatures.cpp -o CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.s

FaceRecognition/CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.o.requires:
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.o.requires

FaceRecognition/CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.o.provides: FaceRecognition/CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.o.requires
	$(MAKE) -f FaceRecognition/CMakeFiles/FaceRecognition.dir/build.make FaceRecognition/CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.o.provides.build
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.o.provides

FaceRecognition/CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.o.provides.build: FaceRecognition/CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.o

FaceRecognition/CMakeFiles/FaceRecognition.dir/kdtree.cpp.o: FaceRecognition/CMakeFiles/FaceRecognition.dir/flags.make
FaceRecognition/CMakeFiles/FaceRecognition.dir/kdtree.cpp.o: ../FaceRecognition/kdtree.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object FaceRecognition/CMakeFiles/FaceRecognition.dir/kdtree.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FaceRecognition.dir/kdtree.cpp.o -c /home/markovito/projects/Sabina2014/FaceRecognition/kdtree.cpp

FaceRecognition/CMakeFiles/FaceRecognition.dir/kdtree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FaceRecognition.dir/kdtree.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/FaceRecognition/kdtree.cpp > CMakeFiles/FaceRecognition.dir/kdtree.cpp.i

FaceRecognition/CMakeFiles/FaceRecognition.dir/kdtree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FaceRecognition.dir/kdtree.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/FaceRecognition/kdtree.cpp -o CMakeFiles/FaceRecognition.dir/kdtree.cpp.s

FaceRecognition/CMakeFiles/FaceRecognition.dir/kdtree.cpp.o.requires:
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/kdtree.cpp.o.requires

FaceRecognition/CMakeFiles/FaceRecognition.dir/kdtree.cpp.o.provides: FaceRecognition/CMakeFiles/FaceRecognition.dir/kdtree.cpp.o.requires
	$(MAKE) -f FaceRecognition/CMakeFiles/FaceRecognition.dir/build.make FaceRecognition/CMakeFiles/FaceRecognition.dir/kdtree.cpp.o.provides.build
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/kdtree.cpp.o.provides

FaceRecognition/CMakeFiles/FaceRecognition.dir/kdtree.cpp.o.provides.build: FaceRecognition/CMakeFiles/FaceRecognition.dir/kdtree.cpp.o

FaceRecognition/CMakeFiles/FaceRecognition.dir/minpq.cpp.o: FaceRecognition/CMakeFiles/FaceRecognition.dir/flags.make
FaceRecognition/CMakeFiles/FaceRecognition.dir/minpq.cpp.o: ../FaceRecognition/minpq.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object FaceRecognition/CMakeFiles/FaceRecognition.dir/minpq.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FaceRecognition.dir/minpq.cpp.o -c /home/markovito/projects/Sabina2014/FaceRecognition/minpq.cpp

FaceRecognition/CMakeFiles/FaceRecognition.dir/minpq.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FaceRecognition.dir/minpq.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/FaceRecognition/minpq.cpp > CMakeFiles/FaceRecognition.dir/minpq.cpp.i

FaceRecognition/CMakeFiles/FaceRecognition.dir/minpq.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FaceRecognition.dir/minpq.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/FaceRecognition/minpq.cpp -o CMakeFiles/FaceRecognition.dir/minpq.cpp.s

FaceRecognition/CMakeFiles/FaceRecognition.dir/minpq.cpp.o.requires:
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/minpq.cpp.o.requires

FaceRecognition/CMakeFiles/FaceRecognition.dir/minpq.cpp.o.provides: FaceRecognition/CMakeFiles/FaceRecognition.dir/minpq.cpp.o.requires
	$(MAKE) -f FaceRecognition/CMakeFiles/FaceRecognition.dir/build.make FaceRecognition/CMakeFiles/FaceRecognition.dir/minpq.cpp.o.provides.build
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/minpq.cpp.o.provides

FaceRecognition/CMakeFiles/FaceRecognition.dir/minpq.cpp.o.provides.build: FaceRecognition/CMakeFiles/FaceRecognition.dir/minpq.cpp.o

FaceRecognition/CMakeFiles/FaceRecognition.dir/utils.cpp.o: FaceRecognition/CMakeFiles/FaceRecognition.dir/flags.make
FaceRecognition/CMakeFiles/FaceRecognition.dir/utils.cpp.o: ../FaceRecognition/utils.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object FaceRecognition/CMakeFiles/FaceRecognition.dir/utils.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FaceRecognition.dir/utils.cpp.o -c /home/markovito/projects/Sabina2014/FaceRecognition/utils.cpp

FaceRecognition/CMakeFiles/FaceRecognition.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FaceRecognition.dir/utils.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/FaceRecognition/utils.cpp > CMakeFiles/FaceRecognition.dir/utils.cpp.i

FaceRecognition/CMakeFiles/FaceRecognition.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FaceRecognition.dir/utils.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/FaceRecognition/utils.cpp -o CMakeFiles/FaceRecognition.dir/utils.cpp.s

FaceRecognition/CMakeFiles/FaceRecognition.dir/utils.cpp.o.requires:
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/utils.cpp.o.requires

FaceRecognition/CMakeFiles/FaceRecognition.dir/utils.cpp.o.provides: FaceRecognition/CMakeFiles/FaceRecognition.dir/utils.cpp.o.requires
	$(MAKE) -f FaceRecognition/CMakeFiles/FaceRecognition.dir/build.make FaceRecognition/CMakeFiles/FaceRecognition.dir/utils.cpp.o.provides.build
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/utils.cpp.o.provides

FaceRecognition/CMakeFiles/FaceRecognition.dir/utils.cpp.o.provides.build: FaceRecognition/CMakeFiles/FaceRecognition.dir/utils.cpp.o

FaceRecognition/CMakeFiles/FaceRecognition.dir/learn.cpp.o: FaceRecognition/CMakeFiles/FaceRecognition.dir/flags.make
FaceRecognition/CMakeFiles/FaceRecognition.dir/learn.cpp.o: ../FaceRecognition/learn.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object FaceRecognition/CMakeFiles/FaceRecognition.dir/learn.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FaceRecognition.dir/learn.cpp.o -c /home/markovito/projects/Sabina2014/FaceRecognition/learn.cpp

FaceRecognition/CMakeFiles/FaceRecognition.dir/learn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FaceRecognition.dir/learn.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/FaceRecognition/learn.cpp > CMakeFiles/FaceRecognition.dir/learn.cpp.i

FaceRecognition/CMakeFiles/FaceRecognition.dir/learn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FaceRecognition.dir/learn.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/FaceRecognition/learn.cpp -o CMakeFiles/FaceRecognition.dir/learn.cpp.s

FaceRecognition/CMakeFiles/FaceRecognition.dir/learn.cpp.o.requires:
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/learn.cpp.o.requires

FaceRecognition/CMakeFiles/FaceRecognition.dir/learn.cpp.o.provides: FaceRecognition/CMakeFiles/FaceRecognition.dir/learn.cpp.o.requires
	$(MAKE) -f FaceRecognition/CMakeFiles/FaceRecognition.dir/build.make FaceRecognition/CMakeFiles/FaceRecognition.dir/learn.cpp.o.provides.build
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/learn.cpp.o.provides

FaceRecognition/CMakeFiles/FaceRecognition.dir/learn.cpp.o.provides.build: FaceRecognition/CMakeFiles/FaceRecognition.dir/learn.cpp.o

FaceRecognition/CMakeFiles/FaceRecognition.dir/load.cpp.o: FaceRecognition/CMakeFiles/FaceRecognition.dir/flags.make
FaceRecognition/CMakeFiles/FaceRecognition.dir/load.cpp.o: ../FaceRecognition/load.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object FaceRecognition/CMakeFiles/FaceRecognition.dir/load.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FaceRecognition.dir/load.cpp.o -c /home/markovito/projects/Sabina2014/FaceRecognition/load.cpp

FaceRecognition/CMakeFiles/FaceRecognition.dir/load.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FaceRecognition.dir/load.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/FaceRecognition/load.cpp > CMakeFiles/FaceRecognition.dir/load.cpp.i

FaceRecognition/CMakeFiles/FaceRecognition.dir/load.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FaceRecognition.dir/load.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/FaceRecognition/load.cpp -o CMakeFiles/FaceRecognition.dir/load.cpp.s

FaceRecognition/CMakeFiles/FaceRecognition.dir/load.cpp.o.requires:
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/load.cpp.o.requires

FaceRecognition/CMakeFiles/FaceRecognition.dir/load.cpp.o.provides: FaceRecognition/CMakeFiles/FaceRecognition.dir/load.cpp.o.requires
	$(MAKE) -f FaceRecognition/CMakeFiles/FaceRecognition.dir/build.make FaceRecognition/CMakeFiles/FaceRecognition.dir/load.cpp.o.provides.build
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/load.cpp.o.provides

FaceRecognition/CMakeFiles/FaceRecognition.dir/load.cpp.o.provides.build: FaceRecognition/CMakeFiles/FaceRecognition.dir/load.cpp.o

FaceRecognition/CMakeFiles/FaceRecognition.dir/tratamiento.cpp.o: FaceRecognition/CMakeFiles/FaceRecognition.dir/flags.make
FaceRecognition/CMakeFiles/FaceRecognition.dir/tratamiento.cpp.o: ../FaceRecognition/tratamiento.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object FaceRecognition/CMakeFiles/FaceRecognition.dir/tratamiento.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FaceRecognition.dir/tratamiento.cpp.o -c /home/markovito/projects/Sabina2014/FaceRecognition/tratamiento.cpp

FaceRecognition/CMakeFiles/FaceRecognition.dir/tratamiento.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FaceRecognition.dir/tratamiento.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/FaceRecognition/tratamiento.cpp > CMakeFiles/FaceRecognition.dir/tratamiento.cpp.i

FaceRecognition/CMakeFiles/FaceRecognition.dir/tratamiento.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FaceRecognition.dir/tratamiento.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/FaceRecognition/tratamiento.cpp -o CMakeFiles/FaceRecognition.dir/tratamiento.cpp.s

FaceRecognition/CMakeFiles/FaceRecognition.dir/tratamiento.cpp.o.requires:
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/tratamiento.cpp.o.requires

FaceRecognition/CMakeFiles/FaceRecognition.dir/tratamiento.cpp.o.provides: FaceRecognition/CMakeFiles/FaceRecognition.dir/tratamiento.cpp.o.requires
	$(MAKE) -f FaceRecognition/CMakeFiles/FaceRecognition.dir/build.make FaceRecognition/CMakeFiles/FaceRecognition.dir/tratamiento.cpp.o.provides.build
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/tratamiento.cpp.o.provides

FaceRecognition/CMakeFiles/FaceRecognition.dir/tratamiento.cpp.o.provides.build: FaceRecognition/CMakeFiles/FaceRecognition.dir/tratamiento.cpp.o

FaceRecognition/CMakeFiles/FaceRecognition.dir/recognize.cpp.o: FaceRecognition/CMakeFiles/FaceRecognition.dir/flags.make
FaceRecognition/CMakeFiles/FaceRecognition.dir/recognize.cpp.o: ../FaceRecognition/recognize.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/markovito/projects/Sabina2014/build/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object FaceRecognition/CMakeFiles/FaceRecognition.dir/recognize.cpp.o"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FaceRecognition.dir/recognize.cpp.o -c /home/markovito/projects/Sabina2014/FaceRecognition/recognize.cpp

FaceRecognition/CMakeFiles/FaceRecognition.dir/recognize.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FaceRecognition.dir/recognize.cpp.i"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/markovito/projects/Sabina2014/FaceRecognition/recognize.cpp > CMakeFiles/FaceRecognition.dir/recognize.cpp.i

FaceRecognition/CMakeFiles/FaceRecognition.dir/recognize.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FaceRecognition.dir/recognize.cpp.s"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/markovito/projects/Sabina2014/FaceRecognition/recognize.cpp -o CMakeFiles/FaceRecognition.dir/recognize.cpp.s

FaceRecognition/CMakeFiles/FaceRecognition.dir/recognize.cpp.o.requires:
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/recognize.cpp.o.requires

FaceRecognition/CMakeFiles/FaceRecognition.dir/recognize.cpp.o.provides: FaceRecognition/CMakeFiles/FaceRecognition.dir/recognize.cpp.o.requires
	$(MAKE) -f FaceRecognition/CMakeFiles/FaceRecognition.dir/build.make FaceRecognition/CMakeFiles/FaceRecognition.dir/recognize.cpp.o.provides.build
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/recognize.cpp.o.provides

FaceRecognition/CMakeFiles/FaceRecognition.dir/recognize.cpp.o.provides.build: FaceRecognition/CMakeFiles/FaceRecognition.dir/recognize.cpp.o

# Object files for target FaceRecognition
FaceRecognition_OBJECTS = \
"CMakeFiles/FaceRecognition.dir/main.cpp.o" \
"CMakeFiles/FaceRecognition.dir/sift.cpp.o" \
"CMakeFiles/FaceRecognition.dir/facedetect.cpp.o" \
"CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.o" \
"CMakeFiles/FaceRecognition.dir/kdtree.cpp.o" \
"CMakeFiles/FaceRecognition.dir/minpq.cpp.o" \
"CMakeFiles/FaceRecognition.dir/utils.cpp.o" \
"CMakeFiles/FaceRecognition.dir/learn.cpp.o" \
"CMakeFiles/FaceRecognition.dir/load.cpp.o" \
"CMakeFiles/FaceRecognition.dir/tratamiento.cpp.o" \
"CMakeFiles/FaceRecognition.dir/recognize.cpp.o"

# External object files for target FaceRecognition
FaceRecognition_EXTERNAL_OBJECTS =

lib/libFaceRecognition.so: FaceRecognition/CMakeFiles/FaceRecognition.dir/main.cpp.o
lib/libFaceRecognition.so: FaceRecognition/CMakeFiles/FaceRecognition.dir/sift.cpp.o
lib/libFaceRecognition.so: FaceRecognition/CMakeFiles/FaceRecognition.dir/facedetect.cpp.o
lib/libFaceRecognition.so: FaceRecognition/CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.o
lib/libFaceRecognition.so: FaceRecognition/CMakeFiles/FaceRecognition.dir/kdtree.cpp.o
lib/libFaceRecognition.so: FaceRecognition/CMakeFiles/FaceRecognition.dir/minpq.cpp.o
lib/libFaceRecognition.so: FaceRecognition/CMakeFiles/FaceRecognition.dir/utils.cpp.o
lib/libFaceRecognition.so: FaceRecognition/CMakeFiles/FaceRecognition.dir/learn.cpp.o
lib/libFaceRecognition.so: FaceRecognition/CMakeFiles/FaceRecognition.dir/load.cpp.o
lib/libFaceRecognition.so: FaceRecognition/CMakeFiles/FaceRecognition.dir/tratamiento.cpp.o
lib/libFaceRecognition.so: FaceRecognition/CMakeFiles/FaceRecognition.dir/recognize.cpp.o
lib/libFaceRecognition.so: SharedMemory/libSharedMemory.so
lib/libFaceRecognition.so: /usr/local/lib/libopencv_calib3d.so
lib/libFaceRecognition.so: /usr/local/lib/libopencv_contrib.so
lib/libFaceRecognition.so: /usr/local/lib/libopencv_core.so
lib/libFaceRecognition.so: /usr/local/lib/libopencv_features2d.so
lib/libFaceRecognition.so: /usr/local/lib/libopencv_flann.so
lib/libFaceRecognition.so: /usr/local/lib/libopencv_gpu.so
lib/libFaceRecognition.so: /usr/local/lib/libopencv_highgui.so
lib/libFaceRecognition.so: /usr/local/lib/libopencv_imgproc.so
lib/libFaceRecognition.so: /usr/local/lib/libopencv_legacy.so
lib/libFaceRecognition.so: /usr/local/lib/libopencv_ml.so
lib/libFaceRecognition.so: /usr/local/lib/libopencv_nonfree.so
lib/libFaceRecognition.so: /usr/local/lib/libopencv_objdetect.so
lib/libFaceRecognition.so: /usr/local/lib/libopencv_photo.so
lib/libFaceRecognition.so: /usr/local/lib/libopencv_stitching.so
lib/libFaceRecognition.so: /usr/local/lib/libopencv_superres.so
lib/libFaceRecognition.so: /usr/local/lib/libopencv_ts.so
lib/libFaceRecognition.so: /usr/local/lib/libopencv_video.so
lib/libFaceRecognition.so: /usr/local/lib/libopencv_videostab.so
lib/libFaceRecognition.so: FaceRecognition/CMakeFiles/FaceRecognition.dir/build.make
lib/libFaceRecognition.so: FaceRecognition/CMakeFiles/FaceRecognition.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../lib/libFaceRecognition.so"
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FaceRecognition.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
FaceRecognition/CMakeFiles/FaceRecognition.dir/build: lib/libFaceRecognition.so
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/build

FaceRecognition/CMakeFiles/FaceRecognition.dir/requires: FaceRecognition/CMakeFiles/FaceRecognition.dir/main.cpp.o.requires
FaceRecognition/CMakeFiles/FaceRecognition.dir/requires: FaceRecognition/CMakeFiles/FaceRecognition.dir/sift.cpp.o.requires
FaceRecognition/CMakeFiles/FaceRecognition.dir/requires: FaceRecognition/CMakeFiles/FaceRecognition.dir/facedetect.cpp.o.requires
FaceRecognition/CMakeFiles/FaceRecognition.dir/requires: FaceRecognition/CMakeFiles/FaceRecognition.dir/imgfeatures.cpp.o.requires
FaceRecognition/CMakeFiles/FaceRecognition.dir/requires: FaceRecognition/CMakeFiles/FaceRecognition.dir/kdtree.cpp.o.requires
FaceRecognition/CMakeFiles/FaceRecognition.dir/requires: FaceRecognition/CMakeFiles/FaceRecognition.dir/minpq.cpp.o.requires
FaceRecognition/CMakeFiles/FaceRecognition.dir/requires: FaceRecognition/CMakeFiles/FaceRecognition.dir/utils.cpp.o.requires
FaceRecognition/CMakeFiles/FaceRecognition.dir/requires: FaceRecognition/CMakeFiles/FaceRecognition.dir/learn.cpp.o.requires
FaceRecognition/CMakeFiles/FaceRecognition.dir/requires: FaceRecognition/CMakeFiles/FaceRecognition.dir/load.cpp.o.requires
FaceRecognition/CMakeFiles/FaceRecognition.dir/requires: FaceRecognition/CMakeFiles/FaceRecognition.dir/tratamiento.cpp.o.requires
FaceRecognition/CMakeFiles/FaceRecognition.dir/requires: FaceRecognition/CMakeFiles/FaceRecognition.dir/recognize.cpp.o.requires
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/requires

FaceRecognition/CMakeFiles/FaceRecognition.dir/clean:
	cd /home/markovito/projects/Sabina2014/build/FaceRecognition && $(CMAKE_COMMAND) -P CMakeFiles/FaceRecognition.dir/cmake_clean.cmake
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/clean

FaceRecognition/CMakeFiles/FaceRecognition.dir/depend:
	cd /home/markovito/projects/Sabina2014/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/markovito/projects/Sabina2014 /home/markovito/projects/Sabina2014/FaceRecognition /home/markovito/projects/Sabina2014/build /home/markovito/projects/Sabina2014/build/FaceRecognition /home/markovito/projects/Sabina2014/build/FaceRecognition/CMakeFiles/FaceRecognition.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : FaceRecognition/CMakeFiles/FaceRecognition.dir/depend

