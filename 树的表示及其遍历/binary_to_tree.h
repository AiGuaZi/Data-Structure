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

/*��ʼ��������*/
void init_BTree(BTree* T);

/*����������*/
void creat_BTree(BTree** T);

/*����������*/
void print_BTree_traverse(BTree* T);

/*�����ֵ���Ŀ*/
int cal_brother_count(BTree* T);

/*�����������ɭ��*/

void BTree_to_forest(BTree* BT, Tree** T, int* T_Size);


/*
* ���ܣ���������������Է��ѳ�������
* ԭ���Ӹ��ڵ�����������ҽڵ�ĸ���Ϊ�������ɷ��ѳ������ĸ���
*/
int cal_count_of_tree_from_binary_tree(BTree* BT);

/*�������������*/
void BTree_to_Tree(BTree* BT, Tree** T);