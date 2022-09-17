#include"BST.h"

int main() {

	BST_NODE* BST = NULL;
	BST_Init(BST);

	cout << "请输入结点个数:";
	int node_count = 0;
	cin >> node_count;
	creat_BST(&BST, node_count);

	/*cout << search_BST(BST, 90) << endl;*/


	//cout << "非递归:"<< endl << "请输入插入的元素:";
	//int elem_1 = 0;
	//cin >> elem_1;
	//insert_elem_1(BST, elem_1);
	//traverse_BST(BST, print_node);
	//cout << endl;
	//cout << "递归:" << endl << "请输入插入的元素:";
	//int elem_2 = 0;
	//cin >> elem_2;
	//insert_elem_2(&BST, elem_2);
	//traverse_BST(BST,print_node);

	////删除节点
	//cout << endl;
	//cout << "删除节点:" << endl;
	//cout << "请输入要删除的节点:";
	//int del_elem = 0;
	//cin >> del_elem;
	//delete_elem(BST,del_elem);
	//traverse_BST(BST, print_node);

	cout << endl;
	traverse_BST(BST, print_node);
	cout << endl;
	traverse_Lev(BST, print_node);
	/*cout << endl << "测试计算平衡因子" << endl;
	cal_bal_factor(BST);
	traverse_BST(BST, print_node);*/


	return 0;
}

/*
10
45 12 53 3 37 100 24 61 90 78
*/