//SemanticAnalysis.cpp
#include "SemanticAnalysis.h"

using std::string;

SemanticAnalysis *SemanticAnalysis::instance = 0;

SemanticAnalysis::SemanticAnalysis()
{
}

SemanticAnalysis* SemanticAnalysis::Instance()
{
	if (instance == 0)
	{
		instance = new SemanticAnalysis;
	}
	return instance;
}

bool SemanticAnalysis::synonymous(string parameter1, string parameter2)
{
	if (parameter1 == parameter2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
