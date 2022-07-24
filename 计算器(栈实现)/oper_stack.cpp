#include"oper_stack.h"

bool creat_equa_oper_stack(Equation_oper** E) {

	//�ж��Ƿ񱻴���
	if (*E) return false;

	//����ռ�
	*E = (Equation_oper*)malloc(sizeof(Equation_oper));
	if (*E == NULL) return false;
	(*E)->oper = NULL;
	(*E)->top = NULL;

	//�������ݿռ�
	(*E)->oper = (char*)malloc(sizeof(char) * EQUA_STACK_MAX_SIZE);
	if (!(*E)->oper) return false;
	memset((*E)->oper, 0, EQUA_STACK_MAX_SIZE);
	(*E)->top = (*E)->oper;

	return true;
}

int equa_stack_oper_length(Equation_oper* E) {

	//�ж�ջ�Ƿ����
	if (!E) return -1;

	return (E->top - E->oper) / sizeof(char);
}

bool in_equa_oper_stack(Equation_oper* E, char e) {

	//�жϱ��Ƿ����
	if (E == NULL) return false;

	//�ж�ջ��
	if (equa_stack_oper_length(E) == EQUA_STACK_MAX_SIZE) return false;

	//��ջ
	*E->top = e;
	E->top++;

	return true;
}

bool out_equa_oper_stack(Equation_oper* E, char* e) {

	//�жϱ��Ƿ����
	if (E == NULL) return false;

	//�ж�ջ��
	if (equa_stack_oper_length(E) == 0) return false;

	//��ջ
	*e = *E->top;
	E->top--;

	return true;
}