#include<iostream>
#include<stdlib.h>

using namespace std;

/**
* ����������ͷ��ѭ������
*/

typedef struct INT {
	int date;
	INT* next;
}INT;

INT* creat_List() {
	INT* ret = NULL;
	return ret;
}

bool insert_Date(INT** L) {
	
	INT* temp = (INT*)malloc(sizeof(INT));
	if (!temp) {
		return false;
	}

	cout << "Please input a number:";
	cin >> temp->date;

	/**
	* ��������Ԫ�أ���Ҫ���⴦��
	*/
	if (*L == NULL) {
		temp->next = temp;
	}
	else {
		temp->next = (*L)->next;
		(*L)->next = temp;
	}
	*L = temp;

	return true;
}

/**
* ���ܣ��ϲ�����ѭ������
* ������INT** L1, INT** L2
* ����������ڷ���false���ϲ���Ľ��βָ��ΪL2��
*/
bool merge_List(INT** L1, INT** L2) {

	if (*L1 == NULL || *L2 == NULL) {
		return false;
	}

	/**
	* ��ͼ������
	*/
	INT* temp = NULL;
	temp = (*L1)->next;
	(*L1)->next = (*L2)->next;
	(*L2)->next = temp;

	return true;
}


int main() {

	INT* nums = creat_List();
	for (int i = 0; i < 1; i++) {
		insert_Date(&nums);
	}
	for (int i = 0; i < 1; i++) {
		cout << nums->date << endl;
		nums = nums->next;
	}

	INT* nums1 = creat_List();
	for (int i = 0; i < 1; i++) {
		insert_Date(&nums1);
	}
	for (int i = 0; i < 1; i++) {
		cout << nums1->date << endl;
		nums1 = nums1->next;
	}

	bool ret = merge_List(&nums, &nums1);
	
	if (ret != false) {
		for (int i = 0; i < 2; i++) {
			cout << nums1->date << "   i = " << i << endl;
			nums1 = nums1->next;
		}
	}
	return 0;
}
