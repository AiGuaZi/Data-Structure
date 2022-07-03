/*
����ʽ���
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;

#define INIT_SIZE 20    //���Ա�洢�ռ�ĳ�ʼ������
#define ADD_SIZE 10		//���Ա�洢�ռ�ķ�������

//����ʽ��������
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
���ܣ�����һ���յ����Ա�List
������PolyList** L
������ɹ�����0��L�Ѻ���ָ�򷵻�-1������䲻�ɹ�����-2��������poly���䲻�ɹ�����-3��
*/
int InitList(PolyList** L);

/*
���ܣ��ж����Ա��Ƿ�Ϊ�ձ�
������PolyList *L
������ձ���0�������ڷ���-1�����ǿձ���-2��
*/
int isEmptyList(PolyList *L);

/*
���ܣ����ر�ĳ���
������PolyList *L
������������Ա�L�е�����Ԫ�ظ������������ڷ���-1.
*/
int ListLength(PolyList* L);

/*
���ܣ��������Ա�
������PolyList *L
������ɹ�����0�������ڷ���-1.
*/
int DestroyList(PolyList** L);

/*
���ܣ������Ա�����Ϊ�ձ�
������PolyList *L
������ɹ�����0�������ڷ���-1,���ñ�����ʧ�ܷ���-2��
*/
int ClearList(PolyList** L);

/*
���ܣ���ȡ���Ա��е�i������Ԫ�ص�ֵ
������PolyList *L��int i��Poly *e
�������e�������Ա�L�е�i������Ԫ�ص�ֵ���ɹ�����0�������ڷ���-1��Խ�緵��-2
*/
int getElem(PolyList* L, int i, Poly* e);

/*
���ܣ���λ����ң�Ԫ��e��ĳ���ж������¹�ϵ
������PolyList *L��Poly e��int(*compare)com(const void*)
���������L�е�1����e����compare()������Ԫ�ص�λ��������������Ԫ�ز������򷵻�ֵ0���������ڷ���-1��
*/
int LocateElem(PolyList* L, const Poly e, int(con)(const Poly e, const Poly e1));

/*
���ܣ�����ǰ��Ԫ��
������PolyList *L��Poly cur_e,Poly* pre_e
�������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ���������ʧ�ܣ��������ڷ���-1.
	 ��ǰ������1������ʧ�ܷ���-2.
*/
int PriorElem(PolyList* L,Poly cur_e, Poly* pre_e);

/*
���ܣ����Һ��Ԫ��
������PolyList *L��Poly cur_e,Poly* pre_e
�������cur_e��L������Ԫ�أ��Ҳ������һ��������pre_e�������ĺ�̷������ʧ�ܣ��������ڷ���-1.
	  �޺�̷���1������ʧ�ܷ���-2.
*/
int NextElem(PolyList* L, Poly cur_e, Poly* next_e);

/*
���ܣ���i��λ�ò���Ԫ��
������PolyList* L,int i,Poly e
���������ɹ�����0�������ڷ���-1������λ�ô��󷵻�-2.����ʧ�ܷ���-3
*/
int InsertList(PolyList* L, int i, Poly e);

/*
���ܣ�ɾ����i��Ԫ��
������PolyList* L,int i
�����ɾ���ɹ�����0�������ڷ���-1��ɾ��λ�ô��󷵻�-2.
*/
int DeleteList(PolyList* L, int i);

/*
���ܣ��Ա���ÿ��Ԫ�ص���visited()����
������PolyList* L��void(*visited)()
������ɹ�����0�������ڷ���-1��ʧ�ܷ���-2��
*/
int ListTraverse(PolyList* L, void(*visited)(Poly e));

/*
���ܣ������ʼֵ
������PolyList* L
������ɹ�����0�������ڷ���-1������ʧ�ܷ���-2��
*/
int inputList(PolyList* L);

/*
���ܣ���cof��С����
������PolyList* L
������ɹ�����0�������ڷ���-1��
*/
int sortOfCofList(PolyList* L);

