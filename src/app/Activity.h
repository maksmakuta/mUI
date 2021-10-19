#ifndef MUI_ACTIVITY_H
#define MUI_ACTIVITY_H

#include "../view/core/View.h"
#include "../Object.h"

class View;

class Activity : public Object{
private:
    View* layout = null;
public:
    Activity();
    fun setLayout(View*);
    View* getLayout();
};


#endif