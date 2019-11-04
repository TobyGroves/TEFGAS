
#include <glm/glm.hpp>
#include "Texture.h"
#include "Component.h"
#include <vector>
#include <list>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>

// TODO need to include assimp idk how look at learn opengl website

namespace TEFGAS{
    class Mesh;
    class ShaderProgram;

    class Model : public Component 
    {
    public:
        Model(std::string path,std::shared_ptr<ShaderProgram> _shader)
        {
            std::cout<<"in model constructor"<<std::endl;
            LoadModel(path);
            shader = _shader;
        }

        void onDisplay();

    private:
    /* model data*/
    std::list<Mesh> meshes;
    std::string directory;
    

    /*functions*/
    void LoadModel(std::string path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    std::vector<Texture>loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
    std::shared_ptr<ShaderProgram> shader;

    };
}