/*
���ܣ�����ʽ�Ӽ�����
������PolyList* L1,PolyList* L2,PolyList** answer;
���������ʽL1 + L2 = answer����answer����
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
	
	//��ʼ����
	int ret = InitList(&list);
	if (ret != 0) {
		printf("InitList error:%d", ret);
		return ret;
	}

	//������ֵ
	inputList(list);

	PolyList* list1 = NULL;

	//��ʼ����
	int ret1 = InitList(&list1);
	if (ret1 != 0) {
		printf("InitList error:%d", ret1);
		return ret1;
	}

	//������ֵ
	inputList(list1);

	PolyList* answer = NULL;

	//��ʼ����
	int ret2 = InitList(&answer);
	if (ret2 != 0) {
		printf("InitList error:%d", ret2);
		return ret2;
	}

	//���Բ��ź������
	computePoly(list, list1, &answer, com);
	//��������
	sortOfCofList(answer);
	//���list�е�ֵ
	ListTraverse(answer, vis);

	//����getElem
	//ȡ��answer���2��ֵ������
	Poly temp;
	getElem(answer, 2, &temp);
	cout << "get answer.poly[1].cof = " << temp.cof << "  answer.poly[1].cof = " << temp.pow << endl;

	//����LocateElem
	//����answer���Ƿ�����(*answer).poly[1]Ԫ��һ����Ԫ��
	cout << "index :" << LocateElem(answer, (*answer).poly[1], con) << endl;

	//����PriorElem��NextElem
	//����answer��(*answer).poly[1]��ǰ��
	Poly pre_e;
	PriorElem(answer, (*answer).poly[1], &pre_e);
	cout << "pre_e.cof = " << pre_e.cof << "  pre_e.cof = " << pre_e.pow << endl;
	//����answer��(*answer).poly[1]�ĺ��
	Poly next_e;
	NextElem(answer, (*answer).poly[1], &next_e);
	cout << "next_e.cof = " << next_e.cof << "  next_e.cof = " << next_e.pow << endl;

	//����DeleteList
	//ɾ��answer���2��ֵ
	DeleteList(answer, 2);
	//ȡ��answer���2��ֵ������
	cout << "delete answer.poly[1].cof = " << (*answer).poly[1].cof << "  answer.poly[1].cof = " << (*answer).poly[1].pow << endl;

	//������ձ�
	//���list��
	ClearList(&list);
	if (isEmptyList(list) == 0) {
		cout << "list is empty!" << endl;
	}

	//�������ٱ�
	//����list��
	DestroyList(&list);
	if (list == NULL) {
		cout << "list is destroied now!" << endl;
	}
	return 0;
}





int InitList(PolyList** L) {

	//�ж��Ƿ���ָ��
	if (*L != NULL) {
		return -1;
	}

	//�������ռ�
	PolyList* temp = NULL;
	temp = (PolyList*)malloc(sizeof(PolyList));

	//�ж��Ƿ����ɹ�
	if (temp == NULL) {
		return -2;
	}

	//��ʼ�����䳤��
	Poly* temp_poly = NULL;
	temp_poly = (Poly*)malloc(sizeof(Poly) * INIT_SIZE);
	if (temp_poly == NULL) {
		return -3;
	}

	temp->poly = temp_poly;
	temp->length = 0;
	temp->listSize = INIT_SIZE;

	//����ɹ�������
	*L = temp;

	return 0;
}

int isEmptyList(PolyList *L) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	//�ж��Ƿ�Ϊ�ձ�
	if (L->length != 0) {
		return -2;
	}

	return 0;
}

int ListLength(PolyList* L) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	//���ر�ĳ���
	return L->length;
}

int DestroyList(PolyList** L) {

	//�жϱ��Ƿ����
	if (*L == NULL) {
		return -1;
	}

	free(*L);
	*L = NULL;

	return 0;
}

int ClearList(PolyList** L) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	//�ж��Ƿ���Ϊ�ձ�
	if (!isEmptyList(*L)) {
		return 0;
	}

	//���·����ڴ�
	Poly* temp = (Poly*)realloc((*L)->poly, sizeof(Poly) * INIT_SIZE);
	if (temp == NULL) {
		return -2;
	}

	//����Ϊ�ձ�
	(*L)->poly = temp;
	(*L)->length = 0;
	(*L)->listSize = INIT_SIZE;

	return 0;
}

int getElem(PolyList* L, int i, Poly* e) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	//�ж��Ƿ�Խ��
	if (i < 1 || i > L->length) {
		return -2;
	}

	//���ص�i������Ԫ�ص�ֵ
	Poly temp = (L->poly)[i - 1];
	*e = temp;

	return 0;
}

int LocateElem(PolyList* L, const Poly e, int(con)(const Poly e, const Poly e1)) {

	//�жϱ��Ƿ����
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

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	//����
	int index = 0;
	for (index = 0; index < L->length; index++) {
		if (cur_e.cof == (*L).poly[index].cof &&
			cur_e.pow == (*L).poly[index].pow) {

			break;
		}
	}

	//�ж��Ƿ�Ϊ��һ��
	if (index == 0) {
		return 1;
	}

	//�ж��Ƿ���ҳɹ�
	else if (index == L->length) {
		return -2;
	}

	//���ҳɹ�������ǰ��
	*pre_e = (*L).poly[index - 1];

	return 0;
}

int NextElem(PolyList* L, Poly cur_e, Poly* next_e) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	//����
	int index = 0;
	for (index = 0; index < L->length; index++) {
		if (cur_e.cof == (*L).poly[index].cof &&
			cur_e.pow == (*L).poly[index].pow) {

			break;
		}
	}

	//�ж��Ƿ�Ϊ���һ��
	if (index == L->length - 1) {
		return 1;
	}

	//�ж��Ƿ���ҳɹ�
	else if (index == L->length) {
		return -2;
	}

	//���ҳɹ�������ǰ��
	*next_e = (*L).poly[index  + 1];

	return 0;
}

int InsertList(PolyList* L, int i, Poly e) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	//�жϲ���λ���Ƿ���ȷ
	if (i < 1 || i > ListLength(L) + 1) {
		return -2;
	}

	Poly* newbase = NULL;
	//�ж��Ƿ���Ҫ����
	if (L->length == L->listSize) {

		//����ռ�
		newbase = (Poly*)realloc(L->poly, sizeof(Poly) * (L->listSize + ADD_SIZE));

		//����ʧ��
		if (newbase == NULL) {
			return -3;
		}

		//����ɹ�
		L->poly = newbase;		
		L->listSize += ADD_SIZE;
	}

	//�ƶ����Ԫ��
	for (int index = L->length - 1; index >= i-1; index++) {
		(L->poly)[index + 1].cof = (L->poly)[index].cof;
		L->poly[index + 1].pow = L->poly[index].pow;
	}

	//����
	L->poly[i - 1].cof = e.cof;
	L->poly[i - 1].pow = e.pow;
	L->length++;

	return 0;
}

int DeleteList(PolyList* L, int i) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	//�ж�ɾ��λ���Ƿ���ȷ
	if (i < 1 || i > ListLength(L) + 1) {
		return -2;
	}

	//�ƶ�Ԫ�أ��Դﵽɾ��Ч��
	for (int index = L->length - 1; index > i - 1; index--) {
		L->poly[index - 1].cof = L->poly[index].cof;
		L->poly[index - 1].pow = L->poly[index].pow;
	}
	L->length--;

	return 0;
}

int ListTraverse(PolyList* L, void(*visited)(const Poly e)) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	//��ÿ��Ԫ��ִ��visited����
	for (int i = 0; i < L->length; i++) {
		visited(L->poly[i]);
	}

	return 0;
}

int inputList(PolyList* L) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	//�������
	printf("Input date('#' stop):\n");
	do {
		

		//�ж�����ڴ��Ƿ����
		if (L->length > L->listSize) {
			
			Poly* newbase = (Poly*)realloc(L->poly, sizeof(Poly) * (L->length + ADD_SIZE));

			if (newbase == NULL) {
				return -2;
			}

			L->poly = newbase;
			L->listSize += ADD_SIZE;
		}

		//����
		char str[100] = { 0 };
		cout << "Please input cof and pow (cof,pow) :";
		if (str[0] == '#') {
			break;
		}
		cin >> str;

		//���볤�Ȳ��ϸ�
		if (strlen(str) < 3) {
			cout << "Please again!" << endl;
			continue;
		}

		L->poly[L->length].cof = (int)(str[0] - '0');
		L->poly[L->length].pow = (int)(str[2] - '0');
		L->length++;
		//�ж��Ƿ��������
		if (str[strlen(str) - 1] == '#') {
			break;
		}

	} while (true);
	cout << "Input date end!" << endl;

	return 0;
}

int sortOfCofList(PolyList* L) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	//��������
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
	
	//�жϱ��Ƿ����
	if (L1 == NULL || L2 == NULL || answer == NULL) {
		return -1;
	}

	//������������ʽ
	sortOfCofList(L1);
	sortOfCofList(L2);

	//��������
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