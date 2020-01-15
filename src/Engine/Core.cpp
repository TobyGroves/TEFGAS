#include "Core.h"
#include "Entity.h"
#include "Time.h"
#include <GL/glew.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "ShaderProgram.h"

namespace TEFGAS
{
	std::shared_ptr<Core> Core::initialize(int _windowWidth, int _windowHeight, std::string _gameName)
	{
		std::shared_ptr<Core> core = std::make_shared<Core>();

		core->self = core;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::exception();
		}

		SDL_CreateWindowAndRenderer(_windowWidth, _windowHeight, SDL_WINDOW_OPENGL, &core->window, &core->renderer);
		std::cout << "created window" << std::endl;
		SDL_SetWindowTitle(core->window, _gameName.c_str());
		std::cout << "set title" << std::endl;

		if (!SDL_GL_CreateContext(core->window)) // check that sdl started fine
		{
			throw std::exception();
		}

		std::cout << "sdl ok" << std::endl;

		if (glewInit() != GLEW_OK) // check that glew started ok
		{
			throw std::exception();
		}
		std::cout << "glew ok" << std::endl;


		ALCdevice* device = alcOpenDevice(NULL);

		if (device == NULL)
		{
			throw std::exception();
		}

		// Create audio context
		ALCcontext* context = alcCreateContext(device, NULL);

		if (context == NULL)
		{
			alcCloseDevice(device);
			throw std::exception();
		}

		// Set as current context
		if (!alcMakeContextCurrent(context))
		{
			alcDestroyContext(context);
			alcCloseDevice(device);
			throw std::exception();
		}
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);

		core->quit = false;
		return core;
	}

	void Core::start(std::vector<std::shared_ptr<ShaderProgram>> _shaders)
	{

		//shaderSetup();
		shaders = _shaders;

		//create camera
		//mainCamera = new Camera(shaders, new Transform(glm::vec3(25.0f, 6.0f, -3.7f), glm::vec3(0, 90, 0), glm::vec3(1, 1, 1)));


		time = std::shared_ptr<Time>(new Time());

		//create time
		time->gameStart();

		for (auto& ent : entities)
		{
			ent->Start();
		}


		// Start the Game Loop
		while (!quit)
		{
			SDL_Event event = { 0 };

			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					quit = true;
				}
			}
			// ultimatly menu thing but atm just quits
			state = SDL_GetKeyboardState(NULL);
			if (state[SDL_SCANCODE_ESCAPE])
			{
				quit = true;
			}


			SDL_GetWindowSize(window, &windowWidth, &windowHeight);
			SDL_ShowCursor(SDL_DISABLE);
			SDL_SetRelativeMouseMode(SDL_TRUE);
			glEnable(GL_CULL_FACE);
			glEnable(GL_DEPTH_TEST);
			glViewport(0, 0, windowWidth, windowHeight);
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			/*
			* Draw with perspective projection matrix
			*/
			for (int i = 0; i < shaders.size(); i++)
			{
				shaders.at(i)->setUniform("in_Projection", glm::perspective(glm::radians(45.0f),
					(float)windowWidth / (float)windowHeight, 0.1f, 1000.f));
			}

			//entity update loop and draw//

			for (auto& ent : entities)
			{
				ent->Update();
			}

			for (auto& ent : entities)
			{
				ent->display();
			}


			SDL_GL_SwapWindow(window);

			time->timeUpdate();

		}

		for (auto& ent : entities)
		{
			ent->~Entity();
		}

		alcMakeContextCurrent(NULL);
		alcDestroyContext(context);
		alcCloseDevice(device);

		SDL_DestroyWindow(window);
		SDL_Quit();
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