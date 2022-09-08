#include"Tu.h"

ALGraph* init_Graph(int vex_count, int arc_count) {

	if (vex_count < 0 || arc_count < 0) return NULL;

	//分配无向图空间
	ALGraph* G = (ALGraph*)malloc(sizeof(ALGraph));
	if (G == NULL) exit(ENOMEM_ERROR);
	G->AG = NULL;
	G->arc_count = arc_count;
	G->vex_count = vex_count;

	//分配结点空间
	G->AG = (AdjList*)malloc(sizeof(AdjList) * G->vex_count);
	if (G->AG == NULL) exit(ENOMEM_ERROR);
	memset(G->AG, NULL, sizeof(AdjList) * G->vex_count);

	return G;
}

int search_node(const ALGraph* G, const VerTexType date) {

	if (G == NULL || G->AG == NULL) return ERROR;

	for (int i = 0; i < G->vex_count; i++) {
		if (G->AG[i].date == date) {
			return i;
		}
	}

	return ERROR;
}

void creat_ALGraph(ALGraph* G,const int modle) {

	if (G == NULL) return;

	//输入结点数据
	cout << "请输入结点数据:";
	for (int i = 0; i < G->vex_count; i++) {
		cin >> G->AG[i].date;
		G->AG[i].head = NULL;
	}

	//构造邻接表
	for (int i = 0; i < G->arc_count; i++) {

		cout << "请输入邻接结点和权值:";
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

		//连接至边表
		/*添加至表尾
		* ArcNode* p = G->AG[index_v1].head;
		* while (p->next) p = p->next;
		* p->next = arc;
		*/
		
		arc_v1_to_v2->next = G->AG[index_v1].head;
		G->AG[index_v1].head = arc_v1_to_v2;

		//v2 -> v1 //模式为有向网就执行
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
		//释放边表
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

	//建立辅助队列
	int* temp_queue = (int*)malloc(sizeof(int) * G->vex_count);
	if (temp_queue == NULL) exit(ENOMEM_ERROR);
	memset(temp_queue, -1, sizeof(int) * G->vex_count);
	int index_head = 0;
	int index_tail = 0;

	//建立访问表
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

	//释放辅助内存
	free(temp_queue);
	free(visited);
	cout << endl;
}

void up_queue(int* up_num, int max) {

	if (up_num == NULL) return;

	*up_num = (*up_num + 1) % max;
}

ALGraph* MST_Prim(ALGraph* G, int i_v) {

	if (G == NULL) return NULL;

	ALGraph* TE = init_Graph(G->vex_count, G->vex_count - 1);

	bool* visited = (bool*)malloc(sizeof(bool) * G->vex_count);
	if (visited == NULL) exit(ENOMEM_ERROR);
	memset(visited, false, sizeof(bool) * G->vex_count);

	TE->AG[i_v].date = G->AG[i_v].date;
	visited[i_v] = true;

	for (int top_TE = 0; top_TE < TE->vex_count; top_TE++) {
		
		TE->AG[top_TE].date = G->AG[top_TE].date;
		

		int min_i = -1;
		int min_j = -1;
		int min_info = 2147483647;
		for (int j = 0; j < G->vex_count; j++) {

			if (visited[j]) continue;

			ArcNode* p = G->AG[j].head;
			while (p) {
				if (visited[p->index_in_AdjList] && p->info < min_info) {
					min_i = p->index_in_AdjList;
					min_j = j;
					min_info = p->info;
				}
				p = p->next;
			}
		}

		visited[min_j] = true;
		creat_ARC(TE, min_j, TE, min_i, min_info);
		creat_ARC(TE, min_i, TE, min_j, min_info);
	}
	return TE;
}

void creat_ARC(ALGraph* from, int i_from, ALGraph* to, int i_to,int info) {

	if (from == NULL || i_from < 0 || i_from >= from->vex_count)return;
	if (to   == NULL || i_to   < 0 || i_to   >=   to->vex_count)return;

	ArcNode* arc_i_j = (ArcNode*)malloc(sizeof(ArcNode));
	if (arc_i_j == NULL) exit(ENOMEM_ERROR);
	arc_i_j->index_in_AdjList = i_from;
	arc_i_j->info = info;
	arc_i_j->next = NULL;

	arc_i_j->next = to->AG[i_to].head;
	to->AG[i_to].head = arc_i_j;

}

Dijk_List* init_DijkList(ALGraph* G) {

	if (G == NULL)return NULL;
	int vex_count = G->vex_count;

	Dijk_List* ret = (Dijk_List*)malloc(sizeof(Dijk_List));
	if (ret == NULL)exit(ENOMEM_ERROR);

	ret->date = (int**)malloc(sizeof(int*) * vex_count);
	if (ret->date == NULL) exit(ENOMEM_ERROR);

	for (int i = 0; i < vex_count; i++) {
		ret->date[i] = (int*)malloc(sizeof(int) * vex_count);
		if (ret->date[i] == NULL)exit(ENOMEM_ERROR);
		for (int j = 0; j < vex_count; j++) {
			ret->date[i][j] = MAX_INT;
		}
	}

	ret->Aim = (AimI_info*)malloc(sizeof(AimI_info) * vex_count);
	if (ret->Aim == NULL)exit(ENOMEM_ERROR);
	memset(ret->Aim, NULL, sizeof(AimI_info) * vex_count);

	return ret;
}

int Dijkstra(ALGraph* G, int orign, int finish) {

	if (G == NULL) return ERROR;
	if (orign  < 0 || orign  >= G->vex_count)return ERROR;
	if (finish < 0 || finish >= G->vex_count)return ERROR;

	int vex_count = G->vex_count;

	//建立访问队列，将未进行排查是否含有出度边的结点入队
	int* temp_queue = (int*)malloc(sizeof(int) * vex_count);
	if (temp_queue == NULL) exit(ENOMEM_ERROR);
	memset(temp_queue, 0, sizeof(int) * vex_count);
	int index_head = 0;
	int index_tail = 0;

	//建立以计算最短路劲结点访问表
	bool* visited = (bool*)malloc(sizeof(bool) * vex_count);
	if (visited == NULL)exit(ENOMEM_ERROR);
	memset(visited, false, sizeof(bool) * vex_count);

	//建立Dijk辅助表
	Dijk_List* D_List = init_DijkList(G);
	int i_D = 1;//计算当前最短路劲轮数

	//起点入队
	temp_queue[index_head] = orign;
	up_queue(&index_head, vex_count);
	visited[orign] = true;

	while (index_head != index_tail) {

		ArcNode* p = G->AG[temp_queue[index_tail]].head;
		if (p == NULL) {
			up_queue(&index_tail, vex_count);
			continue;
		}

		while (p) {

			//将待处理的结点入队
			if (visited[p->index_in_AdjList] == false) {
				temp_queue[index_head] = p->index_in_AdjList;
				up_queue(&index_head, vex_count);
			}
			
			//初始时(第一轮)将，将起始点的出度边的信息进行存储值D_List辅助表中
			if (i_D == 1) { 
				D_List->date[p->index_in_AdjList][i_D] = p->info;
			}

			p = p->next;
		}

		
		//计算是否因为加入新结点后，导致最短路径发生变化
		if (i_D > 1) {
			for (int i = 0; i < vex_count; i++) {
				if (visited[i]) continue;

				for (int j = 1; j < i_D; j++) {
					int temp_info = 0;
					//如果发生变化，则更新最短路径信息
					/*判断原理
					* 搜索已完成计算最短路劲结点，是否为当前，未加入的前驱结点。
					* 若是则继续判断该前驱结点到，当前结点的路劲之和，是否会小于原存储路劲信息
					* 是则更新最短路劲信息，否则延续路劲信息
					*/
					if (is_PreNode(G, D_List->Aim[j].aim_j, i,&temp_info)
						&& D_List->Aim[j].info + temp_info <= D_List->date[i][i_D - 1]) {
						D_List->date[i][i_D] = D_List->Aim[j].info + temp_info;
					}
					else {//如果没有发生变化，则延续路径信息
						D_List->date[i][i_D] = D_List->date[i][i_D - 1];
					}
				}
			}
		}


		up_queue(&index_tail, vex_count);
		
		//寻找最小长度
		/*遍历所有到达该结点的路劲信息
		* 寻找最小值，并并加入至已计算最短路径的表中去
		*/
		int min_i = 0;
		int min_info = MAX_INT;
		for (int i = 0; i < vex_count; i++) {
			//判断原理:
			/*
			* 判断当前结点是否已经被计算，是则跳过，否则继续判断当前结点是否为最小路劲结点
			* 是则存储其结点小标，和最短路劲值
			*/
			if (!visited[i] &&
				/*D_List->date[i][i_D] != ROAD_ERROR &&*/ 
				D_List->date[i][i_D] < min_info) {
				min_i    = i;
				min_info = D_List->date[i][i_D];
			}
		}

		D_List->Aim[i_D].aim_j = min_i;
		D_List->Aim[i_D].info  = min_info;

		//将得到的最短路劲值进行记录至已计算列表中去
		visited[min_i] = true;
		i_D++;//进行下一轮
	}

	int ret_answer = -1;
	for (int i = 1; i < i_D; i++) {
		if (D_List->Aim[i].aim_j == finish) {
			ret_answer = D_List->Aim[i].info;
			break;
		}
	}
	
	//释放辅助空间
	free_D_List(D_List, vex_count);
	free_visited(visited);
	free(temp_queue);
	temp_queue = NULL;
	return ret_answer;
}

void print_DijkList(Dijk_List* D_List,int count) {

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++)
			cout << "  " << D_List->date[i][j];
		cout << endl;
	}

	for (int i = 0; i < count; i++) {
		cout << "  " << D_List->Aim[i].aim_j;
	}
	cout << endl;
	for (int i = 0; i < count; i++) {
		cout << " " << D_List->Aim[i].info;
	}
	cout << endl << endl << endl;
}

