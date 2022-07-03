/*
多项式相加
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;

#define INIT_SIZE 20    //线性表存储空间的初始分配量
#define ADD_SIZE 10		//线性表存储空间的分配增量

//多项式数据类型
typedef struct Polynomial{
	int pow;
	double cof;
}Poly;

typedef struct List {
	Poly* poly;
	int length;
	int listSize;
}PolyList;

/*
功能：构造一个空的线性表List
参数：PolyList** L
结果：成功返回0，L已含有指向返回-1，表分配不成功返回-2，表数据poly分配不成功返回-3。
*/
int InitList(PolyList** L);

/*
功能：判断线性表是否为空表
参数：PolyList *L
结果：空表返回0，表不存在返回-1，不是空表返回-2。
*/
int isEmptyList(PolyList *L);

/*
功能：返回表的长度
参数：PolyList *L
结果：返回线性表L中的数据元素个数。若表不存在返回-1.
*/
int ListLength(PolyList* L);

/*
功能：销毁线性表
参数：PolyList *L
结果：成功返回0，表不存在返回-1.
*/
int DestroyList(PolyList** L);

/*
功能：将线性表重置为空表
参数：PolyList *L
结果：成功返回0，表不存在返回-1,重置表数据失败返回-2，
*/
int ClearList(PolyList** L);

/*
功能：获取线性表中第i个数据元素的值
参数：PolyList *L，int i，Poly *e
结果：用e返回线性表L中第i个数据元素的值，成功返回0，表不存在返回-1，越界返回-2
*/
int getElem(PolyList* L, int i, Poly* e);

/*
功能：定位或查找，元素e在某个判定条件下关系
参数：PolyList *L，Poly e，int(*compare)com(const void*)
结果：返回L中第1个与e满足compare()的数据元素的位序，若这样的数据元素不存在则返回值0，若表不存在返回-1。
*/
int LocateElem(PolyList* L, const Poly e, int(con)(const Poly e, const Poly e1));

/*
功能：查找前驱元素
参数：PolyList *L，Poly cur_e,Poly* pre_e
结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱否则操作失败；若表不存在返回-1.
	 无前驱返回1，查找失败返回-2.
*/
int PriorElem(PolyList* L,Poly cur_e, Poly* pre_e);

/*
功能：查找后继元素
参数：PolyList *L，Poly cur_e,Poly* pre_e
结果：若cur_e是L的数据元素，且不是最后一个，则用pre_e返回它的后继否则操作失败；若表不存在返回-1.
	  无后继返回1，查找失败返回-2.
*/
int NextElem(PolyList* L, Poly cur_e, Poly* next_e);

/*
功能：在i的位置插入元素
参数：PolyList* L,int i,Poly e
结果：插入成功返回0，表不存在返回-1，插入位置错误返回-2.扩充失败返回-3
*/
int InsertList(PolyList* L, int i, Poly e);

/*
功能：删除第i个元素
参数：PolyList* L,int i
结果：删除成功返回0，表不存在返回-1。删除位置错误返回-2.
*/
int DeleteList(PolyList* L, int i);

/*
功能：对表中每个元素调用visited()函数
参数：PolyList* L，void(*visited)()
结果：成功返回0，表不存在返回-1，失败返回-2；
*/
int ListTraverse(PolyList* L, void(*visited)(Poly e));

/*
功能：输入初始值
参数：PolyList* L
结果：成功返回0，表不存在返回-1，扩容失败返回-2；
*/
int inputList(PolyList* L);

/*
功能：按cof大小排序
参数：PolyList* L
结果：成功返回0，表不存在返回-1；
*/
int sortOfCofList(PolyList* L);

/*
功能：多项式加减运算
参数：PolyList* L1,PolyList* L2,PolyList** answer;
结果：多项式L1 + L2 = answer，由answer带回
*/
int computePoly(PolyList* L1, PolyList* L2, PolyList** answer, char(com)());

int con(const void* a) {
	if (((Poly*)a)->cof == 1) {
		return 0;
	}

	return -1;
}

void vis(Poly e) {
	cout << "cof = " << e.cof << "  pow = " << e.pow << endl;
}

char com() {
	return '-';
}

int con(const Poly e,const Poly e1) {
	if (e.cof == e1.cof && e.pow == e1.pow) {
		return 0;
	}
	return -1;
}


