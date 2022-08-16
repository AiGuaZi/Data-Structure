#include"Tu_No.h"

AGraph* creat_AGraph() {

	AGraph* G = (AGraph*)malloc(sizeof(AGraph));
	if (G == NULL) exit(NO_MEMORY);
	G->AG = NULL;

	//���붥�����ͱ���
	cout << "�����붥�����ͱ���:";
	cin >> G->vex_count >> G->arc_count;

	//���춥����Ϣ
	G->AG = (AdjList*)malloc(sizeof(AdjList) * G->vex_count);
	if (G->AG == NULL) exit(NO_MEMORY);

	cout << "�����붥����Ϣ:";
	for (int i = 0; i < G->vex_count; i++) {
		cin >> G->AG[i].date;
		G->AG[i].head = NULL;
	}

	//�����
	for (int i = 0; i < G->arc_count; i++) {
		creat_ArcNode(G);
		cout << "��" << i + 1 << "��" << endl;
		print_info(G);
	}
	cout << endl;
	return G;
}

bool creat_ArcNode(const AGraph* G) {

	if (G == NULL) return false;

	cout << "������ߵ���Ϣ(��:A B 10 , ��ʾ: A <-> B Ȩֵ:10):";
	VerTexType v1,v2;
	int weight;
	cin >> v1 >> v2 >> weight;

	int v1_i = search_node(G, v1);
	int v2_i = search_node(G, v2);

	if (v1_i == ERROR || v2_i == ERROR)return false;

	//����߽��
	ArcNode* arc = (ArcNode*)malloc(sizeof(ArcNode));
	if (arc == NULL) exit(NO_MEMORY);
	arc->mark     = false;
	arc->info     = weight;
	arc->in_vex   = v1_i;
	arc->out_vex  = v2_i;
	arc->in_next  = NULL;
	arc->out_next = NULL;

	//ͷ����г��ȱ߲���
	arc->in_next = G->AG[v1_i].head;
	G->AG[v1_i].head = arc;

	//ͷ�������ȱ߲���
	arc->out_next = G->AG[v2_i].head;
	G->AG[v2_i].head = arc;

	////ͷ����г��ȱ߲���
	//arc->out_next = G->AG[v1_i].head;
	//G->AG[v1_i].head = arc;

	////ͷ�������ȱ߲���
	//arc->in_next = G->AG[v2_i].head;
	//G->AG[v2_i].head = arc;

	/*cout << "v1_i = " << v1_i << endl;
	cout << "v2_i = " << v2_i << endl;
	ArcNode* p, * q;
	p = G->AG[v1_i].head;
	
	if (!p) {
		G->AG[v1_i].head = arc;
		arc->in_next == NULL;
		cout << "p = NULL" << endl;
	}
	else {
		cout << "p = " << p->in_vex << ":" << p->out_vex << endl;
		G->AG[v1_i].head = arc;
		arc->in_next = p;
	}

	q = G->AG[v2_i].head;
	if (!q) {
		G->AG[v2_i].head = arc;
		arc->out_next = NULL;
		cout << "q = NULL" << endl;
	}
	else {
		cout << "q = " << q->in_vex << ":" << q->out_vex << endl;
		G->AG[v2_i].head = arc;
		arc->out_next = q;
	}*/

}

int search_node(const AGraph* G, VerTexType elem) {

	if (G == NULL) return ERROR;

	for (int i = 0; i < G->vex_count; i++) {
		if (G->AG[i].date == elem) {
			return i;
		}
	}

	cout << "��ѯʧ��" << endl;

	return ERROR;
}

void print_info(const AGraph* G) {

	if (G == NULL) return;

	for (int i = 0; i < G->vex_count; i++) {
		
		cout << G->AG[i].date << endl;

		ArcNode* p = G->AG[i].head;
		while (p) {
			cout << p->in_vex << "->" << p->out_vex << "    ";
			if (p->in_vex == i)
				p = p->in_next;
			else
				p = p->out_next;
		}
		cout << endl;

		/*p = G->AG[i].head;
		while (p) {
			cout << p->in_vex << " " << p->out_vex << " " << p->info << "    ";
			p = p->out_next;
		}
		cout << endl;*/
	}
}