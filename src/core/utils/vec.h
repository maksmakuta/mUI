#ifndef MUI_VEC_H
#define MUI_VEC_H

struct vec2{
public:
    f32 x,y;
    vec2() : vec2(0.f){ }
    vec2(f32 i) : vec2(i,i){ }
    vec2(f32 a,f32 b){
        this->x = a;
        this->y = b;
    }
};

struct vec3{
public:
    f32 x,y,z;
    vec3() : vec3(0.f){ }
    vec3(f32 i) : vec3(i,i,i){ }
    vec3(f32 a,f32 b,f32 c){
        this->x = a;
        this->y = b;
        this->z = c;
    }
};

struct vec4{
public:
    f32 x,y,z,w;
    vec4() : vec4(0.f){ }
    vec4(f32 i) : vec4(i,i,i,i){ }
    vec4(f32 a,f32 b,f32 c,f32 d){
        this->x = a;
        this->y = b;
        this->z = c;
        this->w = d;
    }

    bool in(f32 _x,f32 _y){
        return x < _x and z > _x and y < _y and w > _y;
    }
};

#endif
