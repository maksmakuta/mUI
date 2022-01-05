cmake_minimum_required(VERSION 3.20)

project(mUI VERSION 0.6.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "clang++")
set(OpenGL_GL_PREFERENCE GLVND)

find_package(Vulkan REQUIRED FAILURE)
if (VULKAN_FOUND)
    include_directories(${VULKAN_INCLUDE_DIRS})
    link_libraries(     ${VULKAN_LIBRARIES})
endif()

find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIRS})
    link_libraries(     ${OPENGL_LIBRARIES})
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

include_directories(src)

set(CODE
  src/mUI.h
  src/types.h

  src/app/Activity.h
  src/app/App.h
  src/app/Logger.h
  src/app/Theme.h


  src/graphics/core/Color.h
  src/graphics/gl/GLRenderer.h
  src/graphics/gl/glShader.h
  src/graphics/vk/VKRenderer.h
  src/graphics/Window.h
  src/graphics/Canvas.h
  src/graphics/Canvas.cpp

  src/view/View.h

  src/widget/layout/LinearLayout.h
  src/widget/layout/GridLayout.h
  src/widget/layout/ListLayout.h
  src/widget/layout/RelativeLayout.h
  src/widget/layout/ScrollLayout.h
  src/widget/AppBar.h
  src/widget/Button.h
  src/widget/CardView.h
  src/widget/EditText.h
  src/widget/CheckBox.h
  src/widget/EditText.h
  src/widget/ImageView.h
  src/widget/ProgressView.h
  src/widget/Slider.h
  src/widget/Switch.h
  src/widget/TextView.h
  src/widget/ToolBar.h
)

add_library(mUI SHARED ${CODE})
add_executable(mApp main.cpp)
target_link_libraries(mApp mUI)
