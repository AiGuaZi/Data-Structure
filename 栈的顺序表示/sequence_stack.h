#pragma once

#include<iostream>
#include<stdlib.h>
using namespace std;

#define INIT_SIZE 10
#define ADD_SIZE 20

typedef struct Stack {
	int* top;			//ջ��ָ��
	int* base;			//�ڴ�����׵�ַָ��
	int stack_Size;		//ջ�ռ��С
}INT;

/*
* ���ܣ�����ջ
* ������INT *S
* ������ɹ�����true��ʧ�ܷ���false
*/
bool creat_stack(INT** S);

/*
* ���ܣ��ж��Ƿ�Ϊ��ջ
* ������INT *S
* �������ջ����true�����򷵻�false
*/
bool stack_is_empty(INT* S);

/*
* ���ܣ��ж��Ƿ�Ϊ��ջ
* ������INT *S
* �������ջ����true�����򷵻�false
*/
bool stack_is_full(INT* S);

/*
* ���ܣ�����ջ�ĳ���
* ������INT *S
* ���������Ԫ�ظ���
*/
int stack_length(INT* S);

/*
* ���ܣ��ÿ�ջ
* ������INT *S
* ������ɹ�����true��ʧ�ܷ���false
*/
bool clear_statck(INT* S);

/*
* ���ܣ�����ջ
* ������INT **S
* ������ɹ�����true��ʧ�ܷ���false
*/
bool destroy_stack(INT** S);

/*
* ���ܣ�Ԫ����ջ
* ������INT *S,int e
* ������ɹ�����true��ʧ�ܷ���false
*/
bool push(INT* S,int e);

/*
* ���ܣ�Ԫ�س�ջ
* ������INT *S,int *e
* ������ɹ�����true��ʧ�ܷ���false
*/
bool pop(INT* S, int* e);

/*
* ���ܣ�ȡջ��Ԫ��
* ������INT *S,int *e
* ������ɹ�����true��ʧ�ܷ���false
*/
bool getTop(INT* S, int* e);

/*
* ���ܣ�����ջ��ջ��ÿ��Ԫ�ض�ִ��com����
* ������INT *S
* �����������Ԫ�ض�ִ��com����
*/
void traversal_stack(INT* S,void(com)(const void *elem));