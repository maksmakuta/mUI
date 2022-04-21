cmake_minimum_required(VERSION 3.10)

project(mApp VERSION 0.7.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib)

add_executable(mApp main.cpp)
target_link_libraries(mApp PUBLIC mUI)
target_include_directories(mApp PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib"
                          )
