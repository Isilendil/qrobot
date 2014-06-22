//Logger.cpp

#include "Logger.h"


using namespace std;

Logger *Logger::instance = 0;

Logger::Logger()
{
	logInAlready = false;
}

Logger* Logger::Instance()
{
	if (instance == 0)
	{
		instance = new Logger;
	}
	return instance;
}

bool Logger::logIn()
{
	if (logInAlready)
	{
		return true;
	}
	string id;
	string password;
  string speechInput;

  while (true)
	{
	  SpeechOutput::Instance()->speakUp("请出示您的借书证");
	  //图像检测
	  SpeechOutput::Instance()->speakUp("请输入您的密码");
		cin >> password;
		
		if (logInOperation(id, password))
		{
			logInAlready = true;
			return true;
		}
		else
		{
			SpeechOutput::Instance()->speakUp("登录失败");
			SpeechOutput::Instance()->speakUp("要再次尝试登录吗");
			speechInput = SpeechInput::Instance()->waitingForInput();
			if (SemanticAnalysis::Instance()->synonymous(speechInput, "是"))
		  {
				continue;
		  }
			else
			{
				SpeechOutput::Instance()->speakUp("那好吧");
				return false;
			}
		}
	}
}

bool Logger::logInOrNot()
{
	return logInAlready;
}

bool Logger::exit()
{
	//operation
	string speechInput;
  while (true)	
	{
	  if (exitOperation())
	  {
		  logInAlready = false;
		  return true;
	  }
	  else
	  {
		  SpeechOutput::Instance()->speakUp("退出失败");
		  SpeechOutput::Instance()->speakUp("要再次尝试退出吗");
      speechInput = SpeechInput::Instance()->waitingForInput();
			if (SemanticAnalysis::Instance()->synonymous(speechInput, "是"))
		  {
				continue;
		  }
			else
			{
				SpeechOutput::Instance()->speakUp("那好吧");
				return false;
			}
	  }
	}
}

bool Logger::logInOperation(string id, string password)
{
	//do something
	return false;
}

bool Logger::exitOperation()
{
	//do something
	return false;
}

