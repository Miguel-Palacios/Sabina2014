cmake_minimum_required(VERSION 2.8)
PROJECT(FaceRecognition)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../lib)

FIND_PACKAGE( OpenCV REQUIRED )

add_library(FaceRecognition SHARED main.cpp sift.cpp facedetect.cpp imgfeatures.cpp kdtree.cpp  minpq.cpp utils.cpp learn.cpp load.cpp tratamiento.cpp recognize.cpp )
target_link_libraries(FaceRecognition SharedMemory ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT} )

