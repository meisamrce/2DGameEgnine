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
    m_CameraMatrix = glm::mat4(1.0f);
    m_OrthoMatrix = glm::ortho(0.0f,(float)m_Width,(float)m_Height,0.0f);
    m_Position = glm::vec2(0.0f,0.0f);
}

void Camera2D::update()
{
    glm::vec3 position(m_Position.x,m_Position.y,0.0f);
    m_CameraMatrix = glm::translate(m_OrthoMatrix,position);
}

void Camera2D::setPosition(const glm::vec2 &value)
{
    m_Position = value;
}

glm::vec2 Camera2D::getPosition() const
{
    return m_Position;
}

glm::mat4 Camera2D::getCameraMatrix() const
{
    return m_CameraMatrix;
}
