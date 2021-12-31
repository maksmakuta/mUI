#ifndef RECT_H
#define RECT_H

#include "../types.h"
#include "Point.h"

class Rect{
private:
    f32 x,y,w,h;
public:
    Rect() : Rect(0.f,0.f,0.f,0.f){ /* ... */}
    Rect(f32 _x,f32 _y,f32 _w,f32 _h){
        this->pos(_x,_y);
        this->size(_w,_h);
    }

    fun pos(f32 a,f32 b){
        this->setX(a);
        this->setY(b);
    }

    fun size(f32 a,f32 b){
        this->setW(a);
        this->setH(b);
    }

    Point pos(){
        return Point(this->getX(),this->getY());
    }
    Point size(){
        return Point(this->getW(),this->getH());
    }

    fun setX(f32 v){this->x = v;}
    fun setY(f32 v){this->y = v;}
    fun setW(f32 v){this->w = v;}
    fun setH(f32 v){this->h = v;}

    f32 getX(){return this->x;}
    f32 getY(){return this->y;}
    f32 getW(){return this->w;}
    f32 getH(){return this->h;}

    f32 getX() const {return this->x;}
    f32 getY() const {return this->y;}
    f32 getW() const {return this->w;}
    f32 getH() const {return this->h;}

    bool in(f32 px, f32 py){
        return (px >= x && px <= x+w) && (py >= y && py <= y+h);
    }

    bool operator == (const Point& p){
        return in(p.getX(),p.getY());
    }

};

#endif
