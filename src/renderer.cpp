#include "../include/renderer.h"

Renderer::Renderer() : 
    shader_program("shaders/shader.vert", "shaders/shader.frag")
{
    glEnable(GL_DEPTH_TEST); 

    shader_program.Use();

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
    
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
            (void*)0); 
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
            (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
            (void*)(5 * sizeof(float)));

    glEnableVertexAttribArray(2);
}

Renderer::~Renderer()
{
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    glDeleteVertexArrays(1, &vao);

    delete camera;
}


Camera* Renderer::GetCamera(float fov, float window_width, float window_height,
        float camera_x, float camera_y, float camera_z)
{
    camera = new Camera(fov, window_width, window_height,
            glm::vec3(camera_x, camera_y, camera_z)); 
    return camera;
}


void Renderer::Clear(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::RenderCube(float width, float height, float depth)
{
    Cube cube(width, height, depth);

    glBufferData(GL_ARRAY_BUFFER, cube.GetVertexCount() * sizeof(float),
            cube.GetVertices().data(), GL_STATIC_DRAW);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 
            cube.GetIndexCount() * sizeof(unsigned int),
            cube.GetIndices().data(), GL_STATIC_DRAW); 

    glDrawElements(GL_TRIANGLES, cube.GetIndexCount(), GL_UNSIGNED_INT, 
            nullptr);
}


void Renderer::ShaderSetUniformValue(const std::string &name,
        const glm::mat4 &mat)
{
    shader_program.SetMat4(name, mat);
}
