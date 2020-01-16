#ifndef TEFGAS_MOUSE_H
#define  TEFGAS_MOUSE_H


#include <SDL2/SDL.h>
#include <vector>
#include <glm/glm.hpp>
namespace TEFGAS
{
	class Mouse 
	{
	public:
		
		glm::vec2 getMouseMove();
		void manageMouseInput(SDL_Event* _event);

	private:
		
		float mouseX, mouseY;

	};

}
#endif