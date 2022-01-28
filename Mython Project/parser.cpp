#include "parser.h"

std::unordered_map<std::string, Type*> _variables; 

Type* Parser::parseString(std::string str) throw()
{
	Type* variable = NULL;
	if (str[0] == ' ' || str[0] == '\t')
		throw IndentationException();
	std::string command = str.substr(0, str.find("("));
	std::string varName = str.substr((str.find("(") + 1));
	varName = varName.substr(0, varName.find(")"));
	if (command == "type")
	{
		type(varName);
		variable = new Void();
		variable->SetIsTemp(true);
	}
	else if (command == "del")
	{
		del(varName);
		variable = new Void();
		variable->SetIsTemp(true);
		std::cout << varName <<" deleted! "<< std::endl;
	}
	else if (command == "len")
	{
		int length = len(varName);
		variable = new Integer(length);
		variable->SetIsTemp(true);
		std::cout << variable->toString() << std::endl;
	}
	else
	{ 
		if (isLegalVarName(str))
		{
			variable = getVariableValue(str);
			if (variable)
			{
				std::cout<< variable->toString()<<std::endl;
				return variable;// Returning the variable value.
			}
			else
			{
				throw NameErrorException(str);
			}
		}
		variable = getType(str);
		if (!variable)
		{
			variable = copyVariables(str);
			if (!variable)
			{
				if (makeAssignment(str))
				{
					variable = new Void();
					variable->SetIsTemp(true);
				}
				else
				{
					throw SyntaxException();
				}
			}
		}
		if (variable->isPrintable())
		{
			std::cout << variable->toString() << std::endl;
			if (variable->GetIsTemp())
				delete variable;
		}
	}
	return variable;
}

Type* Parser::getType(std::string& str)
{
	Type* newValue = NULL;
	Helper::trim(str);
	Helper::removeLeadingZeros(str);
	if (str == "\0")
		return new Void();
	if (Helper::isInteger(str))
	{
		newValue = new Integer(stoi(str));
	}
	else if (Helper::isBoolean(str))
	{
		bool booleanVar;
		(str == "True") ? (booleanVar = true) : ((booleanVar = false));
		newValue = new Boolean(booleanVar);
	}
	else if (Helper::isString(str))
	{
		newValue = new String(str);
	}
	else if (str[0] == '[')
	{
		newValue = new List(str);
	}
	return newValue;
}

bool Parser::isLegalVarName(const std::string& str)
{
	if (Helper::isDigit(str[0]) || str[0] == '-')
	{
		return false;
	}
	if (str == "True" || str == "False")
	{
		return false;
	}
	for (int i = 1; i < str.length(); i++)
	{
		if (!(Helper::isDigit(str[i])) && !(Helper::isLetter(str[i])) && !(Helper::isUnderscore(str[i])))
			return false;
	}
	return true;
}

bool Parser::makeAssignment(const std::string& str)
{
	if (!(str.find("=")))
		return false;
	int posNameVariable = str.find("="); //until '=' sign. 
	int posValueVariable = str.find("=")+1; //from '=' to the end.

	std::string nameVariable = str.substr(0, posNameVariable);
	std::string ValueVariable = str.substr(posValueVariable,str.length());
	
Helper::trim(nameVariable);
Helper::trim(ValueVariable);

if (!(isLegalVarName(nameVariable)))
{
	throw SyntaxException();
}
Type* variableValue = getType(ValueVariable);

if (!variableValue)
{
	throw SyntaxException();
}

std::unordered_map <std::string, Type*>::iterator variable = _variables.find(nameVariable);
if (variable == _variables.end())
{
	std::pair <std::string, Type*> newVariable(nameVariable, variableValue);
	_variables.insert(newVariable);
}
else
{
	variable->second = variableValue;
}

return true;
}

Type* Parser::getVariableValue(const std::string& str)
{
	std::unordered_map <std::string, Type*>::iterator variable = _variables.find(str);
	if (variable != _variables.end())
	{
		return (variable->second);
	}
	return NULL;
}

void Parser::freeVariables()
{
	std::unordered_map<std::string, Type*>::iterator it = _variables.begin(), temp;

	while (it != _variables.end())
	{
		delete (it->second);

		temp = it;
		it++;

		_variables.erase(temp);
	}
}

