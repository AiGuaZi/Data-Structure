#include"all_number_stack.h"

bool creat_equa_all_number_stack(AllNumber** E) {

	//判断栈是否已经存在
	if (*E != NULL) return false;

	//创建存储等式内所有的数值的内存,分配失败返回假
	*E = (AllNumber*)malloc(sizeof(AllNumber));
	if (*E == NULL) return false;
	(*E)->number = NULL;
	(*E)->number_top = NULL;
	
	//分配存储每个数值的内存,最多存储50个数值,分配失败返回假
	(*E)->number = (char**)malloc(sizeof(char*) * 50);
	if ((*E)->number == NULL) return false;
	(*E)->number_top = (*E)->number;

	return true;
}

int equa_stack_all_number_length(AllNumber* E) {

	//判断栈是否存在
	if (E == NULL) return false;

	return (E->number_top - E->number) / sizeof(AllNumber);
}

bool in_equa_all_number_stack(AllNumber* E, char *number_std) {

	//判断传入参数的正确性
	if (E == NULL || number_std == NULL) return false;

	//判断是否栈满
	if (equa_stack_all_number_length(E) + 1 == ALL_NUMBER_STACK_MAX_SIZE) return false;

	//入栈操作
	*E->number_top = number_std;
	E->number_top++;

	return true;
}

bool out_equa_all_number_stack(AllNumber* E, char** number_std) {

	//判断传入参数的正确性
	if (E == NULL || *number_std != NULL) return false;

	//判断是否为空栈
	if (equa_stack_all_number_length(E) == 0) return false;

	//出栈操作
	number_std = E->number_top;
	E->number_top--;

	return true;
}

bool free_equa_all_number_stack(AllNumber* E) {

	//判断栈是否存在
	if (E == NULL)return false;

	//释放对每个字符的空间
	for (int i = 0; i < equa_stack_all_number_length(E); i++) {
		free(E->number[i]);
		E->number = NULL;
	}

	//释放存储数值字符的空间
	free(E->number);
	E->number = NULL;
	E->number_top = NULL;

	//释放栈空间
	free(E);
	E = NULL;
	
	return true;
}