int main() {

	PolyList* list = NULL;
	
	//初始化表
	int ret = InitList(&list);
	if (ret != 0) {
		printf("InitList error:%d", ret);
		return ret;
	}

	//输入数值
	inputList(list);

	PolyList* list1 = NULL;

	//初始化表
	int ret1 = InitList(&list1);
	if (ret1 != 0) {
		printf("InitList error:%d", ret1);
		return ret1;
	}

	//输入数值
	inputList(list1);

	PolyList* answer = NULL;

	//初始化表
	int ret2 = InitList(&answer);
	if (ret2 != 0) {
		printf("InitList error:%d", ret2);
		return ret2;
	}

	//测试并排好序输出
	computePoly(list, list1, &answer, com);
	//进行排序
	sortOfCofList(answer);
	//输出list中的值
	ListTraverse(answer, vis);

	//测试getElem
	//取得answer表第2个值的内容
	Poly temp;
	getElem(answer, 2, &temp);
	cout << "get answer.poly[1].cof = " << temp.cof << "  answer.poly[1].cof = " << temp.pow << endl;

	//测试LocateElem
	//查找answer中是否含有与(*answer).poly[1]元素一样的元素
	cout << "index :" << LocateElem(answer, (*answer).poly[1], con) << endl;

	//测试PriorElem和NextElem
	//返回answer中(*answer).poly[1]的前驱
	Poly pre_e;
	PriorElem(answer, (*answer).poly[1], &pre_e);
	cout << "pre_e.cof = " << pre_e.cof << "  pre_e.cof = " << pre_e.pow << endl;
	//返回answer中(*answer).poly[1]的后继
	Poly next_e;
	NextElem(answer, (*answer).poly[1], &next_e);
	cout << "next_e.cof = " << next_e.cof << "  next_e.cof = " << next_e.pow << endl;

	//测试DeleteList
	//删除answer表第2个值
	DeleteList(answer, 2);
	//取得answer表第2个值的内容
	cout << "delete answer.poly[1].cof = " << (*answer).poly[1].cof << "  answer.poly[1].cof = " << (*answer).poly[1].pow << endl;

	//测试清空表
	//清空list表
	ClearList(&list);
	if (isEmptyList(list) == 0) {
		cout << "list is empty!" << endl;
	}

	//测试销毁表
	//销毁list表
	DestroyList(&list);
	if (list == NULL) {
		cout << "list is destroied now!" << endl;
	}
	return 0;
}





int InitList(PolyList** L) {

	//判断是否含有指向
	if (*L != NULL) {
		return -1;
	}

	//给表分配空间
	PolyList* temp = NULL;
	temp = (PolyList*)malloc(sizeof(PolyList));

	//判断是否分配成功
	if (temp == NULL) {
		return -2;
	}

	//初始化分配长度
	Poly* temp_poly = NULL;
	temp_poly = (Poly*)malloc(sizeof(Poly) * INIT_SIZE);
	if (temp_poly == NULL) {
		return -3;
	}

	temp->poly = temp_poly;
	temp->length = 0;
	temp->listSize = INIT_SIZE;

	//分配成功即返回
	*L = temp;

	return 0;
}

int isEmptyList(PolyList *L) {

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	//判断是否为空表
	if (L->length != 0) {
		return -2;
	}

	return 0;
}

int ListLength(PolyList* L) {

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	//返回表的长度
	return L->length;
}

int DestroyList(PolyList** L) {

	//判断表是否存在
	if (*L == NULL) {
		return -1;
	}

	free(*L);
	*L = NULL;

	return 0;
}

int ClearList(PolyList** L) {

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	//判断是否已为空表
	if (!isEmptyList(*L)) {
		return 0;
	}

	//重新分配内存
	Poly* temp = (Poly*)realloc((*L)->poly, sizeof(Poly) * INIT_SIZE);
	if (temp == NULL) {
		return -2;
	}

	//重置为空表
	(*L)->poly = temp;
	(*L)->length = 0;
	(*L)->listSize = INIT_SIZE;

	return 0;
}

int getElem(PolyList* L, int i, Poly* e) {

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	//判断是否越界
	if (i < 1 || i > L->length) {
		return -2;
	}

	//带回第i个数据元素的值
	Poly temp = (L->poly)[i - 1];
	*e = temp;

	return 0;
}

int LocateElem(PolyList* L, const Poly e, int(con)(const Poly e, const Poly e1)) {

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	int ret = 0;
	for (int i = 0; i < L->length; i++) {
		if (con(L->poly[i],e) == 0) {
			ret = i + 1;
			break;
		}
	}
	return ret;
}

int PriorElem(PolyList* L, const Poly cur_e, Poly* pre_e) {

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	//搜索
	int index = 0;
	for (index = 0; index < L->length; index++) {
		if (cur_e.cof == (*L).poly[index].cof &&
			cur_e.pow == (*L).poly[index].pow) {

			break;
		}
	}

	//判断是否为第一个
	if (index == 0) {
		return 1;
	}

	//判断是否查找成功
	else if (index == L->length) {
		return -2;
	}

	//查找成功，返回前驱
	*pre_e = (*L).poly[index - 1];

	return 0;
}

int NextElem(PolyList* L, Poly cur_e, Poly* next_e) {

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	//搜索
	int index = 0;
	for (index = 0; index < L->length; index++) {
		if (cur_e.cof == (*L).poly[index].cof &&
			cur_e.pow == (*L).poly[index].pow) {

			break;
		}
	}

	//判断是否为最后一个
	if (index == L->length - 1) {
		return 1;
	}

	//判断是否查找成功
	else if (index == L->length) {
		return -2;
	}

	//查找成功，返回前驱
	*next_e = (*L).poly[index  + 1];

	return 0;
}

