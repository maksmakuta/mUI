#ifndef WINDOW_H
#define WINDOW_H

#include <utils/TypeUtils.h>
#include <graphics/Canvas.h>
#include <app/Activity.h>

class Window{
private:
    Canvas* canvas = null;
    Activity* activity = null;

    int size[2];
    char* title;
public:
    Window();
    fun init();
    fun run();
    int done();
};

#endif // WINDOW_H
