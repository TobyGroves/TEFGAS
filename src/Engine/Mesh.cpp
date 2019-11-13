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

        setupMesh();

    }

    void Mesh::setupMesh()
    {
        std::cout<<"setting up mesh"<<std::endl;
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

        std::cout<<"finished up mesh"<<std::endl;
        
    }


    void Mesh::Draw(std::shared_ptr<ShaderProgram> _shader)
    {
        
        std::cout<<"in draw"<<std::endl;
    glm::mat4 model = glm::mat4(1.0f);

        model = glm::translate(model,glm::vec3(0.0f,-1.75f,0.0f));
        model = glm::scale(model,glm::vec3(0.2f,0.2f,0.2f));

        _shader->setUniform("in_Model",model);

        std::cout<<"set uniform model"<<std::endl;
    unsigned int diffuseNr = 1;
    unsigned int specularNr = 1;
    for(float i = 0; i < textures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i); // activate proper texture unit before binding

        std::cout<<"active texture"<<std::endl;
        // retrieve texture number (the N in diffuse_textureN)
        std::string number;
        std::string name = textures[i].type;
        if(name == "texture_diffuse")
            number = std::to_string(diffuseNr++);
        else if(name == "texture_specular")
        number = std::to_string(specularNr++);


        std::cout<<"constructed string"<<std::endl;
        shader->setUniform(name + number,i);

        std::cout<<"set float uniform"<<std::endl;
        glBindTexture(GL_TEXTURE_2D, textures[i].getId());

        std::cout<<"bound texture"<<std::endl;
    }
    glActiveTexture(GL_TEXTURE0);

    std::cout<<"activated texture"<<std::endl;
    // draw mesh
    glBindVertexArray(VAO);

        std::cout<<"bound VAO"<<std::endl;
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

        std::cout<<"Drew elements"<<std::endl;
    glBindVertexArray(0);

        std::cout<<"finished draw"<<std::endl;

    }
}