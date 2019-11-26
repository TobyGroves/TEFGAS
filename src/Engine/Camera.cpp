#include "Camera.h"
#include "Transform.h"
#include "ShaderProgram.h"


#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <exception>

namespace TEFGAS{

Camera::Camera(std::vector<std::shared_ptr<ShaderProgram>> _shaders,std::shared_ptr<Transform>_transform)
{
	shaders = _shaders;
	transform = _transform;
}

void Camera::Update()
{

	transform->setPosition(transform->getPosition() + glm::vec3(0.0,1.0,0.0));
	transform->setRotation(transform->getRotation() + glm::vec3(0.0,10.0,0.0));


	glm::mat4 model(1.0f);
	model = glm::translate(model, transform->getPosition());
	model = glm::rotate(model, glm::radians(transform->getRotation().x), glm::vec3(1, 0, 0));
	model = glm::rotate(model, glm::radians(transform->getRotation().y), glm::vec3(0, 1, 0));
	model = glm::rotate(model, glm::radians(transform->getRotation().z), glm::vec3(0, 0, 1));
	
	for (int i = 0; i < shaders.size(); i++) 
	{
		shaders.at(i)->setUniform("in_View", glm::inverse(model));
	}
}
}