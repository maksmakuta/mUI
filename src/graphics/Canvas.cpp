#define NANOVG_GL3_IMPLEMENTATION
#include "Canvas.h"


Canvas::Canvas(){
    this->c = nvgCreateGL3(NVGcreateFlags::NVG_STENCIL_STROKES);
}

fun Canvas::beginFrame(f32 w, f32 h,f32 p){
    nvgBeginFrame(this->c,w,h,p);
}
fun Canvas::endFrame(){
    nvgEndFrame(this->c);
}

fun Canvas::Rect(f32 x, f32 y, f32 w,f32 h){

    nvgBeginPath(this->c);
    nvgRect(this->c, x,y,w,h);
    nvgFillColor(this->c, nvgRGBf(1.0,0.5,0.0));
    nvgFill(this->c);
}
