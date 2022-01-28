#include "TypeError.h"

TypeError::TypeError(std::string name)
{
	this->_name = name;
}

std::string TypeError::what()  throw()
{
	std::string ret = "TypeError : object of type \'" + _name + "\' has no len() ";
	return ret;
}