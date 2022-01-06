#include "Canvas.h"
#include "../app/Logger.h"

Canvas::Canvas(Backend mBackend){
    this->backend = mBackend;
    switch(this->backend){
        case GL:
            this->renderer = new GLRenderer();
        break;
        case VK:
            this->renderer = new VKRenderer();
        break;
    }
}


fun Canvas::glew(){
    if(this->backend == GL){
        glewExperimental = GL_TRUE;
        if(glewInit() != GLEW_OK) Log::onError("GLEW::init()");
    }
}

fun Canvas::beginFrame(f32 w, f32 h){}
fun Canvas::endFrame(){}

// ============ shape methods ============
fun Canvas::begin(){}
fun Canvas::moveTo(f32 x,f32 y){}
fun Canvas::lineTo(f32 x,f32 y){}
fun Canvas::bezierTo(f32 x,f32 y,f32 x1,f32 y1,f32 x2,f32 y2){}
fun Canvas::end(){}

fun Canvas::rect(f32 x,f32 y,f32 w,f32 h){}
fun Canvas::circle(f32 x,f32 y,f32 r){}
fun Canvas::line(f32 x1,f32 y1,f32 x2,f32 y2){}
fun Canvas::point(f32 x,f32 y){}

// ============ matrix methods ============
fun Canvas::translate(f32 x,f32 y){}
fun Canvas::scale(f32 x,f32 y){}
fun Canvas::rotate(f32 a){}

fun Canvas::reset(){}
fun Canvas::push(){}
fun Canvas::pop(){}

Canvas::~Canvas(){
    delete this->renderer;
}
