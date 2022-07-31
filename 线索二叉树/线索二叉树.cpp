#pragma once
#include"threaded_binary_tree.h"

TBTree* pre1 = (TBTree*)malloc(sizeof(TBTree));
void cen_order_threading(TBTree* TB) {

	if (TB) {
		//cout << "TB->date = " << TB->date << endl;
		cen_order_threading(TB->left);
		if (!TB->left) {
			TB->ltag = 1;
			TB->left = pre1;
		}
		if (!TB->right) {
			pre1->rtag = 1;
			pre1->right = TB;
		}
		pre1 = TB;
		//cout << "pre = " << pre1->date << endl;
		cen_order_threading(TB->right);
	}
}

void head_node_cen_order_threading(TBTree* TB, TBTree* head) {

	if (head == NULL) return;

	head->ltag = 0;
	head->rtag = NULL_NODE;
	head->right = head;

	if (!TB) head->left = head;
	else {
		head->left = TB;
		pre1 = head;
		cen_order_threading(TB);
		pre1->right = head;
		pre1->rtag = NULL_NODE;
		head->right = pre1;
	}
}

int main() {

	//建立带节点的二叉树的头节点
	TBTree* TB1 = (TBTree*)malloc(sizeof(TBTree));
	if (TB1 == NULL) exit(-1);
	my_memset(TB1);
	TB1->date = '1';

	//测试输入是否正确 ABE##FG###CH#I###
	pro_input_TBTree(&TB1->left);//头节点的左指针才是树的根节点
	pro_order_traverse(TB1->left);
	cout << endl;
	//pre1 = NULL;
	cen_order_threading(TB1->left);
	//head_node_cen_order_threading(TB1->left, TB1);
	//cen_order_thread_traverse(TB1);
	return 0;
}