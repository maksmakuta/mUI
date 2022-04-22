#ifndef APPLICATION_H
#define APPLICATION_H

#include <app/Activity.h>
#include <graphics/Window.h>
#include <string>

class App{
private:
    Activity *mActivity = null;
    Window *mWindow = null;
public:
    App();
    App(int w,int h,const std::string& t);
    App(int w,int h,const std::string& t,Activity*);
};

#endif // APPLICATION_H
