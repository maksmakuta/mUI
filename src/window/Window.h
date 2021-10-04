#ifndef TT_WINDOW_H
#define TT_WINDOW_H

#include <stdio.h>
#include <GL/glew.h>
#define GLFW_INCLUDE_NONE
#define null nullptr
#include <GLFW/glfw3.h>
#include <cstdlib>

class Window {
private:
    GLFWwindow* win;
public:
    Window();
    Window(int _w,int _h,const char* _t);

    void resize(int w,int h);
    void remove(int x,int y);
    void draw();

private:
    void prepare();
    void init(int _w,int _h,const char* _t);
    void error(const char* t);
};


#endif