#include "renderer.h"
#include "window.h"

// The engine initializes GLFW, GLEW, the window and renderer.
class Engine
{
    private:

        Window* window = nullptr;
        Renderer* renderer = nullptr;
        
    public:
        
        ~Engine();

        Window* InitWindow(int width, int height, const char* title);

        Renderer* InitRenderer();

        void Shutdown();
};
