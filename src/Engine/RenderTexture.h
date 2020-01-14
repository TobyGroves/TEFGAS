#include "Texture.h"
namespace TEFGAS
{
	class RenderTexture : public Texture
	{
		GLuint fbo;

	public:
		RenderTexture(int width, int height);

		GLuint getFbId();
		void clear();

	};
}
