#ifndef MUI_CANVAS_H
#define MUI_CANVAS_H

#include <GL/glew.h>
#include "../graphics/nanovg/nanovg.h"
#include "../graphics/nanovg/nanovg_gl.h"
#include "../sTypes.h"

class Canvas {
private:
    NVGcontext *c = null;
public:
    Canvas();

    fun beginFrame(f32 w,f32 h,f32 p);
    fun endFrame();

    fun Rect(f32 x, f32 y, f32 w,f32 h);

};

#endif