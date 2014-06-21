//Logger.h
//class Logger 

#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>

class Logger 
{
public:
  static Logger* Instance();

  bool logIn();
	bool logInOrNot();
	bool exit();

protected:
  Logger();

private:
  static Logger*instance;

	bool logInAlready;

	bool logInOperation(std::string id, std::string password);
	bool exitOperation();

};
	
#endif
