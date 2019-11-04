#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <list>



namespace TEFGAS{
class ShaderProgram;
class VertexArray;

class Mesh
{   
    public:

    struct Vertex
    {
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec2 TexCoords;
    };
    struct Texture
    {
        unsigned int id;
        std::string type;
    };

    
        /*functions*/
        Mesh(std::list<Vertex> _verticies, std::list<unsigned int> _indices, std::list<Texture> _textures);

        void Draw (std::shared_ptr<ShaderProgram> _shader);

        std::shared_ptr<VertexArray> shape;
        std::shared_ptr<ShaderProgram> shader;
};
}