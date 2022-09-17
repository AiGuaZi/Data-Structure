#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

#define ERROR -1
#define NO_MEMORY -18
#define FILL_LIST -2


typedef int keyType;

typedef struct Hash_List {
	keyType* key;
	int length;
}Hash_List;

/*初始化*/
void Init_Hash_List(Hash_List* HL, int length);
/*Hash函数*/
int Hash_function(Hash_List* HL, keyType key);
/*Hash构造*/
void creat_Hash_List(Hash_List* HL);
/*判断获取空位置*/
int get_NULL_i_in_HashList(Hash_List* HL, keyType key);
/*Hash查找*/
int find_elem(Hash_List* HL, keyType key);
/*释放HashList*/
void free_HashList(Hash_List* HL);
