cmake_minimum_required(VERSION 3.15)
project(pong)

find_package(raylib 3.0 REQUIRED)

set(CMAKE_CXX_STANARD 17)

add_executable(pong 
    src/main.cpp
    src/paddle.cpp
    src/ball.cpp)

target_link_libraries(pong raylib)
