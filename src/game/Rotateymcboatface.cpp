#include "rotateymcboatface.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <exception>


void RotateyMcBoat::Update()
{
	getEntity()->getComponent<TEFGAS::Transform>()->setRotation(getEntity()->getComponent<TEFGAS::Transform>()->getRotation() + glm::vec3(0, 0.1, 0));
}

void RotateyMcBoat::Start()
{
	getEntity()->getComponent<TEFGAS::Sound>()->play();
}