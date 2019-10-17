#ifndef TEFGAS_COMPONENT_H
#define TEFGAS_COMPONENT_H

#include <memory>

namespace TEFGAS
{

	class Entity;
	class Core;

	class Component
	{
		friend class Entity;

	public:
		virtual ~Component();
		std::shared_ptr<Core> getCore();
		std::shared_ptr<Entity> getEntity();

	private:
		std::weak_ptr<Entity> entity;
		bool began;

		virtual void Awake();
		virtual void Start();
		virtual void Update();
		virtual void onDisplay();
	};

}

#endif