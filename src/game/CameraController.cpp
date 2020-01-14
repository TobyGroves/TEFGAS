#include "CameraController.h"
#include <iostream>

void CameraController::Update()
{
	if (getCore()->state[SDL_SCANCODE_W])
	{
		std::cout << "forward" << std::endl;
		getEntity()->getComponent<TEFGAS::Transform>()->setPosition(getEntity()->getComponent<TEFGAS::Transform>()->getPosition() + glm::vec3(0, 0, -0.5));
	}
	if (getCore()->state[SDL_SCANCODE_S])
	{
		std::cout << "back" << std::endl;

		getEntity()->getComponent<TEFGAS::Transform>()->setPosition(getEntity()->getComponent<TEFGAS::Transform>()->getPosition() + glm::vec3(0, 0, 0.5));

	}
	if (getCore()->state[SDL_SCANCODE_A])
	{
		std::cout << "left" << std::endl;
		getEntity()->getComponent<TEFGAS::Transform>()->setPosition(getEntity()->getComponent<TEFGAS::Transform>()->getPosition() + glm::vec3(-0.5, 0, 0));
	}
	if (getCore()->state[SDL_SCANCODE_D])
	{
		std::cout << "right" << std::endl;
		getEntity()->getComponent<TEFGAS::Transform>()->setPosition(getEntity()->getComponent<TEFGAS::Transform>()->getPosition() + glm::vec3(0.5, 0, 0));
	}
	if (getCore()->state[SDL_SCANCODE_LEFT])
	{
		std::cout << "turnLeft" << std::endl;
		getEntity()->getComponent<TEFGAS::Transform>()->setRotation(getEntity()->getComponent<TEFGAS::Transform>()->getRotation() + glm::vec3(0, 0.2, 0));
	}
	if (getCore()->state[SDL_SCANCODE_RIGHT])
	{
		std::cout << "turnRight" << std::endl;
		getEntity()->getComponent<TEFGAS::Transform>()->setRotation(getEntity()->getComponent<TEFGAS::Transform>()->getRotation() + glm::vec3(0, -0.2, 0));
	}

}