add_executable(camera_client_smoke_test
    smoke_test.cpp
    ../src/system_info.cpp
)

target_include_directories(camera_client_smoke_test
    PRIVATE
        ../include
)

add_test(NAME camera_client_smoke_test COMMAND camera_client_smoke_test)
