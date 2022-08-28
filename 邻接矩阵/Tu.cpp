#include"Tu.h"

AMGraph* init_Graph(int vex_count,int arc_count) {
	
	if (vex_count <= 0 && arc_count <= 0 || 
		arc_count > (vex_count - 1) * vex_count / 2) {
		return NULL;
	}

	//创建图
	AMGraph *G = (AMGraph*)malloc(sizeof(AMGraph));
	if (G == NULL) exit(-1);
	G->vex_count = vex_count;
	G->arc_count = arc_count;
	

	//输入顶点值
	G->vexs = (VerTexTyper*)malloc(sizeof(VerTexTyper) * G->vex_count);
	if (G->vexs == NULL) exit(-1);
	memset(G->vexs, 0, sizeof(VerTexTyper) * G->vex_count);


	//初始化邻接矩阵
	G->arcs = (ArcType**)malloc(sizeof(ArcType*) * G->vex_count);
	if (G->arcs == NULL) exit(-1);
	for (int i = 0; i < G->vex_count; i++) {

		G->arcs[i] = (ArcType*)malloc(sizeof(ArcType) * G->vex_count);
		if (G->arcs[i] == NULL) exit(-1);

		for (int j = 0; j < G->vex_count; j++) 
			G->arcs[i][j] = MAX_INT;
		/*
		* 无向图:G->arcs[i][j] = 1;
		*/
	}

	
	return G;
}

bool creat_Graph(AMGraph** G) {

	if (*G == NULL)return false;

	cout << "Please enter date:";
	for (int i = 0; i < (*G)->vex_count; i++) {
		cin >> (*G)->vexs[i];
	}

	//构造邻接矩阵
	for (int i = 0; i < (*G)->arc_count; i++) {

		//输入邻接的两个顶点值
		cout << "请输入相邻接的两个顶点值和权值:";
		VerTexTyper v1 = 0;
		VerTexTyper v2 = 0;
		ArcType  wight = 0;
		cin >> v1 >> v2 >> wight;

		//判断输入的值是否相同
		if (v1 == v2) {
			cout << "请误输入相同的值" << endl;
			i--;
			continue;
		}

		//查询其在图中的下标
		int index_v1 = search_elem((*G), v1);
		int index_v2 = search_elem((*G), v2);

		(*G)->arcs[index_v1][index_v2] = wight;
		(*G)->arcs[index_v2][index_v1] = wight;

		/*
		* 有向图:G->arcs[index_v1][index_v2] = wight;
		*/
	}

	return true;
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
		cout << "打印失败！" << endl;
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

void DFS(AMGraph* G,int index_v,bool *visited) {

	if (G == NULL) return;

	cout << G->vexs[index_v] << " ";
	visited[index_v] = true;

	for (int i = 0; i < G->vex_count; i++) {
		if (G->arcs[index_v][i] != MAX_INT && !visited[i]) {
			DFS(G, i, visited);
		}
	}

}

bool* creat_and_init_visited(AMGraph* G) {

	if (G == NULL) return NULL;

	bool* ret = (bool*)malloc(sizeof(bool) * G->vex_count);
	if (ret == NULL) exit(-1);
	memset(ret, false, sizeof(bool) * G->vex_count);

	return ret;
}

void free_Graph(AMGraph* G) {

	if (G == NULL)return;

	//释放顶点表
	free(G->vexs);
	G->vexs = NULL;

	//释放边表
	for (int i = 0; i < G->arc_count; i++) {
		free(G->arcs[i]);
		G->arcs[i] = NULL;
	}
	free(G->arcs);
	G->arcs = NULL;

	//释放图
	free(G);
	G = NULL;
}

void free_visited(bool* visited) {
	if (visited == NULL) return;

	free(visited);
	visited = NULL;
}

void BFS(AMGraph* G,int i_v) {

	if (G == NULL || i_v < 0 || i_v >= G->vex_count) return;

	

	//创建队列并初始化
	int* temp_queue = creat_and_init_queue(G);
	int index_head = 0;
	int index_tail = 0;

	//创建访问表
	int* visited = (int*)malloc(sizeof(int) * G->vex_count);
	if (visited == NULL) exit(-1);
	memset(visited, -1, sizeof(int) * G->vex_count);
	

	temp_queue[index_head] = i_v;
	up_queue(&index_head,G->vex_count);


	while (index_head != index_tail) {

		cout << G->vexs[temp_queue[index_tail]] << " ";
		visited[temp_queue[index_tail]] = 1;

		for (int i = 0; i < G->vex_count; i++) {
			if (G->arcs[temp_queue[index_tail]][i] != MAX_INT && visited[i] == -1) {
				temp_queue[index_head] = i;
				visited[i] = 1;
				up_queue(&index_head, G->vex_count);
			}
		}
		up_queue(&index_tail, G->vex_count);

	}

	free(temp_queue);
	free(visited);

	cout << endl;
}

int* creat_and_init_queue(AMGraph* G) {

	int* vexs = (int*)malloc(sizeof(int) * G->vex_count);
	if (vexs == NULL) exit(-1);
	memset(vexs, -1, sizeof(int) * G->vex_count);

	return vexs;
}

void up_queue(int* up_num, int max) {

	if (up_num == NULL) return;

	if (*up_num + 1 > max - 1) *up_num = 0;
	else *up_num += 1;
}

AMGraph* MST_Prim(AMGraph* G, int i_v) {
	
	if (G == NULL || i_v < 0 || i_v >= G->vex_count) return NULL;
	
	AMGraph* TE = init_Graph(G->vex_count, G->vex_count - 1);

	bool* visited = (bool*)malloc(sizeof(bool) * G->vex_count);
	if (visited == NULL) exit(-1);
	memset(visited, false, sizeof(bool) * G->vex_count);

	copy_node(G, i_v, TE, 0);
	visited[i_v] = true;
	for (int top_TE = 1; top_TE < G->vex_count; top_TE++) {

		int min_i_weight = -1;
		int min_j_weight = -1;
		int min_weight   = 2147483647;
		for (int j = 0; j < G->vex_count; j++) {

			if (visited[j] == true) continue;

			for (int i_arc = 0; i_arc < G->vex_count; i_arc++) {

				if (visited[i_arc] == false) continue;

				if (G->arcs[j][i_arc] != -1 && G->arcs[j][i_arc] < min_weight) {
					min_weight = G->arcs[j][i_arc];
					min_i_weight = i_arc;
					min_j_weight = j;
				}
			}
		}

		copy_node(G, top_TE, TE, top_TE);
		creat_ARC(TE, min_i_weight, min_j_weight, min_weight);
		visited[min_j_weight] = true;

	}

	free(visited);
	return TE;
}

void copy_node(AMGraph* from, int i_from, AMGraph* to,int i_to) {

	if (from == NULL || i_from < 0 || i_from >= from->vex_count)return;
	if (to   == NULL || i_to   < 0 || i_to   >    to->vex_count)return;
	if (from->vex_count != to->vex_count)                       return;

	to->vexs[i_to] = from->vexs[i_from];
}

void creat_ARC(AMGraph* G, int i_from, int i_to,int weight) {

	if (G == NULL)return;

	G->arcs[i_from][i_to] = weight;
	G->arcs[i_to][i_from] = weight;
}