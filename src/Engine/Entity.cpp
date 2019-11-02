#include "Entity.h"
#include "Component.h"

namespace TEFGAS
{

	std::shared_ptr<Core> Entity::getCore() const
	{
		return core.lock();
	}

	void Entity::Update()
	{
		for(auto& compo : components)
		{
			compo->Update();
		}
	}

	void Entity::display()
	{

	}

}