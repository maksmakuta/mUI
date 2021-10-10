#include "Canvas.h"

Canvas::Canvas(i32 w,i32 h){
    glm::mat4 m = glm::mat4(1.0f);
    glm::mat4 v = glm::lookAt(glm::vec3{0,0,-1},glm::vec3{0},glm::vec3{0,1,0});
    glm::mat4 p = glm::ortho(0,w,h,0,-1,1);
    this->c.proj = glm::mat4(1.0f);

}

fun Canvas::color(Color _c){
    this->c.c = _c;
}

fun Canvas::drawPoint(f32 x,f32 y){

}
fun Canvas::drawLine(f32 x,f32 y,f32 x1, f32 y1){

}
fun Canvas::drawCircle(f32 x,f32 y,f32 r){

}
fun Canvas::drawRect(f32 x,f32 y,f32 w,f32 h){

}
fun Canvas::drawRRect(f32 x,f32 y,f32 w,f32 h,f32 r){

}
fun Canvas::drawRRect(f32 x,f32 y,f32 w,f32 h,f32 tlr,f32 trr,f32 blr,f32 brr){

}
fun Canvas::drawQCurve(f32 x0,f32 y0, f32 x1,f32 y1, f32 x2,f32 y2){

}
fun Canvas::drawCCurve(f32 x0,f32 y0, f32 x1,f32 y1, f32 x2,f32 y2, f32 x3,f32 y3){

}
fun Canvas::renderer(){

}
