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


    bool operator == (const vec2& v) const{
        return v.x == x && v.y == y;
    }

    vec2 operator ++(){
        this->x++;
        this->y++;
        return *this;
    }

    vec2 operator --(){
        this->x--;
        this->y--;
        return *this;
    }
    vec2 operator +(const vec2& a){
        this->x += a.x;
        this->y += a.y;
        return *this;
    }
    vec2 operator -(const vec2& a){
        this->x -= a.x;
        this->y -= a.y;
        return *this;
    }

    vec2 operator += (const vec2& v){
        return *this + v;
    }
    vec2 operator -= (const vec2& v){
        return *this - v;
    }

    vec2 operator *(f32 d){
        this->x *= d;
        this->y *= d;
        return *this;
    }

    vec2 operator /(f32 d){
        this->x /= d;
        this->y /= d;
        return *this;
    }

};

#endif
