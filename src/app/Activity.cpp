#include "Activity.h"

Activity::Activity(){

}
fun Activity::setLayout(View* v){
    if(v != null){
        this->layout = v;
    }
}
View* Activity::getLayout(){
    return this->layout;
}
