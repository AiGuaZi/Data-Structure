#include"binary_tree.h"

bool creat_BTree(BTree** T) {

	//判断T是否存在指向
	if (*T != NULL) return false;

	//建树
	*T = (BTree*)malloc(sizeof(BTree) * MAX_BT_SIZE);
	if (*T == NULL) return false;

	//初始化
	memset(*T, 0, MAX_BT_SIZE * sizeof(int));

	/*注意：写实现，所以初始化，将结点内容，表示为结点编号*/
	for (int i = 0; i < MAX_BT_SIZE; i++) {
		(*T)[i] = i + 1;
	}

	return true;
}

void pre_order_traverse(BTree* T,int now_xb /*当前下标*/) {

	if (T == NULL || now_xb > MAX_BT_SIZE - 1) return;

	cout << " " << T[now_xb];

	//遍历左子树
	pre_order_traverse(T, now_xb * 2 + 1);
	//遍历右子树
	pre_order_traverse(T, now_xb * 2 + 2);
}

void cen_order_traverse(BTree* T, int now_xb) {

	if (T == NULL || now_xb > MAX_BT_SIZE - 1) return;

	//遍历左子树
	cen_order_traverse(T, now_xb * 2 + 1);

	cout << " " << T[now_xb];

	//遍历右子树
	cen_order_traverse(T, now_xb * 2 + 2);
}

void pos_order_traverse(BTree* T, int now_xb){

	if (T == NULL || now_xb > MAX_BT_SIZE - 1) return;

	//遍历左子树
	pos_order_traverse(T, now_xb * 2 + 1);
	//遍历右子树
	pos_order_traverse(T, now_xb * 2 + 2);

	cout << " " << T[now_xb];
}