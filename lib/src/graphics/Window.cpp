#include <graphics/Window.h>
#include <utils/Logger.h>

Window::Window() : Window(640,480,"App"){}
Window::Window(int w,int h,const std::string& t){
    init(w,h,t);
}
fun Window::init(int w,int h,const std::string& t){
    if(!glfwInit()) Log::onError("glfw");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->win = glfwCreateWindow(w,h,t.c_str(), nullptr, nullptr);
    if(!win) Log::onError("window");
    glfwMakeContextCurrent(win);
    if(glewInit() != GLEW_OK) Log::onError("glew");
    glfwSwapInterval(1);

    canvas = new Canvas(/*NVG_STENCIL_STROKES|NVG_ANTIALIAS*/);
}
fun Window::run(){
    while(!glfwWindowShouldClose(win)){
        i32 winWidth, winHeight;
        i32 fbWidth, fbHeight;

        glfwGetWindowSize(this->win, &winWidth, &winHeight);
        glfwGetFramebufferSize(this->win, &fbWidth, &fbHeight);
        // Update and render
        glViewport(0, 0, fbWidth, fbHeight);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
        if(canvas != null){
            glClearColor(0.1,0.1,0.1,1);
            canvas->beginFrame(winWidth,winHeight,winHeight/fbHeight);

            canvas->endFrame();
        }
        glfwSwapBuffers(this->win);
        glfwPollEvents();
    }
}
i32 Window::done(){
    return 0;
}
int Window::getWidth(){
    return this->size[0];
}
int Window::getHeigth(){
    return this->size[1];
}

Window::~Window(){

}