int InsertList(PolyList* L, int i, Poly e) {

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	//判断插入位置是否正确
	if (i < 1 || i > ListLength(L) + 1) {
		return -2;
	}

	Poly* newbase = NULL;
	//判断是否需要扩容
	if (L->length == L->listSize) {

		//扩充空间
		newbase = (Poly*)realloc(L->poly, sizeof(Poly) * (L->listSize + ADD_SIZE));

		//过充失败
		if (newbase == NULL) {
			return -3;
		}

		//扩充成功
		L->poly = newbase;		
		L->listSize += ADD_SIZE;
	}

	//移动表格元素
	for (int index = L->length - 1; index >= i-1; index++) {
		(L->poly)[index + 1].cof = (L->poly)[index].cof;
		L->poly[index + 1].pow = L->poly[index].pow;
	}

	//插入
	L->poly[i - 1].cof = e.cof;
	L->poly[i - 1].pow = e.pow;
	L->length++;

	return 0;
}

int DeleteList(PolyList* L, int i) {

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	//判断删除位置是否正确
	if (i < 1 || i > ListLength(L) + 1) {
		return -2;
	}

	//移动元素，以达到删除效果
	for (int index = L->length - 1; index > i - 1; index--) {
		L->poly[index - 1].cof = L->poly[index].cof;
		L->poly[index - 1].pow = L->poly[index].pow;
	}
	L->length--;

	return 0;
}

int ListTraverse(PolyList* L, void(*visited)(const Poly e)) {

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	//对每个元素执行visited函数
	for (int i = 0; i < L->length; i++) {
		visited(L->poly[i]);
	}

	return 0;
}

int inputList(PolyList* L) {

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	//添加数据
	printf("Input date('#' stop):\n");
	do {
		

		//判断添加内存是否充足
		if (L->length > L->listSize) {
			
			Poly* newbase = (Poly*)realloc(L->poly, sizeof(Poly) * (L->length + ADD_SIZE));

			if (newbase == NULL) {
				return -2;
			}

			L->poly = newbase;
			L->listSize += ADD_SIZE;
		}

		//输入
		char str[100] = { 0 };
		cout << "Please input cof and pow (cof,pow) :";
		if (str[0] == '#') {
			break;
		}
		cin >> str;

		//输入长度不合格
		if (strlen(str) < 3) {
			cout << "Please again!" << endl;
			continue;
		}

		L->poly[L->length].cof = (int)(str[0] - '0');
		L->poly[L->length].pow = (int)(str[2] - '0');
		L->length++;
		//判断是否可以跳出
		if (str[strlen(str) - 1] == '#') {
			break;
		}

	} while (true);
	cout << "Input date end!" << endl;

	return 0;
}

int sortOfCofList(PolyList* L) {

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	//进行排序
	for (int i = 0; i < L->length - 1; i++) {
		for (int j = i + 1; j < L->length; j++) {
			if (L->poly[i].pow > L->poly[j].pow) {
				Poly temp = L->poly[i];
				L->poly[i] = L->poly[j];
				L->poly[j] = temp;
			}
		}
	}

	return 0;
}

int computePoly(PolyList* L1, PolyList* L2, PolyList** answer,char(com)()) {
	
	//判断表是否存在
	if (L1 == NULL || L2 == NULL || answer == NULL) {
		return -1;
	}

	//排序两个多项式
	sortOfCofList(L1);
	sortOfCofList(L2);

	//进行运算
	int indexL1 = 0;
	int indexL2 = 0;
	while (indexL1 < ListLength(L1) && indexL2 < ListLength(L2)) {

		Poly temp;
		if (L1->poly[indexL1].pow < L2->poly[indexL2].pow) {
			
			temp.cof = L1->poly[indexL1].cof;
			temp.pow = L1->poly[indexL1].pow;
			indexL1++;
		}
		else if (L1->poly[indexL1].pow > L2->poly[indexL2].pow) {

			temp.cof = L1->poly[indexL2].cof;
			temp.pow = L2->poly[indexL2].pow;
			indexL2++;
		}
		else {

			if (com() == '+') {
				temp.cof = L1->poly[indexL1].cof + L2->poly[indexL2].cof;
			}

			else if (com() == '-') {
				temp.cof = L1->poly[indexL1].cof - L2->poly[indexL2].cof;
			}

			else {
				return -2;
			}

			temp.pow = L1->poly[indexL1].pow;
			indexL1++;
			indexL2++;
		}

		InsertList(*answer, (*answer)->length+1, temp);
	}

	if (indexL1 == ListLength(L1)) {

		for (; indexL2 < ListLength(L2); indexL2++) {
			InsertList(*answer, (*answer)->length+1, L2->poly[indexL2]);
		}
	}
	else {

		for (; indexL1 < ListLength(L1); indexL1++) {
			InsertList(*answer, (*answer)->length+1, L1->poly[indexL1]);
		}
	}

	return 0;
}