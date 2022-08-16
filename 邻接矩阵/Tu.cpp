#include"Tu.h"

AMGraph* init_Graph() {

	//创建图
	AMGraph *G = (AMGraph*)malloc(sizeof(AMGraph));
	if (G == NULL) exit(-1);

	//输入顶点数和边数
	cout << "Please enter two numbers(vex_count and arc_count) : ";
	cin >> G->vex_count >> G->arc_count;

	if (G->vex_count <= 0) {
		cout << "Error: vex_count con't equal or less than 0";
		return NULL;
	}

	//输入顶点值
	G->vexs = (VerTexTyper*)malloc(sizeof(VerTexTyper) * G->vex_count);
	if (G->vexs == NULL) exit(-1);

	cout << "Please enter date:";
	for (int i = 0; i < G->vex_count; i++) {
		cin >> G->vexs[i];
	}

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

	//构造邻接矩阵
	for (int i = 0; i < G->arc_count; i++) {

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
		int index_v1 = search_elem(G, v1);
		int index_v2 = search_elem(G, v2);

		G->arcs[index_v1][index_v2] = wight;
		G->arcs[index_v2][index_v1] = wight;

		/*
		* 有向图:G->arcs[index_v1][index_v2] = wight;
		*/
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