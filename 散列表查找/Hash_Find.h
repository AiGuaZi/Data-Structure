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

/*��ʼ��*/
void Init_Hash_List(Hash_List* HL, int length);
/*Hash����*/
int Hash_function(Hash_List* HL, keyType key);
/*Hash����*/
void creat_Hash_List(Hash_List* HL);
/*�жϻ�ȡ��λ��*/
int get_NULL_i_in_HashList(Hash_List* HL, keyType key);
/*Hash����*/
int find_elem(Hash_List* HL, keyType key);
/*�ͷ�HashList*/
void free_HashList(Hash_List* HL);
