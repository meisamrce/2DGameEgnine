#include "Camera2D.h"

Camera2D * Camera2D::m_Instance = NULL;

Camera2D* Camera2D::getInstance()
{
    if(m_Instance == NULL)
        m_Instance = new Camera2D();
    
    return m_Instance;
}

void Camera2D::init(unsigned int width, unsigned int height)
{
    m_Width = width;
    m_Height = height;
    m_Size = glm::vec2(m_Width,m_Height);
    m_CameraMatrix = glm::mat4(1.0f);
    m_OrthoMatrix = glm::ortho(0.0f,(float)m_Width,(float)m_Height,0.0f);
}

void Camera2D::update()
{

    //translate
    glm::vec3 position(m_Position.x,m_Position.y,0.0f);
    m_CameraMatrix = glm::translate(m_OrthoMatrix,position);

    //rotate
    m_CameraMatrix = glm::translate(m_CameraMatrix,glm::vec3(0.5 * m_Size.x,0.5 * m_Size.y,0.0f));
    m_CameraMatrix = glm::rotate(m_CameraMatrix,glm::radians(m_Rotate),glm::vec3(0.0f,0.0f,1.0f));
    m_CameraMatrix = glm::translate(m_CameraMatrix,glm::vec3(-0.5 * m_Size.x,-0.5 * m_Size.y,0.0f));

    //sacle
    m_CameraMatrix = glm::scale(m_CameraMatrix,glm::vec3(glm::vec2(m_Scale,m_Scale),1.0f));

}


glm::mat4 Camera2D::getCameraMatrix() const
{
    return m_CameraMatrix;
}

