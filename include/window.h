#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

class Camera;

// Use this class after initializing GLFW and before initializing GLEW or else 
// it won't work!
class Window
{
private:

    static Window* window_instance;
    static Camera* camera_instance; 
    
    GLFWwindow* window = nullptr;
    int width;
    int height;

    float lastX = width / 2.0f;
    float lastY = height / 2.0f;
    bool first_mouse = true;

    float last_frame = 0.0f;

    static void FrameBufferSizeCallback(GLFWwindow* window, int width,
            int height);

    static void MouseCallback(GLFWwindow* window, double xpos,
            double ypos);
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

    float GetDeltaTime();

    // This needs to be called in the end of the game loop.
    void SwapBuffersAndPollEvents();

    void CloseWindow();

    void DisableCursor();

    bool WindowShouldClose();

    void ProcessInput();

    void SetMousePositionCallback(Camera& camera);

};

#endif
