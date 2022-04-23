cmake_minimum_required(VERSION 3.10)

project(mUI VERSION 0.7.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(OpenGL_GL_PREFERENCE GLVND)

###################################
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
###################################

include_directories(include)

set(INC
    include/app/Application.h
    include/app/Activity.h

    include/graphics/Canvas.h
    include/graphics/Window.h

    include/graphics/nanovg/fontstash.h
    include/graphics/nanovg/nanosvg.h
    include/graphics/nanovg/nanosvgrast.h
    include/graphics/nanovg/nanovg.h
    include/graphics/nanovg/nanovg_gl.h
    include/graphics/nanovg/nanovg_gl_utils.h

    include/utils/Logger.h
    include/utils/TypeUtils.h

    include/view/View.h

    include/mUI.h
)

set(SRC
    src/app/Application.cpp
    src/app/Activity.cpp

    src/graphics/Canvas.cpp
    src/graphics/Window.cpp

    src/graphics/nanovg/nanosvg.c
    src/graphics/nanovg/nanosvgrast.c
    src/graphics/nanovg/nanovg.c
    src/graphics/nanovg/nanovg_gl.c
    src/graphics/nanovg/nanovg_gl_utils.c

    src/utils/Logger.cpp

    src/view/View.cpp
)

add_library(mUI SHARED ${INC} ${SRC})
target_include_directories(mUI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS mUI DESTINATION lib)
install(FILES ${INC} DESTINATION include)

