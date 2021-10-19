#ifndef MUI_OBJECT_H
#define MUI_OBJECT_H

#include "sTypes.h"

class Object {
private:
    u64 ID{0};
public:
    Object();
    explicit Object(u64);
    Object(Object& obj);

    virtual str  toString();
    virtual bool equal(Object& obj);


    u64 getID();
    fun setID(u64);

    template<class T>  T getClassObj(){
        return (T)this;
    }

};


#endif
