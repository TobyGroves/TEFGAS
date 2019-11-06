#include "Camera.h"
#include "Transform.h"
#include "ShaderProgram.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <iostream>

namespace TEFGAS
{

    Camera::Camera(std::shared_ptr<ShaderProgram> _shader,std::shared_ptr<Transform>_transform)
    {
        shader = _shader;
        transform = _transform;
    }

    void Camera::Update()
    {
        glm::mat4 model(1.0f);
        model = glm::translate(model, transform->getPosition());
        model = glm::rotate(model, glm::radians(transform->getRotation().x),glm::vec3(1,0,0));
        model = glm::rotate(model, glm::radians(transform->getRotation().y),glm::vec3(0,1,0));
        model = glm::rotate(model, glm::radians(transform->getRotation().z),glm::vec3(0,0,1));

        shader->setUniform("in_View",glm::inverse(model));
        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(45.0f),(float)640/(float)480,0.1f,100.0f);
        shader->setUniform("in_Projection", glm::mat4(1.0f));
    }
}