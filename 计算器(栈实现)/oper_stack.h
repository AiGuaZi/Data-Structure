#pragma once
#include"analyze_std.h"

#define EQUA_STACK_MAX_SIZE 50

typedef struct Equation {
	char* oper;
	char* top;
}Equation_oper;

/*
* 功能:创建栈
* 参数：Equation_oper **E
* 结果：成功返回真，并带回创建栈空间，失败返回假
*/
bool creat_equa_oper_stack(Equation_oper** E);

/*
* 功能: 求栈内数据长度
* 参数：Equation_oper *E
* 结果：成功返回数据长度，失败返回假
*/
int equa_stack_oper_length(Equation_oper* E);

/*
* 功能: 入栈
* 参数：Equation_oper *E，char e
* 结果：成功返回真，失败返回假
*/
bool in_equa_oper_stack(Equation_oper* E, char e);

/*
* 功能: 出栈
* 参数：Equation_oper *E，char e
* 结果：成功返回真，失败返回假
*/
bool out_equa_oper_stack(Equation_oper* E, char *e);


