#include"BST.h"

void BST_Init(BST_NODE* BST) {

	if (BST != NULL) return;
	BST = NULL;
}

void creat_Node(BST_NODE** temp, nodeType node_date) {

	if (*temp != NULL) return;

	*temp = (BST_NODE*)malloc(sizeof(BST_NODE));
	if (*temp == NULL) exit(NO_MEMORY);
	
	(*temp)->date = node_date;
	(*temp)->bal_factor = 0;
	(*temp)->left = NULL;
	(*temp)->right = NULL;

}

void creat_BST(BST_NODE** BST, int node_count) {

	if (*BST != NULL || node_count <= 0) return;
	
	cout << "请输入结点值:";
	BST_NODE* temp = NULL;
	int node_date = 0;
	//cin >> node_date;
	//creat_Node(&*BST, node_date);
	for (int i = 0; i < node_count; i++) {

		cin >> node_date;
		BST_NODE* node = NULL;
		creat_Node(&node, node_date);
		
		BST_NODE* p = temp;
		BST_NODE* q = p;
		while (p) {
			q = p;
			if (node_date < p->date) p = p->left;
			else p = p->right;
		}
		if (temp == NULL)temp = node;
		else if (node_date < q->date) q->left = node;
		else q->right = node;
	}
	*BST = temp;

	//计算平衡因子
	cal_bal_factor(*BST);
	
}

void print_node(BST_NODE* node) {
	if (node == NULL) return;
	cout << node->date << ":" << node->bal_factor << "    ";
}

void traverse_BST(BST_NODE* BST, void(workFunction(BST_NODE* BST))) {
	
	if (BST == NULL) return;
	BST_NODE* p = BST;

	traverse_BST(p->left, workFunction);
	workFunction(p);
	traverse_BST(p->right, workFunction);
}

bool search_BST(BST_NODE* BST, int search_elem) {

	if (BST == NULL) return false;

	BST_NODE* p = BST;
	while (p) {
		if (search_elem == p->date) return true;
		else if (search_elem < p->date) p = p->left;
		else p = p->right;
	}

	return false;
}

bool insert_elem_1(BST_NODE* BST, int elem) {

	if (BST == NULL) return false;

	BST_NODE* node = NULL;
	creat_Node(&node, elem);

	BST_NODE* p = BST;
	BST_NODE* q = p;
	bool is_left = false;
	while (p) {

		q = p;
		if (elem < p->date) { 
			is_left = true; 
			p = p->left; 
		}
		else {
			is_left = false;
			p = p->right;
		}

	}
	if (is_left && q) {
		q->left = node;
	}
	else q->right = node;

	return true;
}

void insert_elem_2(BST_NODE** BST, int insert_elem) {

	if (!(*BST)) {
		BST_NODE* node = NULL;
		creat_Node(&node, insert_elem);
		*BST = node;
	}

	else if (insert_elem < (*BST)->date)
		insert_elem_2(&(*BST)->left, insert_elem);
	else
		insert_elem_2(&(*BST)->right, insert_elem);

}

void free_node(BST_NODE** node) {

	if (*node == NULL) return;

	free(*node);
	*node = NULL;
}

BST_NODE* find_left_max(BST_NODE* BST) {

	if (BST == NULL) return NULL;

	BST_NODE* p = BST;
	while (p->right) p = p->right;

	return p;
}

void delete_elem(BST_NODE* BST, int del_elem) {

	if (BST == NULL) return;

	BST_NODE* p = BST;
	BST_NODE* q = p;
	bool is_left = false;
	while (p) {
		if (del_elem == p->date) {
			//没有左子树,有右子树
			if (!p->left && p->right) {
				if (is_left) q->left = p->right;
				else q->right = p->right;
				free_node(&p);
				break;
			}
			//没有右子树，有左子树
			if (!p->right && p->left) {
				if (is_left) q->left = p->left;
				else q->right = p->left;
				free_node(&p);
				break;
			}
			//没有左子树，没有右子树
			if (!p->left && !p->right) {
				if (is_left) q->left = NULL;
				else q->right = NULL;
				free_node(&p);
				break;
			}
			//既有左子树，又有右子树
			if (p->left && p->right) {
				BST_NODE* left_max = find_left_max(p->left);
				if (left_max) {
					int temp_date = left_max->date;
					delete_elem(q, left_max->date);
					p->date = temp_date;
				}
				break;
			}
		}

		q = p;
		if (del_elem < p->date) {
			p = p->left;
			is_left = true;
		}
		else if (del_elem > p->date) {
			p = p->right;
			is_left = false;
		}
		
		
		
	}
}

