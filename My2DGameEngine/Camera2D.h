#ifndef CAMERA2D_H
#define CAMERA2D_H

#include "Engine.h"


class Camera2D
{
    public:
            static Camera2D * getInstance();
            void init(unsigned int width,unsigned int height);
            void update();
            void setPosition(const glm::vec2 &value);
            glm::vec2 getPosition() const;
            glm::mat4 getCameraMatrix() const; 
            void setScale(float value);
            float getScale() const;
            void setRotate(float value);
            float getRotate() const;
    private:
            static Camera2D * m_Instance;
            Camera2D() {};
            ~Camera2D() {} ;
            Camera2D(Camera2D &other) = delete;
            void operator=(const Camera2D &) = delete;
            unsigned int m_Width;
            unsigned int m_Height;
            glm::vec2 m_Position;
            glm::mat4 m_CameraMatrix;
            glm::mat4 m_OrthoMatrix;
            float m_Scale;
            float m_Rotate;
            glm::vec2 m_Size;
};

#endif // CAMERA2D_H
