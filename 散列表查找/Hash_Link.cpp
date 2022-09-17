#include"Hash_Link.h"

void Init_Hash_Link(HashOfLink* HOL, int length) {

	if (length < 1) {
		cout << "ERROR " << ERROR << ":��ϣ���ȴ���!" << endl;
		exit(ERROR);
	}

	HOL->key_list = (keyHead*)malloc(sizeof(keyHead) * length);
	if (HOL->key_list == NULL) exit(NO_MEMORY);
	memset(HOL->key_list, NULL, sizeof(keyHead) * length);
	HOL->key_length = length;

}

int Hash_function_Link(HashOfLink* HOL, keyType key) {

	if (HOL == NULL) {
		cout << "ERROR " << ERROR << ":�������Ϊ��ָ��!" << endl;
		exit(ERROR);
	}

	return key % HOL->key_length;

}

void creat_Node(HashOfLink** HOL, int i, keyType key) {

	keyNode* temp = (keyNode*)malloc(sizeof(keyNode));
	if (temp == NULL) exit(NO_MEMORY);
	temp->key = key;
	temp->next = NULL;

	
	temp->next = (*HOL)->key_list[i].head;
	(*HOL)->key_list[i].head = temp;
	
	(*HOL)->key_list[i].link_length++;
}

void creat_HashOfLink(HashOfLink* HOL) {

	if (HOL == NULL) {
		cout << "ERROR " << ERROR << ":�������Ϊ��ָ��!" << endl;
		exit(ERROR);
	}

	cout << "������ؼ���(��0������):";
	keyType key = 0;
	cin >> key;
	while (key != 0) {

		int i_insert = Hash_function_Link(HOL, key);
		creat_Node(&HOL, i_insert, key);
		cin >> key;
	}
}

void traverse_HOL(HashOfLink* HOL) {

	if (HOL == NULL) {
		cout << "ERROR " << ERROR << ":�������Ϊ��ָ��!" << endl;
		exit(ERROR);
	}

	for (int i = 0; i < HOL->key_length; i++) {
		cout << "i:" << i << "\t" << "link_length:" << HOL->key_list[i].link_length << "\t";
		keyNode* p = HOL->key_list[i].head;
		while (p) {
			cout << p->key << "\t";
			p = p->next;
		}
		cout << endl;
	}
}

void find_elem_in_HashOfLink(HashOfLink* HOL, keyType key) {

	if (HOL == NULL) {
		cout << "ERROR " << ERROR << ":�������Ϊ��ָ��!" << endl;
		exit(ERROR);
	}

	int i_hash = Hash_function_Link(HOL, key);

	keyNode* p = HOL->key_list[i_hash].head;
	while (p && p->key != key) p = p->next;

	if (p) {
		cout << "���ҳɹ�:" << "λ�ڱ�" << i_hash << "������" << endl;
	}
	else {
		cout << "����ʧ��!" << endl;
	}
}