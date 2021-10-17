#ifndef MUI_ONCLICKLISTENER_H
#define MUI_ONCLICKLISTENER_H

#include "Listener.h"

class OnClickListener : public Listener{
public:
    virtual fun onClick(View* v) = 0;
};

#endif