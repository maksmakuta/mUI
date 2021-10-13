cmake_minimum_required(VERSION 3.0)
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
        src/graphics/nanovg/fontstash.h
        src/graphics/nanovg/nanovg.c
        src/graphics/nanovg/nanovg.h
        src/graphics/nanovg/nanovg_gl.h
        src/graphics/nanovg/nanovg_gl_utils.h
        src/graphics/nanovg/stb_image.h
        src/graphics/nanovg/stb_truetype.h
        src/graphics/Canvas.cpp src/graphics/Canvas.h
        src/view/View.cpp src/view/View.h
        src/app/Application.cpp src/app/Application.h
<<<<<<< Updated upstream
<<<<<<< HEAD
<<<<<<< HEAD
        src/app/Activity.cpp src/app/Activity.h)
>>>>>>> dev
=======
        src/app/Activity.cpp src/app/Activity.h src/graphics/Rect.cpp src/graphics/Rect.h src/view/listener/Listener.h src/view/listener/OnClickListener.h)
>>>>>>> stable
=======
        src/app/Activity.cpp src/app/Activity.h)
>>>>>>> parent of 9481cdf... [1.3.3] ad mouse callbacks
=======
        src/app/Activity.cpp src/app/Activity.h)
>>>>>>> Stashed changes
