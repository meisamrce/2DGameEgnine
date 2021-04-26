#ifndef CAMERA2D_H
#define CAMERA2D_H

#include "Engine.h"
#include "Transform.h"


class Camera2D : public Transform
{
    public:
            static Camera2D * getInstance();
            void init(unsigned int width,unsigned int height);
            void update();
            glm::mat4 getCameraMatrix() const; 
    private:
            static Camera2D * m_Instance;
            Camera2D() {};
            ~Camera2D() {} ;
            Camera2D(Camera2D &other) = delete;
            void operator=(const Camera2D &) = delete;
            unsigned int m_Width;
            unsigned int m_Height;
            glm::mat4 m_CameraMatrix;
            glm::mat4 m_OrthoMatrix;
            glm::vec2 m_Size;
};

#endif // CAMERA2D_H
