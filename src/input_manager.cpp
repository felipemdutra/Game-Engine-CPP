#include "../include/input_manager.h"
#include <GLFW/glfw3.h>

int InputManager::ProcessKeyboard()
{
    for (int key : keys)
    {
        if (key == GLFW_PRESS)
        {
            return key;
        }
    }
    
    return 0;
}
