#include "LightMover.h"

void LightMover::Update()
{


	getEntity()->getComponent<TEFGAS::Transform>()->setPosition(glm::vec3(1 * sin(incrimenter), 5.0f, 5 * cos(incrimenter)));

	incrimenter += 0.01;
}