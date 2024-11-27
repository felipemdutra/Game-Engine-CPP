#include <GL/glew.h>

#include "shader.h"

// You need to have GLFW and GLEW working
class Renderer
{
    // TODO: Create vertex shader and fragment shader class. 
    private:
        unsigned int vao, vbo, ebo; 
        unsigned int shader_program;

    public:
        Renderer();

        // This calls destroys the vao, vbo, ebo and the shader program.
        ~Renderer();

        // This function clears the screen and set a new color.
        void Clear(float r, float g, float b, float a);

        void RenderCube();
};
