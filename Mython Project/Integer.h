#include "type.h"

#ifndef INTEGER_H
#define INTEGER_H


class Integer : public Type
{
public:
	Integer(int var);
	bool isPrintable() const;
	std::string toString() const;
	int getVar();

private:
	int _var;
};

#endif // INTEGER_H