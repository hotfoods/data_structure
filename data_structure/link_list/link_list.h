#pragma once
#include <iostream>


int add(int a, int b);

//extern linklist_node * head;

void create();
void insert();
void show();

struct linklist_node
{
	int data;
	linklist_node* next;
};

struct  loop_pre_l_node
{
	int data;
	loop_pre_l_node * pre;
	loop_pre_l_node* next;
};

void insert_loop_l();
void create_loop_l();
void show_loop_l();