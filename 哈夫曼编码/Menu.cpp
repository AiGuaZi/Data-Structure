#include"Menu.h"

void menu_select_code() {
	cout << "|-----------------------------------------|" << endl;
	cout << "|----------�������������-----------------|" << endl;
	cout << "|-----------1.�������--------------------|" << endl;
	cout << "|-----------2.ͨ�ñ���--------------------|" << endl;
	cout << "|��ܰ��ʾ��                               |" << endl;
	cout << "|������룺���Ա����κγ�������#�����    |" << endl;
	cout << "|ȫ���������ַ�                           |" << endl;
	cout << "|ͨ�ñ��룺��֧��Ӣ����ĸ                 |" << endl;
	cout << "|-----------------------------------------|" << endl;
}

int select_code() {

	cout << "�������ѡ��";
	int sel_num = 0;
	cin >> sel_num;

	return sel_num;
}

int Menu_Code() {

	int sel_num = 0;
	do {
		menu_select_code();
		sel_num = select_code();
	} while (sel_num != 1 && sel_num != 2);

	return sel_num;
}