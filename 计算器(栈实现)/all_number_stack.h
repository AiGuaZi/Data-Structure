#pragma once
#include"analyze_std.h"
#include"one_number_stack.h"

#define ALL_NUMBER_STACK_MAX_SIZE 9  //��ʱ����int��������ֵ

typedef struct AllNumber {
	char** number;
	char** number_top;
}AllNumber;

/*
* ����:����ջ�����洢50����ֵ
* ������AllNumber **E
* ������ɹ������棬�����ش���ջ�ռ䣬ʧ�ܷ��ؼ�
*/
bool creat_equa_all_number_stack(AllNumber** E);

/*
* ����: ��ջ�����ݳ���
* ������AllNumber *E
* ������ɹ��������ݳ��ȣ�ʧ�ܷ��ؼ�
*/
int equa_stack_all_number_length(AllNumber* E);

/*
* ����: ��ջ
* ������AllNumber *E��char e
* ������ɹ������棬ʧ�ܷ��ؼ�
*/
bool in_equa_all_number_stack(AllNumber* E, char* number_std);

/*
* ����: ��ջ
* ������AllNumber *E��char e
* ������ɹ������棬ʧ�ܷ��ؼ�
*/
bool out_equa_all_number_stack(AllNumber* E, char** number_std);

/*
* ����: ��ջ
* ������AllNumber *E��char e
* ������ɹ������棬ʧ�ܷ��ؼ�
*/
bool free_equa_all_number_stack(AllNumber* E);