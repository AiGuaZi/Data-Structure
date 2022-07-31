#pragma once

#include<iostream>
#include<stdlib.h>
using namespace std;

typedef char TreeTypeElem;

typedef struct BTree {
	TreeTypeElem date;
	BTree* firstchild, * nextsibling;
}BTree;

typedef struct Tree {
	TreeTypeElem date;
	Tree** child;
}Tree;

/*初始化二叉树*/
void init_BTree(BTree* T);

/*建立二叉树*/
void creat_BTree(BTree** T);

/*遍历二叉树*/
void print_BTree_traverse(BTree* T);

/*计算兄弟数目*/
int cal_brother_count(BTree* T);

/*将二叉树变成森林*/

void BTree_to_forest(BTree* BT, Tree** T, int* T_Size);


/*
* 功能：计算二叉树，可以分裂出几棵树
* 原理：从根节点出发，含有右节点的个数为二叉树可分裂出的树的个数
*/
int cal_count_of_tree_from_binary_tree(BTree* BT);

/*将二叉树变成树*/
void BTree_to_Tree(BTree* BT, Tree** T);