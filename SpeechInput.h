//SpeechInput.h
//class SpeechInput
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
