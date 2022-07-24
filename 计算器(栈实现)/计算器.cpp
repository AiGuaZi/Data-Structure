
#include"analyze_std.h"
#include"oper_stack.h"
#include"caculation_equation.h"

int main() {

	//创建等式
	char* equa = creat_equation();

	//输入等式
	cout << "Please input an equation:";
	cin >> equa;

	AllNumber* value = NULL;
	Equation_oper* oper = NULL;
	creat_equa_oper_stack(&oper);
	creat_equa_all_number_stack(&value);

	extract_equation(equa, value, oper);


	return 0;

}