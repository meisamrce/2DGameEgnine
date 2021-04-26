#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Global.h"

class Transform
{
    public:
        Transform();
        ~Transform();
        void setPosition(const glm::vec2 &value);
        glm::vec2 getPosition() const;
        void setScale(float value);
        float getScale() const;
        void setRotate(float value);
        float getRotate() const;
        void translate(const glm::vec2 &value);
        void translateX(float x);
        void translateY(float y);
        void scale(float value);
        void rotate(float value);
    
protected:
        glm::vec2 m_Position;
        float m_Scale;
        float m_Rotate;


};

#endif // TRANSFORM_H
