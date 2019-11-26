#include "Core.h"
#include "Entity.h"
#include <GL/glew.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "ShaderProgram.h"

namespace TEFGAS
{
	std::shared_ptr<Core> Core::initialize(int _windowWidth,int _windowHeight,std::string _gameName)
	{
		std::shared_ptr<Core> core = std::make_shared<Core>();

		core->self = core;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::exception();
		}

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
			SDL_PollEvent(&event);
			if(event.type == SDL_QUIT){
				break;
			}

			SDL_GetWindowSize(window, &windowWidth, &windowHeight);
			glEnable(GL_CULL_FACE);
			glEnable(GL_DEPTH_TEST);
			glClearColor(135.0f, 206.0f, 235.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (int i = 0; i < shaders.size(); i++)///////////////////////////////////////////////////////////////
			{
				shaders.at(i)->setUniform("in_Projection", glm::perspective(glm::radians(45.0f),
					(float)windowWidth / (float)windowHeight, 0.1f, 1000.f));
			}//////////////////////////////////////////////////////////////////////////////////////////////////////

			for(auto& ent : entities)
			{
				ent->Update();
			}

			for(auto& ent : entities)
			{
				ent->display();
			}

			SDL_GL_SwapWindow(window);
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