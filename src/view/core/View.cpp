#include "View.h"

View::View() : View(false){
    this->x(0.f);
    this->y(0.f);
    this->w(0.f);
    this->h(0.f);
    this->margin(0.f);
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
fun View::setListener(LISTENER l,Listener* _l){
    Listener* lp = this->getListener(l);
    if(_l != null){
        lp = _l;
    }
}

fun View::setVisibility(Visibility v){
    this->visibility = v;
}
Visibility View::getVisibility(){
    return this->visibility;
}
fun View::setGravity(Gravity g){
    this->gravity = g;
}
Gravity View::getGravity(){
    return this->gravity;
}

fun View::marginTop   (f32 _t){this->viewRect.t = _t;}
fun View::marginBottom(f32 _b){this->viewRect.b = _b;}
fun View::marginStart (f32 _s){this->viewRect.s = _s;}
fun View::marginEnd   (f32 _e){this->viewRect.e = _e;}

f32 View::marginTop   (){return this->viewRect.t;}
f32 View::marginBottom(){return this->viewRect.b;}
f32 View::marginStart (){return this->viewRect.s;}
f32 View::marginEnd   (){return this->viewRect.e;}


fun View::margin(f32 a){
    this->marginTop   (a);
    this->marginBottom(a);
    this->marginStart (a);
    this->marginEnd   (a);
}