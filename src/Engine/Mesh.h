#include <string>
#include <memory>
#include "Time.h"
#include "Component.h"
namespace TEFGAS
{
	class ShaderProgram;
	class Transform;
	class Texture;
	class VertexArray;
	class VertexBuffer;
	class RenderTexture;
	class Material;

	class Mesh : public Component
	{
	public:
		//Mesh(Texture* _texture, Texture* _normalMap, VertexArray* _mesh, Transform* _transform, float _shine, std::shared_ptr<ShaderProgram> _shader);
		//Mesh(std::shared_ptr <Material> _material, VertexArray* _mesh);

		std::shared_ptr <Transform> transform;

		std::string tag;

		void Awake(std::shared_ptr <Material> _material, VertexArray* _mesh);
		void onDisplay();
		void draw(std::shared_ptr<RenderTexture> rendTex);
		VertexArray* mesh;
	private:
		std::shared_ptr<ShaderProgram> shader;

		Texture* texture;
		Texture* normalMap;

		std::shared_ptr<Material> material;

		float shine;


	};
}
