#pragma once
#include"analyze_std.h"
#include"caculation_equation.h"
#include"one_number_stack.h"
#include"all_number_stack.h"
#include"oper_stack.h"

/*
* ����: �������������ֵ
* ������char *equa
* ���������������
*/
int extract_equation(const char* equa, AllNumber* value, Equation_oper* oper);

/*
* ����: �������
* ������AllNumber* value, Equation_oper* oper,double* answer
* ���������ɹ�����true,ʧ�ܷ���false
*/
bool caculation_equation(const char* equation, double* answer);