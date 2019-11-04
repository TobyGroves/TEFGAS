#include <glm/glm.hpp>
#include <string>
#include <vector>

namespace TEFGAS{
class Mesh
{   
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

    public:
        /*mesh data*/
        std::vector<Vertex> verticies;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;

        /*functions*/
        Mesh(std::vector<Vertex> _verticies, std::vector<unsigned int> _indices, std::vector<Texture> _textures);
};
}