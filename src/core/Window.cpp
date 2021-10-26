#include <map>
#include "Window.h"

std::map<GLFWwindow *, Window *> mUI_screens;

f32 scale(GLFWwindow* w){
    i32 winWidth, winHeight;
    i32 fbWidth, fbHeight;

    glfwGetWindowSize       (w, &winWidth, &winHeight);
    glfwGetFramebufferSize  (w, &fbWidth, &fbHeight);

    return (f32) fbWidth / (f32) winWidth;
}

Window::Window() : Window(640,480,"Window"){}
Window::Window(i32 w,i32 h,const char* t){
    if(!glfwInit()) error("glfw");

    glfwInitHint(GLFW_VERSION_MAJOR,3);
    glfwInitHint(GLFW_VERSION_MINOR,2);
    glfwInitHint(GLFW_EGL_CONTEXT_API,GLFW_OPENGL_API);
    glfwInitHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_SAMPLES, 4);

    this->win = glfwCreateWindow(w,h,t,null,null);
    if(!win) error("window");

    glfwMakeContextCurrent(this->win);
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK) error("glew");
    glfwSwapInterval(1);

    this->c = new Canvas(NVG_STENCIL_STROKES|NVG_ANTIALIAS);

    mUI_screens.insert(std::pair<GLFWwindow*,Window*>(this->win,this));

    glfwSetKeyCallback(this->win,[](GLFWwindow* w,i32 key, i32 scancode, i32 action, i32 mods){
        auto it = mUI_screens.find(w);
        if(it == mUI_screens.end()) return;
        it->second->onKey(key,scancode,action,mods);
    });

    glfwSetCharCallback(this->win,[](GLFWwindow* w,u32 charcode){
        auto it = mUI_screens.find(w);
        if(it == mUI_screens.end()) return;
        it->second->onKey(charcode);
    });

    glfwSetCursorPosCallback(this->win,[](GLFWwindow* w,f64 mx,f64 my){
        auto it = mUI_screens.find(w);
        if(it == mUI_screens.end()) return;
        f32 s = scale(w);
        it->second->onMousePos(mx * s,my * s);
    });

    glfwSetMouseButtonCallback(this->win,[](GLFWwindow* w,i32 button, i32 action, i32 mods){
        auto it = mUI_screens.find(w);
        if(it == mUI_screens.end()) return;
        it->second->onMouseButton(button,action,mods);
    });

    glfwSetScrollCallback(this->win,[](GLFWwindow* w,f64 dx,f64 dy){
        auto it = mUI_screens.find(w);
        if(it == mUI_screens.end()) return;
        it->second->onMouseScroll(dx,dy);
    });
}


fun Window::theme(Theme* t){
    if(this->c != null)
        c->apply(t);
}

fun Window::draw(View *v) {
    this->mainView = v;
    while (!glfwWindowShouldClose(this->win)) {
        i32 winWidth, winHeight;
        i32 fbWidth, fbHeight;

        glfwGetWindowSize(this->win, &winWidth, &winHeight);
        glfwGetFramebufferSize(this->win, &fbWidth, &fbHeight);

        // Update and render
        glViewport(0, 0, fbWidth, fbHeight);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        if(c != null){
            NVGcolor bg = ColorUtils::color(c->getTheme()->getPrimaryColor());
            glClearColor(bg.r,bg.g,bg.b,bg.a);
            c->beginFrame((f32) winWidth, (f32) winHeight, (f32) fbWidth / (f32) winWidth);
            if (mainView  != null) {
                mainView->size((f32) winWidth, (f32) winHeight);
                mainView ->onDraw(c);
            }
            c->endFrame();
        }
        glfwSwapBuffers(this->win);
        glfwPollEvents();
    }
}


fun Window::onKey(i32 key, i32 scancode, i32 action, i32 mods){
    if(mainView != null){
        mainView->onKeyboard(key,scancode,action,mods);
    }
}
fun Window::onKey(u32 codepoint){
    if(mainView != null){
        mainView->onKeyboard(codepoint);
    }
}

fun Window::onMousePos(f64 x,f64 y){
    if(mainView != null){
        mainView->onMouse((f32)x,(f32)y,0,0,0);
    }
}
fun Window::onMouseButton(i32 button, i32 action, i32 mods){
    if(mainView != null){
        f64 x,y;
        glfwGetCursorPos(this->win,&x,&y);
        mainView->onMouse((f32)x,(f32)y,button,action,mods);
    }
}
fun Window::onMouseScroll(f64 dx,f64 dy){
    if(mainView != null){
        mainView->onScroll((f32)dx,(f32)dy);
    }
}

fun Window::error(const char* t){
    printf("Error -> %s\n",t);
    if(this->win != null)
        glfwTerminate();
    exit(-1);
}