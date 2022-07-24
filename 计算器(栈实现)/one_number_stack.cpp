#pragma once
#include"one_number_stack.h"

/* 暂时不用 */
bool creat_equa_one_number_stack(Number** E) {

	//判断栈是否被建立
	if (*E != NULL)return false;

	//分配栈空间,分配失败返回假
	*E = (Number*)malloc(sizeof(Number));
	if (*E == NULL) return false;
	(*E)->number_top = NULL;
	(*E)->one_number = NULL;

	//分配存储数值的内存，分配失败返回假
	(*E)->one_number = (char*)malloc(sizeof(char) * ONE_NUMBER_STACK_MAX_SIZE);
	if ((*E)->one_number == NULL) return false;
	(*E)->number_top = (*E)->one_number;

	return true;
}

int equa_stack_one_number_length(Number* E) {

	//判断栈是否存在
	if (E == NULL) return false;

	return (E->number_top - E->one_number) / sizeof(char);
}

bool out_equa_one_number_stack(Number* E, char* number_std) {

	//判断传入参数的正确性
	if (E == NULL || number_std == NULL) return false;
}
