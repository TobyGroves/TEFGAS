#include "Component.h"
#include <vector>
#include <list>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

// TODO need to include assimp idk how look at learn opengl website

namespace TEFGAS{
    class Mesh;
    class ShaderProgram;

    class Model : public Component 
    {

        Model(char *path)
        {
            LoadModel(path);
        }

        void onDisplay(std::shared_ptr<ShaderProgram> shader);

    private:
    /* model data*/
    std::list<Mesh> meshes;
    std::string directory;

    /*functions*/
    void LoadModel(std::string path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    //std::vector<Texture>loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);

    };
}