#ifndef MUI_CANVAS_H
#define MUI_CANVAS_H

#include <GL/glew.h>
#include "nanovg/nanovg.h"
#include "nanovg/nanovg_gl.h"
#include "../sTypes.h"

class Canvas {
private:
    NVGcontext *c = null;
    NVGcolor col;
    i32 *font = null;
    i32 fontN = 0;
public:
    Canvas();

    fun beginFrame(f32 w,f32 h,f32 p);
    fun endFrame();

    fun begin();
    fun circle  (f32 x,f32 y,f32 r);
    fun ellipse (f32 x,f32 y,f32 cx,f32 cy);
    fun arc     (f32 x,f32 y,f32 r,f32 s,f32 e,bool);
    fun rect    (f32 x, f32 y, f32 w,f32 h);
    fun rect    (f32 x, f32 y, f32 w,f32 h,f32 r);
    fun rect    (f32 x, f32 y, f32 w,f32 h,f32 tl,f32 tr, f32 bl, f32 br);
    fun end(bool);

    fun beginPath   ();
    fun moveTo      (f32 x,f32 y);
    fun lineTo      (f32 x,f32 y);
    fun bezierTo    (f32 c1x, f32 c1y, f32 c2x, f32 c2y, f32 x, f32 y);
    fun quadTo      (f32 cx, f32 cy, f32 x, f32 y);
    fun arcTo       (f32 x1, f32 y1, f32 x2, f32 y2, f32 radius);
    fun endPath     ();
    fun windingPath(int);

    fun lineWidth(f32);

    fun fill(const char*);
    fun fill(NVGcolor color);

    fun initFont(const char* f,const char* n);
    fun allocateFont(i32 size);
    fun initFont(const char* f,i32 id);

    fun fontFace(const char* fontname);
    fun fontFace(i32 fontID);

    fun fontSize(f32 s);
    fun fontBlur(f32 b);
    fun fontAlign(i32 e);

    fun text    (f32 x,f32 y,const char* _text);
    fun textBox (f32 x,f32 y,f32 w,const char* _text);

    f32* textBounds(f32 x,f32 y,const char* _text);
    f32* textBoxBounds(f32 x,f32 y,f32 w,const char* _text);

};

#endif