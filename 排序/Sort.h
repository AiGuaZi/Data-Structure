#pragma once
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

#define INIT_SIZE 20                    //初始化长度
#define ADD_SIZE 20                     //扩充长度
#define ERROR -1                        //错误
#define NO_MEMORY -18                   //内存不足
#define CENTRY 1                        //哨兵标志

typedef int KeyType;                    //关键字类型

typedef struct Date {                   //数据节点结构体
	int num;                            //数值型数据
}Date;

typedef struct DateArrayNode {          //排序数据节点结构体
	Date date;                          //排序数据
	KeyType key;                        //数据关键字
}DateArrayNode;

typedef struct SqList {                 //排序顺序表节点
	DateArrayNode* date_array;          //排序数据集合
	int length;                         //顺序表长度
	int i_now;                          //当前存储位置
}SqList;

/*  顺序表环境建立  */
/*初始化顺序表*/
void Init_Sqlist(SqList* list);//传入的是一个实体，而非指针
/*建立顺序表*/
void creat_Sqlist(SqList* list);
/*判断是否表满*/
bool is_full(SqList* list);
/*扩充顺序表长度*/
void extend_list(SqList* list, int new_length);
/*输入数据*/
void input_date(SqList* list);
/*遍历输出顺序表内容*/
void print_Sqlist(SqList list);
/*打印数据节点内容*/
void print_Date(Date date);
/*设置为带哨兵顺序表*/
void set_sentry(SqList* list);
/*二分查找*/
//begin:开始下标，end:结束下标（不包括end）返回待插入的位置
int bin_search_Sqlist(SqList* list, Date elem, int begin, int end);

/*  插入排序  */
/*直接插入排序*/
void insert_sort_direct(SqList* list);
/*二分插入排序*/
void insert_sort_bin(SqList* list);



/*  工具  */
void no_memory();
/*空指针判断*/
void if_NULL(SqList* list);