#pragma once
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define STR_LENGTH 100 //�ȸ��һ�㣬��ʱ�޷���������
#define EXTEND_LENGTH 20

typedef struct String {
	char* str;
	int all_count;
	int now_count;
}String;

/*
* ���ܣ���������
* ����������ַ���ͷָ��
*/
String* input_code();

/*
* ���ܣ�����String���Ա�
* ���������Stringָ��
*/
String* creat_String();

/*
* ����: �ж��Ƿ����
* ������������棬�������ؼ�
*/
bool is_full(String* str);

/*
* ���ܣ���չ��ĳ���,ÿ����չ20���ַ�
* �������ĳ��ȱ���չ
*/
void extend_str(String* str);

/*
* ���ܣ������ַ�
* ���������ʧ�ܣ��������
*/
void insert_ch(String* str, char i_ch);