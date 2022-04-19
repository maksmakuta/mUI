#ifndef WINDOW_H
#define WINDOW_H

#include "../types.h"
#include "nanovg.h"
#include "nanovg_gl.h"
#define GLFW_INCLUDE_GLEW
#include <GLFW/glfw3.h>
#include <app/Activity.h>
#include <app/Logger.h>

class Window{
private:
    i32 width,height;
    str title;
    GLFWwindow* win = null;
    NVGcontext* c = null;
    Activity *activity = null;
    f64 lastTime = glfwGetTime();
    i32 nbFrames = 0;
public:
    Window() : Window(640,480,"title"){ /* ... */ }

    Window(i32 w,i32 h,const str& t){
        this->width = w;
        this->height = h;
        this->title = t;
    }

    fun initWindow(i32 w,i32 h,const str& t){
        if(!glfwInit()) onError("GLFW::init()");
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        win = glfwCreateWindow(w,h,t.c_str(),null,null);
        if(!win) onError("GLFW::createWindow()");

        glfwMakeContextCurrent(win);
        glfwSwapInterval(0);   
    }

    void draw(){
        this->initWindow(this->width,this->height,this->title);
        if(nonNull(this->win)){
            while(!glfwWindowShouldClose(this->win)){

#ifdef FPS
                nbFrames++;
                if ( glfwGetTime() - lastTime >= 1.0 ){
                    f64 ftime = 1000.0/f64(nbFrames);
                    char msg[50];
                    sprintf(msg,"%f ms/frame : %.2f fps",ftime,1000.0/ftime);
                    Log::onMessage(msg);
                    nbFrames = 0;
                    lastTime += 1.0;
                }
#endif
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
