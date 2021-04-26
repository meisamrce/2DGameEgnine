#include "Sprite.h"

Sprite::Sprite(const string &image,const string &vertFile,const string &fragFile)
{
    m_Texture = new Texture(image);
    m_Shader = new Shader(vertFile,fragFile);
    m_Position = glm::vec2(0.0f);
    m_Size = glm::vec2(m_Texture->getWidth(),m_Texture->getHeight());//texture width , height
    m_Scale = 1.0f;
    m_Rotate = 0.0f;
    this->init();
}

Sprite::~Sprite()
{
    
    DELETE_SAFE(m_Texture);
    
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
    vertexData[0].setUV(0,1);
    vertexData[1].setPostion(1,0);
    vertexData[1].setUV(1,0);
    vertexData[2].setPostion(0,0);
    vertexData[2].setUV(0,0);
    vertexData[3].setPostion(0,1);
    vertexData[3].setUV(0,1);
    vertexData[4].setPostion(1,1);
    vertexData[4].setUV(1,1);
    vertexData[5].setPostion(1,0);
    vertexData[5].setUV(1,0);

    
    GLuint VBO;
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexData),vertexData,GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);//position
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,position));
    
    
    glEnableVertexAttribArray(1);//uv
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,uv));

    
    glBindBuffer(GL_ARRAY_BUFFER,0);//unbind
    glBindVertexArray(0);

    //enable this line for wireframe mode
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
}


void Sprite::draw()
{
    m_Shader->use();
    
    
    glm::mat4 model(1.0f);

    model = glm::translate(model,glm::vec3(m_Position,0.0f));//translate
    model = glm::translate(model,glm::vec3(0.5 * m_Size.x,0.5 * m_Size.y,0.0f));
    model = glm::rotate(model,glm::radians(m_Rotate),glm::vec3(0.0f,0.0f,1.0f));//rotate
    model = glm::translate(model,glm::vec3(-0.5 * m_Size.x,-0.5 * m_Size.y,0.0f));
    model = glm::scale(model,glm::vec3(glm::vec2(m_Size * m_Scale),1.0f));//scale

    m_Shader->setUniform("model",model);
    m_Shader->setUniform("projection",Camera2D::getInstance()->getCameraMatrix());
    m_Shader->setUniform("spriteColor",m_Color.getColor());

    
    
    glActiveTexture(GL_TEXTURE0);
    m_Shader->setUniform("image",0);
    glBindTexture(GL_TEXTURE_2D,m_Texture->getTextureID());
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


void Sprite::setScale(float value)
{
    m_Scale = value;
}

float Sprite::getScale() const
{
    return m_Scale;
}


void Sprite::setRotate(float value)
{
    m_Rotate = value;
}

float Sprite::getRotate() const
{
    return m_Rotate;
}

void Sprite::setColor(Color color)
{
    m_Color = color;
}

Color Sprite::getColor() const
{
    return m_Color;
}

Texture* Sprite::getTextuer() const
{
    return m_Texture;
}
