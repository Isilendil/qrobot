//SpeechOutput.h
//class SpeechOutput
#include <string>
#include <iostream>

class SpeechOutput
{
public:
  static SpeechOutput* Instance();
	void speakUp(std::string sentence);
  
protected:
  SpeechOutput();

private:
  static SpeechOutput *instance;

};
