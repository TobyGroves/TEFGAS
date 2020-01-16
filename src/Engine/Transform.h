#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "Component.h"

namespace TEFGAS
{
	/// The transform class defines the position rotation and scale.
	/** This defines the position rotation and scale as three vec3's and allows the user to get and set them.*/
	class Transform : public Component
	{
	public:
		/// Awake.
		/** This initialises the Transform class and requires position rotation and a scale.
		(the scale should be larger than 0 if you want to be able to see the object.)*/
		void Awake(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale);

		/// Get Position.
		/** This returns the Position as a vec3.*/
		glm::vec3 getPosition();
		/// Get Rotation.
		/** This returns the Rotation as a vec3.*/
		glm::vec3 getRotation();
		/// Get Scale.
		/** This returns the Scale as a vec3.*/
		glm::vec3 getScale();

		/// Get Forward.
		/** This returns the forward vector.*/
		glm::vec3 getForward();

		/// Get Up.
		/** This returns the up vector.*/
		glm::vec3 getUp();
		/// Get Right.
		/** This returns the right vector.*/
		glm::vec3 getRight();

		/// Set Position.
		/** This sets the Position takeing a vec3.*/
		void setPosition(glm::vec3 _position);
		/// Set Rotation.
		/** This sets the Rotation takeing a vec3.*/
		void setRotation(glm::vec3 _rotation);
		/// Set Scale.
		/** This sets the Scale takeing a vec3.*/
		void setScale(glm::vec3 _scale);

	private:
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

	};
}