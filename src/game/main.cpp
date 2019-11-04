#include <Engine/Engine.h>

#include <iostream>
#include <string>



int main()
{

  //Intt

  std::shared_ptr<TEFGAS::Core> core = TEFGAS::Core::initialize(640,480,"Triangle!!!!!!!!!");

  std::shared_ptr<TEFGAS::Entity> entity = core->addEntity();

  std::shared_ptr<TEFGAS::ShaderProgram> shader = std::make_shared<TEFGAS::ShaderProgram>("../resources/shaders/modelLoading.vert","../resources/shaders/modelLoading.frag");

  std::shared_ptr<TEFGAS::Model> c = entity->addComponent<TEFGAS::Model>("../resources/models/nanosuit/nanosuit.obj",shader);

  //std::shared_ptr<TEFGAS::MeshRenderer> mr = entity->addComponent<TEFGAS::MeshRenderer>();

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