#include"sole_list.h"

INT* creat_list() {

	//������ͷ���
	INT* new_list = (INT*)malloc(sizeof(INT));
	if (new_list == NULL) {
		return NULL;
	}

	//���ָ�����ʼ��
	new_list->prev = NULL;
	new_list->next = NULL;

	return new_list;
}

bool add_elem_list(INT** L,INT insert_elem) {

	if (*L == NULL) {
		return false;
	}

	//������������ڴ�
	INT* temp = (INT*)malloc(sizeof(INT));
	if (temp == NULL) {
		return false;
	}

	//��ֵ
	*temp = insert_elem;

	//������β
	INT* tail = *L;
	while (tail->next) {
		tail = tail->next;
	}

	//���ӽ��
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

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	//�����
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

	//�жϱ��Ƿ����
	if ((*L)->next == NULL) {
		return false;
	}

	//�жϲ���Ԫ��λ���Ƿ���ȷ
	if (i < 1 || i > length_List(*L)) {
		return false;
	}

	//����һ��˼�룺ͨ��ָ��ɾ��Ԫ�ص�ǰһ��Ԫ�أ�ȡ��ɾ��Ԫ�غ������ָ�롣
	////�ƶ���Ҫɾ��Ԫ�ص�ǰһ��Ԫ��
	//INT* delete_index = *L;
	//int index = 1;
	//while (delete_index->next && index < i) {
	//	index++;
	//	delete_index = delete_index->next;
	//}

	////����ɾ������
	//INT* temp = delete_index->next;
	//if (temp && temp->next) {
	//	temp->next->prev = delete_index;
	//	delete_index->next = temp->next;
	//}
	//else {
	//	delete_index->next = NULL;
	//}
	//
	//�Ƿ񱻲����Ľ��
	//free(temp);
	//temp = NULL;
	/*
	* free ֻ���ͷ���malloc������ڴ棬�����ͷ�������ʽ������ڴ�
	* ���磺 INT a,���ܱ�free�ͷţ��ᵼ�³������
	*       INT *a = (INT*)malloc(sizeof(INT))��������ڴ���Ա��ͷš�
	*/

	//��������ͨ��ָ��ɾ��Ԫ�صĽ�㣬����ɾ��ǰ�Ľ���ɾ����Ľ��
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