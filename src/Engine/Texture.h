#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <string>
namespace TEFGAS
{
	/// Texture Class.
	/** This class stores the relevant information about a texture aswell as loading and setting it up in opengl. */
	class Texture
	{

		GLuint id;
		glm::vec2 size;
		Texture(int width, int height);

	public:
		/// Constructor.
		/** This takes the path of the texture. */
		Texture(std::string path);
		/// Get Size.
		/** Returns the size of the texture. */
		glm::vec2 getSize();
		/// GetId.
		/** This returns the opengl ID of the texture. */
		GLuint getId();

	};
}
#endif