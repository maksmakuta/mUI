#ifndef MUI_ACTIVITY_H
#define MUI_ACTIVITY_H

#include "../view/View.h"

class Activity {
private:
    View* layout = null;
public:

    Activity();
    fun setLayout(View*);
    fun draw(Canvas*);

    View* getLayout();
};


#endif