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
* ���ܣ�����ͨ�ù�������
* ���������ͨ�ù�������
*/
Tree** creat_common_Huff();

/*
* ���ܣ�ѡ��������СȨֵ
* �����������СȨֵ�±�
*/
void select_two_smallest_of_weight(Tree** T, const int T_size, int* t1, int* t2);

/*
* ���ܣ�ͨ�ñ���
* �������������
*/
String* common_coding();

/*
* ���ܣ��ڹ��������в���Ҷ�ӽ��
* ���أ��ڹ��������ڵĽ���±�,��ѯʧ�ܷ���-1
*/
int seek_char_on_Huffman(char ch, Tree** Huf);

/*
* ���ܣ�����
* �������������
*/
String* decode_to_code(String* code);