#version 330 core

uniform bool tex;
uniform sampler2D texID;

in vec3 fColor;
in vec2 fTex;

out vec4 FragColor;

void main(){
    if(!tex)
        FragColor = vec4(fColor,1.0);
    else
        FragColor = texture(texID,fTex);
}