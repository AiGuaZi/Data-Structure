#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

#define ERROR -1
#define NO_MEMORY -18
#define QUEUE_LENGTH 20

typedef enum BAL_TYPE {			//ƽ������
	LL = 1,LR,RL,RR
}BAL_TYPE;

typedef int nodeType;

typedef struct BST_NODE {
	nodeType date;
	int bal_factor;				//ƽ������
	BST_NODE* left, * right;
}BST_NODE;

/*��ʼ��*/
void BST_Init(BST_NODE* BST);

/*��������������*/
void creat_BST(BST_NODE** BST, int node_count);

/*�������*/
void creat_Node(BST_NODE**temp , nodeType node_date);

/*����������*/
void traverse_BST(BST_NODE* BST, void(workFunction(BST_NODE* BST)));

/*�������*/
void print_node(BST_NODE* node);

/*����Ԫ��*/
bool search_BST(BST_NODE* BST, int search_elem);

/*����Ԫ��*/
bool insert_elem_1(BST_NODE* BST, int insert_elem);
/*����Ԫ��*/
void insert_elem_2(BST_NODE** BST, int insert_elem);

/*ɾ��Ԫ��*/
void delete_elem(BST_NODE* BST, int del_elem);
/*�ͷŽ��*/
void free_node(BST_NODE** node);
/*Ѱ�����������ֵ*/
BST_NODE* find_left_max(BST_NODE* BST);
/*����ƽ�����ӵ�ֵ*/
int cal_bal_factor(BST_NODE* BST);
/*ƽ�⻯*/
void balance_BST(BST_NODE* BST);
/*�������Ĳ�α���*/
void traverse_Lev(BST_NODE* BST, void workFunction(BST_NODE* elem));
/*������������*/
void up_queue(int* i_que, int que_length);
/*��������������ƽ��Ľڵ�*/
BST_NODE* search_no_bal(BST_NODE* BST);
/*����ȡ�������ڵ���д�С����*/
void sort_node(BST_NODE** min, BST_NODE** mid, BST_NODE** max);