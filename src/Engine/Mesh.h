#include <glm/glm.hpp>
#include "Texture.h"
#include <string>
#include <vector>
#include <list>
#include <memory>



namespace TEFGAS{
class ShaderProgram;
class VertexArray;
class Texture;

struct Vertex
    {
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec2 TexCoords;
    };


class Mesh
{   
    public:

        std::vector<Texture> textures;

    
        /*functions*/
        Mesh(std::vector<Vertex> _verticies, std::vector<unsigned int> _indices, std::vector<Texture> _textures);

        void Draw (std::shared_ptr<ShaderProgram> _shader);

        std::shared_ptr<VertexArray> shape;
        std::shared_ptr<ShaderProgram> shader;

};
}