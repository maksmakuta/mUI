#ifndef MUI_APPLICATION_H
#define MUI_APPLICATION_H

#include "../window/Window.h"
#include "Activity.h"

class Application {
private:
    Window *w = null;
    Activity *a = null;
public:
    Application(i32 w,i32 h,const char* title);
    fun args(i32 a,char** b);
    fun setMainActivity(Activity*);
    fun exec();
};


#endif
