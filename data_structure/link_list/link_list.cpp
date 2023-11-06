
#include "link_list.h"
using namespace std;
linklist_node * head;
loop_pre_l_node * l_p_tail;
loop_pre_l_node * l_p_head;

int add(int a, int b) {
	return a + b;
}

void create() {
	head = new linklist_node;
	head->next = NULL;
	cout<<"头节点内存地址：" << head << endl;
}

void insert() {
	int n;
	cout << "请输入插入的结点的数量:";
	cin >> n;
	int i = 1;
	while (i<=n)
	{
		cout << "<<第" << i << "个结点"<<endl;
		linklist_node * p = new linklist_node;
		cout << "输入该结点保存的值：";
		cin >> p->data;
		cout << "该结点的内存地址：" << p<<endl;
		p->next = head->next;
		head->next = p;
		i++;
	}
}

void show() {
	linklist_node* p = head->next;
	while (p != NULL) {
		cout << "|data:" << p->data << " add:" << p <<" next:"<<p->next << "|·|--> \n";
		p = p->next;
	}
	cout << "\n" << endl;
}

void create_loop_l() {
	cout << "  >>  创建头结点";
	l_p_head = new loop_pre_l_node;
	l_p_head->next = NULL;
	l_p_tail = l_p_head;
	cout << "头结点地址：" << l_p_head<<endl;
}

void insert_loop_l() {
	int n;
	cout << "创建多少个个结点？：";
	cin >> n;
	int i = 1;
	while (i <= n) {
		loop_pre_l_node* p = new loop_pre_l_node;
		cout << "  <<  第" << i << "个结点" << endl;
		cout << "输入该结点保存的值：";
		cin >> p->data;
		l_p_tail->next = p;
		p->pre = l_p_tail;
		p->next = l_p_head->next;
		l_p_tail = p;
		i++;
	}
	cout << endl;
}

void show_loop_l() {
	loop_pre_l_node* p = l_p_head->next;
	cout << " >>  | head node |";
	while (p != NULL) {
		cout <<"<--|·|" << "|data:" << p->data << " pre:" << p->pre << " add:" << p << " next:" << p->next << "|·|--> \n";
		if (p == l_p_tail)
			break;
		p = p->next;
	}
}


