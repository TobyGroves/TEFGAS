#include <Engine/Engine.h>
#include<glm/glm.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "rotateymcboatface.h"
#include "CameraController.h"
#include "LightMover.h"



TEFGAS::Core* newGame;
std::vector<std::shared_ptr<TEFGAS::ShaderProgram>> shaders;

int main()
{
	// initialising core
	std::shared_ptr<TEFGAS::Core> newGame = TEFGAS::Core::initialize(1800, 1000, "Becoming TEFGAS");
	
	// defining shaders
	shaders.push_back(std::shared_ptr <TEFGAS::ShaderProgram>(new TEFGAS::ShaderProgram("../shaders/simple.vert", "../shaders/simple.frag")));
	shaders.push_back(std::shared_ptr <TEFGAS::ShaderProgram>(new TEFGAS::ShaderProgram("../shaders/light.vert", "../shaders/light.frag")));
	shaders.push_back(std::shared_ptr <TEFGAS::ShaderProgram>(new TEFGAS::ShaderProgram("../shaders/lightspecdiff.vert", "../shaders/lightspecdiff.frag")));
	shaders.push_back(std::shared_ptr <TEFGAS::ShaderProgram>(new TEFGAS::ShaderProgram("../shaders/lightsdnorm.vert", "../shaders/lightsdnorm.frag")));
	shaders.push_back(std::shared_ptr <TEFGAS::ShaderProgram>(new TEFGAS::ShaderProgram("../shaders/PBR.vert", "../shaders/PBR.frag")));
	
	// creating entities 
	std::shared_ptr<TEFGAS::Entity> Sphere = newGame->addEntity();
	std::shared_ptr<TEFGAS::Entity> CamEnt = newGame->addEntity();
	newGame->light = newGame->addEntity();

	// defining transforms
	std::shared_ptr <TEFGAS::Transform> sphereTrans = Sphere->addComponent<TEFGAS::Transform>(
		glm::vec3(2.0f, 5.0f, -10.0f), glm::vec3(0, 0.0f, 0), glm::vec3(0.2f, 0.2f, 0.2f));	
	std::shared_ptr <TEFGAS::Transform> camtrans = CamEnt->addComponent<TEFGAS::Transform>(
		glm::vec3(0.0f, 6.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
	std::shared_ptr <TEFGAS::Transform> lighttrans = newGame->light->addComponent<TEFGAS::Transform>(
		glm::vec3(0.0f, 5.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));

	// creating materials
	std::shared_ptr<TEFGAS::Material> sphereMat = Sphere->addComponent<TEFGAS::Material>(new TEFGAS::Texture("../assets/PBR/shipalbedo.png"),
		new TEFGAS::Texture("../assets/PBR/shipnormal.png"), shaders.at(3));

	//adding components
	std::shared_ptr<TEFGAS::Mesh> sphereMesh = Sphere->addComponent<TEFGAS::Mesh>(sphereMat, new TEFGAS::VertexArray("../assets/PBR/sphere.obj"));
	std::shared_ptr<TEFGAS::Sound> s = Sphere->addComponent<TEFGAS::Sound>("../assets/spicegirls.ogg");
	Sphere->addComponent<RotateyMcBoat>();
	std::shared_ptr<TEFGAS::Camera> Cam = CamEnt->addComponent<TEFGAS::Camera>(shaders);
	CamEnt->addComponent<CameraController>();
	newGame->light->addComponent<LightMover>();
	
	
	
	// starting game
	newGame->start(shaders);
	
	return 0;
}