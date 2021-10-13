#include "Rect.h"


Rect::Rect() : Rect(0,0,0,0){

}
Rect::Rect(f32 _x, f32 _y,f32 _w, f32 _h){
    this->setX(_x);
    this->setY(_y);
    this->setW(_w);
    this->setH(_h);
}

fun Rect::setX(f32 _x){this->x = _x;}
fun Rect::setY(f32 _y){this->y = _y;}
fun Rect::setW(f32 _w){this->w = _w;}
fun Rect::setH(f32 _h){this->h = _h;}

f32 Rect::getX(){return this->x;}
f32 Rect::getY(){return this->y;}
f32 Rect::getW(){return this->w;}
f32 Rect::getH(){return this->h;}

f32 Rect::getX() const {return this->x;}
f32 Rect::getY() const {return this->y;}
f32 Rect::getW() const {return this->w;}
f32 Rect::getH() const {return this->h;}

bool Rect::inside(f32 _x,f32 _y){
    bool _v = (this-> x < _x) && (this->x + this->w > _x);
    bool _h = (this-> y < _y) && (this->y + this->h > _y);
    return (bool)(_v && _h);
}