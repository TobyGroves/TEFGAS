#include "Component.h"

#include <memory>

namespace TEFGAS
{

class VertexArray;
class ShaderProgram;

class MeshRenderer : public Component
{
public:

  MeshRenderer(std::string _meshPath,std::string _vertShadPath,std::string _fragShadPath);


  void Awake();

private:

  std::string meshPath;
  std::string vertShadPath;
  std::string fragShadPath;


  void onDisplay();
  std::shared_ptr<VertexArray> shape;
  std::shared_ptr<ShaderProgram> shader;
};

}