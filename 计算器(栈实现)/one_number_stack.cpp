#pragma once
#include"one_number_stack.h"

/* ��ʱ���� */
bool creat_equa_one_number_stack(Number** E) {

	//�ж�ջ�Ƿ񱻽���
	if (*E != NULL)return false;

	//����ջ�ռ�,����ʧ�ܷ��ؼ�
	*E = (Number*)malloc(sizeof(Number));
	if (*E == NULL) return false;
	(*E)->number_top = NULL;
	(*E)->one_number = NULL;

	//����洢��ֵ���ڴ棬����ʧ�ܷ��ؼ�
	(*E)->one_number = (char*)malloc(sizeof(char) * ONE_NUMBER_STACK_MAX_SIZE);
	if ((*E)->one_number == NULL) return false;
	(*E)->number_top = (*E)->one_number;

	return true;
}

int equa_stack_one_number_length(Number* E) {

	//�ж�ջ�Ƿ����
	if (E == NULL) return false;

	return (E->number_top - E->one_number) / sizeof(char);
}

bool out_equa_one_number_stack(Number* E, char* number_std) {

	//�жϴ����������ȷ��
	if (E == NULL || number_std == NULL) return false;
}
