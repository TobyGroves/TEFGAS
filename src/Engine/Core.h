#ifndef TEFGAS_CORE_H
#define TEFGAS_CORE_H
#include <memory>
#include <list>
#include <SDL2/SDL.h>
#undef main
#include <vector>
#include <string>
#include "Time.h"


namespace TEFGAS
{
	class RenderTexture;
	class Texture;

	class ShaderProgram;
	class Entity;
	class Mesh;

	class Core
	{

	public:

		static std::shared_ptr<Core> initialize(int _windowWidth, int _windowHeight, std::string _gameName);
		const Uint8* state;
		std::vector<Mesh*> Meshes;

		std::list <std::shared_ptr<Entity>> entities;
		std::shared_ptr<Time> time;


		void start(std::vector<std::shared_ptr<ShaderProgram>> _shaders);
		void stop();
		std::shared_ptr<Entity> addEntity();
		SDL_Window* window = nullptr;
		std::vector<std::shared_ptr<ShaderProgram>> shaders;

		std::shared_ptr<Entity> light;

	private:
		bool quit;


		bool isRunning = false;
		std::weak_ptr<Core> self;
		SDL_Renderer* renderer = nullptr;
		SDL_Event event;
		int windowWidth, windowHeight;

	};

}
#endif
