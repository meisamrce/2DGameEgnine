#ifndef TEXTURE_H
#define TEXTURE_H

#include "Engine.h"

class Texture
{
    public:
        Texture(const string &path);
        ~Texture();
        GLuint getTextureID() const;
        GLuint getWidth() const;
        GLuint getHeight() const;
    private:
        GLuint m_TextureID;
        GLuint m_ImageID;
        GLuint m_Width;
        GLuint m_Height;
        void loadFromFile(const string &path);
        void loadFromPixle32(ILubyte *pixles);
};

#endif // TEXTURE_H
