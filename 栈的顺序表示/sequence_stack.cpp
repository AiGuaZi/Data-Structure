#include"sequence_stack.h"


bool creat_stack(INT** S) {

	//判断栈是否被创建
	if (*S) return false;

	//创建栈
	*S = (INT*)malloc(sizeof(INT));
	
	//创建失败
	if (*S == NULL) return false;
	(*S)->base = NULL;
	(*S)->top = NULL;
	(*S)->stack_Size = 0;

	//分配栈内元素空间
	(*S)->base = (int*)malloc(sizeof(int) * INIT_SIZE);
	if ((*S)->base == NULL) return false;
	(*S)->stack_Size = INIT_SIZE;
	(*S)->top = (*S)->base;

	return true;
}

bool stack_is_empty(INT* S) {

	//栈不存在
	if (S == NULL) return false;

	return S->base == S->top ? true : false;
}

bool stack_is_full(INT* S) {

	//栈不存在
	if (S == NULL) return false;

	return (S->top - S->base) / sizeof(int) == S->stack_Size ? true : false;
}

int stack_length(INT* S) {

	//栈不存在
	if (S == NULL) return false;

	return (S->top - S->base) / sizeof(int);
}

bool clear_statck(INT* S) {

	//栈不存在
	if (S == NULL) return false;

	S->top = S->base;

	return true;
}

bool destroy_stack(INT** S) {

	//栈已不存在
	if (*S == NULL) return true;

	//销毁栈内 内存
	if ((*S)->base) free((*S)->base);
	else false;

	//销毁栈
	free(*S);
	*S = NULL;

	return true;
}

bool push(INT* S, int e) {

	//栈不存在
	if (S == NULL) return false;

	if (stack_is_full(S)) {
		
		//获取栈长度
		int length = stack_length(S);

		//动态增加空间
		int* newbase = (int*)realloc(S->base, sizeof(int) * (S->stack_Size + ADD_SIZE));
		if (newbase == NULL) {
			return false;
		}

		//释放原内存
		free(S->base);
		S->base = NULL;

		//将新内存分配给栈
		S->base = newbase;
		S->top = S->base + length;
		S->stack_Size += ADD_SIZE;
	}

	//元素入栈
	*S->top = e;
	S->top++;

	return true;
}

bool pop(INT* S, int* e) {

	//栈不存在
	if (S == NULL) return false;

	//判断是否为空表
	if (stack_is_empty(S)) return false;

	//元素出栈
	S->top--;
	*e = *S->top;

	return true;
}

bool getTop(INT* S, int* e) {

	//栈不存在
	if (S == NULL) return false;

	//判断是否为空表
	if (stack_is_empty(S)) return false;

	*e = *(S->top - 1);

	return true;
}

void traversal_stack(INT* S, void(com)(const void* elem)) {

	//栈不存在
	if (S == NULL) return;

	//遍历开始
	int* p = S->base;
	while (p != S->top) com(p++);
}