#include "Shader.h"

Shader::Shader(const string &vertFile,const string &fragFile)
{
    m_ProgramID = glCreateProgram();
    if(m_ProgramID == 0)
    {
        eLog("Error: glCreateProgram !");
    }
    
    m_VertexID = glCreateShader(GL_VERTEX_SHADER);
    if(m_VertexID == 0)
    {
        eLog("Error: glCreateShader GL_VERTEX_SHADER !");
    }

    m_FragID = glCreateShader(GL_FRAGMENT_SHADER);
    if(m_FragID == 0)
    {
        eLog("Error: glCreateShader GL_FRAGMENT_SHADER !");
    }
    
    compileShader(vertFile,m_VertexID);
    compileShader(fragFile,m_FragID);

    linkShader();
    
}

Shader::~Shader()
{
    if(m_VertexID)
    {
        glDetachShader(m_ProgramID,m_VertexID);
        glDeleteShader(m_VertexID);
        m_VertexID = 0;
    }
    
    if(m_FragID)
    {
        glDetachShader(m_ProgramID,m_FragID);
        glDeleteShader(m_FragID);
        m_FragID = 0;
    }
    
    
    if(m_ProgramID)
    {
        this->unuse();
        glDeleteProgram(m_ProgramID);
        m_ProgramID = 0;
    }
    
}

void Shader::linkShader()
{
        glAttachShader(m_ProgramID,m_VertexID);
        glAttachShader(m_ProgramID,m_FragID);
        
        glLinkProgram(m_ProgramID);
        
        GLint success = 0;
        glGetProgramiv(m_ProgramID,GL_LINK_STATUS,&success);
        
        if(success == GL_FALSE)
        {
                GLint maxLen = 0;
        
                glGetShaderiv(m_ProgramID,GL_INFO_LOG_LENGTH,&maxLen);
                
                vector<char> error(maxLen);
                
                glGetProgramInfoLog(m_ProgramID,maxLen,&maxLen,&error[0]);
                
                eLog("Link  Error " +  Tools::getInstance()->toString(error) ); 
        }

}

void Shader::compileShader(const string& file, GLuint id)
{
    ifstream shaderFile(file);
    
    if(shaderFile.fail())
    {
        eLog("Error can not open " + file );
    }
    
    string fileContent = "";
    string line;
    
    while(std::getline(shaderFile,line))
    {
        fileContent += line + "\n";
    }
    
    shaderFile.close();
    
    const char * content = fileContent.c_str();
    
    glShaderSource(id,1,&content,NULL);
    
    glCompileShader(id);
    
    GLint success = 0;
    
    glGetShaderiv(id,GL_COMPILE_STATUS,&success); 
    
    if(success == GL_FALSE)
    {
        GLint maxLen = 0;
        
        glGetShaderiv(id,GL_INFO_LOG_LENGTH,&maxLen);
        
        vector<char> error(maxLen);
        
        glGetShaderInfoLog(id,maxLen,&maxLen,&error[0]);
        
        eLog("Shader " + file + " Error :" + Tools::getInstance()->toString(error) ); 
        
    }
}




void Shader::use()
{
     glUseProgram(m_ProgramID);
}


void Shader::unuse()
{
     glUseProgram(0);
}


void Shader::setUniform(const string& name, GLuint value)
{
    GLint location = glGetUniformLocation(m_ProgramID,name.c_str());
    if(location == -1)
        return;
        
    glUniform1ui(location,value);
}

void Shader::setUniform(const string& name, GLint value)
{
    GLint location = glGetUniformLocation(m_ProgramID,name.c_str());
    if(location == -1)
        return;
    
    glUniform1i(location,value);
}

void Shader::setUniform(const string& name, GLfloat value)
{
    GLint location = glGetUniformLocation(m_ProgramID,name.c_str());
    if(location == -1)
        return;
        
    glUniform1f(location,value);
}

void Shader::setUniform(const string& name, GLdouble value)
{
    GLint location = glGetUniformLocation(m_ProgramID,name.c_str());
    if(location == -1)
        return;

    glUniform1d(location,value);
}

void Shader::setUniform(const string& name, glm::vec2 value)
{
    GLint location = glGetUniformLocation(m_ProgramID,name.c_str());
    if(location == -1)
        return;
        
    glUniform2f(location,value.x,value.y);
}

void Shader::setUniform(const string& name, glm::vec3 value)
{
    GLint location = glGetUniformLocation(m_ProgramID,name.c_str());
    if(location == -1)
        return;

    glUniform3f(location,value.x,value.y,value.z);
}

void Shader::setUniform(const string& name, glm::vec4 value)
{
    GLint location = glGetUniformLocation(m_ProgramID,name.c_str());
    if(location == -1)
        return;
        
    glUniform4f(location,value.x,value.y,value.z,value.w);

}

void Shader::setUniform(const string& name, glm::mat4 value)
{
    GLint location = glGetUniformLocation(m_ProgramID,name.c_str());
    if(location == -1)
        return;
        
    glUniformMatrix4fv(location,1,GL_FALSE,glm::value_ptr(value));

}
