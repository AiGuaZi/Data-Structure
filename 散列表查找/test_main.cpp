#include"Hash_Find.h"
#include"Hash_Link.h"
int main() {

	/*Hash_List HL;
	int HL_length = 0;
	cout << "������洢����:";
	cin >> HL_length;
	Init_Hash_List(&HL, HL_length);
	creat_Hash_List(&HL);
	
	for (int i = 0; i < HL.length; i++) {
		cout << HL.key[i] << " ";
	}

	cout << endl << find_elem(&HL, 100) << endl;

	free_HashList(&HL);*/

	HashOfLink HOL;
	int HOL_length = 0;
	cout << "�������:";
	cin >> HOL_length;
	Init_Hash_Link(&HOL, HOL_length);
	creat_HashOfLink(&HOL);

	traverse_HOL(&HOL);

	cout << "����Ԫ��16:";
	find_elem_in_HashOfLink(&HOL, 16);
	cout << "����Ԫ��100:";
	find_elem_in_HashOfLink(&HOL, 100);
	return 0;
}

/*
11
47 7 29 11 16 92 22 8 3 0
*/