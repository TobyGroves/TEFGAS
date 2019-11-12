#include "Mesh.h"
#include <iostream>
#include <memory>
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>


namespace TEFGAS
{

    Mesh::Mesh(std::vector<Vertex> _vertices, std::vector<unsigned int> _indices, std::vector<Texture> _textures)
    {
        textures = _textures;
        vertices = _vertices;
        indices = _indices;

        /*std::shared_ptr<VertexBuffer> positions = std::make_shared<VertexBuffer>();
        std::shared_ptr<VertexBuffer> texcoords = std::make_shared<VertexBuffer>();
        std::shared_ptr<VertexBuffer> normals = std::make_shared<VertexBuffer>();
        for(auto& vert : _vertices)
        {
            positions->add(vert.Position);

            //std::cout<<"p:"<<vert.Position.x<<" "<<vert.Position.y<<" "<<vert.Position.y<<" ";

            texcoords->add(vert.TexCoords);
            normals->add(vert.Normal);

        }
        //std::cout<<std::endl;
        
        shape = std::make_shared<VertexArray>();

        shape->setBuffer("in_Position",positions);
        //shape->setBuffer("in_Color", colors);
        shape->setBuffer("in_TexCoord",texcoords);
        shape->setBuffer("in_Normal",normals);
        */
        setupMesh();

    }

    void Mesh::setupMesh()
    {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
  
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);  

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), 
                 &indices[0], GL_STATIC_DRAW);

        // vertex positions
        glEnableVertexAttribArray(0);	
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        // vertex normals
        glEnableVertexAttribArray(1);	
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
        // vertex texture coords
        glEnableVertexAttribArray(2);	
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));

        glBindVertexArray(0);
        
    }


    void Mesh::Draw(std::shared_ptr<ShaderProgram> _shader){



        //_shader->setUniform("in_Projection", glm::mat4(1.0f));
        
        /*

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
            std::string uniform =name+number;
            _shader->setUniform(uniform,&textures[i]);
        }

        _shader->draw(*shape,textures.at(0).getId());*/
    glm::mat4 model = glm::mat4(1.0f);

        model = glm::translate(model,glm::vec3(0.0f,-1.75f,0.0f));
        model = glm::scale(model,glm::vec3(0.2f,0.2f,0.2f));

        _shader->setUniform("in_Model",model);

    unsigned int diffuseNr = 1;
    unsigned int specularNr = 1;
    for(unsigned int i = 0; i < textures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i); // activate proper texture unit before binding
        // retrieve texture number (the N in diffuse_textureN)
        std::string number;
        std::string name = textures[i].type;
        if(name == "texture_diffuse")
            number = std::to_string(diffuseNr++);
        else if(name == "texture_specular")
        number = std::to_string(specularNr++);
        shader->setFloat(name + number,i);
        glBindTexture(GL_TEXTURE_2D, textures[i].getId());
    }
    glActiveTexture(GL_TEXTURE0);

    // draw mesh
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    }
}