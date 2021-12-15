#ifndef MUI_APP_H
#define MUI_APP_H

#include "../types.h"
#include "Activity.h"
#include "Theme.h"
#include "../graphics/Window.h"

/**
 * App
 * API 1.0.1
 * @since 0.4.3
 */
class App{
private:
    Window* w = null; // Window when content rendered
    str name;         // global app name
public:
    /**
     *  default constructor
     */
    App() : App(640,480,"App"){ }

    /**
     * constructor
     *
     *  make new window where app render
     *  set global name
     *
     * @param _w : Int -> window width
     * @param _h : Int -> window height
     * @param _t : String -> window title
     */
    App(i32 _w,i32 _h,const str& _t,bool decorated = true){
        this->w = new Window(_w,_h,_t,decorated);
        this->name = _t;
    }
    /**
     * method to set main activity with default theme
     * @param _activity : Activity* -> activity to run
     */
    fun setActivity(Activity* _activity){
        setActivity(_activity,Theme::Dark());
    }
    /**
     * method to set main activity and theme
     * @param _activity : Activity* -> activity to draw
     * @param appTheme : Theme* -> global theme
     */
    fun setActivity(Activity* _activity,Theme *appTheme){
        _activity->setName(name);
        _activity->setTheme(appTheme);
        this->w->currentActivity(_activity);
    }
    /**
     * method to run app
     * @return Int
     */
    i32 exec(){
        if(w != null){
            return w->draw();
        }
        return -1;
    }
};

#endif
