#include "Shader.h"

#include <fstream>
#include <sstream>
#include <iostream>


Shader::Shader(GLuint p){
    if(p != 0)
        this->push(p);
}

Shader Shader::load(const str& v,const str& f){
    const char* vShaderCode = v.c_str();
    const char* fShaderCode = f.c_str();
    unsigned int vertex, fragment;
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    check(vertex, 1);
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    check(fragment, 1);
    GLuint p = glCreateProgram();
    glAttachShader(p, vertex);
    glAttachShader(p, fragment);
    glLinkProgram(p);
    check(p, 0);
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    return Shader(p);
}
Shader Shader::loadFromFile(const str& vPath,const str& fPath){
    str vertexCode;
    str fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        vShaderFile.open(vPath);
        fShaderFile.open(fPath);
        std::stringstream vShaderStream, fShaderStream;
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        vShaderFile.close();
        fShaderFile.close();
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    return load(vertexCode,fragmentCode);
}

void Shader::check(GLuint shader, GLuint type){
    GLuint success;
    GLchar infoLog[1024];
    if (type != 0)
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, reinterpret_cast<GLint *>(&success));
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, reinterpret_cast<GLint *>(&success));
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}