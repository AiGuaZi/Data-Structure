#include"huffman_code.h"

void select_two_smallest_of_weight( Tree** T, const int T_size, int* t1, int* t2) {

	//查询第一个最小值
	int min_1 = 2147483647;
	for (int i = 0; i < T_size; i++) {
		if (T[i]->parent == 0 && T[i]->weight < min_1) {
			min_1 = T[i]->weight;
			*t1 = i;
		}
	}

	//查询第二个最小值
	int min_2 = 2147483647;
	for (int i = 0; i < T_size; i++) {
		if (T[i]->parent == 0 && T[i]->weight < min_2 && i != *t1) {
			min_2 = T[i]->weight;
			*t2 = i;
		}
	}
}

Tree** creat_common_Huff() {
	
	Tree** com_tree = NULL;
	int all_node_count = 2 * LOWER_AND_UPPER_CASE_NUMBER - 1;
	com_tree = (Tree**)malloc(sizeof(Tree*) * all_node_count);
	if (com_tree == NULL) exit(-1);

	//默认权值分布
	int lowercase_wight[] = { 24, 9,17,15,26, 8,10,12,22, 2, 5,18,14,21,20,13, 3,25,19,23,16, 7, 6, 4,11, 1 };
	int uppercase_wight[] = { 50,35,43,41,52,34,36,38,48,28,31,44,40,47,46,39,29,51,45,49,42,33,32,30,37,27 };

	//初始化
	for (int i = 0; i < LOWER_AND_UPPER_CASE_NUMBER; i++) {
		Tree* temp_node = (Tree*)malloc(sizeof(Tree));
		if (temp_node == NULL) exit(-1);

		//初始化权值
		if (i < 26) {
			temp_node->date = 'a' + i;
			temp_node->weight = lowercase_wight[i];
		}
		else {
			temp_node->date = 'A' + (i - LOWER_AND_UPPER_CASE_NUMBER / 2);
			temp_node->weight = uppercase_wight[i - LOWER_AND_UPPER_CASE_NUMBER / 2];
		}

		temp_node->parent = 0;
		temp_node->lchind = 0;
		temp_node->rchind = 0;
		temp_node->Huffman_code = NULL;

		com_tree[i] = temp_node;
	}

	//建立哈夫曼树
	for (int i = LOWER_AND_UPPER_CASE_NUMBER; i < all_node_count; i++) {
		int s1 = 0;
		int s2 = 0;
		select_two_smallest_of_weight(com_tree, i, &s1, &s2);

		com_tree[s1]->parent = i;
		com_tree[s2]->parent = i;

		com_tree[i] = (Tree*)malloc(sizeof(Tree));
		if (com_tree[i] == NULL) exit(-1);
		com_tree[i]->date = '0';
		com_tree[i]->parent = 0;
		com_tree[i]->Huffman_code = NULL;

		com_tree[i]->weight = com_tree[s1]->weight + com_tree[s2]->weight;
		com_tree[i]->lchind = s1;
		com_tree[i]->rchind = s2;

	}

	//获取哈夫曼码
	for (int i = 0; i < LOWER_AND_UPPER_CASE_NUMBER; i++) {

		//定义编码栈
		char temp_code_stack[LOWER_AND_UPPER_CASE_NUMBER] = { 0 };
		int temp_code_top = 0;

		//从叶子结点出发，回溯返回哈夫曼码
		int now_node = i;
		int index_parent = com_tree[now_node]->parent;

		while (index_parent != 0) {

			if (com_tree[index_parent]->lchind == now_node)temp_code_stack[temp_code_top++] = '0';
			else                                           temp_code_stack[temp_code_top++] = '1';

			now_node = index_parent;
			index_parent = com_tree[index_parent]->parent;
		}

		com_tree[i]->Huffman_code = (char*)malloc(sizeof(char) * temp_code_top);
		if (com_tree[i]->Huffman_code == NULL) exit(-1);
		memset(com_tree[i]->Huffman_code, 0, sizeof(char) * temp_code_top);

		//将计算得到的哈夫曼码保存
		int Huff_i = 0;
		while (--temp_code_top >= 0) {
			(com_tree[i]->Huffman_code)[Huff_i++] = temp_code_stack[temp_code_top];	
		}
		com_tree[i]->Huffman_code[Huff_i] = '\0';
	}

	/*for (int i = 0; i < LOWER_AND_UPPER_CASE_NUMBER; i++) {
		cout << "i = " << i << " date = " << com_tree[i]->date;
		cout << " weight = " << com_tree[i]->weight << " lchild = " << com_tree[i]->lchind;
		cout << " rchild = " << com_tree[i]->rchind << " Huff_code = " << com_tree[i]->Huffman_code << endl;
	}*/

	return com_tree;
}

int seek_char_on_Huffman(char ch, Tree** Huf) {

	int ret = -1;
	for (int i = 0; i < LOWER_AND_UPPER_CASE_NUMBER; i++) {
		if(Huf[i]->date == ch) {
			ret = i;
			break;
		}
	}

	return ret;
}

String* common_coding() {

	//输入编码明文
	String* plaintext = input_code();
	
	//建立通用哈夫曼树
	Tree** Huff_tree = creat_common_Huff();

	String* code = creat_String();


	for (int i = 0; i < plaintext->now_count; i++) {

		if (isalpha(plaintext->str[i]) == 0) {
			cout << "明文输入错误!" << endl;
			exit(-1);
		}

		int Huff_i = seek_char_on_Huffman(plaintext->str[i], Huff_tree);

		for (int i = 0; i < strlen(Huff_tree[Huff_i]->Huffman_code); i++) {
			insert_ch(code, Huff_tree[Huff_i]->Huffman_code[i]);
		}
	}

	for (int i = 0; i < 2 * LOWER_AND_UPPER_CASE_NUMBER - 1; i++) {
		free(Huff_tree[i]);
	}
	free(Huff_tree);
	free(plaintext->str);
	free(plaintext);

	return code;
}

String* decode_to_code(String* code) {

	Tree** Huffman_Tree = creat_common_Huff();

	String* ret_code = creat_String();

	int index_code = 0;
	int index_Huff_child = 102;
	while (index_code <= code->now_count) {

		if (Huffman_Tree[index_Huff_child]->lchind == 0 && Huffman_Tree[index_Huff_child]->rchind == 0) {
			ret_code->str[ret_code->now_count++] = Huffman_Tree[index_Huff_child]->date;
			cout << Huffman_Tree[index_Huff_child]->date;
			index_Huff_child = 102;
		}

		if (code->str[index_code] == '0') {
			index_Huff_child = Huffman_Tree[index_Huff_child]->lchind;
		}

		if (code->str[index_code] == '1') {
			index_Huff_child = Huffman_Tree[index_Huff_child]->rchind;
		}

		index_code++;
	}

	for (int i = 0; i < 2 * LOWER_AND_UPPER_CASE_NUMBER - 1; i++) {
		free(Huffman_Tree[i]);
	}
	free(Huffman_Tree);

	return ret_code;
}