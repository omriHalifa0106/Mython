#include "Sequence.h"

#ifndef STRING_H
#define STRING_H

class String : public Sequence
{
public:
	String(std::string var);
	bool isPrintable() const;
	std::string toString() const;
	std::string getVar();

protected:
	std::string _var;
};


#endif // STRING_H