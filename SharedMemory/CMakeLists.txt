
cmake_minimum_required(VERSION 2.8)
FIND_PACKAGE( OpenCV REQUIRED )

add_library (SharedMemory SHARED Arm.cpp ConfigFile.cpp Kinect.cpp Destination.cpp PTZ.cpp Laser.cpp Location.cpp Map.cpp Objective.cpp SharedMemory.cpp Synthesis.cpp Voice.cpp)

target_link_libraries (SharedMemory ${OpenCV_LIBS})