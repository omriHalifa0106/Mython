#ifndef NAME_ERROR_EXCEPTION_H
#define NAME_ERROR_EXCEPTION_H

#include <string>

#include "InterperterException.h"


class NameErrorException : public InterperterException
{
public:
	NameErrorException(std::string name);
	virtual  std::string what() throw();
private:
	std::string _name; 
};


#endif // NAME_ERROR_EXCEPTION_H