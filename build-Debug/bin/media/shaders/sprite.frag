#version 410

in vec2 fragmentUV;

out vec4 color;

uniform sampler2D image;

uniform vec4 spriteColor = vec4(1.0,1.0,1.0,1.0);

void main()
{
    color = texture(image,fragmentUV) * spriteColor;
}