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

/*�����ʼ������������*/  //����ͷ�ڵ�
TBTree* init_TBTree();

/*����,�״������ʼֵ*/
bool pre_input_TBTree(TBTree** TB);