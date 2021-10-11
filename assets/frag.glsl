#version 330 core

uniform bool tex;
uniform sampler2D texID;

in vec4 fColor;
in vec2 fTex;

out vec4 FragColor;

void main(){
    if(!tex)
        FragColor = fColor;
    else
        FragColor = texture(texID,fTex);
}