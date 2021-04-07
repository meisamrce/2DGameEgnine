#ifndef SHADER_H
#define SHADER_H

#include "Engine.h"

class Shader
{
    public:
        Shader(const string &vertFile,const string &fragFile);
        ~Shader();  
        void use();
        void unuse();
        
    private:
            void compileShader(const string &file,GLuint id);
            void linkShader();
            GLuint  m_PrgramID;
            GLuint  m_VertexID;
            GLuint  m_FragID;
    
};

#endif // SHADER_H
