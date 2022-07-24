#pragma once
#include"analyze_std.h"

#define EQUA_STACK_MAX_SIZE 50

typedef struct Equation {
	char* oper;
	char* top;
}Equation_oper;

/*
* ����:����ջ
* ������Equation_oper **E
* ������ɹ������棬�����ش���ջ�ռ䣬ʧ�ܷ��ؼ�
*/
bool creat_equa_oper_stack(Equation_oper** E);

/*
* ����: ��ջ�����ݳ���
* ������Equation_oper *E
* ������ɹ��������ݳ��ȣ�ʧ�ܷ��ؼ�
*/
int equa_stack_oper_length(Equation_oper* E);

/*
* ����: ��ջ
* ������Equation_oper *E��char e
* ������ɹ������棬ʧ�ܷ��ؼ�
*/
bool in_equa_oper_stack(Equation_oper* E, char e);

/*
* ����: ��ջ
* ������Equation_oper *E��char e
* ������ɹ������棬ʧ�ܷ��ؼ�
*/
bool out_equa_oper_stack(Equation_oper* E, char *e);


