//
// Created by hotfoods on 2023/11/10.
//

#ifndef DATA_STRUCTURE_HFT_H
#define DATA_STRUCTURE_HFT_H
#include <iostream>
#include <algorithm>
#include <iomanip>


typedef struct HFT
{
    int weight;
    int parent, LTree, RTree;
}HFT, *PHFT;


void Select(PHFT HFT, int n, int &s1, int &s2)    //选取权值最小的两个结点
{
    for(int i = 1; i < n; i++){         //初始化s1，s1的双亲为0
        if(HFT[i].parent == 0){     /**  思考：为什么不是 i <= n  **/
            s1 = i;					//解答：因为我们第 2n-1  个元素的parent是0
            break;                          /**  思考：为什么要加上 break  **/
        }
    }

    for(int i = 1; i < n; i++){         //s1为权值最小的下标
        if(HFT[i].parent == 0 && HFT[s1].weight > HFT[i].weight)
            s1 = i;
    }

    for(int j = 1; j < n; j++){         //初始化s2，s2的双亲为0
        if(HFT[j].parent == 0 && j != s1){
            s2 = j;
            break;
        }
    }

    for(int j = 1; j < n; j++){         //s2为另一个权值最小的下标
        if(HFT[j].parent == 0 && HFT[s2].weight > HFT[j].weight && j != s1)
            s2 = j;
    }
}

void initHFT(PHFT &H, int n)
{
    if(n <= 1) return;
    int m = 2*n - 1;            //数组共2n - 1个元素
    H = new HFT[m + 1];	//0号单元未用，H[m]表示根节点
    for(int i = 1; i <= m; i++){
        H[i].parent = 0;
        H[i].LTree = 0;
        H[i].RTree = 0;
    }
    cout << "please input the weight of nodes:" << endl;
    for(int i = 1; i <= n; i++)
        cin >> H[i].weight;
    cout << endl;
    for(int i = n + 1; i <= m; i++)         //产生的新结点要放在从n+1开始，一直到2n-1的位置
    {
        int s1, s2;
        Select(H, i, s1, s2);
        H[s1].parent = i;
        H[s2].parent = i;   //相当于从表F中删除s1, s2
        H[i].LTree = s1;
        H[i].RTree = s2;
        H[i].weight = H[s1].weight + H[s2].weight;
    }
}

void showHFT(PHFT &H, int n)
{
    cout << "index  weight  parent  LTree  RTree" << endl;
    cout << left;     //左对齐输出
    int m = 2*n - 1;
    for(int i = 1; i <= m; i++){
        cout << setw(5) << i << "  ";                       /** 思考： 为什么是setw(5) 和 setw(6)   **/
        cout << setw(6) << H[i].weight << "  ";     // 解答：当后面紧跟着的输出字段长度小于n的时候，在该字段前面用空格补齐；当输出字段长度大于n时，全部整体输出
        cout << setw(6) << H[i].parent << "  ";
        cout << setw(6) << H[i].LTree << "  ";
        cout << setw(6) << H[i].RTree << "  " << endl;
    }
}

#endif //DATA_STRUCTURE_HFT_H
