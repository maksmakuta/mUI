#include <app/Application.h>

App::App() : App(640,480,"Title"){/* ... */ }
App::App(int w,int h,const std::string& t) : App(w,h,t,null){/* ... */}
App::App(int w,int h,const std::string& t,Activity* activity){
    this->mWindow = new Window();
    if(nonNull(activity))
        this->mActivity = activity;
}
