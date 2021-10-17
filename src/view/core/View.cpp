#include "View.h"

View::View() : View(false){
    this->x(0.f);
    this->y(0.f);
    this->w(0.f);
    this->h(0.f);
}

View::View(bool b){
    this->isContainer = b;
}

bool View::container(){
    return isContainer;
}

fun View::x(f32 _x){this->viewRect.x = _x;}
fun View::y(f32 _y){this->viewRect.y = _y;}
fun View::w(f32 _w){this->viewRect.w = _w;}
fun View::h(f32 _h){this->viewRect.h = _h;}

f32 View::x(){return this->viewRect.x;}
f32 View::y(){return this->viewRect.y;}
f32 View::w(){return this->viewRect.w;}
f32 View::h(){return this->viewRect.h;}

Listener* View::getListener(LISTENER l){
    switch (l) {
        case OnCLick        : return listeners.onClick;
        case OnLongClick    : return listeners.onLongClick;
        case OnHover        : return listeners.onHover;
        case OnKey          : return listeners.onKey;
        case OnMove         : return listeners.onMove;
        default: return null;
    }
}