#include "Rect.h"

Rect::Rect() : Rect(0.f){}
Rect::Rect(f32 a) : Rect(a,a,a,a){}
Rect::Rect(f32 _x,f32 _y,f32 _w,f32 _h){
    this->x(_x);
    this->y(_y);
    this->w(_w);
    this->h(_h);
}
Rect::Rect(const Rect& r) : Rect(r.x(),r.y(),r.w(),r.h()){}

fun Rect::set(f32 _a){
    this->x(_a);
    this->y(_a);
    this->w(_a);
    this->h(_a);
}

bool Rect::point(f32 mx,f32 my){
    return (x() >= mx && x() + w() <= mx) && ( y() >= my && y() + h() <= my);
}

fun Rect::x(f32 _x){this->rx = _x;}
fun Rect::y(f32 _y){this->ry = _y;}
fun Rect::w(f32 _w){this->rw = _w;}
fun Rect::h(f32 _h){this->rh = _h;}

f32 Rect::x(){return this->rx;}
f32 Rect::y(){return this->ry;}
f32 Rect::w(){return this->rw;}
f32 Rect::h(){return this->rh;}

f32 Rect::x() const {return this->rx;}
f32 Rect::y() const {return this->ry;}
f32 Rect::w() const {return this->rw;}
f32 Rect::h() const {return this->rh;}

str Rect::toString(){
    return "Rect("  + std::to_string(x()) + "," + std::to_string(y()) +","
                    + std::to_string(w()) + "," + std::to_string(h()) + ")";
}