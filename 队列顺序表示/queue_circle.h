#pragma once

#include<iostream>
#include<stdlib.h>

using namespace std;

#define MAX_SIZE 10

typedef struct Queue {
	int* data;			//数据储存内存
	int front;			//头指针
	int rear;			//尾指针
}INT;

/*
* 功能:创建一个队列
* 参数：INT *Q
* 结果：成功返回真，失败返回假
*/
bool creat_queue(INT** Q);

/*
* 功能：循环自增或自减
* 参数：int i,int max,char operator
* 结果：返回自增或自减后的值,失败返回0
*/
int up_or_down(int i, int max,char oper);

/*
* 功能：入队
* 参数：INT*Q,int i
* 结果：成功返回true，失败返回false
*/
bool in_queue(INT* Q, int e);

/*
* 功能：判断队满
* 参数：INT*Q
* 结果：队满返回真，否则返回假
*/
bool is_queue_full(INT* Q);

/*
* 功能：遍历队列
* 参数：INT *Q,void (com)(const void* elem)
* 结果：对队内所有元素执行com函数
*/
void traverse_queue(INT* Q, void (com)(const void* elem));

/*
* 功能：出队
* 参数：INT*Q,int *e
* 结果：成功返回true，失败返回false
*/
bool out_queue(INT* Q, int *e);

/*
* 功能：取队头元素
* 参数：INT*Q,int *e
* 结果：成功返回true，失败返回false
*/
bool get_queue(INT* Q, int* e);

/*
* 功能：计算队长
* 参数：INT*Q
* 结果：成功返回队长，失败返回-1；
*/
int queue_length(INT* Q);