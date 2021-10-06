#version 330 core

uniform vec2 viewport;
in vec2 pos;
in vec4 color;

out vec4 c;

void main(){
    c = color;
    gl_Position = vec4(2.0f * pos.x/viewport.x - 1.0f,2.0f * pos.y/viewport.y - 1.0,0.0f,1.0f);
}