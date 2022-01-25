cmake_minimum_required(VERSION 3.0)

project(mUI VERSION 0.6.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("./bgfx.cmake/")
include_directories(src)

set(CODE
  src/mUI.h
  src/types.h

  src/app/Activity.h
  src/app/App.h
  src/app/Logger.h
  src/app/Theme.h

  src/graphics/core/Color.h
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
