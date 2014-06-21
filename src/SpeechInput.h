//SpeechInput.h
//class SpeechInput

#ifndef _SPEECHINPUT_H_
#define _SPEECHINPUT_H_

#include <string>
#include <iostream>

class SpeechInput
{
public:
  static SpeechInput* Instance();
	std::string waitingForInput();
  
protected:
  SpeechInput();

private:
  static SpeechInput *instance;

};

#endif
