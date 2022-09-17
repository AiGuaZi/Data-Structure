#pragma once
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

#define INIT_SIZE 20                    //��ʼ������
#define ADD_SIZE 20                     //���䳤��
#define ERROR -1                        //����
#define NO_MEMORY -18                   //�ڴ治��
#define CENTRY 1                        //�ڱ���־

typedef int KeyType;                    //�ؼ�������

typedef struct Date {                   //���ݽڵ�ṹ��
	int num;                            //��ֵ������
}Date;

typedef struct DateArrayNode {          //�������ݽڵ�ṹ��
	Date date;                          //��������
	KeyType key;                        //���ݹؼ���
}DateArrayNode;

typedef struct SqList {                 //����˳���ڵ�
	DateArrayNode* date_array;          //�������ݼ���
	int length;                         //˳�����
	int i_now;                          //��ǰ�洢λ��
}SqList;

/*  ˳���������  */
/*��ʼ��˳���*/
void Init_Sqlist(SqList* list);//�������һ��ʵ�壬����ָ��
/*����˳���*/
void creat_Sqlist(SqList* list);
/*�ж��Ƿ����*/
bool is_full(SqList* list);
/*����˳�����*/
void extend_list(SqList* list, int new_length);
/*��������*/
void input_date(SqList* list);
/*�������˳�������*/
void print_Sqlist(SqList list);
/*��ӡ���ݽڵ�����*/
void print_Date(Date date);
/*����Ϊ���ڱ�˳���*/
void set_sentry(SqList* list);
/*���ֲ���*/
//begin:��ʼ�±꣬end:�����±꣨������end�����ش������λ��
int bin_search_Sqlist(SqList* list, Date elem, int begin, int end);

/*  ��������  */
/*ֱ�Ӳ�������*/
void insert_sort_direct(SqList* list);
/*���ֲ�������*/
void insert_sort_bin(SqList* list);



/*  ����  */
void no_memory();
/*��ָ���ж�*/
void if_NULL(SqList* list);