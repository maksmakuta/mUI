#ifndef WINDOW_H
#define WINDOW_H

#include <utils/TypeUtils.h>
#include <graphics/Canvas.h>
#include <app/Activity.h>
#include <GLFW/glfw3.h>
#include <string>

class Window{
private:
    Canvas* canvas = null;
    Activity* activity = null;
    GLFWwindow* win = null;

    i32 size[2];
    std::string title;
public:
    Window();
    Window(int,int,const std::string&);
    fun init(int,int,const std::string&);
    fun run();
    i32 done();

    i32 getWidth();
    i32 getHeigth();

    ~Window();
};

#endif // WINDOW_H
