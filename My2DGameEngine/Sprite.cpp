#include "Sprite.h"

Sprite::Sprite(const string &vertFile,const string &fragFile)
{
    m_Shader = new Shader(vertFile,fragFile);
    m_Position = glm::vec2(0.0f);
    m_Size = glm::vec2(100,100);//texture width , height
    m_Scale = 1.0f;

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
        
    Vertex vertexData[6];
    vertexData[0].setPostion(0,1);
    vertexData[1].setPostion(1,0);
    vertexData[2].setPostion(0,0);
    vertexData[3].setPostion(0,1);
    vertexData[4].setPostion(1,1);
    vertexData[5].setPostion(1,0);

    
    GLuint VBO;
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexData),vertexData,GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);//position
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,position));
    
    
    glBindBuffer(GL_ARRAY_BUFFER,0);//unbind
    glBindVertexArray(0);

    //enable this line for wireframe mode
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
}


void Sprite::draw()
{
     m_Shader->use();
     
     glm::mat4 model(1.0f);
     model = glm::translate(model,glm::vec3(m_Position,0));//translate
    //rotate
    model = glm::scale(model,glm::vec3(m_Size * glm::vec2(m_Scale,m_Scale)  ,1.0f));   //sacle
     
     m_Shader->setUniform("model",model);
     m_Shader->setUniform("projection",Camera2D::getInstance()->getCameraMatrix());

     
    glBindVertexArray(m_VAO);
    glDrawArrays(GL_TRIANGLES,0,6);

}


void Sprite::setPosition(const glm::vec2& value)
{
    m_Position = value;
}

glm::vec2 Sprite::getPosition() const
{
    return m_Position;
}
