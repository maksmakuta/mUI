#ifndef TT_WINDOW_H
#define TT_WINDOW_H

#include "../sTypes.h"
#include "../graphics/Color.h"
#include <cstdlib>
#include <cstdio>
#include <GL/glew.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <functional>

class Window {
private:
    GLFWwindow* win;
    Color *bg = null;
public:
    Window();
    Window(i32 _w,i32 _h,const char* _t);

    fun resize(i32 w,i32 h);
    fun remove(i32 x,i32 y);
    fun setBG(Color*);
    fun draw();
    //fun draw(const std::function<fun(Canvas*)>& s);

private:
    fun prepare();
    fun init(i32 _w,i32 _h,const char* _t);
    fun error(const char* t);
};


#endif