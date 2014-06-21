//SpeechOutput.h
//class SpeechOutput

#ifndef _SPEECHOUTPUT_H_
#define _SPEECHOUTPUT_H_

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

#endif
