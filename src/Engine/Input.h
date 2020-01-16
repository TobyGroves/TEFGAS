#ifndef TEFGAS_KEYBOARD_H
#define  TEFGAS_KEYBOARD_H

#include <SDL2/SDL.h>
#include <vector>
#include "glm/glm.hpp"
namespace TEFGAS
{
	class Input
	{
	public:
		/// Is Key Down.
		/** this returns true constantly while the key is pressed down.*/
		bool isKey(int _key);
		/// Is Key Pressed.
		/** This returns True once when the key is pressed down.*/
		bool isKeyPressed(int _key);
		/// Is Key Released.
		/** This returns True once when the key has been released.*/
		bool isKeyReleased(int _key);
		/// get mouse move.
		/** This returns the mouse movement that has happened since the last frame as a vec2.*/
		glm::vec2 getMouseMove();

		/// Manage Input.
		/** This must be run each frame to check weather anything has been pressed and if the mouse has been moved.*/
		void manageInput(SDL_Event* _event);

	private:
		std::vector<int> keys, pressedKeys, releasedKeys;
		/// Mouse movement.
		/** This is the x and y movement of the mouse.*/
		float mouseX, mouseY;
	};
}

#endif