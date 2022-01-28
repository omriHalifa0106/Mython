#ifndef LIST_H
#define LIST_H

#include "Sequence.h"
#include "parser.h"
#include <string>
#include <vector>
class List : public Sequence
{
public:
	List(std::string str);
	bool isPrintable() const;
	std::string toString() const;
	std::vector<Type*> getVariablesList();

protected:
	std::vector<Type*> _variablesList;
};




#endif // LIST_H