#include "Application.h"

Application::Application(i32 w,i32 h,const char* _title){
    this->w = new Window(w,h,_title);
}
fun Application::args(i32 a,char** b){
    // empty
}
fun Application::setMainActivity(Activity* _a){
    if(_a != null){
        this->a = _a;
    }
}
fun Application::exec(){
    if(this->w != null)
        this->w->draw(this->a->getLayout());
}