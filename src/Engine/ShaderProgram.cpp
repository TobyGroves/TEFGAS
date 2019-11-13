#include "ShaderProgram.h"
#include "VertexArray.h"
#include "Texture.h"

#include <glm/ext.hpp>

#include <fstream>
#include <iostream>

namespace TEFGAS
{

  void ShaderProgram::use()
  {
    glUseProgram(id);
  }

ShaderProgram::ShaderProgram(const char* vertexPath, const char* fragmentPath, const char* geometryPath)
{

  // 1. retrieve the vertex/fragment source code from filePath
        std::string vertexCode;
        std::string fragmentCode;
        std::string geometryCode;
        try 
        {
          std::ifstream vertFile(vertexPath);
          if(!vertFile.is_open())
          {
            throw std::exception();
          }
          std::ifstream fragFile(fragmentPath);
          if(!fragFile.is_open())
          {
            throw std::exception();
          }
          while(!vertFile.eof())
          {
            std::string vertLine;
            std::getline(vertFile, vertLine);
            vertexCode += vertLine + "\n";
          }
          while(!fragFile.eof())
          {
            std::string fragLine;
            std::getline(fragFile, fragLine);
            fragmentCode += fragLine + "\n";
          }
          vertFile.close();
          fragFile.close();
            // if geometry shader path is present, also load a geometry shader
            if(geometryPath != nullptr)
            {
              std::ifstream geometryFile(geometryPath);
              if(!geometryFile.is_open())
              {
                throw std::exception();
              }
              while(!geometryFile.eof())
              {
                std::string geometryLine;
                std::getline(geometryFile, geometryLine);
                geometryCode += geometryLine + "\n";
              }
                geometryFile.close();
            }
        }
        catch (std::ifstream::failure e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }
        const char* vShaderCode = vertexCode.c_str();
        const char * fShaderCode = fragmentCode.c_str();
        // 2. compile shaders
        unsigned int vertex, fragment;
        // vertex shader
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        //checkCompileErrors(vertex, "VERTEX");
        // fragment Shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
        //checkCompileErrors(fragment, "FRAGMENT");
        // if geometry shader is given, compile geometry shader
        unsigned int geometry;
        if(geometryPath != nullptr)
        {
            const char * gShaderCode = geometryCode.c_str();
            geometry = glCreateShader(GL_GEOMETRY_SHADER);
            glShaderSource(geometry, 1, &gShaderCode, NULL);
            glCompileShader(geometry);
            //checkCompileErrors(geometry, "GEOMETRY");
        }
        // shader Program
        id = glCreateProgram();
        glAttachShader(id, vertex);
        glAttachShader(id, fragment);
        if(geometryPath != nullptr)
            glAttachShader(id, geometry);
        glLinkProgram(id);
        //checkCompileErrors(ID, "PROGRAM");
        // delete the shaders as they're linked into our program now and no longer necessery
        glDeleteShader(vertex);
        glDeleteShader(fragment);
        if(geometryPath != nullptr)
            glDeleteShader(geometry);
}

void ShaderProgram::draw(VertexArray& vertexArray)
{
  glUseProgram(id);
  glBindVertexArray(vertexArray.getId());
  
  for (size_t i = 0;i<samplers.size();i++)
  {
    glActiveTexture(GL_TEXTURE0 +i);

    if(samplers.at(i).texture)
    {
      glBindTexture(GL_TEXTURE_2D,samplers.at(i).texture->getId());
    }
    else
    {
      glBindTexture(GL_TEXTURE_2D,0);
    }
  }
  
  glDrawArrays(GL_TRIANGLES, 0, vertexArray.getVertexCount());

  for(size_t i = 0; i<samplers.size(); i++)
  {
    glActiveTexture(GL_TEXTURE0 +i);
    glBindTexture(GL_TEXTURE_2D,0);
  }

  glBindVertexArray(0);
  glUseProgram(0);

}

void ShaderProgram::setUniform(std::string uniform, glm::vec4 value)
{
  GLint uniformId = glGetUniformLocation(id, uniform.c_str());

  if(uniformId == -1)
  {
  std::cout<<"failed vec4 uniform : "<<uniform<<std::endl;
    throw std::exception();
  }

  glUseProgram(id);
  glUniform4f(uniformId, value.x, value.y, value.z, value.w);
  glUseProgram(0);
}

void ShaderProgram::setFloat(const std::string &name,float value)
{
  glUniform1f(glGetUniformLocation(id,name.c_str()),value);
}

void ShaderProgram::setUniform(std::string uniform, float value)
{
  std::cout<<"here with uniform : "<<uniform<<std::endl;
  
  //**************************************************************** this is the problem  VVVVVVV

  GLint uniformId = glGetUniformLocation(id, uniform.c_str());
  
 //**********************************************************dont know the issue but its this line ^^^^^^
  std::cout<<"here 2"<<std::endl;
  if(uniformId == -1)
  {

  std::cout<<"failed float uniform: "<<uniform<<std::endl;
    throw std::exception();
  }
  std::cout<<"here3 "<<std::endl;
  glUseProgram(id);
  glUniform1f(uniformId, value);
  glUseProgram(0);
}

void ShaderProgram::setUniform(std::string uniform, glm::mat4 value)
{

  GLint uniformId = glGetUniformLocation(id, uniform.c_str());
  
  if(uniformId == -1)
  {

  std::cout<<"failed mat4 uniform: "<<uniform<<std::endl;
    throw std::exception();
  }

  glUseProgram(id);
  glUniformMatrix4fv(uniformId, 1, GL_FALSE, glm::value_ptr(value));
  glUseProgram(0);
}

  void ShaderProgram::setUniform(std::string uniform, Texture * texture)
  {

    GLuint uniformId = glGetUniformLocation(id, uniform.c_str());

    if(uniformId == -1)
    {

  std::cout<<"failed texture uniform: "<<uniform<<std::endl;
      return;
    }

    for(size_t i=0;i<samplers.size(); i++)
    {
      if(samplers.at(i).id == uniformId)
      {
        samplers.at(i).texture = texture;

        glUseProgram(id);
        glUniform1i(uniformId,i);
        glUseProgram(0);
        return;
      }
    }

    Sampler s;
    s.id = uniformId;
    s.texture = texture;
    samplers.push_back(s);

    glUseProgram(id);
    glUniform1i(uniformId, samplers.size() -1);
    glUseProgram(0);
  }




GLuint ShaderProgram::getId()
{
  return id;
}

}
