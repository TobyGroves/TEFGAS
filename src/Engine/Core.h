#ifndef TEFGAS_CORE_H
#define TEFGAS_CORE_H
#include <memory>
#include <list>
#include <SDL2/SDL.h>


namespace TEFGAS
{

	class Entity;

	class Core 
	{
	public:

		static std::shared_ptr<Core> initialize(int _windowWidth,int _windowHeight,std::string _gameName);

		void start();
		void stop();
		std::shared_ptr<Entity> addEntity();
		SDL_Window * window = nullptr;
		
	private:
		bool isRunning = false;
		std::list <std::shared_ptr<Entity>> entities;
		std::weak_ptr<Core> self;
		SDL_Renderer * renderer = nullptr;
		SDL_Event event;

	};

}
#endif
