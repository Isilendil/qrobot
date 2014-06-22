//PersonalAssistant.cpp

#include "PersonalAssistant.h"


PersonalAssistant *PersonalAssistant::instance = 0;

PersonalAssistant::PersonalAssistant()
{
}

PersonalAssistant* PersonalAssistant::Instance()
{
	if (instance == 0)
	{
		instance = new PersonalAssistant;
	}
	return instance;
}
