#pragma once
#include"queue_circle.h"

bool creat_queue(INT** Q) {
	
	//�ж϶����Ƿ񱻽���
	if (*Q != NULL) return false;

	//��������
	INT* creat_temp = (INT*)malloc(sizeof(INT));
	if (!creat_temp) return false;
	creat_temp->data = NULL;
	creat_temp->front = 0;
	creat_temp->rear = 0;

	//�������ݿռ�
	creat_temp->data = (int*)malloc(sizeof(int) * MAX_SIZE);
	if (!creat_temp->data) return false;

	*Q = creat_temp;

	return true;
}

int up_or_down(int index, int max, char oper) {

	//������ֵ�Ƿ���ȷ
	if (oper != '+') return 0;

	//����
	return (index + 1) % max;
}

bool in_queue(INT* Q, int e) {

	//�ж϶��Ƿ����
	if (Q == NULL) return false;

	//����
	if (is_queue_full(Q)) return false;

	//��Ӳ���
	Q->data[Q->rear] = e;
	Q->rear = up_or_down(Q->rear, MAX_SIZE, '+');
	cout << "Q->rear = " << Q->rear << endl;

	return true;
}

bool is_queue_full(INT* Q) {

	//�ж϶��Ƿ����
	if (Q == NULL) return false;

	return up_or_down(Q->rear, MAX_SIZE, '+') == Q->front ? true : false;
}

bool is_queue_empty(INT* Q) {

	//�ж϶��Ƿ����
	if (Q == NULL) return false;

	return Q->front == Q->rear ? true : false;
}

void traverse_queue(INT* Q, void (com)(const void* elem)) {

	//�ж϶��Ƿ����
	if (Q == NULL) {
		cout << "Error: Queue is empty!" << endl;
		return;
	}

	for (int i = Q->front; i < Q->rear; i++) {
		com(&Q->data[i]);
	}
}

bool out_queue(INT* Q, int* e) {

	//�ж϶��Ƿ����
	if (Q == NULL) return false;

	//�ж϶ӿ�
	if (is_queue_empty(Q)) return false;

	//ȡ��ͷԪ��
	*e = Q->data[Q->front];
	Q->front = up_or_down(Q->front, MAX_SIZE, '+');

	return true;
}

bool get_queue(INT* Q, int* e) {

	//�ж϶��Ƿ����
	if (Q == NULL) return false;

	//�ж϶ӿ�
	if (is_queue_empty(Q)) return false;

	*e = Q->data[Q->front];

	return true;
}

int queue_length(INT* Q) {

	//�ж϶��Ƿ����
	if (Q == NULL) return -1;

	return (Q->rear - Q->front + MAX_SIZE ) % MAX_SIZE;
}