#include <GL/glew.h>
#include <glm/glm.hpp>

#include "shader.h"
#include "mesh.h"
#include "window.h"
#include "camera.h"

// You need to have GLFW and GLEW working
class Renderer
{
    // TODO: Create vertex shader and fragment shader class. 
    private:
        unsigned int vao, vbo, ebo; 
        ShaderProgram shader_program;

        Camera* camera;

    public:
        Renderer();

        // This calls destroys the vao, vbo, ebo and the shader program.
        ~Renderer();

        Camera* GetCamera(float fov, float window_width, float window_height,
                float camera_x, float camera_y,float camera_z);

        // This function clears the screen and set a new color.
        void Clear(float r, float g, float b, float a);

        void RenderCube(float width = 1.0f, float height = 1.0f, 
                float depth = 1.0f);

        void ShaderSetUniformValue(const std::string &name,
                const glm::mat4 &mat);
};
