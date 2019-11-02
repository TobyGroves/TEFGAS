#include <Engine/Engine.h>

#include <iostream>
#include <string>


int main()
{

  //Intt

  std::shared_ptr<TEFGAS::Core> core = TEFGAS::Core::initialize(640,480,"Triangle!!!!!!!!!");

  std::shared_ptr<TEFGAS::Entity> entity = core->addEntity();

  std::shared_ptr<TEFGAS::RenderComponent> entityRenderer = entity->addComponent<TEFGAS::RenderComponent>();

  entityRenderer->onDisplay();

  core->start();

  std::cout<<"finished"<<std::endl;


  // LOOK AT LAB 7

  return 0;
}