cmake_minimum_required(VERSION 3.0)
project(mUI)
<<<<<<< HEAD
set(CMAKE_CXX_STANDARD 20)
add_executable(mUI main.cpp )
=======
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OpenGL_GL_PREFERENCE GLVND)

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

find_package(glm REQUIRED)
if (GLM_FOUND)
    include_directories(${GLM_INCLUDE_DIRS})
    link_libraries(     ${GLM_LIBRARIES})
endif()

add_executable(mUI main.cpp
        src/window/Window.cpp src/window/Window.h
        src/graphics/Color.cpp src/graphics/Color.h
        src/graphics/GDriver.h
        src/graphics/Shader.cpp src/graphics/Shader.h
        src/sTypes.h)
>>>>>>> dev
