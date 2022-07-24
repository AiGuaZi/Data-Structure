#include"caculation_equation.h"
#include"analyze_std.h"

int extract_equation(const char* equa, AllNumber* value, Equation_oper* oper) {

	//�жϵ�ʽ�Ƿ����,�ж���ֵ���ַ��Ƿ��Ѵ���
	if (!equa) return 0;
	//if (value == NULL || oper == NULL) return 0;


	//��ʽ��Ӧ�ַ���ջ
	int equa_length = strlen(equa);
	for (int i = 0; i < equa_length;) {

		//�����ո��ַ�
		while (i < equa_length && equa[i] == ' ')i++;

		if (isdigit(equa[i])) {

			//��ȡ��ֵ�ַ�����ѹ��ջ��
			char* number_std = extract_number(equa + i);
			in_equa_all_number_stack(value, number_std);

			//�����ַ�
			i += strlen(number_std);

		}
		else {

			if (!in_equa_oper_stack(oper, equa[i++])) {
				cout << "Error: Insert oper failur!" << endl;
				exit(1);
			}

		}
	}

	return 0;
}

bool caculation_equation(const char* equation, double* answer) {

	//�жϴ����������ȷ��
	if (equation == NULL || answer == NULL) return false;
	
	//������ֵ�������
	AllNumber* value = NULL;							//��ֵ
	Equation_oper* oper = NULL;							//�����
	creat_equa_oper_stack(&oper);
	creat_equa_all_number_stack(&value);

	extract_equation(equation, value, oper);


}