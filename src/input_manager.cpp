#include "../include/input_manager.h"
#include <GLFW/glfw3.h>

bool InputManager::ProcessKey(GLFWwindow* window, int key)
{
    return glfwGetKey(window, key) == GLFW_PRESS; 
}
