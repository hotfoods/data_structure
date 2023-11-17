//
// Created by hotfoods on 2023/11/17.
//

#include "avl.h"
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}


int  tree_height(avl_node* node){
        if(node==NULL)
            return 0;
        return 1+ max(tree_height(node->right), tree_height(node->left));
}


int get_balance_facter(avl_node * node){
    if(node==NULL)
        return 0;
    return tree_height(node->left)- tree_height(node->right);
}


avl_node * new_avl_node(int key){
    avl_node* node =new avl_node;
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=0;
    return  node;
}

avl_node * right_rotate(avl_node* y){
      /* 树结构示意图：
                   y
                  / \
                 x   0
                / \
               O   0
       */
      avl_node * x=y->left;
      avl_node * x_r=x->right;
      x->right=y;
      y->left=x_r;
      x->height= tree_height(x);
      y->height= tree_height(y);
      return x;
}

avl_node * left_rotate(avl_node* y){
      /* 树结构示意图：
              y
             / \
            0   x
               / \
              0   O
     */
      avl_node * x=y->right;
      avl_node * x_l=x->left;
      x->left=y;
      y->right=x_l;
      x->height= tree_height(x);
      y->height= tree_height(y);
      return x;
}


avl_node * avl_insert(avl_node * node ,int key){
    //bst递归插入
    if(node==NULL)
        return new_avl_node(key);
    if (key<node->key)
        node->left= avl_insert(node->left,key);
    if (key>node->key)
        node->right= avl_insert(node->right,key);
    else
        return node;

    node->height= tree_height(node);

    int bf= get_balance_facter(node);

    if(bf>1&& key<node->left->key)
        return right_rotate(node);

    if (bf<-1&& key>node->right->key)
        return left_rotate(node);
    if (bf>1&& key>node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    if (bf<-1&& key<node->right->key)   {
        node->right= right_rotate(node->right);
        return left_rotate(node);
    }
    return node;
}

void avl_pre_order(avl_node* node){
    if (node != NULL)
    {
        cout<< node->key<<"  ";
        avl_pre_order(node->left);
        avl_pre_order(node->right);
    }
}


//打印一棵满二叉树，只能打印满二叉树，节点数目最好不要超过10
void print_pic(avl_node*& root) {
    //存放打印的二叉树
    char str[10][100] = {};
    queue<avl_node*> q;
    int h = tree_height(root);
    q.push(root);
    int index = 0;
    while (!q.empty()) {
        int size = q.size();
        //存放每一层的节点
        vector<char> list;
        for (int i = 0; i < size; i++) {
            avl_node* temp = q.front();
            q.pop();
            list.push_back(temp->key);
            //cout << temp->info;
            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            if (temp->right != nullptr) {
                q.push(temp->right);
            }
        }
        bool flag = true;
        int j = 0;
        //打印前面部分空白
        while (j <= 2*h-1-index) {
            str[index][j] = ' ';
            j++;

        }
        //保持第一行居中
        if (index == 0) {
            for (int m = 0; m < h - 2; m++) {
                str[index][j++] = ' ';
            }
        }

        for (int k = 0; k < list.size(); k++) {
            //如果是一层最后一个节点
            if (k == list.size() - 1) {
                str[index][j++] = list[k];
            }
            else {
                //相邻左右子节点
                if (k % 2 == 0) {
                    str[index][j++] = list[k];
                    for (int l = 0; l < 3 + 2 * (h - index/2-1); l++) {
                        str[index][j++] = ' ';
                    }
                }
                else {
                    str[index][j++] = list[k];
                    str[index][j++] = ' ';
                }
            }
        }

        index+=2;
        //cout << endl;
    }
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 1) {
            for (int j = 0; j < 100; j++) {
                str[i][j] = ' ';
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < 100; j++) {
                if (str[i][j] - '0' >= 0 && str[i][j] - '0' <= 9 && i < 2*h -2) {
                    str[i + 1][j - 1] = '/';
                    str[i + 1][j + 1] = '\\';
                }

            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 100; j++) {
            cout << str[i][j];
        }
        cout << endl;
    }
}
