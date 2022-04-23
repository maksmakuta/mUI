#include <app/Application.h>
#include <utils/Logger.h>

App::App() : App(640,480,"Title"){/* ... */ }
App::App(int w,int h,const std::string& t) : App(w,h,t,null){/* ... */}
App::App(int w,int h,const std::string& t,Activity* activity){
    this->mWindow = new Window();
    if(nonNull(activity))
        this->mActivity = activity;
}

int App::exec(){
    if(nonNull(mWindow)){
        this->mWindow->run();
        return this->mWindow->done();
    }else{
        Log::onError("App::Window = null");
        return -1;
    }
}
