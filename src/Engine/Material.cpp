#include "Material.h"
#include "Transform.h"
#include "Texture.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"
#include <memory>

namespace TEFGAS
{

	void Material::Awake(Texture* _albedo, Texture* _normal, std::shared_ptr<ShaderProgram> _shader)
	{
		albedo = _albedo;
		normal = _normal;
		shader = _shader;
	}


	void Material::Awake(Texture* _albedo, Texture* _normal, Texture* _metallic, Texture* _roughness, Texture* _ao, std::shared_ptr<ShaderProgram> _shader)
	{
		albedo = _albedo;
		normal = _normal;
		metallic = _metallic;
		roughness = _roughness;
		ao = _ao;
		shader = _shader;
	}
}