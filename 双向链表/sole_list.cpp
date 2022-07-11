#include"sole_list.h"

INT* creat_list() {

	//创建表头结点
	INT* new_list = (INT*)malloc(sizeof(INT));
	if (new_list == NULL) {
		return NULL;
	}

	//结点指针域初始化
	new_list->prev = NULL;
	new_list->next = NULL;

	return new_list;
}

bool add_elem_list(INT** L,INT insert_elem) {

	if (*L == NULL) {
		return false;
	}

	//给插入结点分配内存
	INT* temp = (INT*)malloc(sizeof(INT));
	if (temp == NULL) {
		return false;
	}

	//赋值
	*temp = insert_elem;

	//到链表尾
	INT* tail = *L;
	while (tail->next) {
		tail = tail->next;
	}

	//连接结点
	/*if (tail->next == NULL) {
		tail->next = temp;
		temp->next = NULL;
	}
	else {*/
		tail->next = temp;
		temp->prev = tail;
		temp->next = NULL;
	/*}*/

	return true;
}

int length_List(INT* L) {

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	//计算表长
	INT* p = L->next;
	int list_length = 0;
	while (p) {
		list_length++;
		p = p->next;
	}

	return list_length;
}

bool insert_elem_list(INT** L, int i, INT* insert_elem) {

	if (*L == NULL) {
		return false;
	}

	if (i < 1 || i > length_List(*L) + 1) {
		return false;
	}

	INT* insert_index = *L;
	int index = 0;
	while (insert_index->next && index < i - 1) {
		index++;
		insert_index = insert_index->next;
	}

	INT* insert_temp = (INT*)malloc(sizeof(INT));
	if (insert_temp == NULL) {
		return false;
	}
	insert_temp = insert_elem;
	insert_temp->next = NULL;

	if (insert_index->next == NULL) {
		insert_index->next = insert_temp;
		insert_temp->prev = insert_index;
	}
	else {
		insert_temp->next = insert_index->next;
		insert_temp->prev = insert_index;
		if (insert_index->next) {
			insert_index->next->prev = insert_temp;
		}
		insert_index->next = insert_temp;
		
	}

	return true;
}

bool delete_elem_list(INT** L, int i) {

	//判断表是否存在
	if ((*L)->next == NULL) {
		return false;
	}

	//判断插入元素位置是否正确
	if (i < 1 || i > length_List(*L)) {
		return false;
	}

	//方法一：思想：通过指向删除元素的前一个元素，取得删除元素后面结点的指针。
	////移动到要删除元素的前一个元素
	//INT* delete_index = *L;
	//int index = 1;
	//while (delete_index->next && index < i) {
	//	index++;
	//	delete_index = delete_index->next;
	//}

	////进行删除操作
	//INT* temp = delete_index->next;
	//if (temp && temp->next) {
	//	temp->next->prev = delete_index;
	//	delete_index->next = temp->next;
	//}
	//else {
	//	delete_index->next = NULL;
	//}
	//
	//是否被产出的结点
	//free(temp);
	//temp = NULL;
	/*
	* free 只能释放有malloc申请的内存，不能释放其他方式申请的内存
	* 例如： INT a,不能被free释放，会导致程序崩溃
	*       INT *a = (INT*)malloc(sizeof(INT))，申请的内存可以被释放。
	*/

	//方法二：通过指向删除元素的结点，连接删除前的结点和删除后的结点
	INT* delete_index = (*L)->next;
	int index = 0;
	while (delete_index && index < i - 1) {
		index++;
		delete_index = delete_index->next;
	}

	if (delete_index && delete_index->next) {
		delete_index->next->prev = delete_index->prev;
		delete_index->prev->next = delete_index->next;
	}
	else {
		delete_index->prev->next = NULL;
	}
	
	free(delete_index);
	delete_index = NULL;
	return true;
}