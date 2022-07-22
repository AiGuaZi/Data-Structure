#include"binary_tree.h"

bool creat_BTree(BTree** T) {

	//�ж�T�Ƿ����ָ��
	if (*T != NULL) return false;

	//����
	*T = (BTree*)malloc(sizeof(BTree) * MAX_BT_SIZE);
	if (*T == NULL) return false;

	//��ʼ��
	memset(*T, 0, MAX_BT_SIZE * sizeof(int));

	/*ע�⣺дʵ�֣����Գ�ʼ������������ݣ���ʾΪ�����*/
	for (int i = 0; i < MAX_BT_SIZE; i++) {
		(*T)[i] = i + 1;
	}

	return true;
}

void pre_order_traverse(BTree* T,int now_xb /*��ǰ�±�*/) {

	if (T == NULL || now_xb > MAX_BT_SIZE - 1) return;

	cout << " " << T[now_xb];

	//����������
	pre_order_traverse(T, now_xb * 2 + 1);
	//����������
	pre_order_traverse(T, now_xb * 2 + 2);
}

void cen_order_traverse(BTree* T, int now_xb) {

	if (T == NULL || now_xb > MAX_BT_SIZE - 1) return;

	//����������
	cen_order_traverse(T, now_xb * 2 + 1);

	cout << " " << T[now_xb];

	//����������
	cen_order_traverse(T, now_xb * 2 + 2);
}

void pos_order_traverse(BTree* T, int now_xb){

	if (T == NULL || now_xb > MAX_BT_SIZE - 1) return;

	//����������
	pos_order_traverse(T, now_xb * 2 + 1);
	//����������
	pos_order_traverse(T, now_xb * 2 + 2);

	cout << " " << T[now_xb];
}