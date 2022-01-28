#ifndef PARSER_H
#define PARSER_H

#include "InterperterException.h"
#include "IndentationException.h"
#include "NameErrorException.h"
#include "SyntaxException.h"
#include "TypeError.h"
#include "Helper.h"

#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>

#include "type.h"
#include "Boolean.h"
#include "Integer.h"
#include "String.h"
#include "Void.h"
#include "List.h"

class Parser
{
public:
	static Type* parseString(std::string str) throw();
	static Type* getType(std::string& str);
	static void freeVariables();
	int add(Integer num1, Integer num2);
	int sub(Integer num1, Integer num2);
	int mul(Integer num1, Integer num2);
	int dev(Integer num1, Integer num2);
private:
	static bool isLegalVarName(const std::string& str);
	static bool makeAssignment(const std::string& str);
	static Type* getVariableValue(const std::string& str);
	static Type*  copyVariables(const std::string& str);

	static void type(std::string name);
	static void del(std::string name);
	static int len(std::string name);
};

#endif //PARSER_H
