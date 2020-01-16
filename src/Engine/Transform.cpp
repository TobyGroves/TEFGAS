#include "Transform.h"

namespace TEFGAS
{

	void Transform::Awake(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale)
	{
		setPosition(_position);
		setRotation(_rotation);
		setScale(_scale);
	}


	glm::vec3 Transform::getPosition()
	{
		return position;
	}
	glm::vec3 Transform::getRotation()
	{
		return rotation;
	}
	glm::vec3 Transform::getScale()
	{
		return scale;
	}

	glm::vec3 Transform::getForward()
	{
		glm::mat4 t(1.0f);

		t = glm::rotate(t, glm::radians(rotation.x), glm::vec3(1, 0, 0));
		t = glm::rotate(t, glm::radians(rotation.y), glm::vec3(0, 1, 0));
		t = glm::rotate(t, glm::radians(rotation.z), glm::vec3(0, 0, 1));
		t = glm::translate(t, glm::vec3(0, 0, 1));

		glm::vec3 fwd = t * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

		fwd = -glm::normalize(fwd);

		return fwd;
	}

	glm::vec3 Transform::getUp()
	{
		glm::mat4 t(1.0f);

		t = glm::rotate(t, glm::radians(rotation.x), glm::vec3(1, 0, 0));
		t = glm::rotate(t, glm::radians(rotation.y), glm::vec3(0, 1, 0));
		t = glm::rotate(t, glm::radians(rotation.z), glm::vec3(0, 0, 1));
		t = glm::translate(t, glm::vec3(0, 1, 0));

		glm::vec3 up = t * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

		up = -glm::normalize(up);

		return up;
	}

	glm::vec3 Transform::getRight()
	{
		glm::mat4 t(1.0f);

		float currentrot = rotation.y;

		t = glm::rotate(t, glm::radians(rotation.x), glm::vec3(1, 0, 0));
		t = glm::rotate(t, glm::radians(rotation.y), glm::vec3(0, 1, 0));
		t = glm::rotate(t, glm::radians(rotation.z), glm::vec3(0, 0, 1));

		t = glm::translate(t, glm::vec3(1, 0, 0));

		glm::vec3 right = t * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

		right = glm::normalize(right);

		return right;
	}


	void Transform::setPosition(glm::vec3 _position)
	{
		position = _position;
	}
	void Transform::setRotation(glm::vec3 _rotation)
	{
		rotation = _rotation;
	}
	void Transform::setScale(glm::vec3 _scale)
	{
		scale = _scale;
	}
}