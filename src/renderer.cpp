#include "../include/renderer.h"

Renderer::Renderer()
{
    ShaderProgram shader_program("shaders/shader.vert", "shaders/shader.frag");
    shader_program.Use();

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
    
    glBindVertexArray(vao);

    glBindBuffer(1, vbo);
    glBindBuffer(1, ebo);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); 
    glEnableVertexAttribArray(0);
}

Renderer::~Renderer()
{
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    glDeleteVertexArrays(1, &vao);
    glDeleteProgram(shader_program);
}

void Renderer::Clear(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


