#ifndef COLOR_H
#define COLOR_H

#include "Global.h"

class Color
{
    public:
        Color();
        Color(GLuint red,GLuint green,GLuint blue,GLuint alpha);
        glm::vec4 getColor() const;
        ~Color();
    private:
        glm::vec4 m_Color;
};

#endif // COLOR_H
