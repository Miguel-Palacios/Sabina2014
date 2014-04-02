project(sabina)

# Declare the minimum version of cmake that we need
cmake_minimum_required(VERSION 2.8)


FIND_PACKAGE(FLTK REQUIRED)


add_subdirectory (Plugin_API)
add_subdirectory (SharedMemory)
add_subdirectory (NavigationClient)
add_subdirectory (VoiceRecognitionServer)
add_subdirectory (VoiceSynthesis)
add_subdirectory (Manipulation)
add_subdirectory (Kinect)
add_subdirectory (Vision_Objects)
add_subdirectory (Human)
add_subdirectory (GestureRecognition)
add_subdirectory (FaceRecognition)


add_executable(sabina main.cpp)

target_link_libraries(sabina  plugin Human SharedMemory fltk fltk_gl)

## Compiler flags
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-O2")        ## Optimize
    set(CMAKE_EXE_LINKER_FLAGS "-s")  ## Strip binary
endif()



