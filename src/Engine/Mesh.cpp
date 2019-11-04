#include "Mesh.h"

namespace TEFGAS
{
    //https://learnopengl.com/index.php?p=Model-Loading/Mesh

    Mesh::Mesh(std::vector<Vertex> _verticies, std::vector<unsigned int> _indices, std::vector<Texture> _textures)
    {
        verticies = _verticies;
        indices = _indices;
        textures = _textures;
    }

}