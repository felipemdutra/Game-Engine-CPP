#include <glm/geometric.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/trigonometric.hpp>

#include "../include/camera.h"
#include "../include/input_manager.h"
#include "../include/window.h"
#include "../include/renderer.h"

Camera::Camera(float fov, float window_width, float window_height,
        glm::vec3 position, glm::vec3 up, float yaw, float pitch) 
            : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), 
            MouseSensitivity(SENSITIVITY)
{
    Window_width = window_width;
    Window_height = window_height;

    Position = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
    Fov = fov;

    UpdateCameraVectors();
}


glm::mat4 Camera::GetViewMatrix() const
{
    return glm::lookAt(Position, Position + Front, Up);
}


//  Recomended FOV: 45.0 - 90.0
//
// @param window_width and @param window_height are used to set the aspect we
// need for the glm::perspective function 
//
glm::mat4 Camera::GetProjectionMatrix(float window_width,
        float window_height) const
{
    auto aspect = window_width / window_height;
    return glm::perspective(glm::radians(Fov), aspect, 0.1f, 100.0f);
}


// Call this inside the game loop.
void Camera::Update(Window* window, Renderer* renderer)
{
    if (!window || !renderer)
    {
        std::cerr << "Error: Null pointer apssed to Camera::Update()\n";
        return;
    }
    
    auto view = GetViewMatrix();
    auto projection = GetProjectionMatrix(Window_width, Window_height);
    renderer->ShaderSetUniformValue("view", view);
    renderer->ShaderSetUniformValue("projection", projection);

}


void Camera::ProcessKeyboard(Window* window)
{
    auto velocity = MovementSpeed * window->GetDeltaTime();

    if (InputManager::ProcessKeyboard() == GLFW_KEY_W)
        Position += Front * velocity;

    if (InputManager::ProcessKeyboard() == GLFW_KEY_S)
        Position -= Front * velocity;

    if (InputManager::ProcessKeyboard() == GLFW_KEY_A)
        Position -= Right * velocity;

    if (InputManager::ProcessKeyboard() == GLFW_KEY_D)
        Position += Right * velocity;

    if (InputManager::ProcessKeyboard() == GLFW_KEY_SPACE)
        Position += Up * velocity;
    
    if (InputManager::ProcessKeyboard() == GLFW_KEY_LEFT_SHIFT)
        Position -= Up * velocity;
}


void Camera::ProcessMouse(float xoffset, float yoffset, 
        GLboolean constrain_pitch)
{
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    Yaw += xoffset;
    Pitch += yoffset;

    if (constrain_pitch)
    {
        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;
    }

    UpdateCameraVectors();
}


void Camera::UpdateCameraVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);
    Right = glm::normalize(glm::cross(Front, WorldUp));
    Up = glm::normalize(glm::cross(Right, Front));
}

