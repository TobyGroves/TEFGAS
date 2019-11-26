#include "ShaderProgram.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "Texture.h"
#include "RenderTexture.h"

#include <glm/ext.hpp>

#include <fstream>
#include <iostream>
#include <memory>

namespace TEFGAS{

ShaderProgram::ShaderProgram(std::string vert, std::string frag)
{
  std::cout<<"point a1"<<std::endl;
  std::ifstream file(vert.c_str());
  std::string vertSrc;

  if(!file.is_open())
  {
    throw std::exception();
  }

  while(!file.eof())
  {
    std::string line;
    std::getline(file, line);
    vertSrc += line + "\n";
  }

  file.close();
  file.open(frag.c_str());
  std::string fragSrc;

  if(!file.is_open())
  {
    throw std::exception();
  }

  while(!file.eof())
  {
    std::string line;
    std::getline(file, line);
    fragSrc += line + "\n";
  }

  const GLchar *vs = vertSrc.c_str();
  GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShaderId, 1, &vs, NULL);
  glCompileShader(vertexShaderId);
  GLint success = 0;
  glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);

  std::cout<<"point a2"<<std::endl;
  if(!success)
  {
	printShaderInfoLog(vertexShaderId);
    throw std::exception();
  }

  const GLchar *fs = fragSrc.c_str();
  GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShaderId, 1, &fs, NULL);
  glCompileShader(fragmentShaderId);
  glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);

  if(!success)
  {
	printShaderInfoLog(fragmentShaderId);
    throw std::exception();
  }

  std::cout<<"point a3"<<std::endl;
  id = glCreateProgram();
  glAttachShader(id, vertexShaderId);
  glAttachShader(id, fragmentShaderId);
  glBindAttribLocation(id, 0, "in_Position");
  glBindAttribLocation(id, 1, "in_Color");
  glBindAttribLocation(id, 2, "in_TexCoord");
  glBindAttribLocation(id, 3, "in_Normal");

  if(glGetError() != GL_NO_ERROR)
  {
    throw std::exception();
  }

  glLinkProgram(id);
  glGetProgramiv(id, GL_LINK_STATUS, &success);

  std::cout<<"point a4"<<std::endl;
  if(!success)
  {
	printProgramInfoLog(id);
    throw std::exception();
  }

  glDetachShader(id, vertexShaderId);
  glDeleteShader(vertexShaderId);
  glDetachShader(id, fragmentShaderId);
  glDeleteShader(fragmentShaderId);

  std::cout<<"point a5"<<std::endl;
  VertexBuffer *positions = new VertexBuffer();
  positions->add(glm::vec2(-1.0f, 1.0f));
  positions->add(glm::vec2(-1.0f, -1.0f));
  positions->add(glm::vec2(1.0f, -1.0f));
  positions->add(glm::vec2(1.0f, -1.0f));
  positions->add(glm::vec2(1.0f, 1.0f));
  positions->add(glm::vec2(-1.0f, 1.0f));

  VertexBuffer *texCoords = new VertexBuffer();
  texCoords->add(glm::vec2(0.0f, 0.0f));
  texCoords->add(glm::vec2(0.0f, -1.0f));
  texCoords->add(glm::vec2(1.0f, -1.0f));
  texCoords->add(glm::vec2(1.0f, -1.0f));
  texCoords->add(glm::vec2(1.0f, 0.0f));
  texCoords->add(glm::vec2(0.0f, 0.0f));

  simpleShape = std::make_shared<VertexArray>();
  simpleShape->setBuffer("in_Position", positions);
  simpleShape->setBuffer("in_TexCoord", texCoords);

  std::cout<<"point a6"<<std::endl;
}

void ShaderProgram::draw(std::shared_ptr<VertexArray>vertexArray)
{
  glUseProgram(id);

  glBindVertexArray(vertexArray->getId());


  for(size_t i = 0; i < samplers.size(); i++)
  {
    glActiveTexture(GL_TEXTURE0 + i);

    if(samplers.at(i).texture)
    {
      glBindTexture(GL_TEXTURE_2D, samplers.at(i).texture->getId());
    }
    else
    {
      glBindTexture(GL_TEXTURE_2D, 0);
    }
  }

  glDrawArrays(GL_TRIANGLES, 0, vertexArray->getVertexCount());

  printShaderInfoLog(id);
  printProgramInfoLog(id);


  for(size_t i = 0; i < samplers.size(); i++)
  {

    glActiveTexture(GL_TEXTURE0 + i);
    glBindTexture(GL_TEXTURE_2D, 0);
  }

  glBindVertexArray(0);
  glUseProgram(0);
}

/*void ShaderProgram::draw(RenderTexture *renderTexture, VertexArray *vertexArray)
{
	glBindFramebuffer(GL_FRAMEBUFFER, renderTexture->getFbId());
	glm::vec4 lastViewport = viewport;
	viewport = glm::vec4(0, 0, renderTexture->getSize().x, renderTexture->getSize().y);
	draw(vertexArray);
	viewport = lastViewport;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void ShaderProgram::draw(std::shared_ptr<RenderTexture>renderTexture, VertexArray *vertexArray)
{
	glBindFramebuffer(GL_FRAMEBUFFER, renderTexture->getFbId());
	glm::vec4 lastViewport = viewport;
	viewport = glm::vec4(0, 0, renderTexture->getSize().x, renderTexture->getSize().y);
	draw(vertexArray);
	viewport = lastViewport;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void ShaderProgram::draw(RenderTexture *renderTexture)
{
	draw(renderTexture, simpleShape);
}

void ShaderProgram::draw(std::shared_ptr<RenderTexture> renderTexture)
{
	draw(renderTexture.get(), simpleShape);
}*/

