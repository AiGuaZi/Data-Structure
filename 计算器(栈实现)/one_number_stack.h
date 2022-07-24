#pragma once
#include"analyze_std.h"

/* 暂时不用 */

#define ONE_NUMBER_STACK_MAX_SIZE 9  //暂时运用int型以内数值

typedef struct OneNumber {
	char* one_number;
	char* number_top;
}Number;

/*
* 功能:创建栈
* 参数：Number **E
* 结果：成功返回真，并带回创建栈空间，失败返回假
*/
bool creat_equa_one_number_stack(Number** E);

/*
* 功能: 求栈内数据长度
* 参数：Number *E
* 结果：成功返回数据长度，失败返回假
*/
int equa_stack_one_number_length(Number* E);

/*
* 功能: 入栈
* 参数：Number *E，char e
* 结果：成功返回真，失败返回假
*/
bool in_equa_one_number_stack(Number* E, char e);

/*
* 功能: 出栈
* 参数：Number *E，char e
* 结果：成功返回真，失败返回假
*/
bool out_equa_one_number_stack(Number* E, char* e);