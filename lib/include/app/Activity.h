#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <utils/TypeUtils.h>
#include <view/View.h>

class Activity{
private:
    View* mView = null;
public:
    Activity();

    fun setContentView(View*);
    virtual fun onCreate() = 0;
    virtual fun onKey();
    virtual fun onMouse();

    View* getView();

    ~Activity();

};

#endif // ACTIVITY_H
