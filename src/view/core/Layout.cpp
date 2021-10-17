#include "Layout.h"

Layout::Layout() : View(true){ }

fun Layout::add(View* v){
    this->childs.push_back(v);
}
fun Layout::remove(View* v){
    for(i32 i = 0;i < (i32)childs.size();i++){
        if(childs[i] == v){
            childs.erase(childs.begin() + i);
        }
    }
}
fun Layout::update(View* v){
    for(auto & child : childs){
        if(child == v){
            child = v;
        }
    }
}


std::vector<View*> Layout::child(){
    return this->childs;
}