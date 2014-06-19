//TouchInput.h
//class TouchInput

class TouchInput
{
public:
  static TouchInput* Instance();

protected:
  TouchInput();

private:
  static TouchInput *instance;

};
