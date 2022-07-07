#include<iostream>
#include<stdlib.h>

using namespace std;

/**
* 建立不带表头的循环链表
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
	* 若表不含有元素，需要特殊处理
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
* 功能：合并两个循环链表
* 参数：INT** L1, INT** L2
* 结果：表不存在返回false，合并后的结果尾指针为L2。
*/
bool merge_List(INT** L1, INT** L2) {

	if (*L1 == NULL || *L2 == NULL) {
		return false;
	}

	/**
	* 画图最好理解
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
