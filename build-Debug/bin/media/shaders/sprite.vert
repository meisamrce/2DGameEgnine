#version 410

layout ( location = 0 ) in vec2 vertexPosition;

uniform mat4 model;
uniform mat4 projection;

void main()
{
    gl_Position = projection *  model * vec4(vertexPosition.xy,0.0,1.0);
}