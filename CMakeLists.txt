cmake_minimum_required(VERSION 3.6)

set(PROJECT_NAME OpenCV-FaceDetectionApp)

project(${PROJECT_NAME} VERSION 1.0)
add_executable( ${PROJECT_NAME} 
    src/main.cpp 
    src/Detectors/FaceDetector.cpp
)

find_package(OpenCV REQUIRED)

if( OpenCV_FOUND )
    include_directories( ${OpenCV_INCLUDE_DIRS} )
    link_directories( ${OpenCV_LIB_DIR} )
    target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )
endif()

set(FACE_DETECTION_CONFIGURATION "${PROJECT_SOURCE_DIR}/assets/deploy.prototxt")
set(FACE_DETECTION_WEIGHTS "${PROJECT_SOURCE_DIR}/assets/res10_300x300_ssd_iter_140000_fp16.caffemodel")

target_compile_definitions(${PROJECT_NAME} PRIVATE FACE_DETECTION_CONFIGURATION="${FACE_DETECTION_CONFIGURATION}")
target_compile_definitions(${PROJECT_NAME} PRIVATE FACE_DETECTION_WEIGHTS="${FACE_DETECTION_WEIGHTS}")