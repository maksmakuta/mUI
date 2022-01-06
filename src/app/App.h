#ifndef APP_H
#define APP_H

#include "../types.h"
#include "Activity.h"
#include "Logger.h"
#include "../graphics/Window.h"
#include "../graphics/Backend.h"

class App{
private:
    Activity* main = null;
    Window* win = null;
    Backend backend;
public:
    App(i32 w, i32 h,const str& n, Activity* a){
        this->setActivity(a);
        this->win = new Window(w,h,n);
        this->backend = Default;
    }

    fun setActivity(Activity* a){
        if(nonNull(a))
            this->main = a;
        else
            Log::onWarning("App()::setActivity(null)");
    }

    fun setBackend(Backend b){
        this->backend = b;
        if(nonNull(win)){
            this->win->renderer(b);
        }
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

    ~App(){
        delete win;
    }
};

#endif

