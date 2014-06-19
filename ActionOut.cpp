//ActionOut.cpp

#include "ActionOut.h"

ActionOut *ActionOut:: instance = 0;

ActionOut::ActionOut()
{
}

ActionOut* ActionOut::Instance()
{
	if (instance == 0)
	{
		instance = new ActionOut;
	}
	return instance;
}
