#ifndef WINDOW_H
#define WINDOW_H

#include "../types.h"
#include <GLFW/glfw3.h>
#include "Canvas.h"

class Window{
private:
    GLFWwindow* win = null;
    Canvas* c = null;
public:
    Window() : Window(640,480,"title"){ /* ... */ }

    Window(i32 w,i32 h,const str& t){
        if(!glfwInit()) onError("GLFW::init()");

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        win = glfwCreateWindow(w,h,t.c_str(),null,null);
        if(!win) onError("GLFW::createWindow()");

        glfwMakeContextCurrent(win);

        glfwSwapInterval(1);

        //this->c = new Canvas();
        //if(nullable(c)) onError("NVG::init()");

    }

    void draw(){
        if(nonNull(this->win)){
            while(!glfwWindowShouldClose(this->win)){

                glfwPollEvents();
                glfwSwapBuffers(this->win);
            }
        }
    }

    ~Window(){
        glfwTerminate();
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
