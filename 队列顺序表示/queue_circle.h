#pragma once

#include<iostream>
#include<stdlib.h>

using namespace std;

#define MAX_SIZE 10

typedef struct Queue {
	int* data;			//���ݴ����ڴ�
	int front;			//ͷָ��
	int rear;			//βָ��
}INT;

/*
* ����:����һ������
* ������INT *Q
* ������ɹ������棬ʧ�ܷ��ؼ�
*/
bool creat_queue(INT** Q);

/*
* ���ܣ�ѭ���������Լ�
* ������int i,int max,char operator
* ����������������Լ����ֵ,ʧ�ܷ���0
*/
int up_or_down(int i, int max,char oper);

/*
* ���ܣ����
* ������INT*Q,int i
* ������ɹ�����true��ʧ�ܷ���false
*/
bool in_queue(INT* Q, int e);

/*
* ���ܣ��ж϶���
* ������INT*Q
* ��������������棬���򷵻ؼ�
*/
bool is_queue_full(INT* Q);

/*
* ���ܣ���������
* ������INT *Q,void (com)(const void* elem)
* ������Զ�������Ԫ��ִ��com����
*/
void traverse_queue(INT* Q, void (com)(const void* elem));

/*
* ���ܣ�����
* ������INT*Q,int *e
* ������ɹ�����true��ʧ�ܷ���false
*/
bool out_queue(INT* Q, int *e);

/*
* ���ܣ�ȡ��ͷԪ��
* ������INT*Q,int *e
* ������ɹ�����true��ʧ�ܷ���false
*/
bool get_queue(INT* Q, int* e);

/*
* ���ܣ�����ӳ�
* ������INT*Q
* ������ɹ����ضӳ���ʧ�ܷ���-1��
*/
int queue_length(INT* Q);