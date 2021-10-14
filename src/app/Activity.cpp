#include "Activity.h"

Activity::Activity(){

}
fun Activity::setLayout(View* v){
    if(v != null){
        this->layout = v;
    }
}
fun Activity::draw(Canvas* canvas){
    if(this->layout != null){
      //  layout->onDraw(canvas);
    }
}

View* Activity::getLayout(){
    return this->layout;
}
