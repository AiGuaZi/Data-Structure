#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

/*˳����ȫ������*/

#define MAX_BT_SIZE 10

typedef int BTree; //��int�����鶨����һ��BTree��

/*����һ��������������ռ�,����ɳ�ʼ��*/
bool creat_BTree(BTree **T);

/*�������*/
void pre_order_traverse(BTree* T, int depth);

/*�������*/
void cen_order_traverse(BTree* T, int depth);

/*�������*/
void pos_order_traverse(BTree* T, int depth);