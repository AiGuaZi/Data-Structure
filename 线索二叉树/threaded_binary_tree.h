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

//ȫ�ֱ���pre1



/*�����ʼ������������*/  //����ͷ�ڵ�
TBTree* init_TBTree();

/*��ʼ���ڵ�*/
void my_memset(TBTree* T);

/*����,�״������ʼֵ*/
bool pro_input_TBTree(TBTree** TB);

/*����������*/
void pro_order_traverse(TBTree* TB);

/*����������*/
void cen_order_threading(TBTree* TB);

/*����ͷ�ڵ������������*/
void head_node_cen_order_threading(TBTree* TB, TBTree* head);

/*������������������*/
void cen_order_thread_traverse(TBTree* TB);