#pragma once
/**
* ��������ͷ�ڵ�ģ�������
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
* ���ܣ���������
* ��������
* ���: ����ָ�������ͷ�ڵ㡣
*/
INT* creat_list();

/**
* ���ܣ�����������ֵ
* ������INT** L, INT insert_elem
* ���: �ɹ������棬ʧ�ܷ��ؼ�
*/
bool add_elem_list(INT** L, INT insert_elem);

/**
* ���ܣ��ڵ�i��λ�ò���Ԫ��
* ������INT* L,int i ,  INT insert_elem
* ���: �ɹ������棬ʧ�ܷ��ؼ�
*/
bool insert_elem_list(INT** L, int i, INT* insert_elem);

/**
* ���ܣ������
* ������INT* L
* ���: �ɹ������棬ʧ�ܷ��ؼ�
*/
int length_List(INT* L);

/**
* ���ܣ�ɾ����i��Ԫ��
* ������INT** L��int i
* ���: �ɹ������棬ʧ�ܷ��ؼ�
*/
bool delete_elem_list(INT** L, int i);