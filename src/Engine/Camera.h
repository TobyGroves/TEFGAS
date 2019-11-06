#include "Component.h"

namespace TEFGAS{
class Transform;
class ShaderProgram;

class Camera : public Component
{
public:

    Camera(std::shared_ptr<ShaderProgram> _shader,std::shared_ptr<Transform>_transform);

    void Update() override;

private:
    std::shared_ptr<Transform> transform;

    std::shared_ptr<ShaderProgram> shader;



};

}