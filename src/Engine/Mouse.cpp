#include "Mouse.h"
#include <iostream>
namespace TEFGAS
{
	void Mouse::manageMouseInput(SDL_Event* _event)
	{
		mouseX = 0;
		mouseY = 0;

		while (SDL_PollEvent(_event))
		{
			if (_event->type == SDL_MOUSEBUTTONDOWN)
			{
				if (_event->button.button == SDL_BUTTON_LEFT)
				{
					//mouse clicked
				}
				if (_event->button.button == SDL_BUTTON_RIGHT)
				{
					//mouse clicked
				}
			}
			if (_event->type == SDL_MOUSEMOTION)
			{
				mouseX = _event->motion.x;
				mouseY = _event->motion.y;

				std::cout << mouseX << " " << mouseY << std::endl;

			}
			
		}
	}

	glm::vec2 Mouse::getMouseMove()
	{
		return glm::vec2(mouseX, mouseY);
	}
}