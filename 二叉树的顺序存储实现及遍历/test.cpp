#include"binary_tree.h"

int main() {
	BTree *bt1 = NULL;
	//����
	creat_BTree(&bt1);

	//�������
	cout << "�������" << endl;
	pre_order_traverse(bt1, 0);

	cout << endl;

	//�������
	cout << "�������" << endl;
	cen_order_traverse(bt1, 0);

	cout << endl;

	//�������
	cout << "�������" << endl;
	pos_order_traverse(bt1, 0);

}