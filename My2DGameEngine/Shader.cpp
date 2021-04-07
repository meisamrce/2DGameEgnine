#include "Shader.h"

Shader::Shader(const string &vertFile,const string &fragFile)
{
    m_PrgramID = glCreateProgram();
    if(m_PrgramID == 0)
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
        glDetachShader(m_PrgramID,m_VertexID);
        glDeleteShader(m_VertexID);
        m_VertexID = 0;
    }
    
    if(m_FragID)
    {
        glDetachShader(m_PrgramID,m_FragID);
        glDeleteShader(m_FragID);
        m_FragID = 0;
    }
    
    
    if(m_PrgramID)
    {
        this->unuse();
        glDeleteProgram(m_PrgramID);
        m_PrgramID = 0;
    }
    
}

void Shader::linkShader()
{
        glAttachShader(m_PrgramID,m_VertexID);
        glAttachShader(m_PrgramID,m_FragID);
        
        glLinkProgram(m_PrgramID);
        
        GLint success = 0;
        glGetProgramiv(m_PrgramID,GL_LINK_STATUS,&success);
        
        if(success == GL_FALSE)
        {
                GLint maxLen = 0;
        
                glGetShaderiv(m_PrgramID,GL_INFO_LOG_LENGTH,&maxLen);
                
                vector<char> error(maxLen);
                
                glGetProgramInfoLog(m_PrgramID,maxLen,&maxLen,&error[0]);
                
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
     glUseProgram(m_PrgramID);
}


void Shader::unuse()
{
     glUseProgram(0);
}


