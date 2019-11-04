#include "Model.h"
#include "Mesh.h"
#include <iostream>
#include <list>

namespace TEFGAS{
    class ShaderProgram;
    void Model::onDisplay(std::shared_ptr<ShaderProgram> shader)
    {
        for(auto&mesh : meshes)
        {
            mesh.Draw(shader); 
        }
    }

    void Model::LoadModel(std::string path)
    {
        Assimp::Importer import;
        const aiScene *scene =import.ReadFile(path,aiProcess_Triangulate | aiProcess_FlipUVs);

        if(!scene||scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        {
                std::cout<<"ERROR::ASSIMP::" << import.GetErrorString()<<std::endl;
                return;
        }
        directory = path.substr(0,path.find_last_of('/'));

        processNode(scene->mRootNode, scene);
    }

    void Model::processNode(aiNode *node, const aiScene *scene)
    {
        for(unsigned int i = 0; i < node->mNumMeshes; i++)
        {
            aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
            meshes.push_back(processMesh(mesh,scene));
        }

        for(unsigned int i=0;i<node->mNumChildren; i++)
        {
            processNode(node->mChildren[i],scene);
        }
    }

    Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene)
    {
        std::list<Mesh::Vertex> vertices;
        std::list<unsigned int> indices;
        std::list<Mesh::Texture>textures;

        for(unsigned int i=0; i< mesh->mNumVertices;i++)
        {
            Mesh::Vertex vertex;
            // process vert location norm and texcoord
            glm::vec3 vector;
            vector.x = mesh->mVertices[i].x;
            vector.y = mesh->mVertices[i].y;
            vector.z = mesh->mVertices[i].z;
            vertex.Position = vector;

            vector.x = mesh->mNormals[i].x;
            vector.y = mesh->mNormals[i].y;
            vector.z = mesh->mNormals[i].z;
            vertex.Normal = vector;

            if(mesh->mTextureCoords[0])
            {
                glm::vec2 vec;
                vec.x = mesh->mTextureCoords[0][i].x;
                vec.y = mesh->mTextureCoords[0][i].y;
                vertex.TexCoords = vec;
            }
            else
            {
                vertex.TexCoords = glm::vec2(0.0f,0.0f);
            }

            vertices.push_back(vertex);

            for(unsigned int i = 0; i<mesh->mNumFaces; i++)
            {
                aiFace face = mesh->mFaces[i];
                for(unsigned int j =0;j<face.mNumIndices; j++)
                {
                    indices.push_back(face.mIndices[j]);
                }
            }
            
            //material bit check learn opengl  

        }

        // process indices

        //process material
        if(mesh->mMaterialIndex >= 0)
        {

        }
        return Mesh(vertices,indices,textures);
    }

}