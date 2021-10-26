cmake_minimum_required(VERSION 3.20)
project(mUI)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(OpenGL_GL_PREFERENCE GLVND)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra ")
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

include_directories(/src)

add_executable(mUI main.cpp

        src/core/gl/fontstash.h
        src/core/gl/nanovg.c
        src/core/gl/nanovg.h
        src/core/gl/nanovg_gl.h
        src/core/gl/nanovg_gl_utils.h

        src/core/gl/stb_image.h
        src/core/gl/stb_truetype.h

        src/core/App.cpp src/core/App.h
        src/core/Window.cpp src/core/Window.h
        src/ui/core/View.cpp src/ui/core/View.h
        src/core/types.h
        src/core/gl/utils/ColorUtils.cpp src/core/gl/utils/ColorUtils.h
        src/core/gl/GL3Renderer.h
        src/core/Theme.cpp src/core/Theme.h
        src/core/Canvas.cpp src/core/Canvas.h
        src/core/utils/vec.h
        src/ui/core/Layout.cpp src/ui/core/Layout.h src/ui/core/Rect.cpp src/ui/core/Rect.h src/ui/core/Gravity.h src/ui/core/Visibility.h)