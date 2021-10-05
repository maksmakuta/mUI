#include "GL3Driver.h"
#include <GL/glew.h>

fun GL3Driver::drawPoint(f32 x,f32 y){

}
fun GL3Driver::drawLine(f32 x1,f32 y1,f32 x2,f32 y2){

}
fun GL3Driver::drawTriangle(f32 x1,f32 y1,f32 x2,f32 y2,f32 x3,f32 y3){

}
fun GL3Driver::drawRect(f32 x,f32 y,f32 w,f32 h){

}
fun GL3Driver::drawRoundRect(f32 x,f32 y,f32 w,f32 h,f32 r){

}
fun GL3Driver::drawRoundRect(f32 x,f32 y,f32 w,f32 h,f32 tl,f32 tr,f32 bl,f32 br){

}
fun GL3Driver::color(Color *c){
    glColor4f(c->getRf(),c->getGf(),c->getBf(),c->getAf());
}
fun GL3Driver::clearColor(Color* c){
    glClearColor(c->getRf(),c->getGf(),c->getBf(),c->getAf());
}