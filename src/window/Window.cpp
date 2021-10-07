#include "Window.h"

fun onResize(GLFWwindow*, i32 w,i32 h){
    glViewport( 0, 0, w,  h );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(0,0,w,h,-1,1);
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
    glfwInitHint(GLFW_VERSION_MINOR,3);
    glfwInitHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

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

fun Window::setBG(Color *c){
    if(c != null)
        this->bg = c;
}

fun Window::draw(){
    while(!glfwWindowShouldClose(win)){
        glClear(GL_COLOR_BUFFER_BIT);

        if(bg != null)
            glClearColor(bg->getRf(),bg->getGf(),bg->getBf(),bg->getAf());


        glfwSwapBuffers(win);
        glfwPollEvents();
    }
}

fun Window::error(const char* t){
    printf("%s\n",t);
    if(win != null){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}