bool is_PreNode(ALGraph* G, int is_i, int aim_i,int* info) {
	
	if (G == NULL) return false;
	if (is_i < 0 || aim_i < 0)return false;
	if (is_i >= G->vex_count || aim_i >= G->vex_count)return false;

	ArcNode* p = G->AG[is_i].head;
	while (p) {
		if (p->index_in_AdjList == aim_i) {
			*info = p->info;
			return true;
		}
		p = p->next;
	}

	return false;
}

void free_D_List(Dijk_List* D_List,int vex_count) {

	if (D_List == NULL) return;

	if (D_List->Aim != NULL) {
		free(D_List->Aim);
		D_List->Aim == NULL;
	}

	for (int i = 0; i < vex_count; i++) {
		if (D_List->date[i] != NULL) {
			free(D_List->date[i]);
			D_List->date[i] = NULL;
		}
	}
	
	if (D_List != NULL) {
		free(D_List->date);
		D_List->date = NULL;
	}

	free(D_List);
}

bool YoNo_PreNode(ALGraph* G, int i_v) {

	if (G == NULL || i_v < 0 || i_v >= G->vex_count) return ERROR;

	int vex_count = G->vex_count;
	for (int i = 0; i < vex_count; i++) {

		if (i == i_v)continue;

		ArcNode* p = G->AG[i].head;
		while (p) {
			if (p->index_in_AdjList == i_v) return true;
			p = p->next;
		}
	}

	return false;
}

