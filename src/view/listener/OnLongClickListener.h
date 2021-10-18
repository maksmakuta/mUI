#ifndef MUI_ONLONGCLICKLISTENER_H
#define MUI_ONLONGCLICKLISTENER_H

#include "Listener.h"

class OnLongClickListener : public Listener{
public:
    virtual fun onLongClick(View* v) = 0;
};

#endif
