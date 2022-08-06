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