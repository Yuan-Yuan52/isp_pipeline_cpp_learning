cmake_minimum_required(VERSION 3.10)
project(ISP_Pipeline)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXE_LINKER_FLAGS "-static")

set(OpenCV_DIR "C:/opencv_final")

find_package(OpenCV REQUIRED)

include_directories(include)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(isp_pipeline 
    main.cpp
    src/image.cpp
    src/raw_image.cpp
)

target_link_libraries(isp_pipeline ${OpenCV_LIBS})