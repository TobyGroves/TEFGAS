#include "Camera.h"
#include "Engine/Engine.h"


#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <exception>
namespace TEFGAS
{
	void Camera::Awake(std::vector<std::shared_ptr<ShaderProgram>>  _shaders)
	{
		shaders = _shaders;
		transform = getEntity()->getComponent<Transform>();
	}

	void Camera::Update()
	{
		// constructing the view matrix
		glm::mat4 model(1.0f);
		model = glm::translate(model, transform->getPosition());
		model = glm::rotate(model, glm::radians(transform->getRotation().x), glm::vec3(1, 0, 0));
		model = glm::rotate(model, glm::radians(transform->getRotation().y), glm::vec3(0, 1, 0));
		model = glm::rotate(model, glm::radians(transform->getRotation().z), glm::vec3(0, 0, 1));

		// setting in view and campos for all shaders
		for (int i = 0; i < shaders.size(); i++)
		{
			shaders.at(i)->setUniform("in_View", glm::inverse(model));
			shaders.at(i)->setUniform("in_camPos", transform->getPosition());
		}
	}
}