#include "Component.h"
#include "Entity.h"
#include <iostream>

namespace TEFGAS
{

	Component::~Component() {}
	void Component::Awake() { std::cout << "awake" << std::endl; }
	void Component::Start() {}
	void Component::Update() {}
	void Component::onDisplay() {}

	std::shared_ptr<Entity> Component::getEntity() const
	{
		return entity.lock();
	}

	std::shared_ptr<Core> Component::getCore() const
	{
		return getEntity()->getCore();
	}

}