#pragma once
#include<iostream>
#include<stdlib.h>

using namespace std;

#define NULL_NODE 1

typedef int TreeElemType;

typedef struct BTree {
	TreeElemType date;
	int ltag, rtag;
	BTree* left;
	BTree* right;
}BTree;

/*��ʼ�����ֵ*/
void init_node(BTree* t);

/*����һ��������������ռ�,����ɳ�ʼ��*/
bool creat_BTree(BTree** T);//����

/*������������*/
void creat_cen_order_BTree(BTree** T);

/*�������*/
void pre_order_traverse(BTree* T);

/*����ǵݹ����*/
void pre_order_traverse_no_recursion(BTree* T);

/*�������*/
void cen_order_traverse(BTree* T);

/*����ǵݹ����*/
void cen_order_traverse_no_recursion(BTree* T);

/*�������*/
void pos_order_traverse(BTree* T);

/*����ǵݹ����*/
void pos_order_traverse_no_recursion(BTree* T);

/*��α����㷨*/
void level_prder_traverse(BTree* T);

/*���ƶ�����*/
void copy_of_tree(BTree* T, BTree** new_tree);

/*��������������*/
/** ԭ��
* �ݹ���� �ȼ�����ߵ���ȣ��ټ����ұߵ���ȣ������ߵ���ȴ����ұߵ���ȣ�
* �򷵻���ߵ���ȼ���1(������ȣ�����֮�����ұߵ���ȼ���1��������ȣ�  
*/
int calculation_tree_depth(BTree* T);

/*��������*/
/* ԭ��
* �ݹ���㣬�ȼ����������Ľ������Ȼ������������Ľ����
* �����������������Ľ�������������������������������
* ���ܺͼ�1�������������
*/
int calculation_tree_node(BTree* T);

/*����Ҷ�ӽ�����*/
/* ԭ��
*  �ݹ���㣬���ж��Ƿ�Ϊ�ս�㣬���򷵻�0���������жϵ�ǰ����Ƿ�ΪҶ�ӽ�㣬
* ��ΪҶ�ӽ�㣬����1������ΪҶ�ӽ�㣬��ֱ��������������ӵ�Ҷ�ӽ������
* �Һ��ӵ�Ҷ�ӽ������Ȼ�󷵻����Һ���Ҷ�ӽ�������
*/
int calculation_leaf_node(BTree* T);

/*��������������������*/
void cen_order_threaded(BTree* TB, BTree* prev);