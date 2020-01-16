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

		/// gets the core.
		/** returns a pointer the the engine's core.*/
		std::shared_ptr<Core> getCore() const;

		/// add component.
		/** This allows the user to add any component engine defined or not to the entity.
		It automatically runs the Awake function.*/
		template <typename T, typename... A>
		std::shared_ptr<T> addComponent(A... args)
		{
			std::shared_ptr<T> component = std::make_shared<T>();

			if (component)
			{
				component->entity = self;
				component->began = false;
				components.push_back(component);
				component->Awake(args...);

				return component;
			}

		}

		/// get component.
		/** This gets the component of the type that has been specified from this entity .
		If there isnt one it will return a null pointer.*/
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
		
		/// Start.
		/** this is called by the core once before the update / game loop begins.*/
		void Start();
		/// Update.
		/** this is called by the core once every frame before rendering.*/
		void Update();
		/// Display.
		/** This calls the Display fuction on the components on this entity.*/
		void display();
		/// Destructor.
		/** This will call the Destructor on all of the components on this Entity.*/
		~Entity();
	private:
		std::weak_ptr<Entity> self;
		std::weak_ptr<Core> core;
		std::list<std::shared_ptr<Component>> components;

	};

}
#endif