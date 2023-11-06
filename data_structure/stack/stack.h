#pragma once
#include <iostream>

void pop();
void push(int data);
void top();

void init_arr_stack();
void show_arr_stack();
struct  arr_stack
{
	int data[10];
	int length;
	int top;
};

struct link_stack {
	int data;
	link_stack* pre;
	int length;
};

void l_pop();
void l_push(int data);
void l_top();
bool l_isempty();
void init_l_stack();
void show_l_stack();