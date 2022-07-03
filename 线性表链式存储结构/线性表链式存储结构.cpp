#include"ADT_line_Poly.h"

void vis(Poly e) {
	cout << "cof = " << e.cof << "  pow = " << e.pow << endl;
}

char com() {
	return '+';
}

int con(Poly e, Poly e1) {

	if (e.cof == e1.cof && e.pow == e1.pow) {
		return 0;
	}
	return -1;
}

int main() {

	cout << "------------list1------------" << endl;
	Poly* list1 = NULL;
	//��ʼ����
	int ret1 = InitList(&list1);
	if (ret1 != 0) {
		cout << "InitList error:%d" << ret1 << endl;
		return ret1;
	}

	//������ֵ
	inputList(list1);
	ListTraverse(list1, vis);

	cout << "------------list2------------" << endl;
	Poly* list2 = NULL;
	//��ʼ����
	int ret2 = InitList(&list2);
	if (ret2 != 0) {
		cout << "InitList error:%d" << ret2 << endl;
		return ret2;
	}

	//������ֵ
	inputList(list2);
	ListTraverse(list2, vis);

	cout << "------------Answer------------" << endl;
	Poly* answer = NULL;
	//��ʼ����
	int ret_A = InitList(&answer);
	if (ret_A != 0) {
		cout << "InitList error:%d" << ret_A << endl;
		return ret_A;
	}

	//�����������
	computePoly(list1, list2, answer,com);
	cout << "answer_length = " << ListLength(answer) << endl;
	//��������
	sortOfCofList(answer);
	//������ӡ
	ListTraverse(answer, vis);

	//����getElem
	//ȡanswer���2��ֵ������
	cout << "------------Answer getElem 2 ------------" << endl;
	Poly* getAnswer_2 = NULL;
	getElem(answer, 2, &getAnswer_2);
	cout << "get 2 : answer->cof = " << getAnswer_2->cof << "  answer->pow = " << getAnswer_2->pow << endl;

	//����LocateElem
	//����answer���Ƿ�����(*answer).poly[1]Ԫ��һ����Ԫ��
	cout << "------------Answer LocateElem 2 ------------" << endl;
	cout << "index :" << LocateElem(answer, *getAnswer_2, con) << endl;

	//����PriorElem��NextElem
	cout << "------------Answer PriorElem  ------------" << endl;
	Poly* pre_2_to_1 = (Poly*)malloc(sizeof(Poly));
	PriorElem(answer, *getAnswer_2, &pre_2_to_1);
	cout << "PriorElem 1 : pre_2_to_1->cof = " << pre_2_to_1->cof << "  pre_2_to_1->pow = " << pre_2_to_1->pow << endl;

	cout << "------------Answer NextElem  ------------" << endl;
	Poly* next_2_to_3 = (Poly*)malloc(sizeof(Poly));
	NextElem(answer, *getAnswer_2, &next_2_to_3);
	cout << "PriorElem 1 : next_2_to_3->cof = " << next_2_to_3->cof << "  next_2_to_3->pow = " << next_2_to_3->pow << endl;

	//����DeleteList
	//ɾ��answer���2��ֵ
	cout << "------------Answer DeleteList  ------------" << endl;
	DeleteList(answer, 2);
	//������ӡ
	ListTraverse(answer, vis);

	//������ձ�
	//���list��
	cout << "------------list1 ClearList  ------------" << endl;
	ClearList(&list1);
	if (isEmptyList(list1) == 0) {
		cout << "list1 is empty!" << endl;
	}

	//�������ٱ�
	//����list��
	cout << "------------list1 DestroyList  ------------" << endl;
	DestroyList(&list1);
	if (list1 == NULL) {
		cout << "list is destroied now!" << endl;
	}

	return 0;
}

