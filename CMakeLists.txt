cmake_minimum_required(VERSION 3.20)

project(mUI VERSION 0.6.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIRS})
    link_libraries(${OPENGL_LIBRARIES})
endif()

###################################
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(     ${GLFW_LIBRARIES})
link_libraries(     ${GLFW_STATIC_LIBRARIES})
###################################

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(     ${GLEW_LIBRARIES})
endif()

set(CODE
  src/mUI.h
)

add_library(mUI SHARED ${CODE})
set_target_properties(mUI PROPERTIES LINKER_LANGUAGE CXX)
add_subdirectory(example)
