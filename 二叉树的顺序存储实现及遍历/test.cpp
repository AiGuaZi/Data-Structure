#include"binary_tree.h"

int main() {
	BTree *bt1 = NULL;
	//建树
	creat_BTree(&bt1);

	//先序遍历
	cout << "先序遍历" << endl;
	pre_order_traverse(bt1, 0);

	cout << endl;

	//中序遍历
	cout << "中序遍历" << endl;
	cen_order_traverse(bt1, 0);

	cout << endl;

	//后序遍历
	cout << "后序遍历" << endl;
	pos_order_traverse(bt1, 0);

}