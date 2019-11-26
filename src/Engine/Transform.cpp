#include "Transform.h"

namespace TEFGAS
{
    Transform::Transform()
    {

    }

    Transform::Transform(glm::vec3 _position,glm::vec3 _rotation,glm::vec3 _scale)
    {
        position = _position;
        rotation = _rotation;
        scale = _scale;
    }
}