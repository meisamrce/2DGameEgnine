#ifndef SPRITE_H
#define SPRITE_H

#include "Engine.h"
#include "Shader.h"
#include "Vertex.h"
#include "Camera2D.h"
#include "Texture.h"
#include "Color.h"
#include "Transform.h"

class Sprite : public Transform
{
    public:
        Sprite(const string &image,const string &vertFile,const string &fragFile);
        ~Sprite();
        void draw();
        void setColor(Color color);
        Color getColor() const;
        Texture * getTextuer() const;
    private:
        void init();
        GLuint m_VAO;
        Shader *m_Shader;
        glm::vec2 m_Size;
        Texture *m_Texture;
        Color m_Color;
};

#endif // SPRITE_H
