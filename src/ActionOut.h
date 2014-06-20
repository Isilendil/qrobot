//ActionOut.h
//class ActionOut

class ActionOut
{
public:
  static ActionOut* Instance();

protected:
  ActionOut();

private:
  static ActionOut *instance;

};
