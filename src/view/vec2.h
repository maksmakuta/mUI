#ifndef MUI_VEC2_H
#define MUI_VEC2_H

class vec2{
public:
    vec2() : vec2(0.f){}
    explicit vec2(f32 a) : vec2(a,a){}
    vec2(f32 a,f32 b) {
        this->set(a,b);
    }

    fun set(f32 a, f32 b){
        this->x = a;
        this->y = b;
    }

    f32 x,y;
};

#endif