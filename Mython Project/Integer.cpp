#include "Integer.h"

Integer::Integer(int var)
{
	this->_var = var;
}
bool Integer::isPrintable() const
{
	return true;
}
std::string Integer::toString() const
{
	return std::to_string(this->_var);
}
int Integer::getVar()
{
	return this->_var;
}