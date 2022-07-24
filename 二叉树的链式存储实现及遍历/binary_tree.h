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

/*初始化结点值*/
void init_node(BTree* t);

/*创建一个二叉树，分配空间,并完成初始化*/
bool creat_BTree(BTree** T);//先序

/*中序建立二叉树*/
void creat_cen_order_BTree(BTree** T);

/*先序遍历*/
void pre_order_traverse(BTree* T);

/*先序非递归遍历*/
void pre_order_traverse_no_recursion(BTree* T);

/*中序遍历*/
void cen_order_traverse(BTree* T);

/*中序非递归遍历*/
void cen_order_traverse_no_recursion(BTree* T);

/*后序遍历*/
void pos_order_traverse(BTree* T);

/*后序非递归遍历*/
void pos_order_traverse_no_recursion(BTree* T);

/*层次遍历算法*/
void level_prder_traverse(BTree* T);

/*复制二叉树*/
void copy_of_tree(BTree* T, BTree** new_tree);

/*计算二叉树的深度*/
/** 原理
* 递归计算 先计算左边的深度，再计算右边的深度，如果左边的深度大于右边的深度，
* 则返回左边的深度加上1(本层深度），反之返回右边的深度加上1（本层深度）  
*/
int calculation_tree_depth(BTree* T);

/*计算结点数*/
/* 原理
* 递归计算，先计算左子树的结点数，然后计算右子树的结点数
* 将左子树和右子树的结点个数加起来，返回左右子树结点个数
* 的总和加1（本身结点个数）
*/
int calculation_tree_node(BTree* T);

/*计算叶子结点个数*/
/* 原理
*  递归计算，先判断是否为空结点，是则返回0，不是则判断当前结点是否为叶子结点，
* 若为叶子结点，返回1，若不为叶子结点，则分别计算这个结点的左孩子的叶子结点数和
* 右孩子的叶子结点数，然后返回左右孩子叶子结点个数。
*/
int calculation_leaf_node(BTree* T);

/*中序建立二叉树，线索化*/
void cen_order_threaded(BTree* TB, BTree* prev);