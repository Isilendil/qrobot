//SpeechInput.cpp

#include "SpeechInput.h"

SpeechInput *SpeechInput::instance = 0;

SpeechInput::SpeechInput()
{
}

std::string SpeechInput::waitingForInput()
{
	std::string input;
	std::cin >> input;
	return input;
}

SpeechInput* SpeechInput::Instance()
{
	if (instance == 0)
	{
		instance = new SpeechInput;
	}
	return instance;
}
