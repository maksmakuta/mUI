#ifndef MUI_ACTIVITY_H
#define MUI_ACTIVITY_H

#include "../types.h"
#include "../view/View.h"
#include "Theme.h"

/**
 * Activity
 * API 1.0
 * since - 0.3
 */
class Activity{
private:
    View* mContent = null;  // main view
    Theme* theme = null;    // main theme
    str name;               // name of app
public:
    /**
     *  default constructor
     */
    Activity() = default;

    /**
     * method to set global name to activity
     * @param _name : String -> global app name
     */
    fun setName(const str& _name){
        this->name = _name;
    }

    /**
     * method to get global name
     * @return String
     */
    str getName(){
        return this->name;
    }
    /**
     * method to set theme to activity
     * @param t : Theme* -> theme for all activity
     */
    fun setTheme(Theme* t){
        this->theme = t;

    }
    /**
     * method to get theme from activity
     * @return Theme
     */
    Theme* getTheme(){
        return this->theme;
    }
    /**
     * setting main view
     * @param v : View -> parent View with childs View
     */
    fun setContentView(View* v){
        this->mContent = v;
    }

    /**
     * get view to render
     * @return View
     */
    View* content(){return this->mContent;}

    /**
     * set global theme to every widget
     */
     fun applyTheme(){
         if(mContent != null)
            mContent->setTheme(theme);
     }

    /**
     * method to init view
     * called by @App
     */
    virtual fun onCreate() = 0;

    /**
     * onKey callback for app
     */
     virtual fun onKey(i32 key, i32 scancode, i32 action, i32 mods){

     }

    /**
     * destructor
     */
    virtual ~Activity(){
        delete mContent;
        delete theme;
    }

};

#endif
