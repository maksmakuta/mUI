#ifndef MUI_MATHUTILS_H
#define MUI_MATHUTILS_H

class MathUtils{

public:

    template<class T> static T range(T rmin,T rmax,T min,T max,T val){
        T OldRange = rmax - rmin;
        T NewRange = max - min;
        return (((val - rmin) * NewRange) / OldRange) + min;
    }

};

#endif
