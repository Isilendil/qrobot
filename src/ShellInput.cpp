//ShellInput.cpp

#include "ShellInput.h"

ShellInput *ShellInput::instance = 0;

ShellInput::ShellInput()
{
}

std::string ShellInput::waitingForInput()
{
	std::string input;
	std::cin >> input;
	return input;
}

ShellInput* ShellInput::Instance()
{
	if (instance == 0)
	{
		instance = new ShellInput;
	}
	return instance;
}
