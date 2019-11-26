#include "Component.h"
#include <string>
#include <memory>

namespace TEFGAS{

    class Transform;
    class Texture;
    class VertexArray;
    class VertexBuffer;
    class RenderTexture;
    class ShaderProgram;

    class Mesh : public Component {
    public:
        Mesh(std::shared_ptr<Texture>_texture, std::shared_ptr<Texture>_normalMap, std::shared_ptr<VertexArray>_mesh, std::shared_ptr<Transform> _transform, float _shine, std::shared_ptr<ShaderProgram> _shader)
        {
            texture = _texture;
	        normalMap = _normalMap;
	        mesh = _mesh;
	        transform = _transform;
	        shader = _shader;
	        shine = _shine;
        };
        std::shared_ptr<Transform> transform;

	    std::string tag;

        void onDisplay();
        //void onDisplay(std::shared_ptr<RenderTexture> rendTex);
        //void onDisplay(RenderTexture *renderTexture);
        std::shared_ptr<VertexArray> mesh;

    private:
    std::shared_ptr<ShaderProgram> shader;
	//std::shared_ptr<Time> time;

	std::shared_ptr<Texture>texture;
	std::shared_ptr<Texture>normalMap;
	
	float shine;

    };
}