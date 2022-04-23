#ifndef VIEW_H
#define VIEW_H

#include <graphics/Canvas.h>
#include <utils/TypeUtils.h>
#include <vector>

class View{
private:
    std::vector<View*> childView;
    i64 id;
public:
    View();
    View(i64);

    virtual fun onDraw(Canvas*) = 0;

    virtual fun onMeasure();
    fun onAdd(View*);
    fun onRemove(View*);
    fun onRemove(i64);

    fun setID(i64);

    ~View();
};

#endif // VIEW_H
