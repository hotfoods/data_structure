#pragma once
#include <iostream>

struct loop_queue
{
	int data[10];
	int front;
	int rear;
};

void init_loop_q();
void enq(int data);
void front();
bool isfull();
bool isempty();
void deq();
void show_loop_q();

