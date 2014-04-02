PROJECT(NavigationClient)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../lib)

include_directories(/usr/local/Arnl/include/ArNetworking)
include_directories(/usr/local/Arnl/include/Aria)

link_directories(/usr/local/Arnl/lib/)

add_library(NavigationClient SHARED main.cpp)

target_link_libraries(NavigationClient AriaForArnl ArNetworkingForArnl rt ${CMAKE_THREAD_LIBS_INIT} )
