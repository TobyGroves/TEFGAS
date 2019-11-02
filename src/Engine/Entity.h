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

		std::shared_ptr<Core> getCore() const;

		template <typename T, typename... A>
		std::shared_ptr<T>addComponent(A...args)
		{
			std::shared_ptr<T> compo = std::make_shared<T>(args...);
			compo->entity = self;
			components.push_back(compo);

			return compo;
		}


		template<typename T>
		std::shared_ptr<T> getComponent(){
			for(auto & compo : components)
			{
				if(std::dynamic_pointer_cast<T>(compo)){
					return compo;
				}
			}
			return nullptr;
		}

		void Update();

	private:
		std::weak_ptr<Entity> self;
		std::weak_ptr<Core> core;
		std::list<std::shared_ptr<Component> > components;
		void display();

	};

}
#endif