#pragma once

#include<iostream>
#include<stdlib.h>
using namespace std;

#define INIT_SIZE 10
#define ADD_SIZE 20

typedef struct Stack {
	int* top;			//栈顶指针
	int* base;			//内存分配首地址指针
	int stack_Size;		//栈空间大小
}INT;

/*
* 功能：创建栈
* 参数：INT *S
* 结果：成功返回true，失败返回false
*/
bool creat_stack(INT** S);

/*
* 功能：判断是否为空栈
* 参数：INT *S
* 结果：空栈返回true，否则返回false
*/
bool stack_is_empty(INT* S);

/*
* 功能：判断是否为满栈
* 参数：INT *S
* 结果：满栈返回true，否则返回false
*/
bool stack_is_full(INT* S);

/*
* 功能：计算栈的长度
* 参数：INT *S
* 结果：返回元素个数
*/
int stack_length(INT* S);

/*
* 功能：置空栈
* 参数：INT *S
* 结果：成功返回true，失败返回false
*/
bool clear_statck(INT* S);

/*
* 功能：销毁栈
* 参数：INT **S
* 结果：成功返回true，失败返回false
*/
bool destroy_stack(INT** S);

/*
* 功能：元素入栈
* 参数：INT *S,int e
* 结果：成功返回true，失败返回false
*/
bool push(INT* S,int e);

/*
* 功能：元素出栈
* 参数：INT *S,int *e
* 结果：成功返回true，失败返回false
*/
bool pop(INT* S, int* e);

/*
* 功能：取栈顶元素
* 参数：INT *S,int *e
* 结果：成功返回true，失败返回false
*/
bool getTop(INT* S, int* e);

/*
* 功能：遍历栈，栈内每个元素都执行com函数
* 参数：INT *S
* 结果：对所有元素都执行com函数
*/
void traversal_stack(INT* S,void(com)(const void *elem));