#include "../include/engine.h"
#include <GLFW/glfw3.h>


// The constructor exits just in case someone forgets to call 
// Shutdown().
Engine::~Engine()
{
    delete window;
    delete renderer;
}


Window* Engine::InitWindow(int width, int height, const char* title)
{
    // initialize GLFW
    if (!glfwInit())
        throw std::runtime_error("Error! Failed to initialize GLFW!");

    window = new Window(width, height, title);
    
    return window;
}


Renderer* Engine::InitRenderer()
{
    // initialize GLEW
    if (glewInit() != GLEW_OK)
        throw std::runtime_error("Error! Failed to initialize GLEW!");
    

    renderer = new Renderer();
    return renderer;
}


void Engine::Shutdown()
{
    glfwTerminate();

    delete window;
    window = nullptr;
    
    delete renderer;
    renderer = nullptr;
}
