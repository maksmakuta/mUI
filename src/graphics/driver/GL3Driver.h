#ifndef MUI_GL3DRIVER_H
#define MUI_GL3DRIVER_H

#include "../GDriver.h"

class GL3Driver : public GDriver{
public:

    GL3Driver() = default;

    fun drawPoint(f32 x,f32 y);
    fun drawLine(f32 x1,f32 y1,f32 x2,f32 y2);
    fun drawTriangle(f32 x1,f32 y1,f32 x2,f32 y2,f32 x3,f32 y3);
    fun drawRect(f32 x,f32 y,f32 w,f32 h);
    fun drawRoundRect(f32 x,f32 y,f32 w,f32 h,f32 r);
    fun drawRoundRect(f32 x,f32 y,f32 w,f32 h,f32 tl,f32 tr,f32 bl,f32 br);
    fun color(Color *c);
    fun clearColor(Color* c);

};

#endif
