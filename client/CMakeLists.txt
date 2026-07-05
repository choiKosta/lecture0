cmake_minimum_required(VERSION 3.20)

project(CameraClient
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_TESTING "Build client tests" ON)

add_executable(camera_client
    src/main.cpp
    src/system_info.cpp
)

target_include_directories(camera_client
    PRIVATE
        include
)

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()
