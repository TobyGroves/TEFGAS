#ifndef TEFGAS_CAMERA_H
#define TEFGAS_CAMERA_H
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/ext.hpp>
#include <vector>
#include <exception>
#include <memory>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp> 

#include "Component.h"
namespace TEFGAS
{
	class ShaderProgram;
	class Transform;

	class Camera : public Component
	{
	public:
		void Awake(std::vector<std::shared_ptr<ShaderProgram>> _shaders);

		void Update();

		std::shared_ptr <Transform> transform;

		std::vector<std::shared_ptr<ShaderProgram>> shaders;


	};
}
#endif