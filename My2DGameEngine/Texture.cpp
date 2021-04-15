#include "Texture.h"

Texture::Texture(const string &path)
{
    m_TextureID = 0;
    m_ImageID = 0;
    m_Width = 0;
    m_Height = 0;
    this->loadFromFile(path);
}

Texture::~Texture()
{
    if(m_ImageID != 0)
        ilDeleteImage(m_ImageID);
        
    if(m_TextureID != 0)
        glDeleteTextures(1,&m_TextureID);
}

GLuint Texture::getTextureID() const
{
    return m_TextureID;
}

GLuint Texture::getWidth() const
{
    return m_Width;
}


GLuint Texture::getHeight() const
{
    return m_Height;
}

void Texture::loadFromFile(const string& path)
{
    ilGenImages(1,&m_ImageID);
    ilBindImage(m_ImageID);
    ILboolean result = ilLoadImage(path.c_str());
    if(!result)
        eLog("Texture Load " + path);
        
    ilConvertImage(IL_RGBA,IL_UNSIGNED_BYTE);
    m_Width = ilGetInteger(IL_IMAGE_WIDTH);
    m_Height = ilGetInteger(IL_IMAGE_HEIGHT);
    loadFromPixle32(ilGetData());
}

void Texture::loadFromPixle32(ILubyte* pixles)
{
    glGenTextures(1,&m_TextureID);
    glBindTexture(GL_TEXTURE_2D,m_TextureID);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,m_Width,m_Height,0,GL_RGBA,GL_UNSIGNED_BYTE,pixles);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}
