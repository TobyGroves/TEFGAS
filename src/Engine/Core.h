#ifndef TEFGAS_CORE_H
#define TEFGAS_CORE_H
#include <memory>
#include <list>
#include <SDL2/SDL.h>
#include <vector>


namespace TEFGAS
{
	class ShaderProgram;
	class Entity;

	class Core 
	{
	public:

		static std::shared_ptr<Core> initialize(int _windowWidth,int _windowHeight,std::string _gameName);

		void start();
		void stop();
		std::shared_ptr<Entity> addEntity();
		SDL_Window * window = nullptr;
		std::vector<std::shared_ptr<ShaderProgram>> shaders;
	private:
		bool isRunning = false;
		std::list <std::shared_ptr<Entity>> entities;
		std::weak_ptr<Core> self;
		SDL_Renderer * renderer = nullptr;
		SDL_Event event;
		int windowWidth,windowHeight;


	};

}
#endif
