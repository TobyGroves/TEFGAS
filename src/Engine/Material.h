#include <string>
#include <memory>
#include "Time.h"
#include "Component.h"


namespace TEFGAS
{
	class ShaderProgram;
	class Texture;

	class Material : public Component
	{
	public:
		//Material(Texture* _texture, Texture* _normalMap,std::shared_ptr<ShaderProgram> _shader);
		void Awake(Texture* _albedo, Texture* _normal, std::shared_ptr<ShaderProgram> _shader);
		void Awake(Texture* _albedo, Texture* _normal, Texture* _metallic, Texture* _roughness, Texture* _ao, std::shared_ptr<ShaderProgram> _shader);
		//Material(Texture* _albedo, Texture* _metallic, Texture* _roughness, Texture* _height, Texture* _ambientOcclusion, Texture* _normal ,std::shared_ptr<ShaderProgram> _shader);

		std::shared_ptr<ShaderProgram> shader;

		Texture* albedo;
		Texture* normal;
		Texture* metallic;
		Texture* roughness;
		Texture* ao;
	};
}