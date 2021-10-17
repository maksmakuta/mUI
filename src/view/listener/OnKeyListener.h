#ifndef MUI_ONKEYLISTENER_H
#define MUI_ONKEYLISTENER_H
#include "../../sTypes.h"
#include "Listener.h"

class OnKeyListener: public Listener{
public:
    virtual fun onKey(View* v) = 0;
};
#endif
