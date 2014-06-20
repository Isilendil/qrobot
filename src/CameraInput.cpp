//LightOutput.cpp

LightOutput *LightOutput::instance = 0;

LightOutput::LightOutput()
{
}

LightOutput* LightOutput::Instance()
{
	if (instance == 0)
	{
		instance = new LightOutput;
	}
	return instance;
}
