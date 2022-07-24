#include"analyze_std.h"
char* creat_equation() {

	//分配内存空间
	char* new_equation = (char*)malloc(sizeof(char) * EQUATION_MAX_SIZE);
	if (!new_equation) return NULL;

	//初始化为0
	memset(new_equation, 0, EQUATION_MAX_SIZE);

	return new_equation;
}

bool check_equation(char* std) {

	//判断std是否含有字符
	if (std != NULL)return false;

	//缺少检测等式合格性的功能

}

int charnum_to_intnum(char char_number) {

	//判断字符串是否为空
	if (char_number < '0' || char_number > '0') return -1;

	return char_number - '0';
}

char* extract_number(const char* base_std) {

	//判断字符串到达结尾
	if (*base_std == '\0') return NULL;

	/*缺陷：应当用动态队列，以便于进行数值扩充，先以最大长度10进行，以后改进*/
	char* number_std = (char*)malloc(sizeof(char) * 9);
	if (number_std == NULL) return NULL;
	memset(number_std, 0, 9);
	
	//抽取字符数值字符串
	int number_count = 0;
	while (isdigit(*(base_std + number_count))) {
		if (number_count == 10) {
			cout << "Warning : " << number_std << " will maybe beyond of \"int\" of max number!" << endl;
			exit(-1);
		}
		number_std[number_count] = *(base_std + number_count);
		number_count++;
	}
	

	return number_std;
}

char* extract_equation_to_char(const char* base_std) {

	//判断传入参数的正确性
	if (base_std == NULL) return NULL;

	//创建存储等式的内存
	char* new_equation = (char*)malloc(sizeof(char) * EQUATION_MAX_SIZE);
	if (!new_equation) return NULL;
	memset(new_equation, 0, EQUATION_MAX_SIZE);

	//读取等式
	int new_equation_count = 0;
	while (*(base_std + new_equation_count) != ')') {
		new_equation[new_equation_count] = *(base_std + new_equation_count);
		new_equation_count++;
	}

	return new_equation;
}