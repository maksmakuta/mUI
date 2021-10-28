#ifndef MUI_APP_H
#define MUI_APP_H

#include "../types.h"
#include "Activity.h"
#include "../graphics/Window.h"

class App{
priv:
    Window* w = null;
pub:
    App() : App(640,480,"App"){

    }

    App(i32 _w,i32 _h,const char* _t){
        this->w = new Window(_w,_h,_t);
    }

    fun setActivity(Activity* _activity){
        this->w->currentActivity(_activity);
    }

    i32 exec(){
        if(w != null){
            return w->draw();
        }
        return -1;
    }
};

#endif
