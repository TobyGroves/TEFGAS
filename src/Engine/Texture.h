#ifndef TEXTURE_H
#define TEXTURE_H


#include <GL/glew.h>
#include <glm/glm.hpp>

#include <string>
namespace TEFGAS{

class RenderTexture;

class Texture
{

	GLuint id;
	glm::vec2 size;

	Texture(int width, int height);

public:
  std::string type;
  Texture(std::string path);
  glm::vec2 getSize();
  GLuint getId();

};
}
#endif