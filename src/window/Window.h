#ifndef TT_WINDOW_H
#define TT_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../graphics/Canvas.h"
#include "../view/core/View.h"

class Window {
private:
    GLFWwindow* win = null;
    Canvas* c = null;
    NVGcolor bg = {{{0.f,0.f,0.f,1.f}}};
    double prevt = 0;
public:
    Window(i32 _w,i32 _h,const char* _t);
    fun draw(View* v);
    fun setBG(const char* h);

private:
    fun error(const char* t);
};


#endif