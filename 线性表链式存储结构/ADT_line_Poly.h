#pragma once
/*
多项式相加
*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef struct Polynomial {
	int pow;
	double cof;
	Polynomial* next;
}Poly;

/*
功能：构造一个空的线性表List
参数：Poly** L
结果：成功返回0，L已含有指向返回-1，表分配不成功返回-2，表数据poly分配不成功返回-3。
*/
int InitList(Poly** L);

/*
功能：判断线性表是否为空表
参数：Poly *L
结果：空表返回0，表不存在返回-1，不是空表返回-2。
*/
int isEmptyList(Poly* L);

/*
功能：返回表的长度
参数：Poly *L
结果：返回线性表L中的数据元素个数。若表不存在返回-1.
*/
int ListLength(Poly* L);

/*
功能：销毁线性表
参数：Poly** L
结果：成功返回0，表不存在返回-1.
*/
int DestroyList(Poly** L);

/*
功能：将线性表重置为空表
参数：Poly** L
结果：成功返回0，表不存在返回-1,重置表数据失败返回-2，
*/
int ClearList(Poly** L);

/*
功能：获取线性表中第i个数据元素的值
参数：Poly* L, int i, Poly** e
结果：用e返回线性表L中第i个数据元素的值，成功返回0，表不存在返回-1，越界返回-2
*/
int getElem(Poly* L, int i, Poly** e);

/*
功能：定位或查找，元素e在某个判定条件下关系
参数：PolyList *L，Poly e，int(*compare)com(const void*)
结果：返回L中第1个与e满足compare()的数据元素的位序，若这样的数据元素不存在则返回值0，若表不存在返回-1。
*/
int LocateElem(Poly* L, const Poly e, int(con)(const Poly e, const Poly e1));

/*
功能：查找前驱元素
参数：PolyList *L，Poly cur_e,Poly* pre_e
结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱否则操作失败；若表不存在返回-1.
	 无前驱返回1，查找失败返回-2.
*/
int PriorElem(Poly* L, Poly cur_e, Poly** pre_e);

/*
功能：查找后继元素
参数：PolyList *L，Poly cur_e,Poly* pre_e
结果：若cur_e是L的数据元素，且不是最后一个，则用pre_e返回它的后继否则操作失败；若表不存在返回-1.
	  无后继返回1，查找失败返回-2.
*/
int NextElem(Poly* L, Poly cur_e, Poly** next_e);

/*
功能：在i的位置插入元素
参数：PolyList* L,int i,Poly e
结果：插入成功返回0，表不存在返回-1，插入位置错误返回-2.扩充失败返回-3
*/
int InsertList(Poly* L, int i, Poly e);

/*
功能：删除第i个元素
参数：PolyList* L,int i
结果：删除成功返回0，表不存在返回-1。删除位置错误返回-2.
*/
int DeleteList(Poly* L, int i);

/*
功能：对表中每个元素调用visited()函数
参数：PolyList* L，void(*visited)()
结果：成功返回0，表不存在返回-1，失败返回-2；
*/
int ListTraverse(Poly* L, void(*visited)(Poly e));

/*
功能：输入初始值
参数：PolyList* L
结果：成功返回0，表不存在返回-1，扩容失败返回-2；
*/
int inputList(Poly* L);

/*
功能：按pow大小排序
参数：PolyList* L
结果：成功返回0，表不存在返回-1；
*/
int sortOfCofList(Poly* L);

/*
功能：多项式加减运算
参数：PolyList* L1,PolyList* L2,PolyList** answer;
结果：多项式L1 + L2 = answer，由answer带回
*/
int computePoly(Poly* L1, Poly* L2, Poly* answer, char(com)());