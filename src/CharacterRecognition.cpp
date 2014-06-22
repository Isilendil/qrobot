//CharacterRecognition.cpp

#include "CharacterRecognition.h"

CharacterRecognition *CharacterRecognition::instance = 0;

CharacterRecognition::CharacterRecognition()
{
}

CharacterRecognition* CharacterRecognition::Instance()
{
	if (instance == 0)
	{
		instance = new CharacterRecognition;
	}
	return instance;
}
