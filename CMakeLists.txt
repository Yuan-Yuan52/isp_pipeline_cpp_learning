cmake_minimum_required(VERSION 3.10)
project(ISP_Pipeline)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXE_LINKER_FLAGS "-static")

include_directories(include)

add_executable(isp_pipeline 
    main.cpp
    src/Image.cpp
    src/raw_image.cpp
)