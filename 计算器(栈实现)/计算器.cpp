
#include"analyze_std.h"
#include"oper_stack.h"
#include"caculation_equation.h"

int main() {

	//������ʽ
	char* equa = creat_equation();

	//�����ʽ
	cout << "Please input an equation:";
	cin >> equa;

	AllNumber* value = NULL;
	Equation_oper* oper = NULL;
	creat_equa_oper_stack(&oper);
	creat_equa_all_number_stack(&value);

	extract_equation(equa, value, oper);


	return 0;

}