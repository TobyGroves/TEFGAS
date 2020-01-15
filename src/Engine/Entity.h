#ifndef TEFGAS_ENTITY_H
#define TEFGAS_ENTITY_H

#include "Component.h"
#include <memory>
#include <list>

namespace TEFGAS
{

	class Core;

	class Entity
	{
	public:
		friend class Core;
		friend class Component;

		std::shared_ptr<Core> getCore() const;

		//Add Component to the game object
		template <typename T, typename... A>
		std::shared_ptr<T> addComponent(A... args)
		{
			std::shared_ptr<T> component = std::make_shared<T>();

			if (component) //Check to see if the component is actually a component
			{
				//Add component to the list if the component is of type component
				component->entity = self;
				component->began = false;
				components.push_back(component);
				component->Awake(args...);

				std::cout << "yes freind" << std::endl;

				return component;
			}

			//throw Oz::Exception("Added component isnt of type Component!"); //Throw engine exception if the added component isnt of the type component
		}


		template<class T> std::shared_ptr<T> getComponent()
		{
			for (auto& comp : components)
			{
				std::shared_ptr<T> c = std::dynamic_pointer_cast<T>(comp);
				if (c)
					return c;
			}
			return nullptr;
		}
		/*template <typename T>
		std::shared_ptr<T> getComponent()
		{
			for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
			{
				std::shared_ptr<T> component = std::dynamic_pointer_cast<T>(*it);

				if (component) //Check if of correct type
				{
					return component; //Return that type
				}
				else
				{

				}
			}
		}*/
		void Start();
		void Update();
		void display();
	private:
		std::weak_ptr<Entity> self;
		std::weak_ptr<Core> core;
		std::list<std::shared_ptr<Component>> components;

	};

}
#endif