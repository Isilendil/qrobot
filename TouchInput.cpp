//TouchInput.cpp

#include "TouchInput.h"

TouchInput *TouchInput::instance = 0;

TouchInput::TouchInput()
{
}

TouchInput* TouchInput::Instance()
{
	if (instance == 0)
	{
		instance = new TouchInput;
	}
	return instance;
}
