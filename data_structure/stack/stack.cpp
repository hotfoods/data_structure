#include "stack.h"
using namespace std;
arr_stack * a_s;
link_stack* _bottom;
link_stack* _top;

void init_arr_stack() {
	a_s = new arr_stack;
	for (int i = 0; i < 10; i++)
	{
		a_s->data[i] = 0;
	}
	a_s->length = 0;
	a_s->top = 0;
}

void pop(){
	if (a_s->length == 0) {
		cout << "Õ»¿Õ" << endl;
	}
	else
	{
		cout <<"ÍÆ³ö£º"<<a_s->data[a_s->top]<<endl;
		a_s->data[a_s->top] = 0;
		a_s->top--;
	}
}

void push(int data) {
	if (a_s->length == 10) {
		cout << "Õ»ÂúÁË" << endl;
	}
	else {
		a_s->data[a_s->top++] = data;
		cout <<"Õ»¶¥£º"<< a_s->top;
		a_s->length++;
		cout <<"³¤¶È£º"<< a_s->length;
	}
	cout << "\n" << endl;
}

void top() {
	if (a_s->length == 0) {
		cout << "Õ»¿Õ" << endl;
	}
	else
	{
		cout << a_s->data[a_s->top]<<endl;
	}
}

void show_arr_stack() {
	for (int i = (a_s->length-1); i >= 0; i--)
	{
		cout << a_s->data[i] << "  ";
	}
	cout << endl;
}


void init_l_stack() {
	_bottom = new link_stack;
	_top =_bottom;
	_top->length = 0;
}

void l_push(int data) {
	link_stack* p = new link_stack;
	p->data = data;
	p->pre = _top;
	_top = p;
	_top->length++;
}

bool l_isempty() {
	if (_top->length == 0)
		return true;
	return false;
}


void l_pop() {
	if (!l_isempty())
	{
		cout << _top->data<<"ÍÆ³öÕ»";
		link_stack *temp = _top;
		_top = _top->pre;
		_top->length--;
		free(temp);
	}
	else {
		cout << "Õ»¿Õ";
	}
}

void l_top() {
	if (!l_isempty())
	{
		cout<<"top:" << _top->data;
	}
	else {
		cout << "Õ»¿Õ";
	}
}

void show_l_stack() {
	link_stack* p = _top;
	while (p!=_bottom)
	{
		cout << p->data << "   ";
		p = p->pre;
	}
}