#include"Yo_Tu.h"

AGraph* creat_AGraph() {

	//����ͼ
	AGraph* G = (AGraph*)malloc(sizeof(AGraph));
	if (G == NULL) exit(NO_MEMORY);
	
	cout << "�����������ͱ���:";
	cin >> G->vex_count >> G->arc_count;

	//����������
	G->AG = (AdjList*)malloc(sizeof(AdjList) * G->vex_count);
	if (G->AG == NULL) exit(NO_MEMORY);
	
	cout << "������������:";
	for (int i = 0; i < G->vex_count; i++) {
		cin >> G->AG[i].date;
		G->AG[i].head_in  = NULL;
		G->AG[i].head_out = NULL;
	}

	//���������
	for (int i = 0; i < G->arc_count; i++) {
		creat_Arc(G);
	}

	return G;
}

int search_node(AGraph* G, VerTexType v) {

	if (G == NULL) return ERROR;

	for (int i = 0; i < G->vex_count; i++) {
		if (G->AG[i].date == v) return i;
	}

	return ERROR;
}

void creat_Arc(AGraph* G) {

	if (G == NULL) return;

	cout << "���������Ϣ(��ʽ:A B 10 ; ��ʾ: A -> B ,Ȩֵ:10):";
	VerTexType v_from;
	VerTexType v_to;
	int weight;
	cin >> v_from >> v_to >> weight;

	int i_v_from = search_node(G, v_from);
	int i_v_to   = search_node(G, v_to);

	//����һ���߽��
	ArcNode* arc_node = (ArcNode*)malloc(sizeof(ArcNode));
	if (arc_node == NULL) exit(NO_MEMORY);
	arc_node->index_tail = i_v_from;
	arc_node->index_head = i_v_to;
	arc_node->info       = weight;
	arc_node->next_in    = NULL;
	arc_node->next_out   = NULL;

	//ͷ�彨�����ȱ�
	arc_node->next_out = G->AG[i_v_from].head_out;
	G->AG[i_v_from].head_out = arc_node;

	//ͷ�彨����ȱ�
	arc_node->next_in = G->AG[i_v_to].head_in;
	G->AG[i_v_to].head_in = arc_node;
}

void print_info(AGraph* G) {

	if (G == NULL)return;

	for (int i = 0; i < G->vex_count; i++) {
		cout << G->AG[i].date << endl;

		cout << "����:";
		ArcNode* p = G->AG[i].head_out;
		while (p) {
			cout << p->index_tail << " -> " << p->index_head << " ";
			p = p->next_out;
		}
		cout << endl;

		cout << "���:";
		p = G->AG[i].head_in;
		while (p) {
			cout << p->index_tail << " -> " << p->index_head << " ";
			p = p->next_in;
		}
		cout << endl;
	}
}

void DFS(AGraph* G,int index_v,bool* visited) {

	if (G == NULL) return;
	static bool* visit = creat_visited(G);
	
	


}

bool* creat_visited(AGraph* G) {

	if (G == NULL) return NULL;

	bool* ret = (bool*)malloc(sizeof(bool) * G->vex_count);
	if (ret == NULL) exit(NO_MEMORY);
	memset(ret, false, sizeof(bool) * G->vex_count);

	return ret;
}