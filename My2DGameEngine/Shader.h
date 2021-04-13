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
        void setUniform(const string &name,GLuint value);
        void setUniform(const string &name,GLint value);
        void setUniform(const string &name,GLfloat value);
        void setUniform(const string &name,GLdouble value);
        void setUniform(const string &name,glm::vec2 value);
        void setUniform(const string &name,glm::vec3 value);
        void setUniform(const string &name,glm::vec4 value);
        void setUniform(const string &name,glm::mat4 value);

    private:
            void compileShader(const string &file,GLuint id);
            void linkShader();
            GLuint  m_ProgramID;
            GLuint  m_VertexID;
            GLuint  m_FragID;
    
};

#endif // SHADER_H
