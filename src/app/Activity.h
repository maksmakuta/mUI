#ifndef ACTIVITY_H
#define ACTIVITY_H

#include "../types.h"
#include "../view/View.h"

class Activity{
private:
    View* main = null;
public:
    Activity(){/* ... */}

    virtual fun onCreate() = 0;
    virtual fun onKey(i32 k){/* ... */}

    ~Activity(){
        delete main;
    }

};

#endif
