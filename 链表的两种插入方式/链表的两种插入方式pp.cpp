#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;


typedef struct INT_List {
	int date;
	INT_List* next;
}INT;

INT* creat_List() {

	INT* list = (INT*)malloc(sizeof(int));
	if (!list) {
		return NULL;
	}
	list->next = NULL;

	//INT* list = NULL;
	return list;
}

//ͷ�巨
/*
 -��Ԫ�ز����������ͷ��λ��
 */
bool head_insert_date(INT** L) {

	if (*L == NULL) {
		return false;
	}

	INT* temp = (INT*)malloc(sizeof(INT));
	if (!temp) {
		return false;
	}
	temp->next = NULL;

	cout << "Please input a number:";
	cin >> temp->date;

	if ((*L)->next != NULL)
		temp->next = (*L)->next;
	(*L)->next = temp;



	return true;

}

//β�巨
/*
-��Ԫ�ز��뵽�����β����
-ÿ�β��붼��Ҫ��ȡ�������β����
-Ч�ʵ���ͷ�巨
*/
bool tail_insert_list(INT** L) {
	
	if (*L == NULL) {
		return false;
	}

	INT* tail = *L;
	while (tail->next) {
		tail = tail->next;
	}

	INT* temp = (INT*)malloc(sizeof(INT));
	if (temp == NULL) {
		return false;
	}
	temp->next = NULL;
	cout << "Please input a number:";
	cin >> temp->date;

	tail->next = temp;
	tail = temp;

	return true;
}

int main() {
	INT* list = creat_List();
	for (int i = 0; i < 3; i++) {
		tail_insert_list(&list);
	}
	INT* p = list->next;

	int i = 0;
	while (p) {
		i++;
		cout << p->date << endl;
		p = p->next;
	}
	return 0;
}