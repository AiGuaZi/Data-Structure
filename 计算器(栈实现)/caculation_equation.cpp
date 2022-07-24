#include"caculation_equation.h"
#include"analyze_std.h"

int extract_equation(const char* equa, AllNumber* value, Equation_oper* oper) {

	//判断等式是否存在,判断数值和字符是否已存在
	if (!equa) return 0;
	//if (value == NULL || oper == NULL) return 0;


	//等式对应字符入栈
	int equa_length = strlen(equa);
	for (int i = 0; i < equa_length;) {

		//跳过空格字符
		while (i < equa_length && equa[i] == ' ')i++;

		if (isdigit(equa[i])) {

			//读取数值字符，并压入栈内
			char* number_std = extract_number(equa + i);
			in_equa_all_number_stack(value, number_std);

			//跳过字符
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

	//判断传入参数的正确性
	if (equation == NULL || answer == NULL) return false;
	
	//分离数值和运算符
	AllNumber* value = NULL;							//数值
	Equation_oper* oper = NULL;							//运算符
	creat_equa_oper_stack(&oper);
	creat_equa_all_number_stack(&value);

	extract_equation(equation, value, oper);


}