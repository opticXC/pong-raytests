cmake_minimum_required(VERSION 3.6)

project(pong)

add_subdirectory(libs/raylib)
add_executable( ${PROJECT_NAME}
    src/main.c
    src/paddle.c
    src/ball.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

if (CMAKE_BUILD_TOOL STREQUAL "Release")
    add_compile_definitions(${PROJECT_NAME} PUBLIC RELEASE_BUILD=true)
endif()