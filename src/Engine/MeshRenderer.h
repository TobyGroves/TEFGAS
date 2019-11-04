#include "Component.h"

#include <memory>

namespace TEFGAS
{

class VertexArray;
class ShaderProgram;

class MeshRenderer : public Component
{
public:
  void Awake();

private:
  void onDisplay();

  std::shared_ptr<VertexArray> shape;
  std::shared_ptr<ShaderProgram> shader;

};

}