cmake_minimum_required(VERSION 3.20)
project(example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(example main.cpp)

target_link_libraries(example mUI)
