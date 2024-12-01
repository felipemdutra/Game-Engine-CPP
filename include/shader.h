#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <glm/glm.hpp>
#include <GL/glew.h>

class ShaderProgram
{
    private:
        unsigned int ID;

    public:

        ShaderProgram(const char* vertex_path, const char* fragment_path);

        void Use();

        unsigned int GetProgramID() const;

        void SetBool(const std::string &name, bool value) const;
        void SetInt(const std::string &name, int value) const;
        void SetFloat(const std::string &name, float value) const; 

        void SetMat4(const std::string &name, const glm::mat4 &mat) const;
};

#endif

