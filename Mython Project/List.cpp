#include "List.h"

List::List(std::string str)
{
	unsigned int i, j; 
	Type* newVariable = NULL;
	std::string typeOfVariable;

	for (i = 1; i < str.length(); i = j + 1)
	{
		typeOfVariable = "";
		for (j = i; ((str[j] != ',') && (str[j] != ']')); j++)
		{
			typeOfVariable += str[j];
		}
		Helper::trim(typeOfVariable);
		Helper::removeLeadingZeros(typeOfVariable);

		if (Helper::isInteger(typeOfVariable))
		{
			newVariable = new Integer(stoi(typeOfVariable));
		}
		else if (Helper::isBoolean(typeOfVariable))
		{
			bool booleanVar;
			(typeOfVariable == "True") ? (booleanVar = true) : ((booleanVar = false));
			newVariable = new Boolean(booleanVar);
		}
		else if (Helper::isString(typeOfVariable))
		{
			newVariable = new String(typeOfVariable);
		}
		this->_variablesList.push_back(newVariable);
	}
}

bool List::isPrintable() const
{
	return true;
}
std::string List::toString() const
{
	std::list<Type*>::iterator it, temp;
	std::string ret = "[";
	for (unsigned int i = 0; i < _variablesList.size(); i++)
	{
		ret += _variablesList[i]->toString();

		if (i != (_variablesList.size() - 1))
		{
			ret += " , ";
		}
	}

	ret += "]";
	
	return ret;
}
std::vector<Type*> List::getVariablesList()
{
	return (this->_variablesList);
}