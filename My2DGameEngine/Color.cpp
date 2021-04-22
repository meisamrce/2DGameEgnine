#include "Color.h"


Color::Color()
{
    m_Color.x =  1.0f;
    m_Color.y =  1.0f;
    m_Color.z =  1.0f;
    m_Color.w =  1.0f;
}


Color::Color(GLuint red,GLuint green,GLuint blue,GLuint alpha)
{
    m_Color.x = red / 255.0f;
    m_Color.y = green / 255.0f;
    m_Color.z = blue / 255.0f;
    m_Color.w = alpha / 255.0f;
}


Color::~Color()
{
}

glm::vec4 Color::getColor() const
{
    return m_Color;
}
