#include"analyze_std.h"
char* creat_equation() {

	//�����ڴ�ռ�
	char* new_equation = (char*)malloc(sizeof(char) * EQUATION_MAX_SIZE);
	if (!new_equation) return NULL;

	//��ʼ��Ϊ0
	memset(new_equation, 0, EQUATION_MAX_SIZE);

	return new_equation;
}

bool check_equation(char* std) {

	//�ж�std�Ƿ����ַ�
	if (std != NULL)return false;

	//ȱ�ټ���ʽ�ϸ��ԵĹ���

}

int charnum_to_intnum(char char_number) {

	//�ж��ַ����Ƿ�Ϊ��
	if (char_number < '0' || char_number > '0') return -1;

	return char_number - '0';
}

char* extract_number(const char* base_std) {

	//�ж��ַ��������β
	if (*base_std == '\0') return NULL;

	/*ȱ�ݣ�Ӧ���ö�̬���У��Ա��ڽ�����ֵ���䣬������󳤶�10���У��Ժ�Ľ�*/
	char* number_std = (char*)malloc(sizeof(char) * 9);
	if (number_std == NULL) return NULL;
	memset(number_std, 0, 9);
	
	//��ȡ�ַ���ֵ�ַ���
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

	//�жϴ����������ȷ��
	if (base_std == NULL) return NULL;

	//�����洢��ʽ���ڴ�
	char* new_equation = (char*)malloc(sizeof(char) * EQUATION_MAX_SIZE);
	if (!new_equation) return NULL;
	memset(new_equation, 0, EQUATION_MAX_SIZE);

	//��ȡ��ʽ
	int new_equation_count = 0;
	while (*(base_std + new_equation_count) != ')') {
		new_equation[new_equation_count] = *(base_std + new_equation_count);
		new_equation_count++;
	}

	return new_equation;
}