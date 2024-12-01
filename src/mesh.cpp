#include "../include/mesh.h"

Cube::Cube(float width, float height, float depth) :
    width_(width), height_(height), depth_(depth)
{
    GenerateGeometry();
}

void Cube::GenerateGeometry()
{
    // width
    float w = width_ / 2.0f;
    // height
    float h = height_ / 2.0f;
    // depth
    float d = depth_ / 2.0f;
    

    vertices_ = {
        // Back face
        -w, -h, -d,  0.0f, 0.0f, -1.0f,  0.0f, 0.0f, 
         w, -h, -d,  0.0f, 0.0f, -1.0f,  1.0f, 0.0f,
         w,  h, -d,  0.0f, 0.0f, -1.0f,  1.0f, 1.0f,
        -w,  h, -d,  0.0f, 0.0f, -1.0f,  0.0f, 1.0f,

        // Front face
        -w, -h,  d,  0.0f, 0.0f,  1.0f,  0.0f, 0.0f, 
         w, -h,  d,  0.0f, 0.0f,  1.0f,  1.0f, 0.0f,
         w,  h,  d,  0.0f, 0.0f,  1.0f,  1.0f, 1.0f,
        -w,  h,  d,  0.0f, 0.0f,  1.0f,  0.0f, 1.0f,

        // Left face
        -w, -h, -d, -1.0f, 0.0f,  0.0f,  0.0f, 0.0f, 
        -w,  h, -d, -1.0f, 0.0f,  0.0f,  1.0f, 0.0f,
        -w,  h,  d, -1.0f, 0.0f,  0.0f,  1.0f, 1.0f,
        -w, -h,  d, -1.0f, 0.0f,  0.0f,  0.0f, 1.0f,

        // Right face
         w, -h, -d,  1.0f, 0.0f,  0.0f,  0.0f, 0.0f, 
         w,  h, -d,  1.0f, 0.0f,  0.0f,  1.0f, 0.0f,
         w,  h,  d,  1.0f, 0.0f,  0.0f,  1.0f, 1.0f,
         w, -h,  d,  1.0f, 0.0f,  0.0f,  0.0f, 1.0f,

        // Bottom face
        -w, -h, -d,  0.0f, -1.0f, 0.0f,  0.0f, 0.0f,
         w, -h, -d,  0.0f, -1.0f, 0.0f,  1.0f, 0.0f,
         w, -h,  d,  0.0f, -1.0f, 0.0f,  1.0f, 1.0f,
        -w, -h,  d,  0.0f, -1.0f, 0.0f,  0.0f, 1.0f,

        // Top face
        -w,  h, -d,  0.0f,  1.0f, 0.0f,  0.0f, 0.0f, 
         w,  h, -d,  0.0f,  1.0f, 0.0f,  1.0f, 0.0f,
         w,  h,  d,  0.0f,  1.0f, 0.0f,  1.0f, 1.0f,
        -w,  h,  d,  0.0f,  1.0f, 0.0f,  0.0f, 1.0f
    };

    indices_ = {
        // Back face
        0, 1, 2, 2, 3, 0,
        // Front face
        4, 5, 6, 6, 7, 4,
        // Left face
        8, 9, 10, 10, 11, 8,
        // Right face
        12, 13, 14, 14, 15, 12,
        // Bottom face
        16, 17, 18, 18, 19, 16,
        // Top face
        20, 21, 22, 22, 23, 20
    };

    vertex_count_= vertices_.size(); 
    index_count_ = indices_.size();
}


Cube::~Cube()
{
    vertices_.clear();
    vertex_count_ = 0;

    indices_.clear();
    index_count_ = 0;
}

std::vector<float> Cube::GetVertices()
{
    return vertices_;
}


int Cube::GetVertexCount()
{
    return vertex_count_;
}


std::vector<unsigned int> Cube::GetIndices()
{
    return indices_;
}


unsigned int Cube::GetIndexCount()
{
    return index_count_;
}
