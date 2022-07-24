#pragma once
#include<iostream>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

#define EQUATION_MAX_SIZE 100

/*
* 功能：分配空间
* 参数：无
* 结果：返回保存等式的地址
*/
char* creat_equation();

/*
* 功能：读入等式，并判断是否正确
* 参数：char* std
* 结果：正确返回true,错误返回false
*/
bool check_equation(char* std);

/*
* 功能：将数字字符转化成数字
* 参数：char ch
* 结果: 返回对应数字
*/
int charnum_to_intnum(char char_number);

/*
* 功能：提取数值字符串
* 参数：字符串开始的首地址
* 结果：返回数值字符串值
*/
char* extract_number(const char* base_std);

/*
* 功能：提取数值等式
* 参数：字符串开始的首地址
* 结果：等式
*/
char* extract_equation_to_char(const char* base_std);