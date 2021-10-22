#include "View.h"

View::View() { }


fun View::add(View* v){
    child.push_back(v);
}
fun View::del(i32 pos){
    child.erase(child.begin() + pos);
}
fun View::del(View* v){
    for(i32 i = 0;i < (i32)child.size();i++)
        if(v == child[i])
            child.erase(child.begin() + i);
}

std::vector<View*> View::getChild(){return this->child;}

fun View::applyTheme(Theme* _t){this->mTheme = _t;}
Theme* View::getTheme(){return this->mTheme;}

fun View::rect  (f32 _x,f32 _y,f32 _w,f32 _h){
    this->x = _x;
    this->y = _y;
    this->w = _w;
    this->h = _h;
}
fun View::margin(f32 _t,f32 _b,f32 _l,f32 _r){
    this->t = _t;
    this->b = _b;
    this->l = _l;
    this->r = _r;
}
fun View::margin(f32 all){
    this->margin(all,all,all,all);
}

fun View::onDraw(Canvas* c) {
    c->begin();
    c->rect(x,y,w,h);
    c->fill("#fa6");
    c->end(true);
}

bool View::onMouseButton   (f32 x,f32 y, i32 button, bool down, i32 modifiers){

}
bool View::onMouseMotion   (f32 x,f32 y, f32 dx,f32 dy, i32 button, i32 modifiers){

}
bool View::onMouseDrag     (f32 x,f32 y, f32 dx,f32 dy, i32 button, i32 modifiers){

}
bool View::onMouseEnter    (f32 x,f32 y, bool enter){

}
bool View::onScroll        (f32 x,f32 y, f32 dx,f32 dy){

}
bool View::onFocus         (bool focused){

}
bool View::onKeyboard      (i32 key, i32 scancode, i32 action, i32 modifiers){

}
bool View::onKeyboardChar  (u32 codepoint){

}
