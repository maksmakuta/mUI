#ifndef CANVAS_H
#define CANVAS_H

#include "../types.h"
#include "gl/GLRenderer.h"
#include "vk/VKRenderer.h"
#include "Backend.h"

class Canvas : public Renderer{
private:
    Renderer* renderer = null;
    Backend backend;
public:
    explicit Canvas(Backend mBackend = Default);
    ~Canvas();

    fun beginFrame(f32 w, f32 h) override;
    fun endFrame() override;

    // ============ shape methods ============
    fun begin() override ;
    fun moveTo(f32 x,f32 y) override;
    fun lineTo(f32 x,f32 y) override;
    fun bezierTo(f32 x,f32 y,f32 x1,f32 y1,f32 x2,f32 y2) override;
    fun end() override;

    fun rect(f32 x,f32 y,f32 w,f32 h) override;
    fun circle(f32 x,f32 y,f32 r) override;
    fun line(f32 x1,f32 y1,f32 x2,f32 y2) override;
    fun point(f32 x,f32 y) override;

    // ============ matrix methods ============
    fun translate(f32 x,f32 y) override;
    fun scale(f32 x,f32 y) override;
    fun rotate(f32 a) override;

    fun reset() override;
    fun push() override;
    fun pop() override;

    fun glew();
};

#endif
