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
    Window() : Window(640,480,"Test"){}

    Window(int _w,int _h,const char* _t){
        prepare();
        init(_w,_h,_t);
    }

    void prepare(){
        if(!glfwInit()) error("GLFWInit()");

        //glfwInitHint(GLFW_VERSION_MAJOR,3);
        //glfwInitHint(GLFW_VERSION_MINOR,3);
    }

    void init(int _w,int _h,const char* _t){
        win = glfwCreateWindow(_w,_h,_t,null,null);
        if(!win) error("window");

        glfwMakeContextCurrent(win);
        if(glewInit() != GLEW_OK) error("glew");
        glfwSwapInterval(1);
    }

    void resize(int w,int h){
        glfwSetWindowSize(win,w,h);
    }

    void remove(int x,int y){
        glfwSetWindowPos(win,x,y);
    }

    void draw(){
        while(!glfwWindowShouldClose(win)){
            glfwSwapBuffers(win);
            glfwPollEvents();
        }
    }

private:
    void error(const char* t){
        printf("%s\n",t);
        if(win != null){
            glfwTerminate();
            exit(EXIT_FAILURE);
        }
    }

};


#endif