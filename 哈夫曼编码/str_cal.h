#pragma once
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define STR_LENGTH 100 //先搞大一点，暂时无法进行增长
#define EXTEND_LENGTH 20

typedef struct String {
	char* str;
	int all_count;
	int now_count;
}String;

/*
* 功能：输入明文
* 结果：返回字符串头指针
*/
String* input_code();

/*
* 功能：建立String线性表
* 结果：返回String指针
*/
String* creat_String();

/*
* 功能: 判断是否表满
* 结果：满返回真，不满返回假
*/
bool is_full(String* str);

/*
* 功能：扩展表的长度,每次扩展20个字符
* 结果：表的长度被扩展
*/
void extend_str(String* str);

/*
* 功能：插入字符
* 结果：扩容失败，程序结束
*/
void insert_ch(String* str, char i_ch);