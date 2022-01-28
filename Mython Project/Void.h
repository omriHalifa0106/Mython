#include "type.h"

#ifndef VOID_H
#define VOID_H

class Void : public Type
{
public:
	Void();
	bool isPrintable() const;
	std::string toString() const;
};

#endif // VOID_H