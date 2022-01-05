#ifndef GLRENDERER_H
#define GLRENDERER_H

#include "../../app/Logger.h"

class GLRenderer{
  public:
    GLRenderer(){
        Log::onMessage("Used GL Backend");
    }

    fun rect(f32 x,f32 y,f32 w,f32 h){

    }
    fun circle(f32 x,f32 y,f32 r){

    }
    fun line(f32 x1,f32 y1,f32 x2,f32 y2){

    }
    fun point(f32 x,f32 y){

    }

    fun begin(){

    }
    fun moveTo(f32 x,f32 y){

    }
    fun lineTo(f32 x,f32 y){

    }
    fun bezierTo(f32 x,f32 y,f32 x1,f32 y1,f32 x2,f32 y2){

    }
    fun end(){

    }

    fun translate(f32 x,f32 y){

    }
    fun scale(f32 x,f32 y){

    }
    fun rotate(f32 a){

    }

    fun reset(){

    }
    fun push(){

    }
    fun pop(){

    }
};

#endif
