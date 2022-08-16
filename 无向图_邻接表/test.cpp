#include"Tu.h"

int main() {
	ALGraph* G = creat_ALGraph(NO_TU);
	print_date(G);

	cout << "AµÄ¶È:" << cal_node_count(&G->AG[0]) << endl;

	bool* visited = creat_and_init_visited(G);
	DFS(G, 0, visited);
	cout << endl;
	BFS(G, 0);

	free(G);
	free(visited);
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





*/