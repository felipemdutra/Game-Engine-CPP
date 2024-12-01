#include "../include/engine.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main()
{
    Engine engine;

    Window* window = engine.InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT,
            "Unreal Engine");
    if (!window)
    {
        std::cout << "Error initializing window!\n";
        return 1;
    }

    Renderer* renderer = engine.InitRenderer();

    auto camera = renderer->GetCamera(45.0f, WINDOW_WIDTH, WINDOW_HEIGHT,
            0.0f, 0.0f, 3.0f);

    window->DisableCursor();
    window->SetMousePositionCallback(*camera);


    if (!renderer)
    {
        std::cout << "Error initializing renderer!\n";
        return 1;
    }


    while (!window->WindowShouldClose())
    {
        window->ProcessInput();
        camera->Update(window, renderer);
        camera->ProcessKeyboard(window);
        
        // Clear the screen
        renderer->Clear(0.5f, 0.3f, 1.0f, 1.0f);

        renderer->RenderCube(1.4f, 2.0f, 0.0f);

        window->SwapBuffersAndPollEvents();
    }

    engine.Shutdown();
}
