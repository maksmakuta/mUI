#ifndef MUI_APPLICATION_H
#define MUI_APPLICATION_H

#include "../window/Window.h"
#include "Activity.h"
#include "../Object.h"

class Application : public Object{
private:
    Window *w = null;
    Activity *a = null;
    str title;
public:
    Application(i32 w,i32 h,const char* title);
    fun args(i32 a,char** b);
    fun setMainActivity(Activity*);
    fun exec();

    bool equal(Object &obj) override;
    str toString() override;
};


#endif
