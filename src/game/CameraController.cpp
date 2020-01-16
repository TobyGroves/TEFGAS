#include "CameraController.h"
#include <iostream>

void CameraController::Update()
{
	if (getCore()->input->isKey('w'))
	{
		std::cout << "forward" << std::endl;
		getEntity()->getComponent<TEFGAS::Transform>()->setPosition(getEntity()->getComponent<TEFGAS::Transform>()->getPosition() + (getEntity()->getComponent<TEFGAS::Transform>()->getForward() * 0.5f));
	}
	if (getCore()->input->isKey('s'))
	{
		std::cout << "back" << std::endl;

		getEntity()->getComponent<TEFGAS::Transform>()->setPosition(getEntity()->getComponent<TEFGAS::Transform>()->getPosition() + (getEntity()->getComponent<TEFGAS::Transform>()->getForward() * -0.5f));

	}
	if (getCore()->input->isKey('a'))
	{
		std::cout << "left" << std::endl;
		getEntity()->getComponent<TEFGAS::Transform>()->setPosition(getEntity()->getComponent<TEFGAS::Transform>()->getPosition() + (getEntity()->getComponent<TEFGAS::Transform>()->getRight() * -0.5f));
	}
	if (getCore()->input->isKey('d'))
	{
		std::cout << "right" << std::endl;

		getEntity()->getComponent<TEFGAS::Transform>()->setPosition(getEntity()->getComponent<TEFGAS::Transform>()->getPosition() + (getEntity()->getComponent<TEFGAS::Transform>()->getRight() * 0.5f));
	}

	getEntity()->getComponent<TEFGAS::Transform>()->setRotation(getEntity()->getComponent<TEFGAS::Transform>()->getRotation() + (-getEntity()->getComponent<TEFGAS::Transform>()->getUp() * (getCore()->input->getMouseMove().x * -1)));

}