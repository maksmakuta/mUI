#ifndef POINT_H
#define POINT_H

#include "../types.h"

class Point{
private:
    f32 x, y;
public:
    Point() : Point(0.f){/* ... */}
    Point(f32 a) : Point(a,a){/* ... */}
    Point(f32 _x,f32 _y){
        this->pos(_x,_y);
    }

    fun pos(f32 a,f32 b){
        this->setX(a);
        this->setY(b);
    }

    fun setX(f32 v){this->x = v;}
    fun setY(f32 v){this->y = v;}

    f32 getX(){return this->x;}
    f32 getY(){return this->y;}

    f32 getX() const {return this->x;}
    f32 getY() const {return this->y;}

    bool operator == (const Point& p){
        return (this->getX() == p.getX()) && (this->getY() == p.getY());
    }

    Point operator = (const Point& p){
        this->setX(p.getX());
        this->setY(p.getY());
        return *this;
    }

};

#endif
