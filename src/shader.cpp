#include "../include/shader.h"

ShaderProgram::ShaderProgram(const char* vertex_path, 
        const char* fragment_path)
{
    std::string vertex_code;
    std::string fragment_code;
    std::ifstream vShader_file;
    std::ifstream fShader_file;

    vShader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        vShader_file.open(vertex_path);
        fShader_file.open(fragment_path);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vShader_file.rdbuf();
        fShaderStream << fShader_file.rdbuf();

        vShader_file.close();
        fShader_file.close();

        vertex_code = vShaderStream.str();
        fragment_code = fShaderStream.str();
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "Error! Couldn't read shader file!" << std::endl;
    }

    const char* vShaderCode = vertex_code.c_str();
    const char* fShaderCode = fragment_code.c_str();

    unsigned int vertex, fragment;
    int success;
    char info_log[512];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, nullptr, info_log);
        std::cout << "Error! Couldn't compile vertex shader." << std::endl;
    }

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragment, 512, nullptr, info_log);
        std::cout << "Error! Couldn't compile fragment shader." << std::endl;
    }

    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    glGetProgramiv(ID, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(ID, 512, nullptr, info_log);
        std::cout << "Error! Couldn't link shader program." << std::endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}


void ShaderProgram::Use()
{
    glUseProgram(ID);
}


void ShaderProgram::SetBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}


void ShaderProgram::SetInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}


void ShaderProgram::SetFloat(const std::string &name, float value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
