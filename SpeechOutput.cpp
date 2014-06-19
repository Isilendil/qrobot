//SpeechOutput.cpp

#include "SpeechOutput.h"

SpeechOutput *SpeechOutput::instance = 0;

SpeechOutput::SpeechOutput()
{
}

void SpeechOutput::speakUp(std::string sentence)
{
	std::cout << sentence << std::endl;
}

SpeechOutput* SpeechOutput::Instance()
{
	if (instance == 0)
	{
		instance = new SpeechOutput;
	}
	return instance;
}
