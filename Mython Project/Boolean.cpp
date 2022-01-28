#include "Boolean.h"

Boolean::Boolean(bool var)
{
	this->_var = var;
}
bool Boolean::isPrintable() const
{
	return true;
}
std::string Boolean::toString() const
{
	std::string ret;
	((this->_var == 1) ? (ret = "True") : (ret = "False"));
	return ret;
}
bool Boolean::getVar()
{
	return this->_var;
}