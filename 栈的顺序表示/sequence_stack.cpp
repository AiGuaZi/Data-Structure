#include"sequence_stack.h"


bool creat_stack(INT** S) {

	//�ж�ջ�Ƿ񱻴���
	if (*S) return false;

	//����ջ
	*S = (INT*)malloc(sizeof(INT));
	
	//����ʧ��
	if (*S == NULL) return false;
	(*S)->base = NULL;
	(*S)->top = NULL;
	(*S)->stack_Size = 0;

	//����ջ��Ԫ�ؿռ�
	(*S)->base = (int*)malloc(sizeof(int) * INIT_SIZE);
	if ((*S)->base == NULL) return false;
	(*S)->stack_Size = INIT_SIZE;
	(*S)->top = (*S)->base;

	return true;
}

bool stack_is_empty(INT* S) {

	//ջ������
	if (S == NULL) return false;

	return S->base == S->top ? true : false;
}

bool stack_is_full(INT* S) {

	//ջ������
	if (S == NULL) return false;

	return (S->top - S->base) / sizeof(int) == S->stack_Size ? true : false;
}

int stack_length(INT* S) {

	//ջ������
	if (S == NULL) return false;

	return (S->top - S->base) / sizeof(int);
}

bool clear_statck(INT* S) {

	//ջ������
	if (S == NULL) return false;

	S->top = S->base;

	return true;
}

bool destroy_stack(INT** S) {

	//ջ�Ѳ�����
	if (*S == NULL) return true;

	//����ջ�� �ڴ�
	if ((*S)->base) free((*S)->base);
	else false;

	//����ջ
	free(*S);
	*S = NULL;

	return true;
}

bool push(INT* S, int e) {

	//ջ������
	if (S == NULL) return false;

	if (stack_is_full(S)) {
		
		//��ȡջ����
		int length = stack_length(S);

		//��̬���ӿռ�
		int* newbase = (int*)realloc(S->base, sizeof(int) * (S->stack_Size + ADD_SIZE));
		if (newbase == NULL) {
			return false;
		}

		//�ͷ�ԭ�ڴ�
		free(S->base);
		S->base = NULL;

		//�����ڴ�����ջ
		S->base = newbase;
		S->top = S->base + length;
		S->stack_Size += ADD_SIZE;
	}

	//Ԫ����ջ
	*S->top = e;
	S->top++;

	return true;
}

bool pop(INT* S, int* e) {

	//ջ������
	if (S == NULL) return false;

	//�ж��Ƿ�Ϊ�ձ�
	if (stack_is_empty(S)) return false;

	//Ԫ�س�ջ
	S->top--;
	*e = *S->top;

	return true;
}

bool getTop(INT* S, int* e) {

	//ջ������
	if (S == NULL) return false;

	//�ж��Ƿ�Ϊ�ձ�
	if (stack_is_empty(S)) return false;

	*e = *(S->top - 1);

	return true;
}

void traversal_stack(INT* S, void(com)(const void* elem)) {

	//ջ������
	if (S == NULL) return;

	//������ʼ
	int* p = S->base;
	while (p != S->top) com(p++);
}