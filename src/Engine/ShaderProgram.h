#include <GL/glew.h>
#include <glm/glm.hpp>

#include <string>
#include <vector>

namespace TEFGAS
{
class Texture;
class VertexArray;

struct Sampler
{
  GLint id;
  Texture *texture;
};


class ShaderProgram
{
  GLuint id;
  std::vector<Sampler> samplers;

public:
  ShaderProgram(const char* vertexPath, const char* fragmentPath, const char* geometryPath  = nullptr);
  void draw(VertexArray& vertexArray);
  void setUniform(std::string uniform, glm::vec4 value);
  void setUniform(std::string uniform, float value);
  void setUniform(std::string uniform, glm::mat4 value);
  void setUniform(std::string uniform, Texture *texture);
  void setFloat(const std::string &name,float value);
  GLuint getId();
  void use();

};

}