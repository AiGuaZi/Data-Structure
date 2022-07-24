#pragma once
#include"analyze_std.h"
#include"caculation_equation.h"
#include"one_number_stack.h"
#include"all_number_stack.h"
#include"oper_stack.h"

/*
* 功能: 分离运算符和数值
* 参数：char *equa
* 结果：返回运算结果
*/
int extract_equation(const char* equa, AllNumber* value, Equation_oper* oper);

/*
* 功能: 计算求和
* 参数：AllNumber* value, Equation_oper* oper,double* answer
* 结果：运算成功返回true,失败返回false
*/
bool caculation_equation(const char* equation, double* answer);