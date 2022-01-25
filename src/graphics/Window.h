#ifndef WINDOW_H
#define WINDOW_H

#include "../types.h"
#include "Canvas.h"
#define GLFW_INCLUDE_GLEW
#include <GLFW/glfw3.h>
#include "Backend.h"
#include <app/Activity.h>
#include <app/Logger.h>

class Window{
private:
    i32 width,height;
    str title;
    GLFWwindow* win = null;
    Canvas* c = null;
    Activity *activity = null;
    Backend backend = Default;
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

        if(this->backend == VK){
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        }else{
            glfwWindowHint(GLFW_VERSION_MAJOR,3);
            glfwWindowHint(GLFW_VERSION_MINOR,3);
        }
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        win = glfwCreateWindow(w,h,t.c_str(),null,null);
        if(!win) onError("GLFW::createWindow()");

        glfwMakeContextCurrent(win);
        glfwSwapInterval(0);
    }

    fun renderer(Backend b){
        this->backend = b;
        //this->c = new Canvas(this->backend);
        //if(nullable(c)) onError("Canvas::init()");
    }

    void draw(){
        this->initWindow(this->width,this->height,this->title);
        if(nonNull(this->win)){
            while(!glfwWindowShouldClose(this->win)){

                if(this->backend == GL){
                    //glClearColor(1.f,0.f,0.f,1.f);
                    //glClear(GL_COLOR_BUFFER_BIT);
                }





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
