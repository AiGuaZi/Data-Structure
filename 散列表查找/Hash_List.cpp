#include"Hash_Find.h"

void Init_Hash_List(Hash_List* HL,int length) {

	if (length < 1) {
		cout << "���ȴ���!" << endl;
		exit(ERROR);
	}

	HL->key = (keyType*)malloc(sizeof(keyType) * length);
	if (HL->key == NULL)exit(NO_MEMORY);
	memset(HL->key, NULL, sizeof(keyType) * length);
	HL->length = length;

}

int Hash_function(Hash_List* HL, keyType key) {

	if (HL == NULL) return ERROR;

	return key % HL->length;
}

void creat_Hash_List(Hash_List* HL) {

	if (HL == NULL) {
		cout << endl << "ERROR " << ERROR << ":�������Ϊ��ָ��" << endl;
		exit(ERROR);
	}

	cout << "������ؼ���(��0������):";
	for (int i = 0; i < HL->length; i++) {
		keyType key = NULL;
		cin >> key;
		if (key == NULL)break;
		int i_key = get_NULL_i_in_HashList(HL, key);
		HL->key[i_key] = key;
	}
}

int get_NULL_i_in_HashList(Hash_List* HL, keyType key) {

	if (HL == NULL) {
		cout << endl << "ERROR " << ERROR << ":�������Ϊ��ָ��" << endl;
		exit(ERROR);
	}

	int up_count = 0;

	//��up_count == HL->length ʱ��ϣ����

	//bool is_minus = false;    //����̽�ⷨ�ĸ������������ڿ�����������
	while (up_count < HL->length) {

		int ret = 0;     //����õ��Ŀ�λ���±�
		////����̽�ⷨ
		//ret = Hash_function(HL, key + up_count++);
		//����̽�ⷨ
		/*if (!is_minus) {
			is_minus = !is_minus;
			ret = Hash_function(HL, key + up_count * up_count);
		}
		else {
			is_minus = !is_minus;
			ret = Hash_function(HL, key - (up_count * up_count));
			up_count++;
		}*/
		//α�������
		srand(time(NULL));
		ret = Hash_function(HL, key + rand());
		if (HL->key[ret] == NULL) {
			return ret;
		}
	}

	if (up_count == HL->length) {
		cout << endl << "ERROR: " << FILL_LIST << "�洢�ռ䲻��" << endl;
		exit(ERROR);
	}
}

int find_elem(Hash_List* HL, keyType key) {

	if (HL == NULL) {
		cout << endl << "ERROR " << ERROR << ":�������Ϊ��ָ��" << endl;
		exit(ERROR);
	}

	if (key == NULL) {
		cout << endl << "ERROR " << ERROR << ":���ҹؼ��ִ���!" << endl;
		return(ERROR);
	}

	int up_count = 0;

	
	while (up_count < HL->length) {
		int ret = Hash_function(HL, key + up_count++);
		if (HL->key[ret] == key) {
			return ret;
		}
	}
	//��up_count == HL->length ʱ��ϣ����,��ʾԪ��δ�ҵ�
	if (up_count == HL->length) {
		cout << endl << "ERROR: " << FILL_LIST << "����ʧ��,δ�ҵ���Ԫ��" << endl;
		return ERROR;
	}

}

void free_HashList(Hash_List* HL) {

	if (HL == NULL) {
		cout << endl << "ERROR " << ERROR << ":�������Ϊ��ָ��" << endl;
		exit(ERROR);
	}

	free(HL->key);
	HL->key = NULL;
}