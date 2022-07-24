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

	cout << "中序" << endl;
	//递归中序遍历
	cen_order_traverse(bt1);
	cout << endl;
	//非递归中序遍历
	cen_order_traverse_no_recursion(bt1);
	cout << endl;

	cout << "先序" << endl;
	//递归先序遍历
	pre_order_traverse(bt1);
	cout << endl;
	//非递归先序遍历
	pre_order_traverse_no_recursion(bt1);
	cout << endl;

	cout << "后序" << endl;
	//递归先序遍历
	pos_order_traverse(bt1);
	cout << endl;
	//非递归先序遍历  /*存在bug，暂时无法调试*/
	//pos_order_traverse_no_recursion(bt1);

	cout << "层次" << endl;
	level_prder_traverse(bt1);
	cout << endl;

	cout << "复制" << endl;
	BTree* bt2 = NULL;
	copy_of_tree(bt1, &bt2);
	cout << "先序遍历bt2" << endl;
	pre_order_traverse(bt2);
	cout << endl;

	cout << "深度" << endl;
	cout << "深度为：" << calculation_tree_depth(bt1) << endl;

	cout << "结点数" << endl;
	cout << "结点数：" << calculation_tree_node(bt1) << endl;

	cout << "叶子结点数" << endl;
	cout << "叶子结点数：" << calculation_leaf_node(bt1) << endl;

	cout << "-------------------------------------------------" << endl;

	cout << "中序建立二叉树" << endl;
	BTree* cen_bt = NULL;
	creat_cen_order_BTree(&cen_bt);
	//cen_order_traverse(cen_bt);
	//线索化
	cen_order_threaded(cen_bt, cen_bt);
	cen_order_traverse2(cen_bt);
}