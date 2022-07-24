#pragma once
#include"analyze_std.h"

/* ��ʱ���� */

#define ONE_NUMBER_STACK_MAX_SIZE 9  //��ʱ����int��������ֵ

typedef struct OneNumber {
	char* one_number;
	char* number_top;
}Number;

/*
* ����:����ջ
* ������Number **E
* ������ɹ������棬�����ش���ջ�ռ䣬ʧ�ܷ��ؼ�
*/
bool creat_equa_one_number_stack(Number** E);

/*
* ����: ��ջ�����ݳ���
* ������Number *E
* ������ɹ��������ݳ��ȣ�ʧ�ܷ��ؼ�
*/
int equa_stack_one_number_length(Number* E);

/*
* ����: ��ջ
* ������Number *E��char e
* ������ɹ������棬ʧ�ܷ��ؼ�
*/
bool in_equa_one_number_stack(Number* E, char e);

/*
* ����: ��ջ
* ������Number *E��char e
* ������ɹ������棬ʧ�ܷ��ؼ�
*/
bool out_equa_one_number_stack(Number* E, char* e);