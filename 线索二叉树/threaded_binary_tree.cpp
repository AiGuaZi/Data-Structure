
#pragma once
#include"threaded_binary_tree.h"

void my_memset(TBTree* T) {
	T->date = 0;
	T->left = NULL;
	T->ltag = 0;
	T->right = NULL;
	T->rtag = 0;
}

TBTree* init_TBTree() {

	TBTree* head = (TBTree*)malloc(sizeof(TBTree));
	if (head == NULL) exit(-1);/*�ռ䲻��*/
	my_memset(head);

	return head;
}

bool pro_input_TBTree(TBTree** TB) {/*����ͷ���*/ 

	//�ж������������Ƿ��Լ�����ָ��
	if (*TB != NULL)return false;

	TBTree** p = TB;

	char temp_ch = 0;
	cin >> temp_ch;

	if (temp_ch == '#') {
		*TB = NULL;
	}
	else {
		//����ռ�
		*TB = (TBTree*)malloc(sizeof(TBTree));
		if (*TB == NULL) exit(-1);/*�ռ䲻��*/
		my_memset(*TB);

		//����ݹ齨������������
		pro_input_TBTree(&(*TB)->left);
		(*TB)->date = temp_ch;
		pro_input_TBTree(&(*TB)->right);
	}
	return true;
}

void pro_order_traverse(TBTree* TB) {

	if (TB == NULL) {
		cout << "#";
		return;
	}

	pro_order_traverse(TB->left);
	cout << TB->date;
	pro_order_traverse(TB->right);
}





void cen_order_thread_traverse(TBTree* TB) {

	TBTree* p = TB->left;
	while (p != TB) {
		while (p->ltag == 0) p = p->left;
		cout << p->date;
		while (p->rtag == 1 && p->right != TB) {
			p = p->right;
			cout << p->date;
		}
		p = p->right;
	}
}