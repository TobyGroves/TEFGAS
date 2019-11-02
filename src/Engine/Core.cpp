#include "Core.h"
#include "Entity.h"
#include <GL/glew.h>

namespace TEFGAS
{
	std::shared_ptr<Core> Core::initialize(int _windowWidth,int _windowHeight,std::string _gameName)
	{
		std::shared_ptr<Core> core = std::make_shared<Core>();

		core->self = core;

		SDL_CreateWindowAndRenderer(_windowWidth,_windowHeight, SDL_WINDOW_OPENGL, &core->window,&core->renderer);
		SDL_SetWindowTitle(core->window,_gameName.c_str());

		if(!SDL_GL_CreateContext(core->window)) // check that sdl started fine
		{
			throw std::exception();
		}

		if(glewInit() != GLEW_OK) // check that glew started ok
		{
			throw std::exception(); 
		}
		return core;
	}

	void Core::start()
	{
		isRunning = true;

		while (isRunning)
		{

			SDL_PollEvent(&event);
			if(event.type == SDL_QUIT){
				break;
			}

			for(auto& ent : entities)
			{
				ent->Update();
			}
			for(auto& ent : entities)
			{
				ent->display();
			}
		}
	}

	void Core::stop()
	{
		isRunning = false;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> ent = std::make_shared<Entity>();
		ent->self = ent;
		ent->core = self;
		entities.push_back(ent);

		return ent;
	}

}