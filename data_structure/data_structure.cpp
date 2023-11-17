// data_structure.cpp: 定义应用程序的入口点。
//

#include "data_structure.h"

using namespace std;

int main()
{
    cout<<"hello ";
	//int a = 1, b = 2;
	//cout << add(a,b) << endl;
	/**
	create();
	insert();
	show();

	create_loop_l();
	insert_loop_l();
	show_loop_l();
	*/

	/**
	init_arr_stack();
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0, 100);
	for (int i = 0; i < 5; i++)
	{
		int random = u(e);
		cout << "将第" << i + 1 << "个随机数" << random << "压入到栈中" << endl;
		push(random);
	}
	show_arr_stack();
	init_l_stack();
	for (int i = 0; i < 10; i++)
	{
		int random = u(e);
		cout << "将第" << i + 1 << "个随机数" << random << "压入到链栈中" << endl;
		l_push(random);
	}
	show_l_stack();
	**/

	/**
	init_loop_q();
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0, 100);
	for (int i = 0; i < 11; i++)
	{
		int random = u(e);
		cout << "将第" << i + 1 << "个随机数" << random << "入队" << endl;
		enq(random);
	}
	show_loop_q();
	**/
//	default_random_engine e;
//	uniform_int_distribution<unsigned> u(0, 100);
//	for (int i = 0; i < 11; i++)
//	{
//		int random = u(e);
//		cout << "将第" << i + 1 << "个随机数" << random << "插入搜索二叉树" << endl;
//		insert_bin_tree(random);
//	}

//	show_bin_tree();
//    cout << "Preorder traversal of the constructed AVL tree is \n";
    avl_node *root = NULL;

    /* 测试，最终树结构应该如下图所示：
            30
           /  \
         20   40
        /  \     \
       10  25    50
    */
    root = avl_insert(root, 10);
    root = avl_insert(root, 20);
    root = avl_insert(root, 30);
    root = avl_insert(root, 40);
    root = avl_insert(root, 50);
    root = avl_insert(root, 25);

    cout << "Preorder traversal of the constructed AVL tree is \n";
    avl_pre_order(root);

    print_pic(root);

	return 0;
}
