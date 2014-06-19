#include <thread>
#include <unistd.h>
#include <iostream>
#include "../include/QrobotController.h"
using namespace qrobot;
using namespace std;

QrobotController &controller = QrobotController::Instance();

void commandThread();
void touchThread();

int main(){
	
	//随便动一动
	controller.HorizontalHead(2, -80);
	controller.LeftWingUp(2,10);
	controller.RightWingUp(2,10);
	sleep(1);
	controller.HorizontalHead(2, 80);
	controller.LeftWingDown(2,10);
	controller.RightWingDown(2,10);
	sleep(1);
	controller.HorizontalHead(2, 0);
	sleep(1);

	int* headpos = controller.GetHeadPosition();
	printf("Head Horizon Position : %d\n", headpos[0]);
	printf("Head Vertical Position : %d\n", headpos[1]);
	
	controller.VerticalHead(1, 10);

	thread t1(commandThread);
	thread t2(touchThread);
	t1.join();
	t2.join();
	
	return 0;
}

void commandThread()
{
	char input;
	while(1)
	{
    cin >> input;
		cout << "Command input: " << input << '\n';
		controller.Eye(3, 11);
		//sleep(1);
	}
}


void touchThread()
{
	//触摸事件
	int query = -1;
	while(1){
		query = controller.Query(0);
		switch(query){
		case 2:     //头部按下
			printf("Touch Head Down\n");
			controller.Eye(3,6);
			break; 		
		case 3:     //头部按下松开
			printf("Touch Head Up\n");
			controller.Eye(3,11);
			break;
		case 4:     //长按
			printf("Bye Bye ~\n");
			exit(0);
		}
		//sleep(1);
	}
}
