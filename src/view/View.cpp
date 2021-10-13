#include "View.h"

View::View() : View(-1){ }

View::View(i32 _i){
    this->id = _i;
}

View::View(f32 x,f32 y,f32 w,f32 h){
    this->setViewRect(x,y,w,h);
}

fun View::setViewRect(f32 x,f32 y,f32 w,f32 h){
    this->r = Rect(x,y,w,h);
}

Listener* View::listeners(LISTENER _l){
    if(this->l != null)
        return l;
    return null;
}


fun View::setOnClickListener(Listener *a){
    this->l = a;
}

Rect View::getViewRect() { return this->r;}