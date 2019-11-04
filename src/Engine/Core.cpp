#include "Core.h"
#include "Entity.h"
#include <GL/glew.h>
#include <iostream>

namespace TEFGAS
{
	std::shared_ptr<Core> Core::initialize(int _windowWidth,int _windowHeight,std::string _gameName)
	{
		std::shared_ptr<Core> core = std::make_shared<Core>();

		core->self = core;

		SDL_CreateWindowAndRenderer(_windowWidth,_windowHeight, SDL_WINDOW_OPENGL, &core->window,&core->renderer);
		std::cout<< "created window"<<std::endl;
		SDL_SetWindowTitle(core->window,_gameName.c_str());
		std::cout<< "set title"<<std::endl;

		if(!SDL_GL_CreateContext(core->window)) // check that sdl started fine
		{
			throw std::exception();
		}

		std::cout<< "sdl ok"<<std::endl;

		if(glewInit() != GLEW_OK) // check that glew started ok
		{
			throw std::exception(); 
		}
		std::cout<< "glew ok"<<std::endl;
		return core;
	}

	void Core::start()
	{
		isRunning = true;

		while (isRunning)
		{
			std::cout<< "beginning of loop"<<std::endl;
			SDL_PollEvent(&event);
			if(event.type == SDL_QUIT){
				break;
			}

			for(auto& ent : entities)
			{
				ent->Update();
			}

			std::cout<< "post update loop"<<std::endl;
			glClearColor(0.0f,0.0f,0.5f,1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for(auto& ent : entities)
			{
				ent->display();
			}

			SDL_GL_SwapWindow(window);

			std::cout<< "end of loop"<<std::endl;
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