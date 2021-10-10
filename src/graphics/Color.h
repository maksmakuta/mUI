#ifndef TT_COLOR_H
#define TT_COLOR_H

#include <string>
#include <glm/vec4.hpp>

class Color {
private:
float r,g,b,a;
public:
    Color();

    Color(int r,int g,int b);
    Color(int r,int g,int b,int a);

    Color(float r,float g,float b);
    Color(float r,float g,float b,float a);

    explicit Color(const std::string& hex);

    void print(int s = 2,bool i = false);

    void setR(int r);
    void setG(int g);
    void setB(int b);
    void setA(int a);

    void setR(float r);
    void setG(float g);
    void setB(float b);
    void setA(float a);

    int getRi();
    int getGi();
    int getBi();
    int getAi();

    int getRi()const;
    int getGi()const;
    int getBi()const;
    int getAi()const;

    float getRf();
    float getGf();
    float getBf();
    float getAf();

    float getRf() const;
    float getGf() const;
    float getBf() const;
    float getAf() const;

    glm::vec4 toVec4();
/*
    Color operator +(const Color&);
    Color operator -(const Color&);

    Color operator +=(const Color&);
    Color operator -=(const Color&);
    Color operator ++();
    Color operator --();
*/
private:
    void initI(  int r,  int g,  int b,  int a);
    void initF(float r,float g,float b,float a);

    int code(char c);
};


#endif
