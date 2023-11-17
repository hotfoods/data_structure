//
// Created by 联想 on 2023/11/17.
//
#pragma once
#ifndef DATA_STRUCTURE_AVL_H
#define DATA_STRUCTURE_AVL_H

#include <iostream>
#include <queue>
#include <vector>

struct avl_node{
    int key;
    struct avl_node *left;
    struct avl_node * right;
    int height;
};

int max(int a, int b);
int tree_height(avl_node * node);
//获取平衡因子
int get_balance_facter(avl_node * node);

avl_node * new_avl_node(int key);

avl_node * right_rotate(avl_node* node);
avl_node * left_rotate(avl_node * node);

avl_node * avl_insert(avl_node * node ,int key);

void avl_pre_order(avl_node* node);

void print_pic(avl_node*& root);

#endif //DATA_STRUCTURE_AVL_H
