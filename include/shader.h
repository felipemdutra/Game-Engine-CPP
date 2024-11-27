#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class ShaderProgram
{
    private:
        unsigned int ID;

    public:

        ShaderProgram(const char* vertex_path, const char* fragment_path);

        void Use();

        void SetBool(const std::string &name, bool value) const;
        void SetInt(const std::string &name, int value) const;
        void SetFloat(const std::string &name, float value) const; 
};

#endif

