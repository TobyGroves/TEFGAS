#include "Component.h"
#include "Entity.h"

namespace TEFGAS
{

	Component::~Component() {}
	void Component::Awake() {}
	void Component::Start() {}
	void Component::Update() {}
	void Component::onDisplay() {}

	std::shared_ptr<Entity> Component::getEntity()
	{
		return entity.lock();
	}

	std::shared_ptr<Core> Component::getCore()
	{
		return getEntity()->getCore();
	}

}