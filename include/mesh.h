#include <vector>

class Mesh
{
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    public:
        
};

class Cube
{
    private:
        float width_, height_, depth_;
        
        int vertex_count_;
        int index_count_;
        
        std::vector<float> vertices_;
        std::vector<unsigned int> indices_;

    public:
         
        Cube(float width = 1.0f, float height = 1.0f, float depth = 1.0f);
        ~Cube();

        void SetDimensions(float width, float height, float depth);
        void GenerateGeometry();
        
        std::vector<float> GetVertices();
        int GetVertexCount();

        std::vector<unsigned int> GetIndices();
        unsigned int GetIndexCount();
        
};
