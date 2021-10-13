#ifndef MUI_RECT_H
#define MUI_RECT_H

#include "../sTypes.h"

class Rect {
private:
    f32 x,y,w,h;
public:
    Rect();
    Rect(f32 _x, f32 _y,f32 _w, f32 _h);

    fun setX(f32 _x);
    fun setY(f32 _y);
    fun setW(f32 _w);
    fun setH(f32 _h);

    f32 getX();
    f32 getY();
    f32 getW();
    f32 getH();

    f32 getX()const;
    f32 getY()const;
    f32 getW()const;
    f32 getH()const;

    bool inside(f32 _x,f32 y);

};


#endif