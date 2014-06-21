//LightOutput.h
//class LightOutput

class LightOutput
{
public:
  static LightOutput* Instance();
	
protected:
  LightOutput();

private:
  static LightOutput *instance;

};
