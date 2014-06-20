//ShellOutput.cpp

#include "ShellOutput.cpp"

ShellOutput *ShellOutput::instance = 0;

ShellOutput::ShellOutput()
{
}

void ShellOutput::print(std::string output)
{
	std::cout << output << std::endl;
}

ShellOutput* ShellOutput::Instance()
{
	if (instance == 0)
	{
		instance = new ShellOutput;
	}
	return instance;
}
