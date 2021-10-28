#ifndef MUI_RECT_H
#define MUI_RECT_H

#include "../types.h"

class Rect{
public:
    f32 x,y,w,h;

    Rect() : Rect(0){ }
    Rect(f32 s) : Rect(s,s){ }
    Rect(f32 w,f32 h) : Rect(0,0,w,h){ }
    Rect(f32 x,f32 y,f32 w,f32 h){
        this->pos(x,y);
        this->size(w,h);
    }

    fun size(f32 _w,f32 _h){
        this->w = _w;
        this->h = _h;
    }
    fun pos(f32 _x,f32 _y){
        this->x = _x;
        this->y = _y;
    }

    bool in(f32 _x,f32 _y) const{
        return (x < _x && x + w > _x) && (y < _y && y + h > _y);
    }
};

#endif
