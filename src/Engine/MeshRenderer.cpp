#include "MeshRenderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"

#include <iostream>

namespace TEFGAS
{

void MeshRenderer::Awake()
{
std::cout<< "beginning of awake in mesh renderer"<<std::endl;

  std::shared_ptr<VertexBuffer> positions = std::make_shared<VertexBuffer>();
  positions->add(glm::vec3(0.0f, 0.5f, 0.0f));
  positions->add(glm::vec3(-0.5f, -0.5f, 0.0f));
  positions->add(glm::vec3(0.5f, -0.5f, 0.0f));

std::cout<< "positions added"<<std::endl;
  std::shared_ptr<VertexBuffer> colors = std::make_shared<VertexBuffer>();
  colors->add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
  colors->add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
  colors->add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

std::cout<< "colors added"<<std::endl;

  shape = std::make_shared<VertexArray>();

std::cout<< "made shared"<<std::endl;
  shape->setBuffer("in_Position", positions);

std::cout<< "pos buffer set"<<std::endl;
  shape->setBuffer("in_Color", colors);

std::cout<< "color buffer set"<<std::endl;

  shader = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
  std::cout<< "shader prog shared"<<std::endl;
}

void MeshRenderer::onDisplay()
{
  shader->setUniform("in_Model", glm::mat4(1.0f));
  shader->setUniform("in_Projection", glm::mat4(1.0f));
  shader->draw(*shape);
}

}