Type* Parser::copyVariables(const std::string& str)
{
	/*if (!(str.find("=")))
		return false;*/
	int posDstNameVariable = str.find("="); //until '=' sign. 
	int posSrcValueVariable = str.find("=") + 1; //from '=' to the end.

	std::string dstNameVariable = str.substr(0, posDstNameVariable);
	std::string srcNameVariable = str.substr(posSrcValueVariable, str.length());

	Helper::trim(dstNameVariable);
	Helper::trim(srcNameVariable);

	if (!(isLegalVarName(dstNameVariable)) || (!(isLegalVarName(srcNameVariable))))
	{
		return NULL;
	}

	std::unordered_map <std::string, Type*>::iterator dstVariable = _variables.find(dstNameVariable);
	std::unordered_map <std::string, Type*>::iterator srcVariable = _variables.find(srcNameVariable);
	Type* variable;
	if (dstVariable == _variables.end())
	{
		variable = srcVariable->second;
		if (srcVariable != _variables.end())
		{
			std::pair <std::string, Type*> CopyVariable(dstNameVariable, variable);
			_variables.insert(CopyVariable);
		}
		else
		{
			dstVariable->second = variable;
		}

	}
	else
	{
		throw NameErrorException(srcNameVariable);
	}
	return variable;

}

void Parser::type(std::string name)
{
	std::unordered_map <std::string, Type*>::iterator variable = _variables.find(name);
	std::string typeVariableCheck;
	std::string typeVariable;
	int lengthVariable = 0;
	if (variable != _variables.end())
	{
		typeVariable = (variable->second)->toString();
	}
	else
	{
		Helper::trim(name);
		Helper::removeLeadingZeros(name);
		typeVariable = name;
	}
	if (name.find("len") != std::string::npos) 
	{
		std::string command = name.substr(0, name.find("("));
		std::string varName = name.substr((name.find("(") + 1));
		varName = varName.substr(0, varName.find(")"));
		typeVariable = "int";
	}
	else if (Helper::isInteger(typeVariable))
	{
		typeVariable = "int";
	}
	else if (Helper::isBoolean(typeVariable))
	{
		typeVariable = "bool";
	}
	else if (Helper::isString(typeVariable))
	{
		typeVariable = "string";
	}
	else if (typeVariable[0] == '[')
	{
		typeVariable = "list";
	}
	else
		throw NameErrorException(typeVariableCheck);

	std::cout << "<type '" + typeVariable + "'>" << std::endl;
}

void Parser::del(std::string name)
{
	std::unordered_map <std::string, Type*>::iterator variable = _variables.find(name);
	if (variable !=_variables.end())
	{
		delete (variable->second);
		_variables.erase(variable);
	}
	else
	{
		throw NameErrorException(name);
	}
	 
	
}

int Parser::len(std::string name)
{
	std::unordered_map <std::string, Type*>::iterator variable = _variables.find(name);
	std::string typeVariableCheck;
	std::string typeVariable;
	std::string variableInList;
	int LengthVariable = 0;
	int i, j;
	if (variable != _variables.end())
	{
		typeVariable = (variable->second)->toString();
	}
	else
	{
		Helper::trim(name);
		Helper::removeLeadingZeros(name);
		typeVariable = name;
	}
	if (Helper::isInteger(typeVariable))
	{
		throw TypeError("int");
	}
	else if (Helper::isBoolean(typeVariable))
	{
		throw TypeError("bool");
	}
	else if (Helper::isString(typeVariable))
	{
		LengthVariable = typeVariable.length() - 2;
	} 
	else if (typeVariable[0] == '[')
	{
		for (i = 1; i < typeVariable.length(); i = j + 1)
		{
			variableInList = "";
			for (j = i; (typeVariable[j] != ',') && (typeVariable[j] != ']'); j++)
			{
				variableInList += typeVariable[j];
			}
			LengthVariable++;
		}
	}
	else
		throw TypeError("Void");;
	return LengthVariable;
}


int Parser::add(Integer num1, Integer num2)
{
	return (num1.getVar() + num2.getVar());
}

int Parser::sub(Integer num1, Integer num2)
{
	return (num1.getVar() - num2.getVar());
}

int Parser::mul(Integer num1, Integer num2)
{
	return (num1.getVar() * num2.getVar());
}

int Parser::dev(Integer num1, Integer num2)
{
	return (num1.getVar() * num2.getVar());
}
