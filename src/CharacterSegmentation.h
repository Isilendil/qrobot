//CharacterSegmentation.h
//class CharacterSegmentation

#ifndef _CHARACTERSEGMENTATION_H_
#define _CHARACTERSEGMENTATION_H_

#include "common.h"


class CharacterSegmentation
{
public:
  static CharacterSegmentation* Instance();

protected:
  CharacterSegmentation();

private:
  static CharacterSegmentation *instance;

};

#endif

