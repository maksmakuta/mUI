#ifndef MUI_CANVAS_H
#define MUI_CANVAS_H

#include <GL/glew.h>
#include "../graphics/nanovg/nanovg.h"
#include "../graphics/nanovg/nanovg_gl.h"
#include "../sTypes.h"

class ColorUtils{
public:
    static NVGcolor color3u(u32 r,u32 g,u32 b);
    static NVGcolor color4u(u32 r,u32 g,u32 b,u32 a);
    static NVGcolor color3f(f32 r,f32 g,f32 b);
    static NVGcolor color4f(f32 r,f32 g,f32 b,f32 a);
    static NVGcolor color(const char* hex);
private:
    static u32 fHex(char);
};

class Canvas {
private:
    NVGcontext *c = null;
    NVGcolor col;
    i32 font;
public:
    Canvas();



    fun beginFrame(f32 w,f32 h,f32 p);
    fun endFrame();

    fun color3u(u32 r,u32 g,u32 b);
    fun color4u(u32 r,u32 g,u32 b,u32 a);
    fun color3f(f32 r,f32 g,f32 b);
    fun color4f(f32 r,f32 g,f32 b,f32 a);
    fun color(const char* hex);

    fun setupText(const char* face, const char* name);

    fun drawRect(f32 x, f32 y, f32 w,f32 h);
    fun drawCircle(f32 x,f32 y,f32 r);
    fun drawEllipse(f32 x,f32 y,f32 cx,f32 cy);
    fun drawArc(f32 x,f32 y,f32 r,f32 s,f32 e);
    fun drawRRect(f32 x, f32 y, f32 w,f32 h,f32 r);
    fun drawRRect(f32 x, f32 y, f32 w,f32 h,f32 tl,f32 tr, f32 bl, f32 br);

    fun drawText(f32 x,f32 y,const char* data,const char* fnt,f32 s);

    f32 getWidth(const char* t);

};

#endif