#include"Tu.h"

int search_node(const ALGraph* G, const VerTexType date) {

	if (G == NULL || G->AG == NULL) return ERROR;

	for (int i = 0; i < G->vex_count; i++) {
		if (G->AG[i].date == date) {
			return i;
		}
	}

	return ERROR;
}

ALGraph* creat_ALGraph(const int modle) {

	//��������ͼ�ռ�
	ALGraph* G = (ALGraph*)malloc(sizeof(ALGraph));
	if (G == NULL) exit(ENOMEM_ERROR);
	G->AG = NULL;
	G->arc_count = 0;
	G->vex_count = 0;

	//���������ͱ���
	cout << "�����������ͱ���:";
	cin >> G->vex_count >> G->arc_count;
	
	//������ռ�
	G->AG = (AdjList*)malloc(sizeof(AdjList) * G->vex_count);
	if (G->AG == NULL) exit(ENOMEM_ERROR);

	//����������
	cout << "������������:";
	for (int i = 0; i < G->vex_count; i++) {
		cin >> G->AG[i].date;
		G->AG[i].head = NULL;
	}

	//�����ڽӱ�
	for (int i = 0; i < G->arc_count; i++) {

		cout << "�������ڽӽ���Ȩֵ:";
		VerTexType v1 = 0;
		VerTexType v2 = 0;
		int weight    = 0;
		cin >> v1 >> v2 >> weight;

		int index_v1 = search_node(G, v1);
		int index_v2 = search_node(G, v2);

		//v1 -> v2
		ArcNode* arc_v1_to_v2 = (ArcNode*)malloc(sizeof(ArcNode));
		if (arc_v1_to_v2 == NULL) exit(ENOMEM_ERROR);
		arc_v1_to_v2->index_in_AdjList = index_v2;
		arc_v1_to_v2->info             = weight;
		arc_v1_to_v2->next             = NULL;

		//�������߱�
		/*�������β
		* ArcNode* p = G->AG[index_v1].head;
		* while (p->next) p = p->next;
		* p->next = arc;
		*/
		
		arc_v1_to_v2->next = G->AG[index_v1].head;
		G->AG[index_v1].head = arc_v1_to_v2;

		//v2 -> v1 //ģʽΪ��������ִ��
		if (modle == NO_TU) {
			ArcNode* arc_v2_to_v1 = (ArcNode*)malloc(sizeof(ArcNode));
			if (arc_v2_to_v1 == NULL) exit(ENOMEM_ERROR);
			arc_v2_to_v1->index_in_AdjList = index_v1;
			arc_v2_to_v1->info = weight;
			arc_v2_to_v1->next = NULL;

			arc_v2_to_v1->next = G->AG[index_v2].head;
			G->AG[index_v2].head = arc_v2_to_v1;
		}
	}

	return G;
}

void print_date(const ALGraph* G) {

	if (G == NULL) return;

	for (int i = 0; i < G->vex_count; i++) {
		
		VerTexType date = G->AG[i].date;

		cout << " " << date << " ";
		
		ArcNode* p = G->AG[i].head;
		while (p) {
			cout << G->AG[p->index_in_AdjList].date << p->index_in_AdjList << " weight = " << p->info << " ";
			p = p->next;
		}

		cout << endl;
	}
}

int cal_node_count(const AdjList* AG) {
	
	if (AG == NULL) return ERROR;

	int count = 0;
	ArcNode* p = AG->head;

	while (p) { count++; p = p->next; }

	return count;
}

bool* creat_and_init_visited(ALGraph* G) {

	if (G == NULL) return NULL;

	bool* ret = (bool*)malloc(sizeof(bool) * G->arc_count);
	if (ret == NULL) exit(-1);
	memset(ret, false, sizeof(bool) * G->arc_count);

	return ret;
}

void DFS(ALGraph* G, int index_v, bool* visited) {

	if (G == NULL   || visited == NULL || 
		index_v < 0 || index_v >= G->vex_count) return;

	cout << G->AG[index_v].date << " ";
	visited[index_v] = true;

	ArcNode* p = G->AG[index_v].head;
	while (p) {
		if (!visited[p->index_in_AdjList]) {
			DFS(G, p->index_in_AdjList, visited);
		}
		p = p->next;
	}

	
}

void free_ALGraph(ALGraph* G) {

	if (G == NULL) return;

	for (int i = 0; i < G->vex_count; i++) {
		//�ͷű߱�
		free_Arc(G->AG[i].head);
	}

	free(G->AG);
	G->AG = NULL;

	free(G);
	G = NULL;
}

void free_ArcNode(ArcNode* arc) {
	if (arc == NULL) return;

	free(arc);
	arc = NULL;
}

void free_Arc(ArcNode* head) {

	if (head == NULL) return;

	ArcNode* p = head;
	while (p) {
		ArcNode* temp = p;
		p = p->next;
		free_ArcNode(temp);
	}
}

void free_visited(bool* visited) {
	if (visited == NULL) return;

	free(visited);
	visited = NULL;
}

void BFS(ALGraph* G, int i_v) {

	if (G == NULL || i_v < 0 || i_v >= G->vex_count) return;

	//������������
	int* temp_queue = (int*)malloc(sizeof(int) * G->vex_count);
	if (temp_queue == NULL) exit(ENOMEM_ERROR);
	memset(temp_queue, -1, sizeof(int) * G->vex_count);
	int index_head = 0;
	int index_tail = 0;

	//�������ʱ�
	int* visited = (int*)malloc(sizeof(int) * G->vex_count);
	if (visited == NULL) exit(ENOMEM_ERROR);
	memset(visited, -1, sizeof(int) * G->vex_count);

	temp_queue[index_head] = i_v;
	visited[i_v] = i_v;
	up_queue(&index_head, G->vex_count);

	while (index_head != index_tail) {
		cout << G->AG[temp_queue[index_tail]].date << " ";

		ArcNode* p = G->AG[temp_queue[index_tail]].head;
		while (p) {
			if (visited[p->index_in_AdjList] != p->index_in_AdjList) {
				temp_queue[index_head] = p->index_in_AdjList;
				up_queue(&index_head, G->vex_count);
				visited[p->index_in_AdjList] = p->index_in_AdjList;
			}
			p = p->next;
		}
		up_queue(&index_tail, G->vex_count);
	}

	cout << endl;
}

void up_queue(int* up_num, int max) {

	if (up_num == NULL) return;

	*up_num = (*up_num + 1) % max;
}