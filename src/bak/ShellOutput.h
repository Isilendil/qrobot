//ShellOutput.h
//class ShellOutput

#include <iostream>
#include <string>

class ShellOutput
{
public:
  static ShellOutput* Instance();
  void print(std::string output);

protected:
  ShellOutput();

private:
  static ShellOutput *instance;

};
