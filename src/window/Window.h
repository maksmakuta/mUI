#ifndef TT_WINDOW_H
#define TT_WINDOW_H

#include "../sTypes.h"
#include "../graphics/Color.h"
#include "../graphics/GDriver.h"
#include <cstdlib>
#include <cstdio>
#include <GL/glew.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class Window {
private:
    GLFWwindow* win;
    Color *bg = null;
    GDriver *drv = null;
public:
    Window();
    Window(i32 _w,i32 _h,const char* _t);

    fun resize(i32 w,i32 h);
    fun remove(i32 x,i32 y);
    fun setBG(Color*);
    fun draw();

private:
    fun prepare();
    fun init(i32 _w,i32 _h,const char* _t);
    fun error(const char* t);
};


#endif