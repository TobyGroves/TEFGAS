#include "Mesh.h"
#include <iostream>
#include <memory>
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"


namespace TEFGAS
{

    Mesh::Mesh(std::vector<Vertex> _verticies, std::vector<unsigned int> _indices, std::vector<Texture> _textures)
    {
        textures = _textures;
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

        std::cout<<"in Draw of mesh"<<std::endl;

        _shader->setUniform("in_Model", glm::mat4(1.0f));
        _shader->setUniform("in_Projection", glm::mat4(1.0f));

        unsigned int diffuseNum = 1;
        unsigned int specularNum = 1;
        unsigned int normalNum = 1;
        for(unsigned int i=0; i< textures.size(); i++)
        {
            std::string number;
            std::string name = textures.at(i).type;
            if(name == "texture_diffuse")
            {
                number = std::to_string(diffuseNum++);
            }
            else if (name == "texture_specular")
            {
                number = std::to_string(specularNum++);
            }
            else if (name == "texture_normal")
            {
                number = std::to_string(normalNum++);
            }
            std::string uniform ="material."+name+number;
            _shader->setUniform(uniform,&textures[i]);
        }

        _shader->draw(*shape);
    }
}