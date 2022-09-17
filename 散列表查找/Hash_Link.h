#pragma once
/*
* ����������ɢ�б�ĳ�ͻ����
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

#define ERROR -1
#define NO_MEMORY -18
#define FILL_LIST -2

typedef int keyType;

/*����ַ��*/
typedef struct keyNode {
	keyType key;
	keyNode* next;
}keyNode;

typedef struct keyHead {
	int link_length;
	keyNode* head;
}keyHead;

typedef struct HashOfLink {
	keyHead* key_list;
	int key_length;
}HashOfLink;


/*��ʼ��*/
void Init_Hash_Link(HashOfLink* HOL, int length);
/*Hash����*/
int Hash_function_Link(HashOfLink* HOL, keyType key);
/*�����ڵ�*/
void creat_Node(HashOfLink** HOL, int i, keyType key);
/*����HashList*/
void creat_HashOfLink(HashOfLink* HOL);
/*�������HashList*/
void traverse_HOL(HashOfLink* HOL);
/*����Ԫ��*/
void find_elem_in_HashOfLink(HashOfLink* HOL, keyType key);