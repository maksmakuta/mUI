#include "Window.h"

#include <cstdlib>
#include <cstdio>
#include <sstream>

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

}

fun Window::init(i32 _w,i32 _h,const char* _t){
    win = glfwCreateWindow(_w,_h,_t,null,null);
    if(!win) error("window");

    glfwMakeContextCurrent(win);
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK) error("glew");
    glfwSwapInterval(1);

    this->c = new Canvas();

    glfwSetWindowSizeCallback(win,onResize);
    onResize(win,_w,_h);

}


fun Window::setBG(const char* h){
    this->bg = ColorUtils::color(h);
}

fun Window::resize(i32 w,i32 h){
    glfwSetWindowSize(win,w,h);
}

fun Window::remove(i32 x,i32 y){
    glfwSetWindowPos(win,x,y);
}

fun Window::draw(View* layout){

    while(!glfwWindowShouldClose(win)){
        f64 mx, my, t, dt;
        i32 winWidth, winHeight;
        i32 fbWidth, fbHeight;
        f32 pxRatio;

        t = glfwGetTime();
        dt = t - prevt;
        prevt = t;

        glfwGetCursorPos(win, &mx, &my);
        glfwGetWindowSize(win, &winWidth, &winHeight);
        glfwGetFramebufferSize(win, &fbWidth, &fbHeight);

        pxRatio = (float)fbWidth / (float)winWidth;

        glViewport(0, 0, fbWidth, fbHeight);
        //glClearColor(0,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
        if(this->c != null){
            this->c->beginFrame( (f32)winWidth, (f32)winHeight, pxRatio);

            glClearColor(this->bg.r,this->bg.g,this->bg.b,this->bg.a);

<<<<<<< HEAD
            if(layout != null)
                    layout->onDraw(this->c);
=======
            if(layout != null) {
                layout->onDraw(this->c);
                if(layout->getViewRect().inside((f32)mx,(f32)my)) {
                    layout->onHover(this->c);
                }

                if(layout->getViewRect().inside((f32)mx,(f32)my) && glfwGetMouseButton(win,GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
                    if(layout->listeners(OnCLick) != null)
                        ((OnClickListener*)layout->listeners(OnCLick))->onClick();
                }
            }
            std::stringstream ss;
            ss << "Mouse : " << mx << ":" << my;
            this->c->color("#fff");
            this->c->drawText(fbWidth / 2, fbHeight / 2,ss.str().c_str(),"font",30);

>>>>>>> stable
            this->c->endFrame();
        }

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