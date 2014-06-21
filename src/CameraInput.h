//LightOutput.h
//class LightOutput

#ifndef _CAMERAINPUT_H_
#define _CAMERAINPUT_H_

class CameraInput 
{
public:
  static CameraInput* Instance();
	
protected:
  CameraInput();

private:
  static CameraInput*instance;

};

#endif
