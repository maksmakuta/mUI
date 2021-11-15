set(SOURCES
  graphics/nanovg/nanovg.c
        graphics/Canvas.cpp
)

set(HEADERS_PUBLIC
  app/Activity.h
  app/App.h
  app/Theme.h

  graphics/nanovg/fontstash.h
  graphics/nanovg/nanosvg.h
  graphics/nanovg/nanovg.h
  graphics/nanovg/nanovg_gl.h
  graphics/nanovg/nanovg_gl_utils.h
  graphics/nanovg/stb_truetype.h
  graphics/nanovg/stb_image.h

  graphics/utils/ColorUtils.h
  graphics/utils/MathUtils.h
  graphics/utils/MaterialIcons.h

  graphics/Canvas.h
  graphics/Window.h

  view/listener/OnClickListener.h
  view/Margin.h
  view/Measure.h
  view/Rect.h
  view/View.h
  view/vec2.h

  widget/layout/LinearLayout.h
  widget/Button.h
  widget/EditText.h
  widget/IconButton.h
  widget/ImageView.h
  widget/RadioButton.h
  widget/Slider.h
  widget/SVGImage.h
  widget/Switch.h
  widget/TextView.h
  widget/ToolBar.h

  widget/layout/ScrollLayout.h
  widget/layout/GridLayout.h

  mUI.h
  types.h
)


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

include(${PROJECT_SOURCE_DIR}/cmake/LibraryConfig.cmake)
