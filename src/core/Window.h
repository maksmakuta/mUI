#ifndef MUI_WINDOW_H
#define MUI_WINDOW_H

#define GLFW_INCLUDE_NONE
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "types.h"
#include "utils/vec.h"
#include "../ui/core/View.h"
#include "Canvas.h"

#define MOUSE_LEFT GLFW_MOUSE_BUTTON_LEFT
#define MOUSE_RIGHT GLFW_MOUSE_BUTTON_RIGHT
#define MOUSE_CLICK GLFW_PRESS

class Window {
private:
    GLFWwindow* win = null;
    View* mainView = null;
    Canvas* c = null;
public:
    Window(i32 w,i32 g,const char* t);
    fun draw(View*);
    fun theme(Theme*);
    fun onKey(i32 key, i32 scancode, i32 action, i32 mods);
    fun onKey(u32 codepoint);

    fun onMousePos(f64 _x,f64 y);
    fun onMouseButton(i32 button, i32 action, i32 mods);
    fun onMouseScroll(f64 dx,f64 dy);

private:
    Window();
    fun error(const char*);
};


#endif
