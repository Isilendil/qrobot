#include <iostream>
#include <unistd.h>
#include <thread>

#include "SpeechInput.h"
#include "SpeechOutput.h"

using namespace std;

void waitingForSpeechInput();
bool login();
void searchForBooks();
void personalInformationManage();

int main()
{
	thread threadWaitingForSpeechInput(waitingForSpeechInput);
	threadWaitingForSpeechInput.join();

	return 0;
}

void waitingForSpeechInput()
{
	string speechInput;
	while(true)
	{
		speechInput = SpeechInput::Instance()->waitingForInput();
		if (speechInput == "登录")
		{
			cout << "登录" << endl;
			bool successful = false;
		  while	(!(successful = login()))
		  {
				SpeechOutput::Instance()->speakUp("密码错误");
				SpeechOutput::Instance()->speakUp("是否需要重新登录");
				speechInput = SpeechInput::Instance()->waitingForInput();
				if (speechInput == "是")
				{
					continue;
				}
				else
				{
					break;
				}
			}
			if (successful)
			{
				SpeechOutput::Instance()->speakUp("登录成功");
				//登录成功操作
			}
			else
			{
				SpeechOutput::Instance()->speakUp("登录失败");
			}
		}
		else if (speechInput == "查询图书")
		{
			searchForBooks();
		}
		else if (speechInput == "查询个人信息")
		{
			personalInformationManage();
		}
		else
		{
		}
	}
	SpeechOutput::Instance()->speakUp("线程结束");
}

bool login()
{
	string id;
	string password;
	SpeechOutput::Instance()->speakUp("请出示您的借书证");
	//图像检测
	SpeechOutput::Instance()->speakUp("请输入您的密码");
  cin >> password;
	//尝试登录
	//登录成功
	//检查数据库
	//更新数据库
	if (password == "password")
	{
	  return true;
	}
	else
	{
		return false;
	}
}

void searchForBooks()
{
}

void personalInformationManage()
{
}
