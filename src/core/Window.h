#ifndef MUI_WINDOW_H
#define MUI_WINDOW_H

#define GLFW_INCLUDE_NONE
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "types.h"
#include "View.h"
#include "Canvas.h"

class Window {
private:
    GLFWwindow* win = null;
    Canvas* c = null;
    f64 prev = 0;
    bool decor = false;
public:
    Window();
    Window(i32 w,i32 g,const char* t);

    fun draw(View*);

private:
    fun error(const char*);

    // custom window decorator
    fun border(Canvas* c,f32 w,f32 h);
};


#endif
