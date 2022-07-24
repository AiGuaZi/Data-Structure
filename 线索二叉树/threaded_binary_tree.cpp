
#include"threaded_binary_tree.h"

TBTree* init_TBTree() {

	TBTree* head = (TBTree*)malloc(sizeof(TBTree));
	if (head == NULL) exit(-1);/*空间不足*/
	head->date = 0;
	head->left = NULL;
	head->ltag = 0;
	head->right = NULL;
	head->rtag = 0;

	return head;
}

bool pre_input_TBTree(TBTree** TB) {/*传入头结点*/

	//判断线索二叉树是否以及存在指向
	if (TB != NULL)return false;

	TBTree** p = TB;

	char temp_ch = 0;
	cin >> temp_ch;

	if (temp_ch) {
		*TB = NULL;
		return false;
	}
	else {

		(*TB)->left = (TBTree*)malloc(sizeof(TBTree));
		if ((*TB)->left == NULL) exit(-1);/*空间不足*/
		(*TB)->left->date = temp_ch;
		(*TB)->left->left = NULL;
		(*TB)->left->ltag = 0;
		(*TB)->left->right = NULL;
		(*TB)->left->rtag = 0;

		if
	}
}