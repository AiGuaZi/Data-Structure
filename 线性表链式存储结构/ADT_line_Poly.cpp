#include"ADT_line_Poly.h"



int InitList(Poly** L) {

	//�жϱ��Ƿ��Ѿ�����ָ��
	if (*L != NULL) {
		return -1;
	}

	//�����ڴ�
	Poly* head = (Poly*)malloc(sizeof(Poly));
	if (head == NULL) {
		return -2;
	}
	head->next = NULL;

	//��L����
	*L = head;

	return 0;
}

int isEmptyList(Poly* L) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	//�жϲ��ǿձ�
	if (L->next != NULL) {
		return 1;
	}

	return 0;
}

int ListLength(Poly* L) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	//���㳤��
	Poly* index = L->next;
	int L_length = 0;
	while (index) {
		index = index->next;
		L_length++;
	}

	return L_length;
}

int DestroyList(Poly** L) {

	//�жϱ��Ƿ����
	if (*L == NULL) {
		return -1;
	}

	if ((*L)->next != NULL) {
		Poly* p = (*L)->next;
	}
	Poly* q = *L;

	while (p) {
		free(q);
		q = p;
		p = p->next;
	}
	if(p == NULL && q != NULL)
		free(q);
	*L = NULL;

	return 0;
}

int ClearList(Poly** L) {

	//�жϱ��Ƿ����
	if (*L == NULL) {
		return -1;
	}

	//�����ٱ�
	DestroyList(L);

	//���³�ʼ�����
	InitList(L);

	return 0;
}

int getElem(Poly* L, int i, Poly** e) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	//�жϲ���λ���Ƿ���ȷ
	if (i < 1 || i > ListLength(L)) {
		return -2;
	}

	//ȡԪ��
	Poly* p = L->next;
	int count = 1;
	while (p != NULL && count < i) {
		p = p->next;
		count++;
	}
	*e = p;

	return 0;
}

int LocateElem(Poly* L, const Poly e, int(con)(const Poly e, const Poly e1)) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	Poly* p = L->next;
	int count = 1;
	while (p) {

		if (!con(e, *p)) {
			return count;
		}

		count++;
		p = p->next;
	}

	return 0;
}

int PriorElem(Poly* L, Poly cur_e, Poly** pre_e) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	Poly* p = L->next->next;
	Poly* q = L->next;

	//�ų���һ��Ϊǰ��
	if (q->cof == cur_e.cof && q->cof == cur_e.pow) {
		free(*pre_e);
		*pre_e = NULL;
	}

	while (p) {

		if (p->cof == cur_e.cof && p->pow == cur_e.pow) {
			*pre_e = q;
			break;
		}

		q = p;
		p = p->next;
	}

	return 0;
}

int NextElem(Poly* L, Poly cur_e, Poly** next_e) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	Poly* p = L->next;

	while (p) {
		if (p->cof == cur_e.cof && p->pow == cur_e.pow) {
			*next_e = p->next;
			break;
		}
		p = p->next;
	}

	//��û�и��ϸ�Ԫ�صĺ�������-2��
	if (!p) {
		return -2;
	}

	return 0;
}

int InsertList(Poly* L, int i, Poly e) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	//�жϲ���λ���Ƿ���ȷ
	if (i<1 || i> ListLength(L)+1) {
		return -2;
	}

	//ƽ����ָ��λ��
	Poly* p = L->next;
	Poly* q = L;
	int count = 1;
	while (p && count < i) {
		q = p;
		p = p->next;
	}

	//Ԫ�ز���
	Poly* date = (Poly*)malloc(sizeof(Poly));

	if (date == NULL) {
		return -2;
	}
	date->pow = e.pow;
	date->cof = e.cof;
	date->next = NULL;
	
	if (L->next == NULL) {
		L->next = date;
	}
	else {
		q->next = date;
		date->next = p;
	}
	

	return 0;
}

