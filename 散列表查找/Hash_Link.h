#pragma once
/*
* 拉链法处理散列表的冲突问题
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

#define ERROR -1
#define NO_MEMORY -18
#define FILL_LIST -2

typedef int keyType;

/*链地址法*/
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


/*初始化*/
void Init_Hash_Link(HashOfLink* HOL, int length);
/*Hash函数*/
int Hash_function_Link(HashOfLink* HOL, keyType key);
/*创建节点*/
void creat_Node(HashOfLink** HOL, int i, keyType key);
/*创建HashList*/
void creat_HashOfLink(HashOfLink* HOL);
/*遍历输出HashList*/
void traverse_HOL(HashOfLink* HOL);
/*查找元素*/
void find_elem_in_HashOfLink(HashOfLink* HOL, keyType key);