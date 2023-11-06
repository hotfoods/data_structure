#include "binary_tree.h"
using namespace std;
binary_tree* root;

void insert_bin_tree(int data) {
	if (root==NULL)
	{
		root = new binary_tree;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}
	else {
		binary_tree* node = new binary_tree;
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		binary_tree* cur = get_insert_pos(root, data);
		if (cur->data > data)
			cur->right = node;
		else
			cur->left = node;
	}
}


binary_tree * get_insert_pos(binary_tree * node,int data) {
	if (node->data > data) {
		if (node->right == NULL)
			return node;
		else
			get_insert_pos(node->right, data);
	}
	else {
		if (node->left == NULL)
			return node;
		else
			get_insert_pos(node->left, data);
	}
}

void show_bin_tree() {
	if (root==NULL)
	{
		cout << "该树为空";
	}
	else {
		mid_show_bin_tree(root);
		level_show_bin_tree();
	}
}

void mid_show_bin_tree(binary_tree * node) {
	if (node == NULL)
		return;
	mid_show_bin_tree(node->left);
	cout << "当前结点：" << node->data<<" "<<endl;
	mid_show_bin_tree(node->right);
}


bool is_power(int a) {
	for (int i = 0; i < 10; i++)
	{
		if (pow(2, i)-1 == a)
			return true;
	}
	return false;
}

void level_show_bin_tree() {
	queue<binary_tree*> q;
	q.push(root);
	while (!q.empty()) {
		cout << setw(5);
		binary_tree* tmp = q.front();
		string l, r;
		q.pop();
		if (tmp == NULL) 
			continue;
		else{
			(tmp->left == NULL) ? l = "NULL" : l += to_string(tmp->left->data);
			(tmp->right == NULL) ? r = "NULL" : r += to_string(tmp->right->data);
			cout << "|data：" << tmp->data << "|l:" << l << "|r:" << r << "|    ";
			q.push(tmp->left);
			q.push(tmp->right);
		}
		cout << "\n" << endl;
	}
}