cmake_minimum_required(VERSION 3.20)

project(CameraClient
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_TESTING "Build client tests" ON)

add_library(camera_client_core
    src/system_info.cpp
    src/server_interface/mock_server_gateway.cpp
    src/server_interface/server_gateway.cpp
    src/ui/client_controller.cpp
    src/ui/console_view.cpp
)

target_include_directories(camera_client_core
    PUBLIC
        include
)

add_executable(camera_client
    src/main.cpp
)

target_link_libraries(camera_client
    PRIVATE
        camera_client_core
)

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()
