#include <view/View.h>

View::View() : View(0){/* ... */ }
View::View(i64 i){
    this->setID(i);
}
fun View::onMeasure(){

}
fun View::onAdd(View* v){
    this->childView.push_back(v);
}
fun View::onRemove(View* v){
    this->onRemove(v->id);
}
fun View::onRemove(i64 id){
    for(int a = 0;a < this->childView.size();a++){
        if(childView[a]->id == id) this->childView.erase(this->childView.begin() + a);
    }
}
fun View::setID(i64 i){
    this->id = i;
}
View::~View(){
    this->childView.clear();
}
