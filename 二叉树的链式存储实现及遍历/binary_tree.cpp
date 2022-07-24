#include"binary_tree.h"

bool creat_BTree(BTree** T) {

	if (*T != NULL) return false;

	//输入结点元素
	char ch_elem;
	cin >> ch_elem;
	
	//判断输入为空元素
	if (ch_elem == '#') {
		*T = NULL;
		return false;
	}
	else {
		*T = (BTree*)malloc(sizeof(BTree));
		if (*T == NULL) exit(-1);/*空间不足*/
		(*T)->date = (int)ch_elem - '0';
		(*T)->left = NULL;
		(*T)->right = NULL;

		creat_BTree(&(*T)->left);
		creat_BTree(&(*T)->right);
	}

	return true;
}

void pre_order_traverse(BTree* T) {

	if (T == NULL)return;
	
	cout << " " << T->date;
	pre_order_traverse(T->left);
	pre_order_traverse(T->right);
}

void cen_order_traverse(BTree* T) {

	if (T == NULL)return;

	cen_order_traverse(T->left);
	cout << " " << T->date;
	cen_order_traverse(T->right);
}

void cen_order_traverse_no_recursion(BTree* T) {

	static BTree *temp_stack[10] = { NULL };
	static int stack_top = 0;

	BTree* p = T;
	while (p || stack_top != 0) {
		if (p) {
			temp_stack[stack_top++] = p;
			p = p->left;
		}
		else {
			BTree* q = temp_stack[--stack_top];
			if (q) {
				cout << " " << q->date;
				p = q->right;
			}
		}
	}
}

void pre_order_traverse_no_recursion(BTree* T) {

	static BTree* temp_stack[10] = { NULL };
	static int stack_top = 0;

	BTree* p = T;

	while (p || stack_top != 0) {
		if (p) {
			cout << " " << p->date;
			temp_stack[stack_top++] = p;
			p = p->left;
		}

		while (!p && stack_top != 0) {
			if(temp_stack[stack_top - 1])
			    p = temp_stack[--stack_top]->right;
		}
	}
}

void pos_order_traverse(BTree* T) {

	if (T == NULL)return;

	pos_order_traverse(T->left);
	pos_order_traverse(T->right);
	cout << " " << T->date;
}

void pos_order_traverse_no_recursion(BTree* T) {

	static BTree* temp_stack[10] = { NULL };
	static int stack_top = 0;

	BTree* p = T,*q = NULL;
	while (p || stack_top != 0) {

		if (p) {
			temp_stack[stack_top++] = p;
			p = p->left;
		}

		if (!p) {
			q = temp_stack[--stack_top];
			if(q) p = q->right;
		}


		if (!p && q) {
			cout << " " << q->date;
		}


	}
}

/*队列自增辅助函数*/
int up_of_queue(int index,const int MAX) {
	return (index + 1) % MAX;
}

void level_prder_traverse(BTree* T) {

	if (T == NULL) return;

	BTree* p = T;
	const int MAX_QUEUE_LENGTH = 6;
	BTree* temp_queue[6] = { NULL };
	int indexhead = 0;
	int indextail = 0;

	temp_queue[indexhead] = T;
	indexhead = up_of_queue(indexhead,MAX_QUEUE_LENGTH);

	while (indexhead != indextail) {
		BTree* temp_p = temp_queue[indextail];
		indextail = up_of_queue(indextail,MAX_QUEUE_LENGTH);

		cout << " " << temp_p->date;

		if (temp_p->left) {
			temp_queue[indexhead] = temp_p->left;
			indexhead = up_of_queue(indexhead, MAX_QUEUE_LENGTH);
		}

		if (temp_p -> right) {
			temp_queue[indexhead] = temp_p->right;
			indexhead = up_of_queue(indexhead, MAX_QUEUE_LENGTH);
		}

	} 
}

void copy_of_tree(BTree* T, BTree** new_tree) {
	if (T == NULL) {
		*new_tree = NULL;
	}
	else {
		*new_tree = (BTree*)malloc(sizeof(BTree));
		if (*new_tree == NULL) exit(-1);/*空间不足*/

		(*new_tree)->date = T->date;
		(*new_tree)->left = NULL;
		(*new_tree)->right = NULL;

		copy_of_tree(T->left, &(*new_tree)->left);
		copy_of_tree(T->right, &(*new_tree)->right);
	}
}

int calculation_tree_depth(BTree* T) {

	//遇到空树时返回深度为0
	if (T == NULL) return 0;

	int depth_of_left_child = 0;
	int depth_of_right_child = 0;

	/*依次计算左右子树的深度*/
	depth_of_left_child = calculation_tree_depth(T->left);
	depth_of_right_child = calculation_tree_depth(T->right);

	/*判断左右子树的深度那个更大，大的深度加上本层深度*/
	if (depth_of_left_child > depth_of_right_child)return depth_of_left_child + 1;
	else return depth_of_right_child + 1;
}

int calculation_tree_node(BTree* T) {
	
	//遇到空结点返回0
	if (T == NULL) return 0;

	int node_left_count = 0;
	int node_right_count = 0;

	/*依次计算左右子树结点个数*/
	node_left_count = calculation_tree_node(T->left);
	node_right_count = calculation_tree_node(T->right);

	//返回左右子树结点个数的总和加上本身结点
	return node_left_count + node_right_count + 1;
}

int calculation_leaf_node(BTree* T) {

	//判断是否为空结点
	if (T == NULL) return 0;

	int node_leaf_left_count = 0;
	int node_leaf_right_count = 0;

	//判断当前结点是否为叶子结点
	if (!T->left && !T->right) return 1;

	//当前结点不是叶子结点，分别计算左孩子和右孩子的叶子结点个数
	if (T->left) node_leaf_left_count = calculation_leaf_node(T->left);
	if (T->right) node_leaf_right_count = calculation_leaf_node(T->right);

	//返回左右孩子叶子结点个数
	return node_leaf_left_count + node_leaf_right_count;
}

void init_node(BTree* t) {
	t->left = NULL;
	t->ltag = 0;
	t->right = NULL;
	t->rtag = 0;
}

void creat_cen_order_BTree(BTree** T) {

	if (*T != NULL) return;

	char temp_ch;
	cin >> temp_ch;

	if (temp_ch == '#') {
		*T = NULL;
	}
	else {

		//分配空间
		*T = (BTree*)malloc(sizeof(BTree));
		if (*T == NULL) exit(-1);/*空间不足*/
		init_node(*T);

		creat_cen_order_BTree(&(*T)->left);
		(*T)->date = temp_ch - '0';
		creat_cen_order_BTree(&(*T)->right);
		
	}
}

void cen_order_threaded(BTree* TB, BTree* prev) {

	if (TB == NULL)return;

	cen_order_threaded(TB->left, prev);

	if (TB->left == NULL) {
		TB->left = prev;
		TB->ltag = NULL_NODE;
	}

	if (prev && prev->right == NULL) {
		prev->right = TB;
		prev->rtag = NULL_NODE;
	}

	prev = TB;
	cen_order_threaded(TB->right, prev);
}
