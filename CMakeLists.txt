cmake_minimum_required(VERSION 3.20)
project(mUI)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(OpenGL_GL_PREFERENCE GLVND)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

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

add_executable(mUI main.cpp
        src/window/Window.cpp src/window/Window.h
        src/sTypes.h
        src/graphics/nanovg/fontstash.h
        src/graphics/nanovg/nanovg.c
        src/graphics/nanovg/nanovg.h
        src/graphics/nanovg/nanovg_gl.h
        src/graphics/nanovg/nanovg_gl_utils.h
        src/graphics/nanovg/stb_image.h
        src/graphics/nanovg/stb_truetype.h
        src/graphics/Canvas.cpp src/graphics/Canvas.h
        src/app/Application.cpp src/app/Application.h
        src/app/Activity.cpp src/app/Activity.h
        src/view/core/View.cpp src/view/core/View.h
        src/view/core/Layout.cpp src/view/core/Layout.h src/graphics/ColorUtils.cpp src/graphics/ColorUtils.h)
