#ifndef MUI_ONMOVELISTENER_H
#define MUI_ONMOVELISTENER_H

#include "../../sTypes.h"
#include "Listener.h"

class OnMoveListener: public Listener{
public:
    virtual fun onMove(View* v) = 0;
};

#endif
