#pragma once
#include<iostream>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

#define EQUATION_MAX_SIZE 100

/*
* ���ܣ�����ռ�
* ��������
* ��������ر����ʽ�ĵ�ַ
*/
char* creat_equation();

/*
* ���ܣ������ʽ�����ж��Ƿ���ȷ
* ������char* std
* �������ȷ����true,���󷵻�false
*/
bool check_equation(char* std);

/*
* ���ܣ��������ַ�ת��������
* ������char ch
* ���: ���ض�Ӧ����
*/
int charnum_to_intnum(char char_number);

/*
* ���ܣ���ȡ��ֵ�ַ���
* �������ַ�����ʼ���׵�ַ
* �����������ֵ�ַ���ֵ
*/
char* extract_number(const char* base_std);

/*
* ���ܣ���ȡ��ֵ��ʽ
* �������ַ�����ʼ���׵�ַ
* �������ʽ
*/
char* extract_equation_to_char(const char* base_std);