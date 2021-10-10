#version 330 core
layout (location = 0) in vec2 Position;
layout (location = 1) in vec3 Color;
layout (location = 2) in vec2 TexP;

uniform mat4 mat;

out vec3 fColor;
out vec2 fTex;

void main(){
    gl_Position = mat * vec4(Position,0,1);
    fColor = Color;
    fTex = TexP;
}