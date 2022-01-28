#include "type.h"
#include "InterperterException.h"
#include "parser.h"
#include "IndentationException.h"
#include <iostream>

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define NAME "Omri Halifa"


int main(int argc,char **argv)
{
	std::cout << WELCOME << NAME << std::endl;

	std::string input_string;

	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);
	
	while (input_string != "quit()")
	{
		// prasing command
		try
		{
			Parser::parseString(input_string);
		}
		catch (const IndentationException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (const SyntaxException & e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (NameErrorException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (TypeError & e)
		{
			std::cout << e.what() << std::endl;
		}
		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}

	Parser::freeVariables();

	return 0;
}


