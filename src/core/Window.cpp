#include "Window.h"

Window::Window() : Window(640,480,"Window"){}
Window::Window(i32 w,i32 h,const char* t){
    if(!glfwInit()) error("glfw");

    glfwInitHint(GLFW_VERSION_MAJOR,3);
    glfwInitHint(GLFW_VERSION_MINOR,2);
    glfwInitHint(GLFW_EGL_CONTEXT_API,GLFW_OPENGL_API);
    glfwInitHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_SAMPLES, 4);
    //glfwWindowHint(GLFW_DECORATED,false);


    this->win = glfwCreateWindow(w,h,t,null,null);
    if(!win) error("window");

    glfwMakeContextCurrent(this->win);
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK) error("glew");
    glfwSwapInterval(1);

    this->c = new Canvas(NVG_STENCIL_STROKES|NVG_ANTIALIAS);
}


fun Window::draw(View *v) {
    while (!glfwWindowShouldClose(this->win)) {
        f64 mx, my, t, dt;
        i32 winWidth, winHeight;
        i32 fbWidth, fbHeight;
        f32 pxRatio;

        t = glfwGetTime();
        dt = t - prev;
        prev = t;

        glfwGetCursorPos(this->win, &mx, &my);
        glfwGetWindowSize(this->win, &winWidth, &winHeight);
        glfwGetFramebufferSize(this->win, &fbWidth, &fbHeight);

        pxRatio = (float) fbWidth / (float) winWidth;

        // Update and render
        glViewport(0, 0, fbWidth, fbHeight);
        glClearColor(0.3f, 0.3f, 0.32f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        if(c != null){
            c->beginFrame((f32) winWidth, (f32) winHeight, pxRatio);
                if(decor)
                    border(c,(f32)winWidth,(f32)winHeight);
            if (v != null) {
                v->onDraw(c);
            }
            c->endFrame();
        }
        glfwSwapBuffers(this->win);
        glfwPollEvents();
    }
}

fun Window::border(Canvas* _c,f32 w,f32 h){
    _c->begin();
    _c->rect(0,0,w,h);
    _c->fill("#F00");
    _c->end(false);
}


fun Window::error(const char* t){
    printf("Error -> %s\n",t);
    if(this->win != null){
        glfwTerminate();
        exit(-1);
    }
}