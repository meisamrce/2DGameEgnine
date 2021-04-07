#ifndef SPRITE_H
#define SPRITE_H

#include "Engine.h"
#include "Shader.h"

class Sprite
{
    public:
        Sprite(const string &vertFile,const string &fragFile);
        ~Sprite();
        void draw();
    private:
        void init();
        GLuint m_VAO;
        Shader *m_Shader;


};

#endif // SPRITE_H
