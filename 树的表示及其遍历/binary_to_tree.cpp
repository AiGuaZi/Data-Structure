#include"binary_to_tree.h"

/*初始化二叉树*/
void init_BTree(BTree* T) {

	if (T != NULL) return;

	T = NULL;
}

/*建立二叉树*/
void creat_BTree(BTree** T) {

	if (T == NULL) return;

	char temp_ch;
	cin >> temp_ch;

	if (temp_ch == '#') *T = NULL;
	else {

		*T = (BTree*)malloc(sizeof(BTree));
		if (*T == NULL) exit(-1);/*空间不足*/

		(*T)->date = temp_ch;
		creat_BTree(&(*T)->firstchild);
		creat_BTree(&(*T)->nextsibling);
	}
}

/*遍历二叉树*/
void print_BTree_traverse(BTree* T) {

	if (T == NULL) return;

	cout << T->date;
	print_BTree_traverse(T->firstchild);
	print_BTree_traverse(T->nextsibling);
}

/*计算兄弟数目*/
int cal_brother_count(BTree* T) {
	int count = 0;

	while (T) {
		count++;
		T = T->nextsibling;
	}

	return count;
}

int cal_count_of_tree_from_binary_tree(BTree* BT) {

	if (BT == NULL) return -1;

	int tree_count = 0;
	BTree* p = BT;
	
	while (p) {
		tree_count++;
		p = p->nextsibling;
	}

	return tree_count;
}

/*将二叉树变成森林*/
void BTree_to_forest(BTree* BT, Tree** T, int* T_Size) {
	
	if (BT == NULL || T != NULL) return;

	*T_Size = cal_count_of_tree_from_binary_tree(BT);

	if (*T_Size == -1) return;

	T = (Tree**)malloc(sizeof(Tree*) * (*T_Size));
	memset(T, NULL, sizeof(Tree*) * (*T_Size));
	if (T == NULL) return;

	BTree* p = BT;
	int i = 0;
	while (p) {
		*(T + i) = (Tree*)malloc(sizeof(Tree));
		(*(T + i))->date = p->date;
		BTree_to_Tree(p, (T + i));
		p = p->nextsibling;
		i++;
	}
	
}

void BTree_to_Tree(BTree* BT, Tree** T) {

	if (BT == NULL || *T == NULL) return;

	BTree* p = BT->firstchild;

	if (p) {

		int brother_count = cal_brother_count(p);

		(*T)->child = (Tree**)malloc(sizeof(Tree*) * brother_count);
		if ((*T)->child == NULL) return;

		int i = 0;
		while (p) {
			((*T)->child)[i] = (Tree*)malloc(sizeof(Tree));
			printf("%d", sizeof(((*T)->child)[i]));
			if (((*T)->child)[i] == NULL) return;

			((*T)->child)[i]->date = p->date;
			cout << "(*T)->child[" << i << "]->date = " << ((*T)->child)[i]->date << endl;
			((*T)->child)[i]->child = NULL;
			if (p->firstchild) {
				BTree_to_Tree(p, &(*T));
			}
			p = p->nextsibling;
			i++;
		}
	}
}

