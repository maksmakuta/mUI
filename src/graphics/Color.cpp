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
    int data[4];

    for(int & i : data)
        i = 255;

    switch (hex.size() - 1) {
        case 3: // #abc
            for(int i = 0;i < 3;i++){
                data[i] = code(hex[i+1]) * 16 + 15;
            }
            break;
        case 4: // #abcd
            for(int i = 0;i < 4;i++){
                data[i] = code( hex[i+1]) * 16 + 15;
            }
            break;
        case 6: // #123456
            for(int i = 0;i < 3;i++){
                data[i] = code(hex[2*i+1]) * 16 + code(hex[2*i+2]);
            }
            break;
        case 8: // #12345678
            for(int i = 0;i < 4;i++){
                data[i] = code(hex[2*i+1]) * 16 + code(hex[2*i+2]);
            }
            break;

    }

    initI(data[0],data[1],data[2],data[3]);
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


void Color::print(int s,bool _i) {
    std::string p = "Color{";
    for (int i = 0; i < 4; i++) {
        if(_i) p += "%." + std::to_string(s) +"f";
        else  p += "%i";

        if(i < 3) p += ",";
    }
    p += "}";

    if(_i) printf(p.c_str(),this->getRf(),this->getGf(),this->getBf(),this->getAf());
    else printf(p.c_str(),this->getRi(),this->getGi(),this->getBi(),this->getAi());

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


int Color::code(char c){
    switch (c) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'a': case 'A': return 10;
        case 'b': case 'B': return 11;
        case 'c': case 'C': return 12;
        case 'd': case 'D': return 13;
        case 'e': case 'E': return 14;
        case 'f': case 'F': return 15;
        default: return  -1;
    }
}