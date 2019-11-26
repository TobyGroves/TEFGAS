#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/ext.hpp>
#include <vector>
#include <exception>
#include <memory>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> 

#include "Component.h"

namespace TEFGAS{
class Transform;
class ShaderProgram;

class Camera : public Component
{
public:

    Camera(std::vector<std::shared_ptr<ShaderProgram>> _shaders,std::shared_ptr<Transform>_transform);

    void Update() override;

private:
    std::shared_ptr<Transform> transform;

    std::vector<std::shared_ptr<ShaderProgram>> shaders;



};

}