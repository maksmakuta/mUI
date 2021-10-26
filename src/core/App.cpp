#define WINDOW_VIEW
#include "App.h"

App::App(i32 _w,i32 _h,const char* _t){
    this->w = new Window(_w,_h,_t);
}
fun App::layout(View* _v){
    this->view = _v;
    if(theme != null)
        this->view->applyTheme(theme);
}
fun App::setTheme(Theme* t){
    this->theme = t;
}
int App::run() {
    if(this->w != null) {
        this->w->draw(this->view);
    }
    return 0;
}