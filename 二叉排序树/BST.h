#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

#define ERROR -1
#define NO_MEMORY -18
#define QUEUE_LENGTH 20

typedef enum BAL_TYPE {			//平衡类型
	LL = 1,LR,RL,RR
}BAL_TYPE;

typedef int nodeType;

typedef struct BST_NODE {
	nodeType date;
	int bal_factor;				//平衡因子
	BST_NODE* left, * right;
}BST_NODE;

/*初始化*/
void BST_Init(BST_NODE* BST);

/*创建二叉排序树*/
void creat_BST(BST_NODE** BST, int node_count);

/*创建结点*/
void creat_Node(BST_NODE**temp , nodeType node_date);

/*遍历二叉树*/
void traverse_BST(BST_NODE* BST, void(workFunction(BST_NODE* BST)));

/*输出函数*/
void print_node(BST_NODE* node);

/*查找元素*/
bool search_BST(BST_NODE* BST, int search_elem);

/*插入元素*/
bool insert_elem_1(BST_NODE* BST, int insert_elem);
/*插入元素*/
void insert_elem_2(BST_NODE** BST, int insert_elem);

/*删除元素*/
void delete_elem(BST_NODE* BST, int del_elem);
/*释放结点*/
void free_node(BST_NODE** node);
/*寻找左子树最大值*/
BST_NODE* find_left_max(BST_NODE* BST);
/*计算平衡因子的值*/
int cal_bal_factor(BST_NODE* BST);
/*平衡化*/
void balance_BST(BST_NODE* BST);
/*二叉树的层次遍历*/
void traverse_Lev(BST_NODE* BST, void workFunction(BST_NODE* elem));
/*队列自增函数*/
void up_queue(int* i_que, int que_length);
/*遍历搜索不满足平衡的节点*/
BST_NODE* search_no_bal(BST_NODE* BST);
/*将获取的三个节点进行大小排序*/
void sort_node(BST_NODE** min, BST_NODE** mid, BST_NODE** max);