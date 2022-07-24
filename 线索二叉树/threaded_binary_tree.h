#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef int TreeTypeElem;

typedef struct TBTree {
	TreeTypeElem date;
	int ltag, rtag;
	TBTree* left, * right;
}TBTree;

/*先序初始化线索二叉树*/  //建立头节点
TBTree* init_TBTree();

/*先序,首次输入初始值*/
bool pre_input_TBTree(TBTree** TB);