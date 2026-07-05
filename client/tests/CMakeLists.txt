add_executable(camera_client_smoke_test
    smoke_test.cpp
)

target_link_libraries(camera_client_smoke_test
    PRIVATE
        camera_client_core
)

add_test(NAME camera_client_smoke_test COMMAND camera_client_smoke_test)
