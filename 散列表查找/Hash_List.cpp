#include"Hash_Find.h"

void Init_Hash_List(Hash_List* HL,int length) {

	if (length < 1) {
		cout << "长度错误!" << endl;
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
		cout << endl << "ERROR " << ERROR << ":传入参数为空指针" << endl;
		exit(ERROR);
	}

	cout << "请输入关键字(“0”结束):";
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
		cout << endl << "ERROR " << ERROR << ":传入参数为空指针" << endl;
		exit(ERROR);
	}

	int up_count = 0;

	//当up_count == HL->length 时哈希表满

	//bool is_minus = false;    //二次探测法的辅助变量，用于控制正负交替
	while (up_count < HL->length) {

		int ret = 0;     //计算得到的空位置下标
		////线性探测法
		//ret = Hash_function(HL, key + up_count++);
		//二次探测法
		/*if (!is_minus) {
			is_minus = !is_minus;
			ret = Hash_function(HL, key + up_count * up_count);
		}
		else {
			is_minus = !is_minus;
			ret = Hash_function(HL, key - (up_count * up_count));
			up_count++;
		}*/
		//伪随机数法
		srand(time(NULL));
		ret = Hash_function(HL, key + rand());
		if (HL->key[ret] == NULL) {
			return ret;
		}
	}

	if (up_count == HL->length) {
		cout << endl << "ERROR: " << FILL_LIST << "存储空间不足" << endl;
		exit(ERROR);
	}
}

int find_elem(Hash_List* HL, keyType key) {

	if (HL == NULL) {
		cout << endl << "ERROR " << ERROR << ":传入参数为空指针" << endl;
		exit(ERROR);
	}

	if (key == NULL) {
		cout << endl << "ERROR " << ERROR << ":查找关键字错误!" << endl;
		return(ERROR);
	}

	int up_count = 0;

	
	while (up_count < HL->length) {
		int ret = Hash_function(HL, key + up_count++);
		if (HL->key[ret] == key) {
			return ret;
		}
	}
	//当up_count == HL->length 时哈希表满,表示元素未找到
	if (up_count == HL->length) {
		cout << endl << "ERROR: " << FILL_LIST << "查找失败,未找到该元素" << endl;
		return ERROR;
	}

}

void free_HashList(Hash_List* HL) {

	if (HL == NULL) {
		cout << endl << "ERROR " << ERROR << ":传入参数为空指针" << endl;
		exit(ERROR);
	}

	free(HL->key);
	HL->key = NULL;
}