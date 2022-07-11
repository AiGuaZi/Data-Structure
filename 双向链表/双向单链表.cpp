#include"sole_list.h"

#define N 3
int main() {
	INT* list = creat_list();

	//测试向表尾添加元素
	for (int i = 0; i < N; i++) {
		INT temp = { NULL,0,NULL };
		cout << "Please input a number:";
		cin >> temp.date;
		add_elem_list(&list,temp);
	}

	//测试插入元素和删除元素
	INT* temp = (INT*)malloc(sizeof(INT));
	if (temp == NULL) {
		return -1;
	}
	temp->prev = NULL;
	temp->date = 6;
	temp->next = NULL;
	insert_elem_list(&list, 1, temp);
	delete_elem_list(&list, 1);

	//遍历链表元素
	INT* P = list->next;
	while (P) {
		cout << P->date << endl;
		P = P->next;
	}
	return 0;
}