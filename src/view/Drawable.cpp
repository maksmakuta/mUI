#include "Drawable.h"

Drawable::Drawable(const std::string& svg) : View(){

}

fun Drawable::onResize(f32 _w, f32 _h){

}

fun Drawable::onDraw(Canvas *c){
    c->begin();

    c->end(false);
}