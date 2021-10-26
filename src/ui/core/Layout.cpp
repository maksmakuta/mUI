#include "Layout.h"


fun Layout::add(View* v){
        child.push_back(v);
        //onMeasure();
}
fun Layout::del(i32 pos) {
    child.erase(child.begin() + pos);
}
fun Layout::del(View* v){
        for (i32 i = 0; i < (i32) child.size(); i++)
            if (v == child[i])
                child.erase(child.begin() + i);
}

std::vector<View*> Layout::getChild(){return this->child;}