int DeleteList(Poly* L, int i) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	if (!isEmptyList(L)) {
		return -1;
	}
	//ƽ����ָ��λ��
	Poly* p = L->next;
	Poly* q = L;
	int count = 1;
	while (p && count < i) {
		q = p;
		p = p->next;
		count++;
	}

	//ɾ������
	if (p && p->next == NULL) {
		q->next = NULL;
	}
	else {
		if (p) q->next = p->next;
	}

	return 0;
}

int ListTraverse(Poly* L, void(*visited)(Poly e)) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	Poly* p = L->next;
	while (p) {
		visited(*p);
		p = p->next;
	}

	return 0;
}

int inputList(Poly* L) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}

	//�ƶ�����β
	Poly* p = L->next;
	while (p) {
		p = p->next;
	}

	//�������
	cout << "Input date('#' stop):" << endl;
	do {

		//����Ԫ��
		Poly* temp = (Poly*)malloc(sizeof(Poly));
		if (temp == NULL) {
			return -2;
		}
		temp->next = NULL;

		//����Ԫ�ص�ֵ
		cout << "Please input cof and pow (cof,pow) :";

		//����
		char str[100] = { 0 };

		cin >> str;
		if (str[0] == '#') {
			break;
		}

		//���볤�Ȳ��ϸ�
		if (strlen(str) < 3) {
			cout << "Please again!" << endl;
			continue;
		}

		//��ֵ����
		temp->cof = str[0] - '0';
		temp->pow = str[2] - '0';

		//cout << "Insert : cof = " << temp->cof << " pow = " << temp->pow << endl;

		//��������
		if (!p) {
			L->next = temp;
			p = temp;
		}
		else {
			p->next = temp;
			p = p->next;
		}


		//�ж��Ƿ��������
		if (str[strlen(str) - 1] == '#') {
			break;
		}

	} while (true);
	cout << "Input date end!" << endl;

	return 0;
}

int sortOfCofList(Poly* L) {

	//�жϱ��Ƿ����
	if (L == NULL) {
		return -1;
	}



	//����ѡ������
	Poly* p = NULL, * q = NULL;
	p = L->next;
	while (p) {
		q = p->next;
		while (q) {
			if (p->pow > q->pow) {
				int temp = p->pow;
				p->pow = q->pow;
				q->pow = temp;
			}
			q = q->next;
		}
		p = p->next;
	}

	return 0;
}

int computePoly(Poly* L1, Poly* L2, Poly* answer, char(com)()) {

	//�жϱ��Ƿ����
	if (L1 == NULL || L2 == NULL || answer == NULL) {
		return -1;
	}

	//����������
	sortOfCofList(L1);
	sortOfCofList(L2);

	Poly* indexl1 = L1->next;
	Poly* indexl2 = L2->next;

	while (indexl1 && indexl2) {

		//������
		Poly* temp = (Poly*)malloc(sizeof(Poly));
		if (temp == NULL) {
			return -2;
		}
		temp->next = NULL;

		if (indexl1->pow < indexl2->pow) {
			temp->cof = indexl1->cof;
			temp->pow = indexl1->pow;
			indexl1 = indexl1->next;
		}
		else if (indexl1->pow < indexl2->pow) {
			temp->cof = indexl2->cof;
			temp->pow = indexl2->pow;
			indexl2 = indexl2->next;
		}
		else {

			if (com() == '+') {
				temp->cof = indexl1->cof + indexl2->cof;
				temp->pow = indexl1->pow;
				indexl1 = indexl1->next;
				indexl2 = indexl2->next;
			}

			else if (com() == '-') {
				temp->cof = indexl1->cof - indexl2->cof;
				temp->pow = indexl1->pow;
				indexl1 = indexl1->next;
				indexl2 = indexl2->next;
			}

			else {
				return -2;
			}
			
		}
		cout << "com : temp->cof = " << temp->cof << " temp->pow = " << temp->pow << endl;
		InsertList(answer, ListLength(answer) + 1, *temp);
	}

	while (indexl1) {
		InsertList(answer, ListLength(answer) + 1, *indexl1);
		indexl1 = indexl1->next;
	}
	cout << "answer = " << answer << endl;
	while (indexl2) {
		InsertList(answer, ListLength(answer) + 1, *indexl2);
		indexl2 = indexl2->next;
	}

	return 0;
}