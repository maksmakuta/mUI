#include "View.h"

View::View(bool container) {
    this->isContainer = container;
}

fun View::add(View* v){
    if(isContainer) {
        child.push_back(v);
        onMeasure();
    }
}
fun View::del(i32 pos) {
    if (isContainer) {
        child.erase(child.begin() + pos);
        onMeasure();
    }
}
fun View::del(View* v){
    if(isContainer) {
        for (i32 i = 0; i < (i32) child.size(); i++)
            if (v == child[i])
                child.erase(child.begin() + i);
        onMeasure();
    }
}

std::vector<View*> View::getChild(){return this->child;}

fun View::applyTheme(Theme* _t){
    this->mTheme = _t;
    for(auto v : child)
        v->applyTheme(_t);
}
Theme* View::getTheme(){return this->mTheme;}


fun View::rect    (f32 x,f32 y,f32 w,f32 h){
    this->size(w,h);
    this->pos(x,y);
}
fun View::margin  (f32 l,f32 t,f32 r,f32 b){
    this->mMargin = vec4(l,r,t,b);
}
fun View::margin  (f32 a){
    this->margin(a,a,a,a);
}
fun View::size    (f32 w,f32 h){
    this->mRect.z = w;
    this->mRect.w = h;
}
fun View::pos     (f32 x,f32 y){
    this->mRect.x = x;
    this->mRect.y = y;
}

vec2 View::pos (){return {mRect.x,mRect.y};}
vec2 View::size(){return {mRect.z,mRect.w};}
vec4 View::margin(){return mMargin;}
vec4 View::rect(){return mRect;}

fun View::onDraw(Canvas* c) {
    c->begin();
    c->rect(0,0,1,1);
    c->fill("#fa6");
    c->end(true);
}
fun View::onMeasure(){
    if(!child.empty() && isContainer)
        for(View* v : child)
            v->onMeasure();
}
fun View::onMouse(f32 x,f32 y,i32 button,i32 action,i32 mod){
    if(!child.empty() && isContainer)
        for(View* v : child)
            v->onMouse(x,y, button, action,mod);
}
fun View::onKeyboard(i32 key,i32 scancode,i32 action,i32 mod){
    if(!child.empty() && isContainer)
        for(View* v : child)
            v->onKeyboard(key,scancode,action,mod);
}
fun View::onKeyboard(u32 charcode){
    if(!child.empty() && isContainer)
        for(View* v : child)
            v->onKeyboard(charcode);
}
fun View::onScroll(f32 x,f32 y){
    if(!child.empty() && isContainer)
        for(View* v : child)
            v->onScroll(x,y);
}