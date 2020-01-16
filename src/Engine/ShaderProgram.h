#include <GL/glew.h>
#include <glm/glm.hpp>

#include <string>
#include <vector>
#include <memory>
namespace TEFGAS
{
	class VertexArray;
	class Texture;
	class Skybox;
	/// Sampler.
	/** This is a struct used for storing textures along with their opengl ID in the same place.*/
	struct Sampler
	{
		GLint id;
		Texture* texture;
	};
	/// Shader Program.
	/** This is the wrapper that handles most of the communication between opengl and the Engine.*/
	class ShaderProgram
	{
		GLuint id;
		std::vector<Sampler> samplers;
		glm::vec4 viewport;
		VertexArray* simpleShape;

	public:
		/// Constructor.
		/** This takes the 2 shaders vertex and fragment and sets them up ready to be used.*/
		ShaderProgram(std::string vert, std::string frag);
		void draw();
		/// Draw.
		/** This will draw the vertex array passed to it onto the screen.*/
		void draw(VertexArray* vertexArray);
		/// Set Vec3 Uniform.
		void setUniform(std::string uniform, glm::vec3 value);
		/// Set Vec4 Uniform.
		void setUniform(std::string uniform, glm::vec4 value);
		/// Set Float Uniform.
		void setUniform(std::string uniform, float value);
		/// Set Mat4 Uniform.
		void setUniform(std::string uniform, glm::mat4 value);
		/// Set Texture Uniform.
		void setUniform(std::string uniform, Texture* texture);
		/// Set Texture Uniform.
		void setUniform(std::string uniform, std::shared_ptr<Texture> texture);
		/// Set Int Uniform.
		void setUniform(std::string uniform, int value);

		GLuint getId();
		void setViewport(glm::vec4 viewPort);

		///Prints any shader errors to the console.
		void printShaderInfoLog(GLuint obj);

		/// Prints any OpenGL errors to the console.
		void printProgramInfoLog(GLuint obj);

	};
}
