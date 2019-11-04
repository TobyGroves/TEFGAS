#include "Component.h"
#include <vector>
#include <list>
//#include <assimp/assimp.h>

// TODO need to include assimp idk how look at learn opengl website

namespace TEFGAS{
    class Mesh;

    class Model : public Component 
    {

        Model(char *path)
        {
            LoadModel(path);
        }

        void onDisplay();

    private:
    /* model data*/
    std::list<Mesh> meshes;
    std::string directory;

    /*functions*/
    void LoadModel(std::string path);
    //void processNode(aiNode *node, const aiScene *scene);
    //Mesh processMesh(aiMesh *mesh, const siScene *scene);
    //std::vector<Texture>loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);

    };
}