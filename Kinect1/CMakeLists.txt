cmake_minimum_required(VERSION 2.8)
PROJECT(Kinect)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../lib)

include_directories(/usr/include/ni)

find_package( OpenCV REQUIRED )

add_library(Kinect SHARED main.cpp Ni_Device.cpp )
target_link_libraries(Kinect OpenNI ${OpenCV_LIBS}  )

