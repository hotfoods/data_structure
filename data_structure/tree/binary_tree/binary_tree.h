#pragma once
#include<iostream>
//#include"..\..\stack\stack.h"
//#include"..\..\queue\loop_queue\loop_queue.h"
#include<queue>
#include<string>
#include<cmath>
#include <iomanip>
//¶ş²æËÑË÷Ê÷
struct binary_tree
{
	int data;
	binary_tree* left;
	binary_tree* right;
};

//void cre_bin_tree();
void insert_bin_tree(int data);
binary_tree* get_insert_pos(binary_tree* node, int data);
void mid_show_bin_tree(binary_tree* node);//ÖĞĞò±éÀú
void show_bin_tree();
void level_show_bin_tree();