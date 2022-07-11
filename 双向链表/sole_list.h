#pragma once
/**
* 创建带有头节点的，单链表
*/
#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct INT {
	INT* prev;
	int date;
	INT* next;
}INT;

/**
* 功能：创建链表
* 参数：无
* 结果: 返回指向量表的头节点。
*/
INT* creat_list();

/**
* 功能：给链表输入值
* 参数：INT** L, INT insert_elem
* 结果: 成功返回真，失败返回假
*/
bool add_elem_list(INT** L, INT insert_elem);

/**
* 功能：在第i个位置插入元素
* 参数：INT* L,int i ,  INT insert_elem
* 结果: 成功返回真，失败返回假
*/
bool insert_elem_list(INT** L, int i, INT* insert_elem);

/**
* 功能：输出表长
* 参数：INT* L
* 结果: 成功返回真，失败返回假
*/
int length_List(INT* L);

/**
* 功能：删除第i个元素
* 参数：INT** L，int i
* 结果: 成功返回真，失败返回假
*/
bool delete_elem_list(INT** L, int i);