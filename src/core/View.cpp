#include "View.h"

View::View() {
    this->margin(10);
    this->rect(0,0,0,0);
}

fun View::add(View* v){
    child.push_back(v);
    onMeasure();
}
fun View::del(i32 pos){
    child.erase(child.begin() + pos);
    onMeasure();
}
fun View::del(View* v){
    for(i32 i = 0;i < (i32)child.size();i++)
        if(v == child[i])
            child.erase(child.begin() + i);
    onMeasure();
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

fun View::onMeasure(){
    if(!child.empty())
        for(View* v : child)
            v->onMeasure();
}