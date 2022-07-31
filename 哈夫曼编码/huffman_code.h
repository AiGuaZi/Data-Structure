#pragma once
#include"str_cal.h"

#define LOWER_AND_UPPER_CASE_NUMBER 52

typedef struct HuffmanTree {
	char date;
	int weight;
	int parent, lchind, rchind;
	char* Huffman_code;
}Tree;



/*
* 功能：建立通用哈夫曼树
* 结果：返回通用哈夫曼树
*/
Tree** creat_common_Huff();

/*
* 功能：选择两个最小权值
* 结果：返回最小权值下标
*/
void select_two_smallest_of_weight(Tree** T, const int T_size, int* t1, int* t2);

/*
* 功能：通用编码
* 结果：返回码文
*/
String* common_coding();

/*
* 功能：在哈夫曼树中查找叶子结点
* 返回：在哈夫曼树内的结点下标,查询失败返回-1
*/
int seek_char_on_Huffman(char ch, Tree** Huf);

/*
* 功能：译码
* 结果：返回明文
*/
String* decode_to_code(String* code);