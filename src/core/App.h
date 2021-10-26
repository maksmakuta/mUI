#ifndef MUI_APP_H
#define MUI_APP_H

#include "types.h"
#include "Window.h"

class App {
private:
    Window* w = null;
    View* view = null;
    Theme* theme;
public:
    App(i32 _w,i32 _h,const char* _t);
    fun setTheme(Theme* t);
    fun layout(View*);
    int run();
};


#endif
