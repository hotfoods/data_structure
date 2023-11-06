#include "loop_queue.h"
using namespace std;

loop_queue* q;

void init_loop_q() {
	q = new loop_queue;
	for (int i = 0; i < 10; i++)
		q->data[i] = 0;
	q->front = q->rear = -1;
}


void enq(int data) {
	cout << "front:" << q->front << "  rear:" << q->rear<<"  "<<endl;
	if (isfull()) {
		cout << "队列满了" << endl;
	}
	else {
		q->data[(q->rear + 1) % 10] = data;
		q->rear = (q->rear + 1) % 10;
		if (q->front == -1)
			q->front++;
	}
}


void front() {
	if (isempty())
		cout << "队空" << endl;
	else
		cout << q->data[q->front];
}


bool isfull() {
	cout << (q->rear + 1) % 10<<"\n";

	if ((q->rear + 1) % 10 == q->front)
		return true;
	return false;
}

bool isempty() {
	if (q->front == q->rear)
		return true;
	return false;
}

void deq(){
	if (isempty())
	{
		cout << "队空" << endl;
	}
	else {
		cout << "出队：" << q->data[q->front]<<endl;
		q->data[q->front] = 0;
		q->front = (q->front + 1) % 10;
	}
}

void show_loop_q() {
	for (int i = 0; i < 10; i++)
		cout << q->data[i];
	cout << endl;
}


