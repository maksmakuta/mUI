#ifndef MUI_CANVAS_H
#define MUI_CANVAS_H

#include "../sTypes.h"
#include "Shader.h"
#include "Color.h"

struct Context{
    Shader s = Shader::def();
    Color c = Color();
    u32 VAO = 0,VBO = 0,EBO = 0;
    u32 TextureID = 0;
};

class Canvas {
private:
    Context c;
public:

    Canvas();

    fun color(Color c);

    fun drawPoint(f32 x,f32 y);
    fun drawLine(f32 x,f32 y,f32 x1, f32 y1);
    fun drawCircle(f32 x,f32 y,f32 r);
    fun drawRect(f32 x,f32 y,f32 w,f32 h);
    fun drawRRect(f32 x,f32 y,f32 w,f32 h,f32 r);
    fun drawRRect(f32 x,f32 y,f32 w,f32 h,f32 tlr,f32 trr,f32 blr,f32 brr);

    fun drawQCurve(f32 x0,f32 y0, f32 x1,f32 y1, f32 x2,f32 y2);
    fun drawCCurve(f32 x0,f32 y0, f32 x1,f32 y1, f32 x2,f32 y2, f32 x3,f32 y3);

private:

    fun vertex();

};


#endif
