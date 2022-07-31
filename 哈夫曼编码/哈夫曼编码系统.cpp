#include"Menu.h"
#include"str_cal.h"
#include"huffman_code.h"

int main() {

	//—°‘Ò±‡¬Î∏Ò Ω
	/*int code_num = Menu_Code();*/

	String* code = common_coding();
	for (int i = 0; i < code->now_count; i++) {
		cout << code->str[i];
	}
	cout << endl;
	cout << code->now_count << endl;

	decode_to_code(code);

}