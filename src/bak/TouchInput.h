//TouchInput.h
//class TouchInput

#include "../include/QrobotController.h"

class TouchInput
{
public:
  static TouchInput* Instance();

protected:
  TouchInput();

private:
  static TouchInput *instance;

};
