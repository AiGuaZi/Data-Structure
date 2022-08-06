#include"Tu.h"

AMGraph* init_Graph() {

	//����ͼ
	AMGraph *G = (AMGraph*)malloc(sizeof(AMGraph));
	if (G == NULL) exit(-1);

	//���붥�����ͱ���
	cout << "Please enter two numbers(vex_count and arc_count) : ";
	cin >> G->vex_count >> G->arc_count;

	if (G->vex_count <= 0) {
		cout << "Error: vex_count con't equal or less than 0";
		return NULL;
	}

	//���붥��ֵ
	G->vexs = (VerTexTyper*)malloc(sizeof(VerTexTyper) * G->vex_count);
	if (G->vexs == NULL) exit(-1);

	cout << "Please enter date:";
	for (int i = 0; i < G->vex_count; i++) {
		cin >> G->vexs[i];
	}

	//��ʼ���ڽӾ���
	G->arcs = (ArcType**)malloc(sizeof(ArcType*) * G->vex_count);
	if (G->arcs == NULL) exit(-1);
	for (int i = 0; i < G->vex_count; i++) {

		G->arcs[i] = (ArcType*)malloc(sizeof(ArcType) * G->vex_count);
		if (G->arcs[i] == NULL) exit(-1);

		for (int j = 0; j < G->vex_count; j++) 
			G->arcs[i][j] = MAX_INT;
	}

	//�����ڽӾ���
	for (int i = 0; i < G->arc_count; i++) {

		//�����ڽӵ���������ֵ
		cout << "���������ڽӵ���������ֵ��Ȩֵ:";
		VerTexTyper v1 = 0;
		VerTexTyper v2 = 0;
		ArcType  wight = 0;
		cin >> v1 >> v2 >> wight;

		//�ж������ֵ�Ƿ���ͬ
		if (v1 == v2) {
			cout << "����������ͬ��ֵ" << endl;
			i--;
			continue;
		}

		//��ѯ����ͼ�е��±�
		int index_v1 = search_elem(G, v1);
		int index_v2 = search_elem(G, v2);

		G->arcs[index_v1][index_v2] = wight;
		G->arcs[index_v2][index_v1] = wight;
	}
	
	return G;
}

int search_elem(AMGraph* G, VerTexTyper v2) {

	if (G == NULL) return -1;

	for (int i = 0; i < G->vex_count; i++) {
		if (G->vexs[i] == v2) {
			return i;
		}
	}

	return -1;
}

void print_AMG(AMGraph* G) {

	if (G == NULL) {
		cout << "��ӡʧ�ܣ�" << endl;
		return;
	}

	for (int i = -1; i < G->vex_count; i++) {

		if (i >= 0) printf("%-14c", G->vexs[i]);
		else printf("              ");

		for (int j = 0; j < G->vex_count; j++) {

			if (i < 0) {
				printf("%-14c", G->vexs[j]);
				continue;
			}

			printf("%-14d", G->arcs[i][j]);
		}

		printf("\n");
	}
}