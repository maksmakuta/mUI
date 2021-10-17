#ifndef MUI_ACTIVITY_H
#define MUI_ACTIVITY_H

#include "../view/core/View.h"

class View;

class Activity {
private:
    View* layout = null;
public:
    Activity();
    fun setLayout(View*);
    View* getLayout();
};


#endif