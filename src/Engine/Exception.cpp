#include "Exception.h"

namespace TEFGAS
{

Exception::Exception(std::string message)
{
  this->message = message;
}

Exception::~Exception() throw() { }

const char *Exception::what()
{
  return message.c_str();
}

}