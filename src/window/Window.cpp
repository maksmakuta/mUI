#include "Window.h"

Window::Window() : Window(640,480,"Test"){}

Window::Window(int _w,int _h,const char* _t){
    prepare();
    init(_w,_h,_t);
}

void Window::prepare(){
    if(!glfwInit()) error("GLFWInit()");

    //glfwInitHint(GLFW_VERSION_MAJOR,3);
    //glfwInitHint(GLFW_VERSION_MINOR,3);
}

void Window::init(int _w,int _h,const char* _t){
    win = glfwCreateWindow(_w,_h,_t,null,null);
    if(!win) error("window");

    glfwMakeContextCurrent(win);
    if(glewInit() != GLEW_OK) error("glew");
    glfwSwapInterval(1);
}

void Window::resize(int w,int h){
    glfwSetWindowSize(win,w,h);
}

void Window::remove(int x,int y){
    glfwSetWindowPos(win,x,y);
}

void Window::draw(){
    while(!glfwWindowShouldClose(win)){
        glfwSwapBuffers(win);
        glfwPollEvents();
    }
}

void Window::error(const char* t){
    printf("%s\n",t);
    if(win != null){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}