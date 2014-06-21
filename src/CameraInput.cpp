//CameraInput.cpp

CameraInput *CameraInput::instance = 0;

CameraInput::CameraInput()
{
}

CameraInput* CameraInput::Instance()
{
	if (instance == 0)
	{
		instance = new CameraInput;
	}
	return instance;
}
