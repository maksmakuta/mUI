#ifndef APP_H
#define APP_H

#include "../types.h"
#include "Activity.h"
#include "Logger.h"
#include "../graphics/Window.h"

class App{
private:
    Activity* main = null;
    Window* win = null;
public:
    App(i32 w, i32 h,const str& n, Activity* a){
        this->setActivity(a);
        this->win = new Window(w,h,n);
    }

    fun setActivity(Activity* a){
        if(nonNull(a))
            this->main = a;
        else
            Log::onWarning("App()::setActivity(null)");
    }

    int run(){
        if(nonNull(win)){
            win->draw();
            return 0;
        }else{
            Log::onError("App()::run()");
            return 1;
        }

    }
};

#endif

