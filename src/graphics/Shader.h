#ifndef MUI_SHADER_H
#define MUI_SHADER_H

#include "../sTypes.h"
#include <GL/glew.h>
#include <string>

#include <glm/glm.hpp>

class Shader {
private:
    GLuint program = 0;

    explicit Shader(GLuint);
public:

    Shader() = delete; // no default constructor

    static Shader def();

    static Shader load(const str& v,const str& f);
    static Shader loadFromFile(const str& vPath,const str& fPath);
    static fun check(GLuint shader, GLuint type);

    inline fun use() const  {glUseProgram(program);}
    inline fun use()        {glUseProgram(program);}

    inline fun push(GLuint p){this->program = p;}

    inline fun setBool(const  str& name, bool value) const {
        glUniform1i(glGetUniformLocation(program, name.c_str()), (i32)value);
    }
    inline fun setInt(const  str& name, i32 value) const {
        glUniform1i(glGetUniformLocation(program, name.c_str()), value);
    }
    inline fun setFloat(const  str& name, f32 value) const {
        glUniform1f(glGetUniformLocation(program, name.c_str()), value);
    }
    inline fun setVec2(const  str& name, f32 x, f32 y) const {
        glUniform2f(glGetUniformLocation(program, name.c_str()), x, y);
    }
    inline fun setVec3(const  str& name, f32 x, f32 y, f32 z) const {
        glUniform3f(glGetUniformLocation(program, name.c_str()), x, y, z);
    }
    inline fun setVec4(const  str& name, f32 x, f32 y, f32 z, f32 w) const {
        glUniform4f(glGetUniformLocation(program, name.c_str()), x, y, z, w);
    }

    inline fun setVec2(const str& name, const glm::vec2 &value) const{
        glUniform2fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]);
    }
    inline fun setVec3(const str& name, const glm::vec3 &value) const{
        glUniform3fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]);
    }
    inline fun setVec4(const str& name, const glm::vec4 &value) const{
        glUniform4fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]);
    }

    inline fun setMat2(const str& name, const glm::mat2 &mat) const{
        glUniformMatrix2fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    inline fun setMat3(const str& name, const glm::mat3 &mat) const{
        glUniformMatrix3fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    inline fun setMat4(const str& name, const glm::mat4 &mat) const{
        glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
};

#endif
