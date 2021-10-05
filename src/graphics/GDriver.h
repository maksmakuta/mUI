#ifndef MUI_GDRIVER_H
#define MUI_GDRIVER_H

#include "../sTypes.h"
#include "Color.h"

class GDriver{
public:
    virtual fun drawPoint(f32 x,f32 y) = 0;
    virtual fun drawLine(f32 x1,f32 y1,f32 x2,f32 y2) = 0;
    virtual fun drawTriangle(f32 x1,f32 y1,f32 x2,f32 y2,f32 x3,f32 y3) = 0;
    virtual fun drawRect(f32 x,f32 y,f32 w,f32 h) = 0;
    virtual fun drawRoundRect(f32 x,f32 y,f32 w,f32 h,f32 r) = 0;
    virtual fun drawRoundRect(f32 x,f32 y,f32 w,f32 h,f32 tl,f32 tr,f32 bl,f32 br) = 0;

    virtual fun viewport(i32 w,i32 h) = 0;

    virtual fun color(Color *c) = 0;
    virtual fun clearColor(Color* c) = 0;
};

#endif
