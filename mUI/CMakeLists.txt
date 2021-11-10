set(SOURCES
  graphics/nanovg/nanovg.c
  graphics/utils/ColorUtils.cpp
  graphics/Canvas.cpp

)

set(HEADERS_PUBLIC
  app/Activity.h
  app/App.h

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

  mUI.h
  types.h
)
include(${PROJECT_SOURCE_DIR}/cmake/LibraryConfig.cmake)
