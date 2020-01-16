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
		/// Awake.
		/** This assigns the albedo and normal map for regular materials it also takes the shader to be used.*/
		void Awake(Texture* _albedo, Texture* _normal, std::shared_ptr<ShaderProgram> _shader);
		/// Awake PBR.
		/** This assigns the albedo , normal map, metallic map, roughness map and ao map for pbr materials it also takes the shader to be used.*/
		void Awake(Texture* _albedo, Texture* _normal, Texture* _metallic, Texture* _roughness, Texture* _ao, std::shared_ptr<ShaderProgram> _shader);
		
		std::shared_ptr<ShaderProgram> shader;
		/// Albedo map.
		/** */
		Texture* albedo;
		/// Normal map.
		/** */
		Texture* normal;
		/// Metallic Map.
		/** */
		Texture* metallic;
		/// Roughness map.
		/** */
		Texture* roughness;
		/// Ambient Occlusion map.
		/** */
		Texture* ao;
	};
}