#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

#define NULL_NODE 1

typedef char TreeTypeElem;

typedef struct TBTree {
	TreeTypeElem date;
	int ltag, rtag;
	TBTree* left, * right;
}TBTree;

//全局变量pre1



/*先序初始化线索二叉树*/  //建立头节点
TBTree* init_TBTree();

/*初始化节点*/
void my_memset(TBTree* T);

/*中序,首次输入初始值*/
bool pro_input_TBTree(TBTree** TB);

/*中序遍历结果*/
void pro_order_traverse(TBTree* TB);

/*中序线索化*/
void cen_order_threading(TBTree* TB);

/*代表头节点的中序线索化*/
void head_node_cen_order_threading(TBTree* TB, TBTree* head);

/*遍历中序线索二叉树*/
void cen_order_thread_traverse(TBTree* TB);