#include"binary_to_tree.h"

int main() {
	BTree* b1 = NULL;
	init_BTree(b1);
	creat_BTree(&b1);//AB#C#D##EF##GH#IJ####
	print_BTree_traverse(b1);

	Tree* t1 = NULL;
	int t1_size = 0;
	BTree_to_forest(b1, &t1, &t1_size);


	BTree* tree = NULL;
	return 0;
}