#include "Window.h"
#include "../graphics/ColorUtils.h"
#include "../view/core/Layout.h"
#include <cstdlib>
#include <cstdio>

Window::Window(i32 _w,i32 _h,const char* _t) {
    if(!glfwInit()) error("GLFWInit()");

    glfwInitHint(GLFW_VERSION_MAJOR,3);
    glfwInitHint(GLFW_VERSION_MINOR,2);
    glfwInitHint(GLFW_EGL_CONTEXT_API,GLFW_OPENGL_API);
    glfwInitHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);
    this->win = glfwCreateWindow(_w,_h,_t,null,null);
    if(!this->win) error("window");

    glfwMakeContextCurrent(this->win);
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK) error("glew");
    glfwSwapInterval(1);

    this->c = new Canvas();
}
fun Window::setBG(const char* h){
    this->bg = ColorUtils::color(h);
}

fun Window::draw(View* v){
    while(!glfwWindowShouldClose(this->win)){
        f64 t, dt;
        t = glfwGetTime();
        dt = t - prevt;
        prevt = t;

        i32 fbWidth, fbHeight;
        glfwGetFramebufferSize(this->win, &fbWidth, &fbHeight);

        i32 w,h;
        glfwGetWindowSize(this->win,&w,&h);

        f64 mx,my;
        glfwGetCursorPos(this->win,&mx,&my);

        glViewport(0, 0, fbWidth, fbHeight);

        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
        if(this->c != null){
            this->c->beginFrame( (f32)w, (f32)h, (f32)fbWidth / (f32)w);
            glClearColor(this->bg.r,this->bg.g,this->bg.b,this->bg.a);
            if(v != null) {
                v->onDraw(this->c);
                v->onResize((f32)w,(f32)h);
            }
            this->c->endFrame();
        }
        glfwSwapBuffers(this->win);
        glfwPollEvents();
    }

}

fun Window::error(const char* t){
    printf("%s\n",t);
    if(this->win != null){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}