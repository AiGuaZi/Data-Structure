#include"str_cal.h"

String* creat_String() {

	//创建这个线性表
	String* ret = NULL;
	ret = (String*)malloc(sizeof(String));
	if (ret == NULL) exit(-1);
	ret->all_count = 0;
	ret->now_count = 0;
	ret->str = NULL;

	//创建存储空间
	ret->str = (char*)malloc(sizeof(char) * STR_LENGTH);
	if(ret->str == NULL) exit(-1);
	memset(ret->str, 0, sizeof(char) * STR_LENGTH);
	ret->all_count = STR_LENGTH;

	return ret;
}

bool is_full(String* str) {
	return str->all_count - 1 == str->now_count ? true : false;
}

void extend_str(String* str) {

	//申请新空间
	char* newbase = (char*)realloc(str->str, sizeof(char) * (str->all_count + EXTEND_LENGTH));//无法进行增长
	if (newbase == NULL) exit(-1);

	str->str = newbase;
	str->all_count += EXTEND_LENGTH;
	
}

String* input_code() {
	cout << "输入明文( ‘#’ 结束):" << endl;
	
	String* str = creat_String();

	char temp_ch = 0;
	cin >> temp_ch;

	int str_i = 0;
	while (temp_ch != '#') {

		if (is_full(str)) extend_str(str);

		str->str[str->now_count++] = temp_ch;
		cin >> temp_ch;
	}

	return str;
}

void insert_ch(String* str, char i_ch) {

	if (is_full(str)) extend_str(str);
	str->str[str->now_count++] = i_ch;

}