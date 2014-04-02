cmake_minimum_required(VERSION 2.8)
PROJECT(Kinect)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../lib)

include_directories(/usr/include/ni)
include_directories(/usr/include/nite)

find_package( OpenCV REQUIRED )

add_library(Kinect SHARED main.cpp Ni_Device.cpp )

set(NITE_LIBS OpenNI XnVNite_1_5_2)
target_link_libraries(Kinect ${NITE_LIBS}  ${OpenCV_LIBS}  )

