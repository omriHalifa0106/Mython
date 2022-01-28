#ifndef TYPE_ERROR_H
#define TYPE_ERROR_H

#include "InterperterException.h"
#include <string>
class TypeError : public InterperterException
{
public:
	TypeError(std::string name);
	virtual  std::string what() throw();
private:
	std::string _name;
};
#endif // TYPE_ERROR_H