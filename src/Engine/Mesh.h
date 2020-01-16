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
	class Material;

	class Mesh : public Component
	{
	public:

		std::shared_ptr <Transform> transform;

		///Awake
		/** Awake initializes the mesh and takes a material and a vertex array*/
		void Awake(std::shared_ptr <Material> _material, VertexArray* _mesh);
		/// Display.
		/** This is the function that draws the mesh to the screen.*/
		void onDisplay();
		VertexArray* mesh;
	private:
		std::shared_ptr<ShaderProgram> shader;

		Texture* texture;
		Texture* normalMap;

		std::shared_ptr<Material> material;

		float shine;


	};
}
