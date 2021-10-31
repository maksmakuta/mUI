#ifndef MUI_WINDOW_H
#define MUI_WINDOW_H

#include <map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Canvas.h"
#include "utils/ColorUtils.h"
#include "../app/Activity.h"

class Window;

std::map<GLFWwindow*,Window*> __windows;

class Window{
private:
    GLFWwindow* w = null;
    Canvas* canvas = null;
    Activity *a = null;
public:
    Window(int _w,int _h,const char* _t){
        if(!glfwInit()) error("glfw");

        glfwWindowHint(GLFW_VERSION_MAJOR,3);
        glfwWindowHint(GLFW_VERSION_MINOR,3);
        glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);

        w = glfwCreateWindow(_w,_h,_t, nullptr, nullptr);
        if(!w)error("window");
        glfwMakeContextCurrent(w);
        if(glewInit() != GLEW_OK) error("glew");
        glfwSwapInterval(1);

        canvas = new Canvas(NVG_STENCIL_STROKES|NVG_ANTIALIAS);

        __windows.insert(std::pair<GLFWwindow*,Window*>(w,this));


        glfwSetKeyCallback(this->w,[](GLFWwindow* _w,i32 key, i32 scancode, i32 action, i32 mods){
            auto it = __windows.find(_w);
            if(it ==  __windows.end()) return;
            it->second->onKey(key,scancode,action,mods);
        });

        glfwSetCharCallback(this->w,[](GLFWwindow* _w,u32 charcode){
            auto it = __windows.find(_w);
            if(it ==  __windows.end()) return;
            it->second->onKey(charcode);
        });

        glfwSetCursorPosCallback(this->w,[](GLFWwindow* _w,f64 mx,f64 my){
            auto it = __windows.find(_w);
            if(it ==  __windows.end()) return;
            it->second->onMousePos(mx,my);
        });

        glfwSetMouseButtonCallback(this->w,[](GLFWwindow* _w,i32 button, i32 action, i32 mods){
            auto it = __windows.find(_w);
            if(it ==  __windows.end()) return;
            it->second->onMouseButton(button,action,mods);
        });

        glfwSetScrollCallback(this->w,[](GLFWwindow* _w,f64 dx,f64 dy){
            auto it = __windows.find(_w);
            if(it ==  __windows.end()) return;
            it->second->onMouseScroll(dx,dy);
        });
    }

    fun currentActivity(Activity* _a){
        this->a = _a;
    }

    int draw(){
        if(a != null) a->onCreate();
        while(!glfwWindowShouldClose(w)){
            View* v = a->content();
            i32 winWidth, winHeight;
            i32 fbWidth, fbHeight;

            glfwGetWindowSize(this->w, &winWidth, &winHeight);
            glfwGetFramebufferSize(this->w, &fbWidth, &fbHeight);
            vec2 viewport((f32)winWidth, (f32)winHeight);
            a->size(viewport);

            // Update and render
            glViewport(0, 0, fbWidth, fbHeight);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
            if(canvas != null){
                glClearColor(0.3,0.3,0.3,1.0);
                canvas->beginFrame((f32) winWidth, (f32) winHeight, (f32) fbWidth / (f32) winWidth);
                    if(v != null) {
                        v->onMeasure();
                        v->onDraw(canvas);
                    }
                canvas->endFrame();
            }
            glfwSwapBuffers(this->w);
            glfwPollEvents();
        }
        return 0;
    }
/*
    fun checkScrollable(View* v){
        i32 _w,_h;
        glfwGetWindowSize(this->w,&_w,&_h);
        v->setWinSize((f32)_w,(f32)_h);
        if(v->rect().w > (f32)_w){
            v->setScrollableH(true);
        }else{
            v->setScrollableH(false);
        }
        if(v->rect().h > (f32)_h){
            v->setScrollableV(true);
        }else{
            v->setScrollableV(false);
        }
    }
*/
    fun onKey(i32 key, i32 scancode, i32 action, i32 mods){
        if(a != null && a->content() != null) a->content()->onKey(key,scancode,action,mods);
    }
    fun onKey(u32 codepoint){
        if(a != null && a->content() != null) a->content()->onKey(codepoint);
    }
    fun onMousePos(f64 x,f64 y){
        if(a != null && a->content() != null) a->content()->onMouse(x,y,0,0,0);
    }
    fun onMouseButton(i32 button, i32 action, i32 mods){
        if(a != null && a->content() != null) {
            f64 x,y;
            glfwGetCursorPos(this->w,&x,&y);
            a->content()->onMouse(x, y, button, action, mods);
        }
    }
    fun onMouseScroll(f64 dx,f64 dy){
        if(a != null && a->content() != null) a->content()->onMouseScroll(dx,dy);
    }

private:
    static void error(const char* err){
        printf("%s\n",err);
        exit(-1);
    }
};

#endif
