#include <iostream>
#include <unistd.h>
#include <thread>

#include "common.h"

using namespace std;
using namespace qrobot;

void waitingForSpeechInput();
void searchForBooks();
void personalInformationManage();

void randomMove();

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
		if (SemanticAnalysis::Instance()->synonymous(speechInput, "登录"))
		{
			cout << "登录" << endl;
			if( Logger::Instance()->logIn())
			{
				SpeechOutput::Instance()->speakUp("登录成功");
				//登录成功操作
			}
			else
			{
				SpeechOutput::Instance()->speakUp("登录失败");
			}
		}
		else if (SemanticAnalysis::Instance()->synonymous(speechInput, "查询图书"))
		{
			searchForBooks();
		}
		else if (SemanticAnalysis::Instance()->synonymous(speechInput, "查询个人信息"))
		{
			randomMove();
			personalInformationManage();
		}
		else if(SemanticAnalysis::Instance()->synonymous(speechInput, "再见"))
		{
			break;
		}
		else
		{
			SpeechOutput::Instance()->speakUp("您说啥");
		}
	}
	SpeechOutput::Instance()->speakUp("线程结束");
}


void searchForBooks()
{
	bool inputError = true;
	string speechInput;
	do
	{
	  SpeechOutput::Instance()->speakUp("请选择查询方式");
	  SpeechOutput::Instance()->speakUp("题名责任者还是ISBN号");
		speechInput = SpeechInput::Instance()->waitingForInput();
		if (SemanticAnalysis::Instance()->synonymous(speechInput, "题名"))
		{
			//search
			inputError = false;
		}
		else if (SemanticAnalysis::Instance()->synonymous(speechInput, "责任者"))
		{
			//search
			inputError = false;
		}
		else if (SemanticAnalysis::Instance()->synonymous(speechInput, "ISBN号"))
		{
			//search
			inputError = false;
		}
		else
		{
			SpeechOutput::Instance()->speakUp("输入错误");
			SpeechOutput::Instance()->speakUp("是否重新选择");
		  speechInput = SpeechInput::Instance()->waitingForInput();
			if (SemanticAnalysis::Instance()->synonymous(speechInput, "是"))
			{
			}
			else
			{
				inputError = false;
			}
		}
	} while (inputError);
}

void personalInformationManage()
{
}

void randomMove()
{
	QrobotController::Instance().HorizontalHead(2, -80);
	QrobotController::Instance().LeftWingUp(2, 10);
	QrobotController::Instance().RightWingUp(2, 10);
  sleep(1);
	QrobotController::Instance().HorizontalHead(2, 80);
	QrobotController::Instance().LeftWingDown(2, 10);
	QrobotController::Instance().RightWingDown(2, 10);
  sleep(1);

  int *headPosition = QrobotController::Instance().GetHeadPosition();
	cout << "Head Horizon Position: ";
	cout << headPosition[0] << '\n';
	cout << "Head Vertical Position: ";
	cout << headPosition[1] << '\n';

}
