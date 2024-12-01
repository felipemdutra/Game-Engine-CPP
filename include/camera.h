#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <glm/glm.hpp>

class Renderer;
class Window;

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 3.0f;
const float SENSITIVITY = 0.1f;

class Camera
{
    public:
        glm::vec3 Position;
        glm::vec3 Front;
        glm::vec3 Up;
        glm::vec3 Right;
        glm::vec3 WorldUp;

        float Yaw;
        float Pitch;
        float MovementSpeed;
        float MouseSensitivity;
        float Fov;

        Camera(float fov, float window_width, float window_height,
                glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), 
                glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW,
                float pitch = PITCH);

        glm::mat4 GetViewMatrix() const;

        glm::mat4 GetProjectionMatrix(float window_width,
                float window_height) const;

        void Update(Window* window, Renderer* renderer);
                
        void ProcessKeyboard(Window* window);

        void ProcessMouse(float xoffset, float yoffset, 
                GLboolean constrain_pitch = true);

    private:
        float Window_width;
        float Window_height;

        void UpdateCameraVectors();

};

#endif
