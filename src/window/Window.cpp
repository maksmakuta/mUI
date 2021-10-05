#include "Window.h"
#include "../graphics/driver/GL3Driver.h"

Window::Window() : Window(640,480,"Test"){}

Window::Window(i32 _w,i32 _h,const char* _t){
    prepare();
    init(_w,_h,_t);
}

fun Window::prepare(){
    if(!glfwInit()) error("GLFWInit()");

    //glfwInitHint(GLFW_VERSION_MAJOR,3);
    //glfwInitHint(GLFW_VERSION_MINOR,3);

    this->drv = new GL3Driver();
}

fun Window::init(i32 _w,i32 _h,const char* _t){
    win = glfwCreateWindow(_w,_h,_t,null,null);
    if(!win) error("window");

    glfwMakeContextCurrent(win);
    if(glewInit() != GLEW_OK) error("glew");
    glfwSwapInterval(1);
}

fun Window::resize(i32 w,i32 h){
    glfwSetWindowSize(win,w,h);
}

fun Window::remove(i32 x,i32 y){
    glfwSetWindowPos(win,x,y);
}


fun Window::setBG(Color *c){
    if(c != null)
        this->bg = c;
}

fun Window::draw(){
    while(!glfwWindowShouldClose(win)){
        glClear(GL_COLOR_BUFFER_BIT);

        if(drv != null){
            if(bg != null)
                drv->clearColor(bg);
        }

        glfwSwapBuffers(win);
        glfwPollEvents();
    }
}

fun Window::error(const char* t){
    printf("%s\n",t);
    if(win != null){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}