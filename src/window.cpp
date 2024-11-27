#include "../include/window.h"
#include <GLFW/glfw3.h>

// Public functions

Window::Window(int window_width, int window_height, const char* window_title)
    : width(window_width), height(window_height)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(window_width, window_height, window_title,
            nullptr, nullptr);

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallback);
}

Window::~Window()
{
    glfwDestroyWindow(window);
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


bool Window::WindowShouldClose()
{
    return glfwWindowShouldClose(window);
}


void Window::ProcessInput()
{
    if (InputManager::ProcessKey(window, GLFW_KEY_ESCAPE))
            CloseWindow();
}

// Private functions

void Window::FrameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    (void)window;
    glViewport(0, 0, width, height); 
}

