#ifndef SPRITE_H
#define SPRITE_H

#include "Engine.h"
#include "Shader.h"
#include "Vertex.h"
#include "Camera2D.h"
#include "Texture.h"
#include "Color.h"


class Sprite
{
    public:
        Sprite(const string &image,const string &vertFile,const string &fragFile);
        ~Sprite();
        void draw();
        void setPosition(const glm::vec2 &value);
        glm::vec2 getPosition() const;
        void setScale(float value);
        float getScale() const;
        void setRotate(float value);
        float getRotate() const;
        void setColor(Color color);
        Color getColor() const;
        Texture * getTextuer() const;
    private:
        void init();
        GLuint m_VAO;
        Shader *m_Shader;
        glm::vec2 m_Position;
        glm::vec2 m_Size;
        float m_Scale;
        float m_Rotate;
        Texture *m_Texture;
        Color m_Color;
};

#endif // SPRITE_H
