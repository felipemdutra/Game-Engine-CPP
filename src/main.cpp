#include "../include/engine.h"

const int WINDOW_WIDTH = 800, WINDOW_HEIGHT = 600;

int main()
{
    Engine engine;

    Window* window = engine.InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT,
            "Unreal Engine");

    Renderer* renderer = engine.InitRenderer();

    while (!window->WindowShouldClose())
    {
        window->ProcessInput();
        
        // Clear the screen
        renderer->Clear(0.5f, 0.3f, 1.0f, 1.0f);

        window->SwapBuffersAndPollEvents();
    }

    engine.Shutdown();
}
