#ifndef MUI_RECT_H
#define MUI_RECT_H

#include "../../core/types.h"

class Rect {
priv:
    f32 rx,ry,rw,rh;
pub:
    Rect() : Rect(0){ }
    Rect(f32 s) : Rect(s,s){ }
    Rect(f32 w,f32 h) : Rect(0,0,w,h){ }
    Rect(f32 x,f32 y,f32 w,f32 h){
        this->pos(x,y);
        this->size(w,h);
    }

    fun size(f32 _w,f32 _h){
        this->rw = _w;
        this->rh = _h;
    }
    fun pos(f32 _x,f32 _y){
        this->rx = _x;
        this->ry = _y;
    }

    fun x(f32 _x){this->rx = _x;}
    fun y(f32 _y){this->ry = _y;}
    fun w(f32 _w){this->rw = _w;}
    fun h(f32 _h){this->rh = _h;}

    f32 x(){return this->rx;}
    f32 y(){return this->ry;}
    f32 w(){return this->rw;}
    f32 h(){return this->rh;}

};

#endif