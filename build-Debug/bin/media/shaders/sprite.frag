#version 410

in vec2 fragmentUV;

out vec4 color;

uniform sampler2D image;

void main()
{
    color = texture(image,fragmentUV);
}