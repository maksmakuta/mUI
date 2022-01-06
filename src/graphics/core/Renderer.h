#ifndef RENDERER_H
#define RENDERER_H

#include "../../types.h"

class Renderer{
public:
    // ============ frame methods ============
    virtual fun beginFrame(f32 w, f32 h) = 0;
    virtual fun endFrame() = 0;

    // ============ shape methods ============
    virtual fun begin() = 0;
    virtual fun moveTo(f32 x,f32 y) = 0;
    virtual fun lineTo(f32 x,f32 y) = 0;
    virtual fun bezierTo(f32 x,f32 y,f32 x1,f32 y1,f32 x2,f32 y2) = 0;
    virtual fun end() = 0;

    virtual fun rect(f32 x,f32 y,f32 w,f32 h) = 0;
    virtual fun circle(f32 x,f32 y,f32 r) = 0;
    virtual fun line(f32 x1,f32 y1,f32 x2,f32 y2) = 0;
    virtual fun point(f32 x,f32 y) = 0;

    // ============ matrix methods ============
    virtual fun translate(f32 x,f32 y) = 0;
    virtual fun scale(f32 x,f32 y) = 0;
    virtual fun rotate(f32 a) = 0;

    virtual fun reset() = 0;
    virtual fun push() = 0;
    virtual fun pop() = 0;

    virtual ~Renderer(){/* ... */}
};

#endif
