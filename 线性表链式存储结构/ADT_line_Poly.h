#pragma once
/*
����ʽ���
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
���ܣ�����һ���յ����Ա�List
������Poly** L
������ɹ�����0��L�Ѻ���ָ�򷵻�-1������䲻�ɹ�����-2��������poly���䲻�ɹ�����-3��
*/
int InitList(Poly** L);

/*
���ܣ��ж����Ա��Ƿ�Ϊ�ձ�
������Poly *L
������ձ���0�������ڷ���-1�����ǿձ���-2��
*/
int isEmptyList(Poly* L);

/*
���ܣ����ر�ĳ���
������Poly *L
������������Ա�L�е�����Ԫ�ظ������������ڷ���-1.
*/
int ListLength(Poly* L);

/*
���ܣ��������Ա�
������Poly** L
������ɹ�����0�������ڷ���-1.
*/
int DestroyList(Poly** L);

/*
���ܣ������Ա�����Ϊ�ձ�
������Poly** L
������ɹ�����0�������ڷ���-1,���ñ�����ʧ�ܷ���-2��
*/
int ClearList(Poly** L);

/*
���ܣ���ȡ���Ա��е�i������Ԫ�ص�ֵ
������Poly* L, int i, Poly** e
�������e�������Ա�L�е�i������Ԫ�ص�ֵ���ɹ�����0�������ڷ���-1��Խ�緵��-2
*/
int getElem(Poly* L, int i, Poly** e);

/*
���ܣ���λ����ң�Ԫ��e��ĳ���ж������¹�ϵ
������PolyList *L��Poly e��int(*compare)com(const void*)
���������L�е�1����e����compare()������Ԫ�ص�λ��������������Ԫ�ز������򷵻�ֵ0���������ڷ���-1��
*/
int LocateElem(Poly* L, const Poly e, int(con)(const Poly e, const Poly e1));

/*
���ܣ�����ǰ��Ԫ��
������PolyList *L��Poly cur_e,Poly* pre_e
�������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ���������ʧ�ܣ��������ڷ���-1.
	 ��ǰ������1������ʧ�ܷ���-2.
*/
int PriorElem(Poly* L, Poly cur_e, Poly** pre_e);

/*
���ܣ����Һ��Ԫ��
������PolyList *L��Poly cur_e,Poly* pre_e
�������cur_e��L������Ԫ�أ��Ҳ������һ��������pre_e�������ĺ�̷������ʧ�ܣ��������ڷ���-1.
	  �޺�̷���1������ʧ�ܷ���-2.
*/
int NextElem(Poly* L, Poly cur_e, Poly** next_e);

/*
���ܣ���i��λ�ò���Ԫ��
������PolyList* L,int i,Poly e
���������ɹ�����0�������ڷ���-1������λ�ô��󷵻�-2.����ʧ�ܷ���-3
*/
int InsertList(Poly* L, int i, Poly e);

/*
���ܣ�ɾ����i��Ԫ��
������PolyList* L,int i
�����ɾ���ɹ�����0�������ڷ���-1��ɾ��λ�ô��󷵻�-2.
*/
int DeleteList(Poly* L, int i);

/*
���ܣ��Ա���ÿ��Ԫ�ص���visited()����
������PolyList* L��void(*visited)()
������ɹ�����0�������ڷ���-1��ʧ�ܷ���-2��
*/
int ListTraverse(Poly* L, void(*visited)(Poly e));

/*
���ܣ������ʼֵ
������PolyList* L
������ɹ�����0�������ڷ���-1������ʧ�ܷ���-2��
*/
int inputList(Poly* L);

/*
���ܣ���pow��С����
������PolyList* L
������ɹ�����0�������ڷ���-1��
*/
int sortOfCofList(Poly* L);

/*
���ܣ�����ʽ�Ӽ�����
������PolyList* L1,PolyList* L2,PolyList** answer;
���������ʽL1 + L2 = answer����answer����
*/
int computePoly(Poly* L1, Poly* L2, Poly* answer, char(com)());