#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#include <iostream>
using namespace std;


class Data
{
public:
  int a;
	char b[10];
	double c;
};

struct Message
{
	int n;
	char m[10];
	//Data d;
};

int main()
{
	int shmid;
	Message *msg;


	shmid = shmget(34567, sizeof(Message), 0);
	msg = (Message*)shmat(shmid, 0, 0);

	cout << msg->n << '\n';
	printf("%s\n", msg->m);



	
	return 0;
}
