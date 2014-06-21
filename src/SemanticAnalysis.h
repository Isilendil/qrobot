//SemanticAnalysis.h
//class SemanticAnalysis 

#ifndef _SEMANTICANALYSIS_H_
#define _SEMANTICANALYSIS_H_

#include <string>

class SemanticAnalysis 
{
public:
  static SemanticAnalysis* Instance();
	bool synonymous(std::string parameter1, std::string parameter2);
	
protected:
  SemanticAnalysis();

private:
  static SemanticAnalysis *instance;

};

#endif
