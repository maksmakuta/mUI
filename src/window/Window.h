#ifndef TT_WINDOW_H
#define TT_WINDOW_H

#include <GL/glew.h>
#define GLFW_INCLUDE_GLEXT
#include <GLFW/glfw3.h>
#include "../graphics/Canvas.h"
#include "../sTypes.h"

#include "../view/View.h"


class Window {
private:
    GLFWwindow* win;
    Canvas* c = null;
    double prevt = 0, cpuTime = 0;
public:
    Window();
    Window(i32 _w,i32 _h,const char* _t);

    fun resize(i32 w,i32 h);
    fun remove(i32 x,i32 y);
    fun draw(View* v);

private:
    fun prepare();
    fun init(i32 _w,i32 _h,const char* _t);
    fun error(const char* t);
};


#endif