void ShaderProgram::draw()
{
	draw(simpleShape);
}

void ShaderProgram::setUniform(std::string uniform, glm::vec3 value)
{
	GLint uniformId = glGetUniformLocation(id, uniform.c_str());

	if (uniformId == -1)
	{
		return;
	}

	glUseProgram(id);
	glUniform3f(uniformId, value.x, value.y, value.z);
	glUseProgram(0);
}

void ShaderProgram::setUniform(std::string uniform, glm::vec4 value)
{
  GLint uniformId = glGetUniformLocation(id, uniform.c_str());

  if(uniformId == -1)
  {
	  return;
  }

  glUseProgram(id);
  glUniform4f(uniformId, value.x, value.y, value.z, value.w);
  glUseProgram(0);
}

void ShaderProgram::setUniform(std::string uniform, float value)
{
  GLint uniformId = glGetUniformLocation(id, uniform.c_str());

  if(uniformId == -1)
  {
	  return;
  }

  glUseProgram(id);
  glUniform1f(uniformId, value);
  glUseProgram(0);
}

void ShaderProgram::setUniform(std::string uniform, glm::mat4 value)
{
  GLint uniformId = glGetUniformLocation(id, uniform.c_str());

  if(uniformId == -1)
  {
	  return;
  }

  glUseProgram(id);
  glUniformMatrix4fv(uniformId, 1, GL_FALSE, glm::value_ptr(value));
  glUseProgram(0);
}

void ShaderProgram::setUniform(std::string uniform, Texture *texture)
{
  GLint uniformId = glGetUniformLocation(id, uniform.c_str());

  if(uniformId == -1)
  {
	  return;
  }

  for(size_t i = 0; i < samplers.size(); i++)
  {
    if(samplers.at(i).id == uniformId)
    {
      samplers.at(i).texture = texture;

      glUseProgram(id);
      glUniform1i(uniformId, i);
      glUseProgram(0);
      return;
    }
  }

  Sampler s;
  s.id = uniformId;
  s.texture = texture;
  samplers.push_back(s);

  glUseProgram(id);
  glUniform1i(uniformId, samplers.size() - 1);
  glUseProgram(0);
}

void ShaderProgram::setUniform(std::string uniform,std::shared_ptr<Texture> texture)
{
	GLint uniformId = glGetUniformLocation(id, uniform.c_str());

	if (uniformId == -1)
	{
		return;
	}

	for (size_t i = 0; i < samplers.size(); i++)
	{
		if (samplers.at(i).id == uniformId)
		{
			samplers.at(i).texture = texture.get();

			glUseProgram(id);
			glUniform1i(uniformId, i);
			glUseProgram(0);
			return;
		}
	}

	Sampler s;
	s.id = uniformId;
	s.texture = texture.get();
	samplers.push_back(s);

	glUseProgram(id);
	glUniform1i(uniformId, samplers.size() - 1);
	glUseProgram(0);
}


// making issues 

/*void ShaderProgram::setUniform(std::string uniform, glm::vec3[] _lights)
{
	GLint uniformId = glGetUniformLocation(id, uniform.c_str());
	if (uniformId == -1)
	{
		return;
	}
	for (size_t i = 0; i < samplers.size(); i++)
	{
		if (samplers.at(i).id == uniformId)
		{
			samplers.at(i).texture = texture.get();
			glUseProgram(id);
			glUniform1i(uniformId, i);
			glUseProgram(0);
			return;
		}
	}
	Sampler s;
	s.id = uniformId;
	s.texture = texture.get();
	samplers.push_back(s);
	glUseProgram(id);
	glUniform1i(uniformId, samplers.size() - 1);
	glUseProgram(0);
}*/






GLuint ShaderProgram::getId()
{
  return id;
}

void ShaderProgram::printShaderInfoLog(GLuint obj)
{
	int infologLength = 0;
	int charsWritten = 0;
	char *infoLog;

	glGetShaderiv(obj, GL_INFO_LOG_LENGTH, &infologLength);

	if (infologLength > 0)
	{
		infoLog = (char *)malloc(infologLength);
		glGetShaderInfoLog(obj, infologLength, &charsWritten, infoLog);
		printf("%s\n", infoLog);
		free(infoLog);
	}
}

void ShaderProgram::printProgramInfoLog(GLuint obj)
{
	int infologLength = 0;
	int charsWritten = 0;
	char *infoLog;

	glGetProgramiv(obj, GL_INFO_LOG_LENGTH, &infologLength);

	if (infologLength > 0)
	{
		infoLog = (char *)malloc(infologLength);
		glGetProgramInfoLog(obj, infologLength, &charsWritten, infoLog);
		printf("%s\n", infoLog);
		free(infoLog);
	}
}

void ShaderProgram::setViewport(glm::vec4 viewport)
{
	this->viewport = viewport;
}
}