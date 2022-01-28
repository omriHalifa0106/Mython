#include "String.h"

String::String(std::string var)
{
	this->_var = var;
}

bool String::isPrintable() const
{
	return true;
}
std::string String::toString() const
{
	return  this->_var;
}
std::string String::getVar()
{
	return this->_var;
}