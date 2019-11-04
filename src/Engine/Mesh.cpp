#include "Mesh.h"
#include <iostream>
#include <memory>
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"

namespace TEFGAS
{
    //https://learnopengl.com/index.php?p=Model-Loading/Mesh

    Mesh::Mesh(std::list<Vertex> _verticies, std::list<unsigned int> _indices, std::list<Texture> _textures)
    {

        std::cout<< "beginning of awake in mesh renderer"<<std::endl;

        std::shared_ptr<VertexBuffer> positions = std::make_shared<VertexBuffer>();
        std::shared_ptr<VertexBuffer> texcoords = std::make_shared<VertexBuffer>();
        std::shared_ptr<VertexBuffer> normals = std::make_shared<VertexBuffer>();
        for(auto& vert : _verticies)
        {
            positions->add(vert.Position);
            texcoords->add(vert.TexCoords);
            normals->add(vert.Normal);

        }

        //positions->add(glm::vec3(0.0f, 0.5f, 0.0f));
        //positions->add(glm::vec3(-0.5f, -0.5f, 0.0f));
        //positions->add(glm::vec3(0.5f, -0.5f, 0.0f));

        //std::shared_ptr<VertexBuffer> colors = std::make_shared<VertexBuffer>();
        //colors->add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
        //colors->add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
        //colors->add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

        std::cout<< "colors added"<<std::endl;

        shape = std::make_shared<VertexArray>();

        std::cout<< "made shared"<<std::endl;
        shape->setBuffer("in_Position", positions);
        //shape->setBuffer("in_Color", colors);
        shape->setBuffer("in_TexCoord", texcoords);
        shape->setBuffer("in_Normal",normals);
        std::cout<< "buffers set"<<std::endl;

    }

    void Mesh::Draw(std::shared_ptr<ShaderProgram> _shader){
        _shader->setUniform("in_Model", glm::mat4(1.0f));
        _shader->setUniform("in_Projection", glm::mat4(1.0f));
        _shader->draw(*shape);
    }
}