void search_no_PreNode(ALGraph* G, Stack** no_PreNode) {

	if (G == NULL) return;

	init_Stack(G->vex_count,no_PreNode);

	int no_count = 0;
	for (int i = 0; i < G->vex_count; i++) {
		if (!YoNo_PreNode(G, i)) {
			(*no_PreNode)->date[(*no_PreNode)->top++] = i;
		}
	}
}

void init_Stack(int count,Stack **S) {
	if (count <= 0)return;

	*S = (Stack*)malloc(sizeof(Stack));
	if (S == NULL) exit(ENOMEM_ERROR);

	(*S)->date = (int*)malloc(sizeof(int) * count);
	if ((*S)->date == NULL) exit(ENOMEM_ERROR);
	memset((*S)->date, 0, sizeof(int) * count);
	(*S)->top = 0;
}

bool delete_Node(ALGraph* G, int i_v) {

	if (G == NULL || i_v < 0 || i_v >= G->vex_count) return ERROR;

	
}

void Topo_Sort(ALGraph* G) {

	if (G == NULL)return;
	Stack* no_PreNode = NULL;
	search_no_PreNode(G, &no_PreNode);

	int count = 0;
	while (no_PreNode->top != 0) {
		
		int s_top_elem = no_PreNode->date[--no_PreNode->top];
		cout << G->AG[s_top_elem].date << " ";

		ArcNode* p = G->AG[s_top_elem].head;
		while (p) {
			if (!YoNo_PreNode(G, p->index_in_AdjList)) {
				no_PreNode->date[no_PreNode->top++] = p->index_in_AdjList;
			}
			p = p->next;
		}
	}

	if (count < G->vex_count) {
		cout << "此图存在环" << endl;
	}
}