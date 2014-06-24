#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#include <iostream>
using namespace std;


struct Data
{
public:
  int a;
	//char b[10];
	double c;
};

struct Message
{
public:
	int n;
	char m[10];
	//Data d;
};

int main()
{

	int shmid;
	//Message *msg = new Message;
	Message *msg;


	shmid = shmget(34567, sizeof(Message), 0666|IPC_CREAT);
	msg = (Message*)shmat(shmid, 0, 0);
	msg->n = 100;
  strcpy(msg->m, "abc");


  cout << msg->n << '\n';
  printf("%s\n", msg->m);

	int t;
	cin >> t;

	
	return 0;
}
