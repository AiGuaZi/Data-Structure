#include"BST.h"

int main() {

	BST_NODE* BST = NULL;
	BST_Init(BST);

	cout << "�����������:";
	int node_count = 0;
	cin >> node_count;
	creat_BST(&BST, node_count);

	/*cout << search_BST(BST, 90) << endl;*/


	//cout << "�ǵݹ�:"<< endl << "����������Ԫ��:";
	//int elem_1 = 0;
	//cin >> elem_1;
	//insert_elem_1(BST, elem_1);
	//traverse_BST(BST, print_node);
	//cout << endl;
	//cout << "�ݹ�:" << endl << "����������Ԫ��:";
	//int elem_2 = 0;
	//cin >> elem_2;
	//insert_elem_2(&BST, elem_2);
	//traverse_BST(BST,print_node);

	////ɾ���ڵ�
	//cout << endl;
	//cout << "ɾ���ڵ�:" << endl;
	//cout << "������Ҫɾ���Ľڵ�:";
	//int del_elem = 0;
	//cin >> del_elem;
	//delete_elem(BST,del_elem);
	//traverse_BST(BST, print_node);

	cout << endl;
	traverse_BST(BST, print_node);
	cout << endl;
	traverse_Lev(BST, print_node);
	/*cout << endl << "���Լ���ƽ������" << endl;
	cal_bal_factor(BST);
	traverse_BST(BST, print_node);*/


	return 0;
}

/*
10
45 12 53 3 37 100 24 61 90 78
*/