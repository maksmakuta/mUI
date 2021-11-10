#ifndef MUI_MATHUTILS_H
#define MUI_MATHUTILS_H

class MathUtils{

public:

    template<class T> static T range(T rmin,T rmax,T min,T max,T val){
        T OldRange = rmax - rmin;
        T NewRange = max - min;
        return (((val - rmin) * NewRange) / OldRange) + min;
    }
    template<class T> static T max(T a,T b){
        if(a == b)
            return a;
        if(a > b)
            return a;
        else
            return b;
    }

    template<class T> static T min(T a,T b){
        if(a == b)
            return a;
        if(a > b)
            return b;
        else
            return a;
    }

};

#endif
