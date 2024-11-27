#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../include/input_manager.h"

// Use this class after initializing GLFW and before initializing GLEW or else 
// it won't work!
class Window
{
private:

    GLFWwindow* window = nullptr;
    int width;
    int height;

    static void FrameBufferSizeCallback(GLFWwindow* window, int width,
            int height);

public: 

    Window(int window_width, int window_height, const char* window_title);

    // This calls glfwDestroyWindow(window).
    ~Window();

    
    // Returns the width of the window. 
    int GetWindowWidth();

    // Returns the height of the window.
    int GetWindowHeight();

    // Returns the GLFW window object.
    GLFWwindow* GetWindowObject();

    // This needs to be called in the end of the game loop.
    void SwapBuffersAndPollEvents();

    void CloseWindow();

    bool WindowShouldClose();

    void ProcessInput();

};

#endif
