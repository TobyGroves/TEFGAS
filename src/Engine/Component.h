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
		friend class Core;
	public:
		/// Destructor
		/**Runs before destroying the game object use this to clean up after yourself*/
		virtual ~Component();
		/// Get Core.
		/** Returns a pointer to the Core of the engine.*/
		std::shared_ptr<Core> getCore() const;
		/// Get Entity.
		/** Returns a referance to the Entity that this script is on.*/
		std::shared_ptr<Entity> getEntity() const;

	private:
		std::weak_ptr<Entity> entity;
		bool began;
		/// Awake.
		/** this is called once when the component is created.*/
		virtual void Awake();
		/// Start.
		/** this is called by the entity once before the update / game loop begins.*/
		virtual void Start();
		/// Update.
		/** this is called by the entity once every frame before rendering.*/
		virtual void Update();
		/// on Display.
		/** this is called once per frame as it is for drawing the component.*/
		virtual void onDisplay();
	};

}

#endif