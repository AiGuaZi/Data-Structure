#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

/*顺序完全二叉树*/

#define MAX_BT_SIZE 10

typedef int BTree; //以int型数组定义了一个BTree树

/*创建一个二叉树，分配空间,并完成初始化*/
bool creat_BTree(BTree **T);

/*先序遍历*/
void pre_order_traverse(BTree* T, int depth);

/*中序遍历*/
void cen_order_traverse(BTree* T, int depth);

/*后序遍历*/
void pos_order_traverse(BTree* T, int depth);