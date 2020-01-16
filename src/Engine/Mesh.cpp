#include "Mesh.h"
#include "Transform.h"
#include "Texture.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"
#include "Material.h"
#include "Entity.h"
#include "Core.h"
#include <memory>
#include <iostream>
namespace TEFGAS
{
	void Mesh::Awake(std::shared_ptr <Material> _material, VertexArray* _mesh)
	{
		material = getEntity()->getComponent<Material>();
		mesh = _mesh;
		transform = getEntity()->getComponent<Transform>();
		std::cout << "yes we here" << std::endl;

	}

	void Mesh::onDisplay()
	{


		glm::mat4 model(1.0f);


		model = glm::translate(model, transform->getPosition());
		model = glm::rotate(model, glm::radians(transform->getRotation().x), glm::vec3(1, 0, 0));
		model = glm::rotate(model, glm::radians(transform->getRotation().y), glm::vec3(0, 1, 0));
		model = glm::rotate(model, glm::radians(transform->getRotation().z), glm::vec3(0, 0, 1));
		model = glm::scale(model, transform->getScale());

		//material->shader->setUniform("in_Model", model);////////////
		material->shader->setUniform("in_Texture", material->albedo);//
		material->shader->setUniform("in_NormalMap", material->normal);//
		material->shader->setUniform("in_Ambient", glm::vec3(0.7, 0.7, 0.7));//
		material->shader->setUniform("in_LightPos", getCore()->light->getComponent<Transform>()->getPosition());//
		material->shader->setUniform("in_LightColor", glm::vec3(0.6, 0.6, 0.6));//
		material->shader->setUniform("in_shine", 0.5f);
		material->shader->setUniform("in_Model", model);////////////
		material->shader->setUniform("in_albedo", material->albedo);
		material->shader->setUniform("in_normalMap", material->normal);
		material->shader->setUniform("in_metallic", material->metallic);
		material->shader->setUniform("in_roughness", material->roughness);
		material->shader->setUniform("in_ao", material->ao);

		glm::vec3 lightPositions[] = {
		   glm::vec3(0.0f, 5.0f, -10.0f),
		   glm::vec3(0.0f, 0.0f, -10.0f)
		};
		glm::vec3 lightColors[] = {
			glm::vec3(150.0f, 150.0f, 150.0f),
			glm::vec3(150.0f, 150.0f, 150.0f)
		};
		for (unsigned int i = 0; i < 2; ++i)
		{
			material->shader->setUniform("lightPositions[" + std::to_string(i) + "]", lightPositions[i]);
			material->shader->setUniform("lightColors[" + std::to_string(i) + "]", lightColors[i]);
		}



		material->shader->draw(mesh);
		//shader->draw(mesh);
	}
}