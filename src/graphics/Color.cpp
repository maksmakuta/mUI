#include "Color.h"


Color::Color() : Color(0,0,0){ }
Color::Color(int r,int g,int b) : Color(r,g,b,255){ }
Color::Color(int r,int g,int b,int a){
    this->initI(r,g,b,a);
}
Color::Color(float r,float g,float b) : Color(r,g,b,1.0f){ }
Color::Color(float r,float g,float b,float a){
    this->initF(r,g,b,a);
}
Color::Color(const std::string& hex){

}

void Color::setR(int _r){this->r = (float)_r / 255.0f;}
void Color::setG(int _g){this->g = (float)_g / 255.0f;}
void Color::setB(int _b){this->b = (float)_b / 255.0f;}
void Color::setA(int _a){this->a = (float)_a / 255.0f;}

void Color::setR(float _r){this->r = _r;}
void Color::setG(float _g){this->g = _g;}
void Color::setB(float _b){this->b = _b;}
void Color::setA(float _a){this->a = _a;}

int Color::getRi(){return (int)(this->r * 255.0f);}
int Color::getGi(){return (int)(this->g * 255.0f);}
int Color::getBi(){return (int)(this->b * 255.0f);}
int Color::getAi(){return (int)(this->a * 255.0f);}

float Color::getRf(){return this->r;}
float Color::getGf(){return this->g;}
float Color::getBf(){return this->b;}
float Color::getAf(){return this->a;}

/*
    Color operator +(const Color&);
    Color operator -(const Color&);

    Color operator +=(const Color&);
    Color operator -=(const Color&);
    Color operator ++();
    Color operator --();
*/


void Color::print(int s) {
    std::string p = "Color{";
    for (int i = 0; i < 4; i++) {
        p += "%." + std::to_string(s) +"f";
        if(i < 3) p += ",";
    }
    p += "}";
    printf(p.c_str(),this->getRf(),this->getGf(),this->getBf(),this->getAf());
}

void Color::initF(float _r,float _g,float _b,float _a){
    this->setR(_r);
    this->setG(_g);
    this->setB(_b);
    this->setA(_a);
}
void Color::initI(  int _r,  int _g,  int _b,  int _a){
    this->setR(_r);
    this->setG(_g);
    this->setB(_b);
    this->setA(_a);
}