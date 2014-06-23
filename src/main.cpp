//main.cpp

#include "common.h"

#include <thread>
#include <unistd.h>

using namespace std;
using namespace qrobot;

void waitingForSpeechInput();

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
			BookSearcher::Instance()->search();
		}
		else if (SemanticAnalysis::Instance()->synonymous(speechInput, "查询个人信息"))
		{
			randomMove();
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
