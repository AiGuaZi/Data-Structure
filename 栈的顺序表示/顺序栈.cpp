#include"sequence_stack.h"

#define N 3

void com(const void* elem) {
	cout << *(int*)elem << endl;
}

int main() {

	//����ջ
	INT* stack = NULL;
	creat_stack(&stack);

	//����Ԫ����ջ
	cout << "----------Push----------" << endl;
	for (int i = 0; i < N; i++) {
		cout << "Please input a number:";
		int number = 0;
		cin >> number;
		push(stack,number);
	}

	//����ջ
	cout << "----------Result----------" << endl;
	traversal_stack(stack, com);

	//���Գ�ջ
	cout << "----------Pop----------" << endl;
	int top_temp = 0;
	pop(stack, &top_temp);
	traversal_stack(stack, com);
	cout << "pop number:" << top_temp << endl;

	//����ȡջ��Ԫ��
	cout << "----------getTop----------" << endl;
	int getTop_temp = 0;
	getTop(stack, &getTop_temp);
	cout << "getTop number:" << getTop_temp << endl;

	//�����ÿ�ջ
	cout << "----------Clear_stack----------" << endl;
	clear_statck(stack);
	traversal_stack(stack, com);

	//��������ջ
	cout << "----------Destroy_stack----------" << endl;
	destroy_stack(&stack);
	cout << stack << endl;

	return 0;
}