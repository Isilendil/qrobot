//CharacterSegmentation.cpp

#include "CharacterSegmentation.h"

CharacterSegmentation *CharacterSegmentation::instance = 0;

CharacterSegmentation::CharacterSegmentation()
{
}

CharacterSegmentation* CharacterSegmentation::Instance()
{
	if (instance == 0)
	{
		instance = new CharacterSegmentation;
	}
	return instance;
}
