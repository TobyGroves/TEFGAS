#include "Entity.h"

namespace TEFGAS
{

	std::shared_ptr<Core> Entity::getCore()
	{
		return core.lock();
	}

	void Entity::Update()
	{
		for (std::vector<std::shared_ptr<Component> >::iterator it = components.begin();
			it != components.end(); it++)
		{
			if (!(*it)->began)
			{
				(*it)->Start();
				(*it)->began = true;
			}

			(*it)->Update();
		}
	}

	void Entity::display()
	{
		for (std::vector<std::shared_ptr<Component> >::iterator it = components.begin();
			it != components.end(); it++)
		{
			(*it)->onDisplay();
		}
	}

}