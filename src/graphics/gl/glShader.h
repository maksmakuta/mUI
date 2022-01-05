#ifndef GLSHADER_H
#define GLSHADER_H

#include "../../types.h"
#include "../../app/Logger.h"
#include <GL/glew.h>

const str vert =
        "#version 330 core"
        "layout (location = 0) in vec2 aPos;"
        "layout (location = 1) in vec4 aCol;"
        "out vec4 gl_color;"
        "void main(){"
        "   gl_color = aCol;"
        "   gl_Position = vec4(aPos.x, aPos.y, 0.0f, 1.0f);"
        "}";

const str frag =
        "#version 330 core"
        "in vec4 gl_color;"
        "out vec4 FragColor;"
        "void main(){"
        "    FragColor = gl_color;"
        "} ";

class glShader{
private:
    GLuint program,vertex,fragment;
public:
    glShader(){
        this->vertex   = create(vert.c_str(),  GL_VERTEX_SHADER);
        this->fragment = create(frag.c_str(),GL_FRAGMENT_SHADER);
        if(this->vertex   != 0 && this->fragment != 0)
            this->program  = createProgram(this->vertex,this->fragment);
        else
            Log::onError("GL Shader Program");
    }

    GLuint create(const char* code, GLuint type){
            unsigned int shader = glCreateShader(type);
            glShaderSource(shader, 1, &code, NULL);
            glCompileShader(shader);

            int  success;
            char infoLog[512];
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if(!success){
                glGetShaderInfoLog(shader, 512, NULL, infoLog);
                std::cout << "COMPILATION_FAILED: \n" << infoLog << std::endl;
            }else{
                return shader;
            }
            return 0;
        }

        GLuint createProgram(GLuint v,GLuint f){
            GLuint pp = glCreateProgram();
            glAttachShader(pp, v);
            glAttachShader(pp, f);
            glLinkProgram(pp);

            int  success;
            char infoLog[512];
            glGetProgramiv(pp, GL_LINK_STATUS, &success);
            if(!success){
                glGetShaderInfoLog(pp, 512, NULL, infoLog);
                std::cout << "COMPILATION_FAILED: \n" << infoLog << std::endl;
            }else{
                return pp;
            }
            return 0;
        }

        void use(){
            glUseProgram(this->program);
        }


};

#endif
