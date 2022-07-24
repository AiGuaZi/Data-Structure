#include"binary_tree.h"

void cen_order_traverse2(BTree* T) {

	if (T == NULL)return;

	cen_order_traverse2(T->left);
	if (T->date == 3) {
		cout << " " << T->date;
		cout << " " << T->right->date;
	}
	cen_order_traverse2(T->right);
}

int main() {
	BTree *bt1 = NULL;
	creat_BTree(&bt1);
	//123##4##56#7##89###

	cout << "����" << endl;
	//�ݹ��������
	cen_order_traverse(bt1);
	cout << endl;
	//�ǵݹ��������
	cen_order_traverse_no_recursion(bt1);
	cout << endl;

	cout << "����" << endl;
	//�ݹ��������
	pre_order_traverse(bt1);
	cout << endl;
	//�ǵݹ��������
	pre_order_traverse_no_recursion(bt1);
	cout << endl;

	cout << "����" << endl;
	//�ݹ��������
	pos_order_traverse(bt1);
	cout << endl;
	//�ǵݹ��������  /*����bug����ʱ�޷�����*/
	//pos_order_traverse_no_recursion(bt1);

	cout << "���" << endl;
	level_prder_traverse(bt1);
	cout << endl;

	cout << "����" << endl;
	BTree* bt2 = NULL;
	copy_of_tree(bt1, &bt2);
	cout << "�������bt2" << endl;
	pre_order_traverse(bt2);
	cout << endl;

	cout << "���" << endl;
	cout << "���Ϊ��" << calculation_tree_depth(bt1) << endl;

	cout << "�����" << endl;
	cout << "�������" << calculation_tree_node(bt1) << endl;

	cout << "Ҷ�ӽ����" << endl;
	cout << "Ҷ�ӽ������" << calculation_leaf_node(bt1) << endl;

	cout << "-------------------------------------------------" << endl;

	cout << "������������" << endl;
	BTree* cen_bt = NULL;
	creat_cen_order_BTree(&cen_bt);
	//cen_order_traverse(cen_bt);
	//������
	cen_order_threaded(cen_bt, cen_bt);
	cen_order_traverse2(cen_bt);
}