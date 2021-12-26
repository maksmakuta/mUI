#ifndef WINDOW_H
#define WINDOW_H

#include "../types.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window{
private:
    GLFWwindow* win = null;
public:
    Window() : Window(640,480,"title"){ /* ... */ }

    Window(i32 w,i32 h,const str& t){
        if(!glfwInit()) onError("GLFW::init()");

        win = glfwCreateWindow(w,h,t.c_str(),null,null);
        if(!win) onError("GLFW::createWindow()");

        glfwMakeContextCurrent(win);
        if(glewInit() != GLEW_OK) onError("GLEW::init()");
        glfwSwapInterval(1);

    }

    void draw(){
        if(nonNull(this->win)){
            while(!glfwWindowShouldClose(this->win)){
                glClearColor(0,0,0,1);
                glClear(GL_COLOR_BUFFER_BIT);

                glfwPollEvents();
                glfwSwapBuffers(this->win);
            }
        }
    }

private:
    void onError(const str& msg){
        cerr << msg << "\n";
        if(nonNull(this->win)){
            glfwTerminate();
        }
        exit(-1);
    }
};

#endif
