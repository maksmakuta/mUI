#include <app/Activity.h>

Activity::Activity(){/* ... */}

fun Activity::setContentView(View* v){
    this->mView = v;
}
fun Activity::onKey(){/* ... */}
fun Activity::onMouse(){/* ... */}

View* Activity::getView(){
    return this->mView;
}


Activity::~Activity(){
    delete this->mView;
}
