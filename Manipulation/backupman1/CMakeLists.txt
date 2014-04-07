cmake_minimum_required(VERSION 2.8)
PROJECT(Manipulation)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../lib)

find_package(MRPT)

link_directories(${PROJECT_SOURCE_DIR}/../Manipulation/lib)

set(LIBRARY_DIR ${PROJECT_SOURCE_DIR}/../Manipulation/lib)
set(BASE_LIBRARY ${LIBRARY_DIR}/libKNIBase.a)
set(KINE_LIBRARY ${LIBRARY_DIR}/libKinematics.a)
set(INVKIN_LIBRARY ${LIBRARY_DIR}/libKNI_InvKin.a)
set(LM_LIBRARY ${LIBRARY_DIR}/libKNI_LM.a)
set(KATANA_LIBRARIES ${LM_LIBRARY} ${INVKIN_LIBRARY} ${KINE_LIBRARY} ${BASE_LIBRARY} )

include_directories(${MRPT_INCLUDE_DIRS})


add_library(Manipulation SHARED  main.cpp  armkatana.cpp armkatanaforsabina.cpp kintoarmtransf.cpp )
target_link_libraries(Manipulation ${CMAKE_THREAD_LIBS_INIT}  ${KATANA_LIBRARIES}  ${LIBS_MRPT} )
