#include"queue_circle.h"

#define N 3
#define M 10

void com(const void* elem) {
	cout << *(int*)elem << endl;
}

int main() {

	INT* Queue = NULL;
	if (!creat_queue(&Queue)) {
		cout << "Creat failure!" << endl;
		return -1;
	}

	cout << "------------\tin_queue\t------------" << endl;
	for (int i = 0; i < N; i++) {
		cout << "Please input a number:";
		int temp = 0;
		cin >> temp;
		if (!in_queue(Queue, temp)) {
			cout << "Queue full!" << endl;
			break;
		}
	}
	cout << "Traverse:" << endl;
	traverse_queue(Queue, com);

	cout << "------------\tqueue_length\t------------" << endl;
	cout << "queue length:" << queue_length(Queue) << endl;

	cout << "------------\tget_queue\t------------" << endl;
	int get_temp = 0;
	get_queue(Queue, &get_temp);
	cout << "get_elem:" << get_temp << endl;
	cout << "Traverse:" << endl;
	traverse_queue(Queue, com);

	cout << "------------\tout_queue\t------------" << endl;
	int out_temp = 0;
	out_queue(Queue, &out_temp);
	cout << "out_elem:" << out_temp << endl;
	cout << "Traverse:" << endl;
	traverse_queue(Queue, com);

	cout << endl;
	cout << endl;
	cout << endl;

	//测试其循环性
	cout << "------------\tcircle\t------------" << endl;
	INT* Queue1 = NULL;
	if (!creat_queue(&Queue1)) {
		cout << "Creat failure!" << endl;
		return -1;
	}
	for (int i = 0; i < M; i++) {
		cout << "Please input a number:";
		int temp = 0;
		cin >> temp;
		if (!in_queue(Queue1, temp)) {
			cout << "Queue full!" << endl;
			break;
		}
	}
	cout << "Queue1->rear" << Queue1->rear << endl;
	cout << "Traverse:" << endl;
	traverse_queue(Queue1, com);

	//出队3个
	for (int i = 0; i < 3; i++) {
		int out_temp = 0;
		out_queue(Queue1, &out_temp);
		cout << "out_temp " << i + 1 << ":" << out_temp << endl;
	}
	cout << "Queue1->front = " << Queue1->front << endl;

	//测试再次入队4个
	for (int i = 0; i < 4; i++) {
		cout << "Please input a number:";
		int temp = 0;
		cin >> temp;
		if (!in_queue(Queue1, temp)) {
			cout << "Queue1 full!" << endl;
			break;
		}
	}
	cout << "Traverse:" << endl;
	traverse_queue(Queue1, com);

	cout << "Queue1_length = " << queue_length(Queue1) << endl;

	return 0;
}