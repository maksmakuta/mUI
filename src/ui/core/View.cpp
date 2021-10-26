#include "View.h"

View::View() { }

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
fun View::onMeasure(){ }
fun View::onMouse(f32 x,f32 y,i32 button,i32 action,i32 mod){ }
fun View::onKeyboard(i32 key,i32 scancode,i32 action,i32 mod){ }
fun View::onKeyboard(u32 charcode){ }
fun View::onScroll(f32 x,f32 y){ }