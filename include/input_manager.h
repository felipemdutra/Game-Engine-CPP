#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <GLFW/glfw3.h>

// TODO: this bullshit
class InputManager
{
    private:
      
        static constexpr int keys[7] = {
            GLFW_KEY_W,
            GLFW_KEY_A,
            GLFW_KEY_S,
            GLFW_KEY_D,
            GLFW_KEY_SPACE,
            GLFW_KEY_LEFT_SHIFT,
            GLFW_KEY_ESCAPE,
        };

    public:

        // This function returns the key that was pressed.
        //
        // Only works if the pressed key is inside the keys array.
        // This needs some kind of fixing I think.
        static int ProcessKeyboard();    
};

#endif
