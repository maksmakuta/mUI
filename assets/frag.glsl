#version 330 core

in vec2 Frag_UV;
in vec4 Frag_Color;

uniform sampler2D Texture;

out vec4 Out_Color;

void main(){
    if(Frag_UV == vec2(0.0))
        Out_Color = Frag_Color;
    else
        Out_Color = Frag_Color * texture(Texture, Frag_UV.st);
}