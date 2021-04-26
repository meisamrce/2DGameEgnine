#include "Transform.h"

Transform::Transform()
{
    m_Position = glm::vec2(0.0f);
    m_Scale = 1.0f;
    m_Rotate = 0.0f;
}

Transform::~Transform()
{
}

void Transform::setPosition(const glm::vec2& value)
{
    m_Position = value;
}

glm::vec2 Transform::getPosition() const
{
    return m_Position;
}


void Transform::setScale(float value)
{
    m_Scale = value;
}

float Transform::getScale() const
{
    return m_Scale;
}


void Transform::setRotate(float value)
{
    m_Rotate = value;
}

float Transform::getRotate() const
{
    return m_Rotate;
}


void Transform::translate(const glm::vec2& value)
{
    m_Position += value;
}

void Transform::translateX(float x)
{
    m_Position.x += x;
}

void Transform::translateY(float y)
{
    m_Position.y += y;
}

void Transform::scale(float value)
{
    m_Scale += value;
}

void Transform::rotate(float value)
{
    m_Rotate += value;
}
