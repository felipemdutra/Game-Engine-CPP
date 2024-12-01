
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "../include/camera.h"
#include "../include/input_manager.h"
#include "../include/window.h"

// Public functions

Window* Window::window_instance = nullptr;
Camera* Window::camera_instance = nullptr;

Window::Window(int window_width, int window_height, const char* window_title)
    : width(window_width), height(window_height)
{
    window_instance = this;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(window_width, window_height, window_title,
            nullptr, nullptr);

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallback);

    last_frame = glfwGetTime();

    if (camera_instance == nullptr)
    {
        std::cout <<  "Error! Camera instance is null!" << '\n';
    }

    if (!window_instance)
    {
        std::cout << "Error! Window instance is null!" << '\n';
    }
}

Window::~Window()
{
    glfwDestroyWindow(window);
}


float Window::GetDeltaTime()
{
    float current_frame = glfwGetTime();
    float delta_time = current_frame - last_frame;
    last_frame = current_frame;
    
    return delta_time;
}


GLFWwindow* Window::GetWindowObject()
{
    return window;
}


void Window::SwapBuffersAndPollEvents()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::CloseWindow()
{
    glfwSetWindowShouldClose(window, true);
}


void Window::DisableCursor()
{
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}


bool Window::WindowShouldClose()
{
    return glfwWindowShouldClose(window);
}


void Window::ProcessInput()
{
    if (InputManager::ProcessKeyboard() == GLFW_KEY_ESCAPE)
        CloseWindow();
}


void Window::SetMousePositionCallback(Camera& camera)
{
    camera_instance = &camera;
    glfwSetCursorPosCallback(window, MouseCallback);
}


// Private functions

void Window::FrameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    (void)window;
    glViewport(0, 0, width, height); 
}


// The camera_instance are causing a segfault. 
void Window::MouseCallback(GLFWwindow* window, double xpos, double ypos)
{
    (void) window;
    if (window_instance->first_mouse)
    {
        window_instance->lastX = xpos;
        window_instance->lastY = ypos;
        window_instance->first_mouse = false;
    }

    float xoffset = xpos - window_instance->lastX;
    float yoffset = window_instance->lastY - ypos;
    window_instance->lastX = xpos;
    window_instance->lastY = ypos;
    
    camera_instance->ProcessMouse(xoffset, yoffset);
}

