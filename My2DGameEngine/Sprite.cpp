#include "Sprite.h"

Sprite::Sprite(const string &vertFile,const string &fragFile)
{
    m_Shader = new Shader(vertFile,fragFile);
    this->init();
}

Sprite::~Sprite()
{
    if(m_VAO != 0)
    {
        glDeleteVertexArrays(1,&m_VAO);
    }

    DELETE_SAFE(m_Shader);
}


void Sprite::init()
{
    
    glGenVertexArrays(1,&m_VAO);
    glBindVertexArray(m_VAO);
    
    float vertexData[] = {
        0.0f,1.0f, //v1-x,y
        -1.0f,-1.0f, //v2-x,y
        1.0f,-1.0f, //v3-x,y        
    };
    
    GLuint VBO;
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexData),vertexData,GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);//position
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(float),(void*)0);
    
    
    glBindBuffer(GL_ARRAY_BUFFER,0);//unbind
    glBindVertexArray(0);


}


void Sprite::draw()
{
     m_Shader->use();
     glBindVertexArray(m_VAO);
     glDrawArrays(GL_TRIANGLES,0,3);

}