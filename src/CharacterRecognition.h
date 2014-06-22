//CharacterRecognition.h
//class CharacterRecognition

#ifndef _CHARACTERRECOGNITION_H_
#define _CHARACTERRECOGNITION_H_

#include "common.h"


class CharacterRecognition
{
public:
  static CharacterRecognition* Instance();

protected:
  CharacterRecognition();

private:
  static CharacterRecognition *instance;

};

#endif

