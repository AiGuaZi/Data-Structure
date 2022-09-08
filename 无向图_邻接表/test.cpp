#include"Tu.h"

int main() {
	int vex_count, arc_count;
	/*cout << "请输入结点数和边数:";
	
	cin >> vex_count >> arc_count;
	ALGraph* G = init_Graph(vex_count, arc_count);
	creat_ALGraph(G,NO_TU);
	print_date(G);

	cout << "A的度:" << cal_node_count(&G->AG[0]) << endl;

	bool* visited = creat_and_init_visited(G);
	DFS(G, 0, visited);
	cout << endl;
	BFS(G, 0);

	cout << endl;
	ALGraph* MST = MST_Prim(G, 0);
	print_date(MST);

	free(G);
	free(visited);*/



	//最短路劲
	/*cout << "请输入结点数和边数:";
	cin >> vex_count >> arc_count;
	ALGraph*GD = init_Graph(vex_count, arc_count);
	creat_ALGraph(GD, YO_TU);
	print_date(GD);
	cout << endl;

	cout << Dijkstra(GD, 4, 6);*/

	cout << "请输入结点数和边数:";
	cin >> vex_count >> arc_count;
	ALGraph* GD = init_Graph(vex_count, arc_count);
	creat_ALGraph(GD, YO_TU);
	print_date(GD);
	cout << endl;

	Topo_Sort(GD);

	return 0;
}

/*

6 10
A B C D E F
A B 6 
A C 8
A D 7
A F 3
B C 5
C F 9
C D 6
D F 6
D E 5
E F 2

MST
6 10
A B C D E F
A B 6
A D 5
A C 1
B C 5
C D 5
B E 3
C E 6
C F 4
D F 2
E F 6

最短路劲
7 10
0 1 2 3 4 5 6
0 2 8
0 1 13
2 3 5
3 4 6
0 4 30
1 5 9
4 5 2
5 6 17
1 6 7
0 6 32

拓扑排序
12 16
A B C D E F G H I J K L
A B 1
A D 1
A L 1
A C 1
B C 1
C E 1
C G 1
C H 1
D E 1
E G 1
I L 1
I J 1
I K 1
J L 1
K F 1
F H 1

*/