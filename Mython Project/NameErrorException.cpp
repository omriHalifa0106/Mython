#include "NameErrorException.h"

NameErrorException::NameErrorException(std::string name)
{
	this->_name = name;
}

std::string NameErrorException::what()  throw()
{
	std::string ret = "NameError : name \'" + _name + "\' is not defined";
	return ret;
}