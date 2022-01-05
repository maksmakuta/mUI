#ifndef WINDOW_H
#define WINDOW_H

#include "../types.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "Canvas.h"

class Window{
private:
    GLFWwindow* win = null;
    Canvas* c = null;

    f64 lastTime = glfwGetTime();
    i32 nbFrames = 0;
public:
    Window() : Window(640,480,"title"){ /* ... */ }

    Window(i32 w,i32 h,const str& t){
        if(!glfwInit()) onError("GLFW::init()");

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        win = glfwCreateWindow(w,h,t.c_str(),null,null);
        if(!win) onError("GLFW::createWindow()");

        glfwMakeContextCurrent(win);

        glfwSwapInterval(1);

        this->c = new Canvas();
        if(nullable(c)) onError("Canvas::init()");

    }

    void draw(){
        if(nonNull(this->win)){
            while(!glfwWindowShouldClose(this->win)){

                glClearColor(0.f,0.f,0.f,1.f);
                glClear(GL_COLOR_BUFFER_BIT);

                nbFrames++;
                if ( glfwGetTime() - lastTime >= 1.0 ){
                    f64 ftime = 1000.0/f64(nbFrames);
                    char msg[50];
                    sprintf(msg,"%f ms/frame : %.2f fps",ftime,1000.0/ftime);
                    Log::onMessage(msg);
                    nbFrames = 0;
                    lastTime += 1.0;
                }

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
