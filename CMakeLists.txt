cmake_minimum_required(VERSION 3.6)

# Configure Project

set(PROJECT_NAME OpenCV-intro)

project(${PROJECT_NAME} VERSION 1.0)
add_executable( ${PROJECT_NAME} src/main.cpp )

find_package(OpenCV REQUIRED)

if( OpenCV_FOUND )
    include_directories( ${OpenCV_INCLUDE_DIRS} )
    link_directories( ${OpenCV_LIB_DIR} )
    target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )
endif()