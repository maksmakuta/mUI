#ifndef MUI_ONCLICKLISTENER_H
#define MUI_ONCLICKLISTENER_H

#include "../View.h"

class View;

class OnClickListener{
public:
    virtual fun onClick(View* v) = 0;
};

#endif
