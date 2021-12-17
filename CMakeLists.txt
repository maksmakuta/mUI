cmake_minimum_required(VERSION 3.10)
project(mUI VERSION 0.6.0)

set(LIBRARY_NAME   ${PROJECT_NAME})
set(LIBRARY_FOLDER ${PROJECT_NAME})

include(${PROJECT_SOURCE_DIR}/cmake/SetEnv.cmake)
add_subdirectory(${LIBRARY_FOLDER})
add_subdirectory(example)

# taken from https://github.com/pablospe/cmake-example-library
