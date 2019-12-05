#include <Engine/Engine.h>
#include<glm/glm.hpp>
#include <iostream>
#include <string>
#include <vector>



int main()
{

  //Intt

  std::shared_ptr<TEFGAS::Core> core = TEFGAS::Core::initialize(640,480,"Journey");

  std::shared_ptr<TEFGAS::Entity> Object = core->addEntity();

  std::shared_ptr<TEFGAS::Entity> player = core->addEntity();


  std::vector<std::shared_ptr<TEFGAS::ShaderProgram>> shaders;

  core->shaders.push_back(std::make_shared<TEFGAS::ShaderProgram>("../resources/shaders/simple.vert","../resources/shaders/simple.frag"));

  std::shared_ptr<TEFGAS::Transform> playerTrans = player->addComponent<TEFGAS::Transform>();
  playerTrans->setPosition(glm::vec3(0.0f,0.0f,0.0f));
  //must be vector of shaders


  std::shared_ptr<TEFGAS::Camera> cam = player->addComponent<TEFGAS::Camera>(shaders,playerTrans);
  Object->addComponent<TEFGAS::Transform>();
  std::shared_ptr<TEFGAS::Texture> albedo = std::make_shared<TEFGAS::Texture>("../resources/models/Graveyard/graveyard.png");
  std::shared_ptr<TEFGAS::Texture> normal = std::make_shared<TEFGAS::Texture>("../resources/models/Graveyard/graveyard.png");
  std::shared_ptr<TEFGAS::VertexArray> vertArray = std::make_shared<TEFGAS::VertexArray>("../resources/models/Graveyard/graveyard.obj");
  std::shared_ptr<TEFGAS::Transform> trans =  std::make_shared<TEFGAS::Transform>(glm::vec3(0,-10,0),glm::vec3(0,0,0),glm::vec3(100,100,100));
  std::shared_ptr<TEFGAS::Mesh> mesh = Object->addComponent<TEFGAS::Mesh>(albedo,normal,vertArray,trans,0.5f,core->shaders.at(0));

try{

  core->start();

}
catch(TEFGAS::Exception& e)
{
  std::cout<<"TEFGAS Exception: "<< e.what()<<std::endl;
}
catch(std::exception& e)
{
  std::cout<<"Exception: "<< e.what() << std::endl;
}
catch (...)
{
  std::cout<<"An unknown object was thrown" << std::endl;
}

std::cout<<"finished"<<std::endl;



  return 0;
}