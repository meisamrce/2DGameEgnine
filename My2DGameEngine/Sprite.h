#ifndef SPRITE_H
#define SPRITE_H

#include "Engine.h"
#include "Shader.h"
#include "Vertex.h"
#include "Camera2D.h"


class Sprite
{
    public:
        Sprite(const string &vertFile,const string &fragFile);
        ~Sprite();
        void draw();
        void setPosition(const glm::vec2 &value);
        glm::vec2 getPosition() const;
    private:
        void init();
        GLuint m_VAO;
        Shader *m_Shader;
        glm::vec2 m_Position;
        glm::vec2 m_Size;
        float m_Scale;

};

#endif // SPRITE_H
