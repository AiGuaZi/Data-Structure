#pragma once
#include"analyze_std.h"
#include"one_number_stack.h"

#define ALL_NUMBER_STACK_MAX_SIZE 9  //暂时运用int型以内数值

typedef struct AllNumber {
	char** number;
	char** number_top;
}AllNumber;

/*
* 功能:创建栈，最多存储50个数值
* 参数：AllNumber **E
* 结果：成功返回真，并带回创建栈空间，失败返回假
*/
bool creat_equa_all_number_stack(AllNumber** E);

/*
* 功能: 求栈内数据长度
* 参数：AllNumber *E
* 结果：成功返回数据长度，失败返回假
*/
int equa_stack_all_number_length(AllNumber* E);

/*
* 功能: 入栈
* 参数：AllNumber *E，char e
* 结果：成功返回真，失败返回假
*/
bool in_equa_all_number_stack(AllNumber* E, char* number_std);

/*
* 功能: 出栈
* 参数：AllNumber *E，char e
* 结果：成功返回真，失败返回假
*/
bool out_equa_all_number_stack(AllNumber* E, char** number_std);

/*
* 功能: 出栈
* 参数：AllNumber *E，char e
* 结果：成功返回真，失败返回假
*/
bool free_equa_all_number_stack(AllNumber* E);