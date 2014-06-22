//PersonalAssistant.h
//class PersonalAssistant

#ifndef _PERSONALASSISTANT_H_
#define _PERSONALASSISTANT_H_

#include "common.h"
//我的资料
//我的财经（是否欠费）
//我的书架
//密码修改
//我的借阅
//--是否有快到期的书
//--是否可以续借
//--续借操作
//--什么时候该还哪本书

class PersonalAssistant
{
public:
  static PersonalAssistant* Instance();

protected:
  PersonalAssistant();

private:
  static PersonalAssistant *instance;

};

#endif
