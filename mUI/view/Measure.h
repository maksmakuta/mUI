#ifndef MUI_MEASURE_H
#define MUI_MEASURE_H

#include "../types.h"

enum MeasureSize{
    Parent,
    Content,
    Fixed
};

class Measure{
private:
    MeasureSize w,h;
public:
    Measure() : Measure(Content,Content){ }
    Measure(MeasureSize _w,MeasureSize _h){
        this->w = _w;
        this->h = _h;
    }

    fun setW(MeasureSize _w){
        this->w = _w;
    }
    fun setH(MeasureSize _h){
        this->h = _h;
    }

    MeasureSize getW(){
        return this->w;
    }
    MeasureSize getH(){
        return this->h;
    }
};

#endif
