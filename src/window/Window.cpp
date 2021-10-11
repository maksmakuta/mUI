#include "Window.h"

fun onResize(GLFWwindow*, i32 w,i32 h){
    glViewport( 0, 0, w,  h );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(0,w,h,0,-1,1);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

Window::Window() : Window(640,480,"Test"){}

Window::Window(i32 _w,i32 _h,const char* _t){
    prepare();
    init(_w,_h,_t);
}

fun Window::prepare(){
    if(!glfwInit()) error("GLFWInit()");

    glfwInitHint(GLFW_VERSION_MAJOR,3);
    glfwInitHint(GLFW_VERSION_MINOR,2);
    glfwInitHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    c = nvgCreateGL3(NVG_ANTIALIAS | NVG_STENCIL_STROKES);
    if(!c) error("nanoVG");

}

fun Window::init(i32 _w,i32 _h,const char* _t){
    win = glfwCreateWindow(_w,_h,_t,null,null);
    if(!win) error("window");

    glfwMakeContextCurrent(win);
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK) error("glew");
    glfwSwapInterval(1);

    glfwSetWindowSizeCallback(win,onResize);
    onResize(win,_w,_h);

}

fun Window::resize(i32 w,i32 h){
    glfwSetWindowSize(win,w,h);
}

fun Window::remove(i32 x,i32 y){
    glfwSetWindowPos(win,x,y);
}

fun Window::draw(){

    while(!glfwWindowShouldClose(win)){
        double mx, my, t, dt;
        int winWidth, winHeight;
        int fbWidth, fbHeight;
        float pxRatio;

        t = glfwGetTime();
        dt = t - prevt;
        prevt = t;

        glfwGetCursorPos(win, &mx, &my);
        glfwGetWindowSize(win, &winWidth, &winHeight);
        glfwGetFramebufferSize(win, &fbWidth, &fbHeight);

        pxRatio = (float)fbWidth / (float)winWidth;

        glViewport(0, 0, fbWidth, fbHeight);
        glClearColor(0,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);

        nvgBeginFrame(c, winWidth, winHeight, pxRatio);

        //renderDemo(c, mx,my, winWidth,winHeight, t, blowup, &data);

        nvgEndFrame(c);
        cpuTime = glfwGetTime() - t;

        glfwSwapBuffers(win);
        glfwPollEvents();
    }
}


fun Window::error(const char* t){
    printf("%s\n",t);
    if(win != null){
        if(c != null){
            nvgDeleteGL3(c);
        }
        glfwTerminate();
        exit(EXIT_FAILURE);

    }
}