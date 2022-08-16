#include"Yo_Tu.h"

AGraph* creat_AGraph() {

	//建立图
	AGraph* G = (AGraph*)malloc(sizeof(AGraph));
	if (G == NULL) exit(NO_MEMORY);
	
	cout << "请输入结点数和边数:";
	cin >> G->vex_count >> G->arc_count;

	//输入结点数据
	G->AG = (AdjList*)malloc(sizeof(AdjList) * G->vex_count);
	if (G->AG == NULL) exit(NO_MEMORY);
	
	cout << "请输入结点数据:";
	for (int i = 0; i < G->vex_count; i++) {
		cin >> G->AG[i].date;
		G->AG[i].head_in  = NULL;
		G->AG[i].head_out = NULL;
	}

	//构造边数据
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

	cout << "请输入边信息(格式:A B 10 ; 表示: A -> B ,权值:10):";
	VerTexType v_from;
	VerTexType v_to;
	int weight;
	cin >> v_from >> v_to >> weight;

	int i_v_from = search_node(G, v_from);
	int i_v_to   = search_node(G, v_to);

	//创建一个边结点
	ArcNode* arc_node = (ArcNode*)malloc(sizeof(ArcNode));
	if (arc_node == NULL) exit(NO_MEMORY);
	arc_node->index_tail = i_v_from;
	arc_node->index_head = i_v_to;
	arc_node->info       = weight;
	arc_node->next_in    = NULL;
	arc_node->next_out   = NULL;

	//头插建立出度边
	arc_node->next_out = G->AG[i_v_from].head_out;
	G->AG[i_v_from].head_out = arc_node;

	//头插建立入度边
	arc_node->next_in = G->AG[i_v_to].head_in;
	G->AG[i_v_to].head_in = arc_node;
}

void print_info(AGraph* G) {

	if (G == NULL)return;

	for (int i = 0; i < G->vex_count; i++) {
		cout << G->AG[i].date << endl;

		cout << "出度:";
		ArcNode* p = G->AG[i].head_out;
		while (p) {
			cout << p->index_tail << " -> " << p->index_head << " ";
			p = p->next_out;
		}
		cout << endl;

		cout << "入度:";
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