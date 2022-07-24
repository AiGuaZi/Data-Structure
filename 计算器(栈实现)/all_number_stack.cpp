#include"all_number_stack.h"

bool creat_equa_all_number_stack(AllNumber** E) {

	//�ж�ջ�Ƿ��Ѿ�����
	if (*E != NULL) return false;

	//�����洢��ʽ�����е���ֵ���ڴ�,����ʧ�ܷ��ؼ�
	*E = (AllNumber*)malloc(sizeof(AllNumber));
	if (*E == NULL) return false;
	(*E)->number = NULL;
	(*E)->number_top = NULL;
	
	//����洢ÿ����ֵ���ڴ�,���洢50����ֵ,����ʧ�ܷ��ؼ�
	(*E)->number = (char**)malloc(sizeof(char*) * 50);
	if ((*E)->number == NULL) return false;
	(*E)->number_top = (*E)->number;

	return true;
}

int equa_stack_all_number_length(AllNumber* E) {

	//�ж�ջ�Ƿ����
	if (E == NULL) return false;

	return (E->number_top - E->number) / sizeof(AllNumber);
}

bool in_equa_all_number_stack(AllNumber* E, char *number_std) {

	//�жϴ����������ȷ��
	if (E == NULL || number_std == NULL) return false;

	//�ж��Ƿ�ջ��
	if (equa_stack_all_number_length(E) + 1 == ALL_NUMBER_STACK_MAX_SIZE) return false;

	//��ջ����
	*E->number_top = number_std;
	E->number_top++;

	return true;
}

bool out_equa_all_number_stack(AllNumber* E, char** number_std) {

	//�жϴ����������ȷ��
	if (E == NULL || *number_std != NULL) return false;

	//�ж��Ƿ�Ϊ��ջ
	if (equa_stack_all_number_length(E) == 0) return false;

	//��ջ����
	number_std = E->number_top;
	E->number_top--;

	return true;
}

bool free_equa_all_number_stack(AllNumber* E) {

	//�ж�ջ�Ƿ����
	if (E == NULL)return false;

	//�ͷŶ�ÿ���ַ��Ŀռ�
	for (int i = 0; i < equa_stack_all_number_length(E); i++) {
		free(E->number[i]);
		E->number = NULL;
	}

	//�ͷŴ洢��ֵ�ַ��Ŀռ�
	free(E->number);
	E->number = NULL;
	E->number_top = NULL;

	//�ͷ�ջ�ռ�
	free(E);
	E = NULL;
	
	return true;
}