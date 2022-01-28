#include "type.h"

#ifndef BOOLEAN_H
#define BOOLEAN_H

class Boolean : public Type
{
public: 
	Boolean(bool var);
	 bool isPrintable() const;
	 std::string toString() const;
	bool getVar(); 

protected: 
	bool _var;
};

#endif // BOOLEAN_H