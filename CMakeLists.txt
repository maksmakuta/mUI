cmake_minimum_required(VERSION 3.10)

project(mUI VERSION 0.7.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

include_directories(src)

set(CODE
  src/mUI.h
  src/types.h
  src/app/Activity.h
  src/app/App.h
  src/app/Logger.h
  src/app/Theme.h
  src/graphics/utils/ColorUtils.h
  src/graphics/utils/MaterialIcons.h
  src/graphics/utils/MathUtils.h
  src/graphics/Window.h
  src/graphics/Canvas.h
  src/graphics/Canvas.cpp
  src/graphics/fontstash.h
  src/graphics/nanovg.c
  src/graphics/nanovg.h
  src/graphics/nanovg_gl.h
  src/graphics/nanovg_gl_utils.h
  src/graphics/stb_image.h
  src/graphics/stb_truetype.h
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

set_target_properties(mUI PROPERTIES LINKER_LANGUAGE CXX)
