#include "Entity.h"
#include "Component.h"
#include <iostream>
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

			if(!compo->began)
			{
				
				compo->Awake();
				compo->began = true;
			}


			compo->Update();
		}
	}

	void Entity::display()
	{
for(auto& compo : components)
		{
			compo->onDisplay();
		}
	}

}