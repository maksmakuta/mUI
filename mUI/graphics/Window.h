#ifndef MUI_WINDOW_H
#define MUI_WINDOW_H

#include <map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Canvas.h"
#include "utils/ColorUtils.h"
#include "../app/Activity.h"

class Window; // class declaration

/**
 * used for multi-window rendering (not implemented)
 */
std::map<GLFWwindow*,Window*> __windows;

/**
 * Window
 * API 2.0
 * @since 0.0.2a (alpha)
 */
class Window{
private:
    GLFWwindow* w = null;   // Window class to make context for drawing
    Canvas* canvas = null;  // Canvas class to draw in window
    Activity *a = null;     // Activity to draw
public:
    /**
     * constructor
     *
     * init glfw and glew  libraries
     * and load window with renderer (Canvas class)
     *
     * @param _w : Int
     * @param _h : Int
     * @param _t : String
     */
    Window(int _w,int _h,const str& _t){
        if(!glfwInit()) error("glfw");

        glfwWindowHint(GLFW_VERSION_MAJOR,3);
        glfwWindowHint(GLFW_VERSION_MINOR,3);
        glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);

        w = glfwCreateWindow(_w,_h,_t.c_str(), nullptr, nullptr);
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

    /**
     * method to set activity for draw
     * @param _a : Activity
     */
    fun currentActivity(Activity* _a){
        this->a = _a;
    }
    /**
     * method for draw interface
     * @return Int
     */
    int draw(){
        if(a != null){
            a->onCreate();
            a->applyTheme();
        }
        NVGcolor bg = ColorUtils::color(a->getTheme()->colorBackground());
        while(!glfwWindowShouldClose(w)){
            View* v = a->content();
            i32 winWidth, winHeight;
            i32 fbWidth, fbHeight;

            glfwGetWindowSize(this->w, &winWidth, &winHeight);
            glfwGetFramebufferSize(this->w, &fbWidth, &fbHeight);
            // Update and render
            glViewport(0, 0, fbWidth, fbHeight);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
            if(canvas != null){
                glClearColor(bg.r,bg.g,bg.b,bg.a);
                canvas->beginFrame((f32) winWidth, (f32) winHeight, (f32) fbWidth / (f32) winWidth);
                    if(v != null) {
                        v->onMeasure((f32)winWidth,(f32)winHeight);
                        v->onDraw(canvas);
                    }
                canvas->endFrame();
            }
            glfwSwapBuffers(this->w);
            glfwPollEvents();
        }
        return 0;
    }
    /**
     * onKey callback
     *
     * run when keyboard is pressed
     *
     * @param key : Int
     * @param scancode : Int
     * @param action : Int
     * @param mods : Int
     */
    fun onKey(i32 key, i32 scancode, i32 action, i32 mods){
        if(a != null && a->content() != null) a->content()->onKey(key,scancode,action,mods);
    }
    /**
     * onKey callback
     * @param codepoint : Unsigned Int -> code of key
     */
    fun onKey(u32 codepoint){
        if(a != null && a->content() != null) a->content()->onKey(codepoint);
    }
    /**
     * onMouse callback
     * @param x : Double -> x position of mouse pointer
     * @param y : Double -> y position of mouse pointer
     */
    fun onMousePos(f64 x,f64 y){
        if(a != null && a->content() != null) a->content()->onMouse(x,y,0,0,0);
    }
    /**
     * onMouseButton callback
     * @param button : Int -> name of mouse button
     * @param action : Int -> type of action
     * @param mods : Int -> modificator
     */
    fun onMouseButton(i32 button, i32 action, i32 mods){
        if(a != null && a->content() != null) {
            f64 x,y;
            glfwGetCursorPos(this->w,&x,&y);
            a->content()->onMouse(x, y, button, action, mods);
        }
    }
    /**
     * onScroll callback
     * @param dx : Double -> amount of scroll by x
     * @param dy : Double -> amount of scroll by y
     */
    fun onMouseScroll(f64 dx,f64 dy){
        if(a != null && a->content() != null) a->content()->onMouseScroll(dx,dy);
    }

    /**
     * destructor
     */
    ~Window(){
        delete a;
        delete canvas ;
        glfwTerminate();
        //delete (w = null);
    }

private:
    /**
     * print error message and end app
     * @param err : String -> error message
     */
    static void error(const char* err){
        printf("%s\n",err);
        exit(-1);
    }
};

#endif
