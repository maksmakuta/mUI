#include "Object.h"


Object::Object() : Object(0){

}
Object::Object(u64 id){
    this->setID(id);
}
Object::Object(Object& obj) : Object(obj.getID()){}

str  Object::toString(){
    return "Object()";
}
bool Object::equal(Object& obj){
    return this->toString() == obj.toString() && this->getID() == obj.getID();
}

u64 Object::getID(){
    return this->ID;
}

fun Object::setID(u64 i){
    this->ID = i;
}