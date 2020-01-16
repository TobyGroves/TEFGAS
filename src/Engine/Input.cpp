#include "Input.h"
#include <iostream>

namespace TEFGAS
{
	bool Input::isKey(int _key)
	{
		for (auto& k : keys)
			if (k == _key)
				return true;

		return false;
	}

	bool Input::isKeyPressed(int _key)
	{
		for (auto& k : pressedKeys)
			if (k == _key)
				return true;

		return false;
	}

	bool Input::isKeyReleased(int _key)
	{
		for (auto& k : releasedKeys)
			if (k == _key)
				return true;

		return false;
	}

	void Input::manageInput(SDL_Event * _event)
	{
		pressedKeys.clear();
		releasedKeys.clear();
		mouseX = 0;
		mouseY = 0;

		while (SDL_PollEvent(_event))
		{

			switch (_event->type)
			{
			case SDL_MOUSEMOTION:
			{
				mouseX = _event->motion.xrel;
				mouseY = _event->motion.yrel;

				std::cout << mouseX << " " << mouseY << std::endl;

				break;
			}
			case SDL_KEYDOWN:
			{
				pressedKeys.push_back(_event->key.keysym.sym);
				if (std::find(keys.begin(), keys.end(), _event->key.keysym.sym) != keys.end())
				{
					//Do nothing
				}
				else
					keys.push_back(_event->key.keysym.sym);

				break;
			}
			case SDL_KEYUP:
			{
				releasedKeys.push_back(_event->key.keysym.sym);
				for (int i = 0; i < keys.size(); i++)
				{
					if (keys.at(i) == _event->key.keysym.sym)
						keys.erase(keys.begin() + i);
				}
				break;
			}
			case SDL_QUIT:
			{
				break;
			}
			default:;
			}
		}
	}

	glm::vec2 Input::getMouseMove()
	{
		return glm::vec2(mouseX, mouseY);
	}
}