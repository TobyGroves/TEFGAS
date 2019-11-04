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

		std::cout<< "beginning entity update"<<std::endl;
		for(auto& compo : components)
		{

			if(!compo->began)
			{
				
				std::cout<< "about to run a component awake"<<std::endl;
				compo->Awake();
				std::cout<< "finished component awake"<<std::endl;
				compo->began = true;
			}

			std::cout<< "ABOUT TO RUN component update"<<std::endl;

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