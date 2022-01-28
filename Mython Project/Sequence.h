#include "type.h"
#include <stdio.h>
#include <string>

#ifndef SEQUENCE_H
#define SEQUENCE_H

class Sequence : public Type
{
public:
	virtual bool isPrintable() const = 0 ;
	virtual std::string toString() const = 0 ;
};

#endif // SEQUENCE_H