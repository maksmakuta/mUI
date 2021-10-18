#ifndef MUI_ONHOVERLISTENER_H
#define MUI_ONHOVERLISTENER_H

#include "../../sTypes.h"
#include "Listener.h"

class OnHoverListener : public Listener{
public:
    virtual fun onHover(View* v) = 0;
};
#endif