int cal_bal_factor(BST_NODE* BST) {

	if (BST == NULL) return 0;
	/*
	* 采用后序遍历的方式进行计算平衡因子
	*/
	int left_depth = 0;
	int right_depth = 0;
	left_depth = cal_bal_factor(BST->left);
	right_depth = cal_bal_factor(BST->right);

	int depth = 0;
	depth = left_depth > right_depth ? left_depth : right_depth;
	BST->bal_factor = left_depth - right_depth;

	return depth + 1;
	
}

void up_queue(int* i_que, int que_length) {

	if (que_length < 1) return;

	*i_que = (*i_que + 1) % que_length;
}

void traverse_Lev(BST_NODE* BST, void workFunction(BST_NODE* elem)) {

	if (BST == NULL) return;

	BST_NODE* temp_queue[QUEUE_LENGTH] = { NULL };
	int i_head = 0;
	int i_tail = 0;

	temp_queue[i_head] = BST;
	up_queue(&i_head, QUEUE_LENGTH);
	while (i_head != i_tail) {
		
		BST_NODE* p = temp_queue[i_tail];
		up_queue(&i_tail, QUEUE_LENGTH);

		if (p && p->left) {
			temp_queue[i_head] = p->left;
			up_queue(&i_head, QUEUE_LENGTH);
		}

		if (p && p->right) {
			temp_queue[i_head] = p->right;
			up_queue(&i_head, QUEUE_LENGTH);
		}

		if(p) workFunction(p);
	}
}

BST_NODE* search_no_bal(BST_NODE* BST) {
	
	if (BST == NULL) return NULL;
	
	BST_NODE* temp = NULL;
	temp = search_no_bal(BST->left);
	if (temp->date != 1 || temp->date != 0 || temp->date != -1) return temp;
	temp = search_no_bal(BST->right);
	return temp;
}

void sort_node(BST_NODE** min, BST_NODE** mid, BST_NODE** max) {

	if (!min || !mid || !max) return;

	BST_NODE* p1 = *min;
	BST_NODE* p2 = *mid;
	BST_NODE* p3 = *max;
	BST_NODE* temp_max = NULL;
	BST_NODE* temp_min = NULL;

	if (p1->date > p2->date) {
		
		if (p1->date > p3->date) {
			temp_max = p1;
		}
		else {
			if (p2->date > p3->date) {
				temp_max = p2;
			}
			else {
				temp_max = p3;
			}
		}
	}
}

void balance_BST(BST_NODE* BST) {

	if (BST == NULL) return;

	BST_NODE* no_bal_node = search_no_bal(BST);
	if (!no_bal_node) return;

	BST_NODE* n1, * n2;
	n1 = n2 = NULL;
	bool n1_is_left = false;
	bool n2_is_left = false;

	if (no_bal_node < 0) { n1 = no_bal_node->right; n1_is_left = false; }
	else { n1 = no_bal_node->left; n1_is_left = true; }

	if (n1 && n1->date < 0) { n2 = n1->right; n2_is_left = false; }
	else { n2 = n1->left; n2_is_left = true; }

	BST_NODE* min, * mid, * max;
	min = mid = max = NULL;

	if (n1_is_left && n2_is_left) { min = n2; mid = n1; max = no_bal_node; }
	else if (n1_is_left && !n2_is_left) { min = n1; mid = n2; max = no_bal_node; }
	else if (!n1_is_left && n2_is_left) { min = no_bal_node; mid = n2; max = n1; }
	else { min = no_bal_node; mid = n1; max = n2; }

	BST_NODE* mid_left = mid->left;
	BST_NODE* mid_right = mid->right;
	BST_NODE* min_left = min->left;
	BST_NODE* min_right = min->right;
	BST_NODE* max_left = max->left;
	BST_NODE* max_right = max->right;
	mid->left = min;
	min->


}
