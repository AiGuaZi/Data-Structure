#include"ADT_line_Poly.h"



int InitList(Poly** L) {

	//判断表是否已经存有指向
	if (*L != NULL) {
		return -1;
	}

	//分配内存
	Poly* head = (Poly*)malloc(sizeof(Poly));
	if (head == NULL) {
		return -2;
	}
	head->next = NULL;

	//由L返回
	*L = head;

	return 0;
}

int isEmptyList(Poly* L) {

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	//判断不是空表
	if (L->next != NULL) {
		return 1;
	}

	return 0;
}

int ListLength(Poly* L) {

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	//计算长度
	Poly* index = L->next;
	int L_length = 0;
	while (index) {
		index = index->next;
		L_length++;
	}

	return L_length;
}

int DestroyList(Poly** L) {

	//判断表是否存在
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

	//判断表是否存在
	if (*L == NULL) {
		return -1;
	}

	//先销毁表
	DestroyList(L);

	//重新初始化表格
	InitList(L);

	return 0;
}

int getElem(Poly* L, int i, Poly** e) {

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	//判断插入位置是否正确
	if (i < 1 || i > ListLength(L)) {
		return -2;
	}

	//取元素
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

	//判断表是否存在
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

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	Poly* p = L->next->next;
	Poly* q = L->next;

	//排除第一个为前驱
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

	//判断表是否存在
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

	//若没有复合该元素的后驱返回-2；
	if (!p) {
		return -2;
	}

	return 0;
}

int InsertList(Poly* L, int i, Poly e) {

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	//判断插入位置是否正确
	if (i<1 || i> ListLength(L)+1) {
		return -2;
	}

	//平移至指定位置
	Poly* p = L->next;
	Poly* q = L;
	int count = 1;
	while (p && count < i) {
		q = p;
		p = p->next;
	}

	//元素插入
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

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	if (!isEmptyList(L)) {
		return -1;
	}
	//平移至指定位置
	Poly* p = L->next;
	Poly* q = L;
	int count = 1;
	while (p && count < i) {
		q = p;
		p = p->next;
		count++;
	}

	//删除操作
	if (p && p->next == NULL) {
		q->next = NULL;
	}
	else {
		if (p) q->next = p->next;
	}

	return 0;
}

int ListTraverse(Poly* L, void(*visited)(Poly e)) {

	//判断表是否存在
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

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}

	//移动到表尾
	Poly* p = L->next;
	while (p) {
		p = p->next;
	}

	//输入操作
	cout << "Input date('#' stop):" << endl;
	do {

		//创建元素
		Poly* temp = (Poly*)malloc(sizeof(Poly));
		if (temp == NULL) {
			return -2;
		}
		temp->next = NULL;

		//输入元素的值
		cout << "Please input cof and pow (cof,pow) :";

		//输入
		char str[100] = { 0 };

		cin >> str;
		if (str[0] == '#') {
			break;
		}

		//输入长度不合格
		if (strlen(str) < 3) {
			cout << "Please again!" << endl;
			continue;
		}

		//赋值操作
		temp->cof = str[0] - '0';
		temp->pow = str[2] - '0';

		//cout << "Insert : cof = " << temp->cof << " pow = " << temp->pow << endl;

		//插入表操作
		if (!p) {
			L->next = temp;
			p = temp;
		}
		else {
			p->next = temp;
			p = p->next;
		}


		//判断是否可以跳出
		if (str[strlen(str) - 1] == '#') {
			break;
		}

	} while (true);
	cout << "Input date end!" << endl;

	return 0;
}

int sortOfCofList(Poly* L) {

	//判断表是否存在
	if (L == NULL) {
		return -1;
	}



	//进行选择排序
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

	//判断表是否存在
	if (L1 == NULL || L2 == NULL || answer == NULL) {
		return -1;
	}

	//排序两个表
	sortOfCofList(L1);
	sortOfCofList(L2);

	Poly* indexl1 = L1->next;
	Poly* indexl2 = L2->next;

	while (indexl1 && indexl2) {

		//创建答案
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