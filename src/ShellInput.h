//ShellInput.h
//class ShellInput

#include <iostream>
#include <string>

class ShellInput
{
public:
  static ShellInput* Instance();
	std::string waitingForInput();

protected:
  ShellInput();

private:
  static ShellInput *instance;

};
	
