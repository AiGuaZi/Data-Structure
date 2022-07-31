#include"Menu.h"

void menu_select_code() {
	cout << "|-----------------------------------------|" << endl;
	cout << "|----------哈夫曼编码计算-----------------|" << endl;
	cout << "|-----------1.特殊编码--------------------|" << endl;
	cout << "|-----------2.通用编码--------------------|" << endl;
	cout << "|温馨提示：                               |" << endl;
	cout << "|特殊编码：可以编译任何除结束‘#’外的    |" << endl;
	cout << "|全部可输入字符                           |" << endl;
	cout << "|通用编码：仅支持英文字母                 |" << endl;
	cout << "|-----------------------------------------|" << endl;
}

int select_code() {

	cout << "输入你的选择：";
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