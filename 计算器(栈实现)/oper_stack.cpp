#include"oper_stack.h"

bool creat_equa_oper_stack(Equation_oper** E) {

	//ÅĞ¶ÏÊÇ·ñ±»´´½¨
	if (*E) return false;

	//·ÖÅä¿Õ¼ä
	*E = (Equation_oper*)malloc(sizeof(Equation_oper));
	if (*E == NULL) return false;
	(*E)->oper = NULL;
	(*E)->top = NULL;

	//·ÖÅäÊı¾İ¿Õ¼ä
	(*E)->oper = (char*)malloc(sizeof(char) * EQUA_STACK_MAX_SIZE);
	if (!(*E)->oper) return false;
	memset((*E)->oper, 0, EQUA_STACK_MAX_SIZE);
	(*E)->top = (*E)->oper;

	return true;
}

int equa_stack_oper_length(Equation_oper* E) {

	//ÅĞ¶ÏÕ»ÊÇ·ñ´æÔÚ
	if (!E) return -1;

	return (E->top - E->oper) / sizeof(char);
}

bool in_equa_oper_stack(Equation_oper* E, char e) {

	//ÅĞ¶Ï±íÊÇ·ñ´æÔÚ
	if (E == NULL) return false;

	//ÅĞ¶ÏÕ»Âú
	if (equa_stack_oper_length(E) == EQUA_STACK_MAX_SIZE) return false;

	//ÈëÕ»
	*E->top = e;
	E->top++;

	return true;
}

bool out_equa_oper_stack(Equation_oper* E, char* e) {

	//ÅĞ¶Ï±íÊÇ·ñ´æÔÚ
	if (E == NULL) return false;

	//ÅĞ¶ÏÕ»¿Õ
	if (equa_stack_oper_length(E) == 0) return false;

	//³öÕ»
	*e = *E->top;
	E->top--;

	return true;
}