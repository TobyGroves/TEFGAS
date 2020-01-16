#ifndef TEFGAS_CORE_H
#define TEFGAS_CORE_H
#include <memory>
#include <list>
#include <SDL2/SDL.h>
#include <AL/al.h>
#include <AL/alc.h>

#undef main
#include <vector>
#include <string>


namespace TEFGAS
{
	class RenderTexture;
	class Texture;

	class ShaderProgram;
	class Entity;
	class Mesh;
	class Time;
	class Input;

	class Core
	{

	public:
		/// Initializes the and returns an instance of the Engine.
		/** This function must be called before doing anything with the engine as it creates and returns an instance of it. */
		static std::shared_ptr<Core> initialize(int _windowWidth, int _windowHeight, std::string _gameName);
		const Uint8* state;
		/// A List of all entities.
		/** This List contains all of the curent entities in existance. */
		std::list <std::shared_ptr<Entity>> entities;
		/// Time.
		/** This is a referance to the time class which handels all the time related stuff.*/
		std::shared_ptr<Time> time;
		/// Input
		/**This is a referance to the Input class which handels all the Input related stuff such as mouse and keyboard.*/
		std::shared_ptr<Input> input;
		/// Starts the Game Engine.
		/** This is called after intitializing and creating all of the entities and components needed to start your game. */
		void start(std::vector<std::shared_ptr<ShaderProgram>> _shaders);
		/// Stop's the Game Engine.
		/** This is called when you quit the game / program and cleans up all of the currently present entities. */
		void stop();
		/// Creates a new Entity.
		/** This Creates a new Entity and pushes it to the Entity list.*/
		std::shared_ptr<Entity> addEntity();
		SDL_Window* window = nullptr;
		/// Vector of shaders.
		/** This is a vector of all the shaders this is cycled through every loop to set the projection matrix for every shader.*/
		std::vector<std::shared_ptr<ShaderProgram>> shaders;

		std::shared_ptr<Entity> light;

	private:
		bool quit;


		bool isRunning = false;
		std::weak_ptr<Core> self;
		SDL_Renderer* renderer = nullptr;
		SDL_Event event;
		int windowWidth, windowHeight;

		ALCdevice* device;
		ALCcontext* context;

	};

}
#endif
