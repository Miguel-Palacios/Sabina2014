cmake_minimum_required(VERSION 2.8)

PROJECT(GestureRecognition)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../lib)

#set(PRJ_NAME Kinect_HandControl)
#project(${PRJ_NAME} )

# -----------------------------  ARIA & NITE -----------------
include_directories(/usr/include/ni /usr/include/nite)
#link_directories(/home/luisgiii/documents/PatrickGentoo/NITE/Bin)
#set(LIBS_ARIA Aria ArNetworking rt dl pthread)
set(LIBS_NITE OpenNI XnVNite_1_5_2)

#add_executable(${PRJ_NAME} Robot.cpp HandControl.cpp main.cpp)

add_library(GestureRecognition SHARED main.cpp HandControl.cpp )

target_link_libraries(GestureRecognition ${LIBS_NITE})
